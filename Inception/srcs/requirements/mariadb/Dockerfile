FROM alpine

RUN apk update && apk upgrade
RUN apk add mysql mysql-client

COPY ./conf/db.sh /usr/local/bin/
RUN mkdir /run/mysqld

ENTRYPOINT ["/bin/sh", "/usr/local/bin/db.sh"]
