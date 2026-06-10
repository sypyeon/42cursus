#!/bin/bash

if [ ! -d /var/lib/mysql/mysql ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
fi

envsubst < /etc/mysql/init.sql > /etc/mysql/init_real.sql

exec mysqld --user=mysql --init-file=/etc/mysql/init_real.sql --console --bind-address=0.0.0.0