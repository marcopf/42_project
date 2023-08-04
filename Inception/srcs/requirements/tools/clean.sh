echo "stopping containers..."
sudo docker-compose -f ./srcs/docker-compose.yml down
echo "removing volumes..."
if [ "$(sudo docker volume ls -q)" != "" ]
then
  sudo docker volume rm -f $(sudo docker volume ls -q)
fi
