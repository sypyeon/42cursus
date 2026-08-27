FROM debian:12

RUN apt-get update && apt-get install -y \
    mariadb-server \
    gettext-base \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /run/mysqld && chown mysql:mysql /run/mysqld

COPY conf/init.sql /etc/mysql/init.sql
COPY tools/run.sh /usr/local/bin/run.sh
RUN chmod +x /usr/local/bin/run.sh

EXPOSE 3306

ENTRYPOINT ["run.sh"]