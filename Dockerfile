FROM yg397/thrift-microservice-deps:xenial

ARG NUM_CPUS=2

COPY ./ /vending-machine-microservices
RUN cd /vending-machine-microservices \
    && mkdir -p build \
    && cd build \
    && cmake .. \
    && make -j${NUM_CPUS} \
    && make install

WORKDIR /vending-machine-microservices
