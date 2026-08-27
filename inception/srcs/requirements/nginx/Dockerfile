FROM alpine:3.23.5

COPY ./conf/template.conf /etc/nginx/template.conf
COPY ./tools/run.sh /etc/nginx/run.sh

RUN apk add --no-cache gettext nginx openssl

EXPOSE 443

ENTRYPOINT ["sh", "/etc/nginx/run.sh"]