# Initial docker was created using below code
# FROM ubuntu:focal
# COPY . /home/app
# WORKDIR /home/app
# SHELL ["/bin/bash", "-o", "pipefail", "-c"]
# RUN echo "Running on Prady Docker  " && \
#     apt update && \
#     apt install build-essential -y && \
#     g++ -std=c++2a app.cpp -o out && ./out

# Then docker container was updated and a new version was pushed as v2 after commiting it

# Either I can pull my v2 and then update on top of it or create a new docker -
# looks like creating is a new one is a better choice as containers should be immutable 


# Creating a new image only with instalations and not the shell commands
FROM ubuntu:focal
SHELL ["/bin/bash", "-o", "pipefail", "-c"]
RUN echo "Running on Prady Docker  " && \
    apt update && \
    apt install build-essential -y && \
    apt install -y build-essential libssl-dev libffi-dev python3-dev  && \
    apt install -y vim nano  

