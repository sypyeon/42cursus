#!/bin/sh
envsubst '${DOMAIN_NAME} ${SSL_CERT_PATH} ${SSL_KEY_PATH}' \
	< /etc/nginx/template.conf \
	> /etc/nginx/nginx.conf
exec nginx -g 'daemon off;'