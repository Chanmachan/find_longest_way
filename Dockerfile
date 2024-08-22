FROM ubuntu:latest
RUN rm -rf /var/lib/apt/lists/*
RUN apt-get -y update && apt-get -y install build-essential cmake libboost-all-dev graphviz

CMD ["bash"]