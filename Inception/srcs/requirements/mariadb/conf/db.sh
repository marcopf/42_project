#!/bin/sh

echo "[Inception-MariaDB] Initializing the database"

mysql_install_db

mysqld --bind-address=127.0.0.1 --user=root --datadir=/data --skip-networking=0 &
SQL_PID=$!

sleep 1

echo "CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';" | mysql -u root
echo "CREATE DATABASE $MYSQL_DATABASE;" | mysql -u root


echo "GRANT ALL PRIVILEGES ON wordpress.* TO '$MYSQL_USER'@'%';" | mysql -u root
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';" | mysql -u root

echo "[Inception-MariaDB] Rebooting the database"
kill $SQL_PID
wait $SQL_PID

mysqld --bind-address=0.0.0.0 --user=root --datadir=/data --skip-networking=0
