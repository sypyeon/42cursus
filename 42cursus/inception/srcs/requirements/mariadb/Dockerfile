FROM alpine:3.20

COPY ./conf/template.sql /etc/mysql/template.sql
COPY ./conf/run.sh /etc/mysql/run.sh

RUN apk add --no-cache gettext mariadb && \
	mkdir -p /var/lib/mysql /run/mysqld && \
	chown -R mysql:mysql /var/lib/mysql /run/mysqld

RUN sed -i 's/^skip-networking/#skip-networking/' /etc/my.cnf.d/mariadb-server.cnf && \
	sed -i 's/^#bind-address=0.0.0.0/bind-address=0.0.0.0/' /etc/my.cnf.d/mariadb-server.cnf

EXPOSE 3306

ENTRYPOINT ["sh"]
CMD ["/etc/mysql/run.sh"]