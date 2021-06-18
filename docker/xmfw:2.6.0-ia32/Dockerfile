FROM danoloan/xmfw:base

ADD https://github.com/Danoloan10/xm-ia32/archive/refs/tags/2.6.0.tar.gz /opt/xtratum.tar.gz

RUN dpkg --add-architecture i386 && apt-get update && apt-get install --yes libxml2-dev:i386 && tar -C /opt -zxf /opt/xtratum.tar.gz && rm /opt/xtratum.tar.gz && mv /opt/* /opt/xtratum

CMD [ "sh" ]
