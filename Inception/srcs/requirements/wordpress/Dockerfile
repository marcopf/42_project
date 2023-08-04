FROM alpine

RUN apk update && apk upgrade
RUN apk add curl php php-fpm php-mysqli php-curl php-dom php-exif php-fileinfo php-xml php-zip php-phar php-tokenizer
RUN apk add php8-pecl-redis --repository=http://dl-cdn.alpinelinux.org/alpine/edge/testing/
RUN		adduser -S nginx && addgroup -S nginx
RUN mkdir -p /var/www/html
COPY tools/setup.sh /usr/local/bin/
COPY	file/php-fpm.conf /etc/php81/php-fpm.conf
COPY	file/www.conf	/etc/php81/php-fpm.d/www.conf
WORKDIR /var/www/html/wordpress
RUN   curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN php wp-cli.phar core download --allow-root
EXPOSE 9000

ENTRYPOINT ["/bin/sh", "/usr/local/bin/setup.sh"]
