#!/bin/sh
set -e

sed -i 's/listen = 127.0.0.1:9000/listen = 9000/g' /etc/php83/php-fpm.d/www.conf

echo "Waiting for MariaDB..."
tries=0
until nc -z mariadb 3306; do
    tries=$((tries + 1))
    if [ "$tries" -ge 30 ]; then
        echo "MariaDB is unreachable after 60s, giving up." >&2
        exit 1
    fi
    sleep 2
done
echo "MariaDB is up."

cd /var/www/html

if [ ! -f /var/www/html/wp-settings.php ]; then
    wp core download --allow-root
fi

if ! wp core is-installed --allow-root 2>/dev/null; then
    envsubst '${DOMAIN_NAME} ${MARIADB_DATABASE} ${MARIADB_USER} ${MARIADB_PASSWORD} ${WORDPRESS_DB_HOST} ${AUTH_KEY} ${SECURE_AUTH_KEY} ${LOGGED_IN_KEY} ${NONCE_KEY} ${AUTH_SALT} ${SECURE_AUTH_SALT} ${LOGGED_IN_SALT} ${NONCE_SALT}' \
        < /etc/wordpress/template.php \
        > /var/www/html/wp-config.php

    wp core install \
        --url="https://${DOMAIN_NAME}" \
        --title="Inception" \
        --admin_user="${WP_ADMIN_USER}" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --allow-root

    wp user create "${WP_USER}" "${WP_EMAIL}" \
        --role=subscriber \
        --user_pass="${WP_PASSWORD}" \
        --allow-root
fi

# php-fpm workers run as "nobody" on Alpine, but wp-cli ran as root.
chown -R nobody:nobody /var/www/html

exec php-fpm83 -F
