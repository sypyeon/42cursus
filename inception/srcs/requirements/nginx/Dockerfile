FROM alpine:3.20

COPY ./conf/template.conf /etc/nginx/template.conf
COPY ./conf/run.sh /etc/nginx/run.sh

RUN apk add --no-cache gettext nginx

EXPOSE 443

ENTRYPOINT ["sh"]
CMD ["/etc/nginx/run.sh"]