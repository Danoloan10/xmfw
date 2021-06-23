FROM danoloan/xmfw:base

ADD https://github.com/Danoloan10/xm-sparc/archive/refs/tags/1.0.8.tar.gz /opt/xtratum.tar.gz

RUN tar -C /opt -zxf /opt/xtratum.tar.gz && rm /opt/xtratum.tar.gz && mv /opt/* /opt/xtratum

COPY . /

CMD [ "sh" ]
