echo "stopping containers..."
docker-compose -f ./srcs/docker-compose.yml down
echo "removing volumes..."
if [ "$(docker volume ls -q)" != "" ]
then
  docker volume rm -f $(docker volume ls -q)
fi
echo "cleaning hosts..."
sed '/mpaterno.42.fr/d' /etc/hosts > temp && sudo mv temp /etc/hosts
if [ "$(command -v docker)" != "" ] && [ "$OSTYPE" == "linux-gnu" ]
then
  sudo apt remove docker -y
fi
if [ "$(command -v docker-compose)" != "" ] && [ "$OSTYPE" == "linux-gnu" ]
then
  sudo apt remove docker-compose -y
fi
