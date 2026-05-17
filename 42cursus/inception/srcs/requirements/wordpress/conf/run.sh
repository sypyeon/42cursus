#!/bin/sh
set -eo pipefail

if ! wp core is-installed; then
	envsubst '${DOMAIN_NAME} \
		${MARIADB_DATABASE} \
		${MARIADB_USER} \
		${MARIADB_PASSWORD} \
		${WORDPRESS_DB_HOST} \
		${AUTH_KEY} \
		${SECURE_AUTH_KEY} \
		${LOGGED_IN_KEY} \
		${NONCE_KEY} \
		${AUTH_SALT} \
		${SECURE_AUTH_SALT} \
		${LOGGED_IN_SALT} \
		${NONCE_SALT}' \
		< /var/www/html/template.php \
		> /var/www/html/wp-config.php

	sed -i 's/;cgi.fix_pathinfo=1/cgi.fix_pathinfo=0/g' /etc/php/php.ini && \
	sed -i 's/listen = 127.0.0.1:9000/listen = 9000/g' /etc/php/php-fpm.d/www.conf

	wp core install --url="${DOMAIN_NAME}" \
		--title="My WordPress Site" \
		--admin_user="${WP_ADMIN_USER}" \
		--admin_password="${WP_ADMIN_PASSWORD}" \
		--admin_email="${WP_ADMIN_EMAIL}" || exit 1;
	wp user create ${WP_USER} ${WP_EMAIL} \
		--role=subscriber \
		--user_pass="${WP_PASSWORD}" || exit 1;
	wp plugin install redis-cache --activate
else
	echo wp installed
fi

exec php-fpm -F