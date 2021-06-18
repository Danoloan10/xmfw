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

COPY . /

CMD [ "sh" ]
