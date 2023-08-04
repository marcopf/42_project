echo "stopping containers..."
sudo docker-compose -f ./srcs/docker-compose.yml down
echo "removing volumes..."
if [ "$(sudo docker volume ls -q)" != "" ]
then
  sudo docker volume rm -f $(sudo docker volume ls -q)
fi
echo "cleaning hosts..."
sed '/mpaterno.42.fr/d' /etc/hosts > temp && sudo mv temp /etc/hosts
if [ "$(command -v docker)" != "" ] && [ "$OSTYPE" == "linux-gnu" ]
then
  dpkg -l | grep -i docker
  sudo apt-get purge -y docker-engine docker docker.io docker-ce docker-ce-cli docker-compose-plugin
  sudo apt-get autoremove -y --purge docker-engine docker docker.io docker-ce docker-compose-plugin
fi
if [ "$(command -v docker-compose)" != "" ] && [ "$OSTYPE" == "linux-gnu" ]
then
  sudo apt remove docker-compose -y
fi
