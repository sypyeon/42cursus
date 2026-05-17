#!/bin/sh
if [ ! "$(ls -A /var/lib/mysql/mysql)" ]; then
    mysql_install_db --user=mysql --ldata=/var/lib/mysql
fi
envsubst '${MARIADB_ROOT_PASSWORD} ${MARIADB_DATABASE} ${MARIADB_USER} ${MARIADB_PASSWORD}' \
		< /etc/mysql/template.sql \
		> /etc/mysql/init.sql
exec mysqld --user=mysql --init-file=/etc/mysql/init.sql --console
