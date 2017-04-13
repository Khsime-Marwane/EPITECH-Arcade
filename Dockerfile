FROM ubuntu
MAINTAINER Samuel Romain <romain.samuel@epitech.eu>
MAINTAINER Khsime Marwane <marwane.khsime@epitech.eu>
MAINTAINER Maud Marel <maud.marel@epitech.eu>

RUN apt-get update
RUN apt-get install -y build-essential apt-utils
RUN apt-get install -y libglfw3-dev \
                        libsoil-dev \
                        libopenal-dev \
                        libsfml-dev \
                        libglew-dev \
                        libsndfile1-dev \
                        libncurses5-dev \
                        ftgl-dev \
                        wget \
                        git \
                        gcc \
                        clang \
                        g++ \
                        libegl1-mesa \ 
                        libgl1-mesa-dev \
                        libglu1-mesa \
                        libglu1-mesa-dev \
                        libsfml-dev \
                        libgtest-dev \
                        binutils-dev \
                        libtool \
                        lua5.2 \
                        liblua5.2-dev \
                        liblua5.2-0 \
                        graphviz \
                        doxygen

RUN mkdir -p /arcade
COPY . /arcade/

EXPOSE 3001
