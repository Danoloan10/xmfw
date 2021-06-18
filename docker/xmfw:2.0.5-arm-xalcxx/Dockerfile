FROM danoloan/xmfw:base

ADD https://github.com/Danoloan10/xm-arm/archive/refs/tags/2.0.5-xalc++.tar.gz /opt/xtratum.tar.gz

RUN tar -C /opt -zxf /opt/xtratum.tar.gz && rm /opt/xtratum.tar.gz && mv /opt/* /opt/xtratum

CMD [ "sh" ]
