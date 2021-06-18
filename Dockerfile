FROM ubuntu:14.04

RUN apt-get update && apt-get install --yes \
	git \
	gcc-multilib \
	binutils \
	make \
	makeself \
	ncurses-dev \
	libxml2-dev \
	libxml2-utils

COPY build config /bin/
COPY defaults /usr/share/

CMD [ "build" ]
