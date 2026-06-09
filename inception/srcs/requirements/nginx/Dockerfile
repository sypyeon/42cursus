FROM debian:11

RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    && rm -rf /var/lib/apt/lists/*
    
RUN apk add --no-cache gettext nginx openssl

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY tools/run.sh /usr/local/bin/run.sh
RUN chmod +x /usr/local/bin/run.sh

EXPOSE 443

ENTRYPOINT ["run.sh"]