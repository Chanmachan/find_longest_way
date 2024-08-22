FROM ubuntu:latest
RUN rm -rf /var/lib/apt/lists/*
RUN apt-get -y update && apt-get -y install build-essential cmake libboost-all-dev graphviz

WORKDIR /app
COPY data/ /app/data/
COPY src/ /app/src/
COPY test/ /app/test/
COPY custom_input_script.py /app/
COPY CMakeLists.txt /app/

CMD ["bash"]