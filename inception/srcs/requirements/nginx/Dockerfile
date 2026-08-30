FROM alpine:3.23.5

RUN apk add --no-cache gettext nginx openssl

COPY ./conf/template.conf /etc/nginx/template.conf
COPY ./tools/run.sh /etc/nginx/run.sh

EXPOSE 443

ENTRYPOINT ["sh", "/etc/nginx/run.sh"]