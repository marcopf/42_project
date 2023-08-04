while ! nc -z mariadb 3306; do
  echo "looking for db..."
  sleep 0.1
done
mv wp-config-sample.php wp-config.php
sed "s/database_name_here/$MYSQL_DATABASE/1" -i -r wp-config.php
sed "s/username_here/$MYSQL_USER/1" -i -r wp-config.php
sed "s/password_here/$MYSQL_PASSWORD/1" -i -r wp-config.php
sed "s/localhost/mariadb/1" -i -r wp-config.php
php wp-cli.phar core install --url=$DOMAIN_NAME/ --title=$WORDPRESS_TITLE --admin_user=$WORDPRESS_ADMIN_USERNAME --admin_password=$WORDPRESS_ADMIN_PASSWORD --admin_email=$WORDPRESS_ADMIN_EMAIL --skip-email --allow-root
php wp-cli.phar user create $WORDPRESS_USER_USERNAME $WORDPRESS_USER_EMAIL --role=author --user_pass=$WORDPRESS_USER_PASSWORD --allow-root
php wp-cli.phar theme install twentytwentytwo --activate --allow-root
php wp-cli.phar post create --post_title=Inception42 --post_status=publish
php wp-cli.phar option update blogdescription "42 project Inceptio website"
sed "s/127.0.0.1:9000/0.0.0.0:9000/1" -i -r /etc/php81/php-fpm.d/www.conf
chmod -R 777 .
/usr/sbin/php-fpm81 -F
