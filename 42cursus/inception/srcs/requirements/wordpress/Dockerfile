FROM alpine:3.20

COPY ./conf/template.php /var/www/html/template.php
COPY ./conf/run.sh /var/www/html/run.sh

RUN apk add --no-cache \
    php \
    php-fpm \
    php-mysqli \
    php-json \
    php-xml \
    php-dom \
    php-mbstring \
    php-session \
    php-gd \
	php-phar \
    php-redis \
    php-ctype \
	gettext \
    curl

RUN ln -s /usr/sbin/php-fpm83 /usr/bin/php-fpm
RUN ln -s /etc/php83 /etc/php

WORKDIR /var/www/html
RUN curl -O https://wordpress.org/latest.tar.gz && \
    tar -xzf latest.tar.gz && \
    mv wordpress/* . && \
    rmdir wordpress && \
    rm latest.tar.gz

RUN chown -R nobody:nobody /var/www/html
RUN chmod 777 /var/www/html

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp && \
	chmod +x /usr/local/bin/wp

EXPOSE 9000

ENTRYPOINT ["sh"]
CMD ["/var/www/html/run.sh"]