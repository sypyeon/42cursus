FROM alpine:3.23.5

RUN apk add --no-cache \
    php83 \
    php83-fpm \
    php83-pdo \
    php83-pdo_mysql \
    php83-mysqli \
    php83-json \
    php83-curl \
    php83-mbstring \
    php83-xml \
    php83-zip \
    php83-gd \
    php83-opcache \
    php83-session \
    php83-tokenizer \
    php83-phar \
    curl \
    bash \
    gettext \
    netcat-openbsd && \
    ln -sf /usr/bin/php83 /usr/bin/php

RUN echo "memory_limit=512M" > /etc/php83/conf.d/50-memory.ini

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

COPY conf/template.php /etc/wordpress/template.php
COPY tools/run.sh /usr/local/bin/run.sh
RUN chmod +x /usr/local/bin/run.sh

EXPOSE 9000

ENTRYPOINT ["run.sh"]
