#!/bin/sh
mkdir -p /etc/ssl/nginx
openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/nginx/nginx.key \
    -out /etc/ssl/nginx/nginx.crt \
    -subj "/CN=${DOMAIN_NAME}"

envsubst '${DOMAIN_NAME}' \
    < /etc/nginx/template.conf \
    > /etc/nginx/nginx.conf

exec nginx -g 'daemon off;'