echo "stopping containers..."
docker-compose -f ./srcs/docker-compose.yml down
echo "removing volumes..."
if [ "$(docker volume ls -q)" != "" ]
then
  docker volume rm -f $(docker volume ls -q)
fi
