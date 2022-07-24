## Basic commands used for docker 

* Dockerfile in repo is used to create the basic docker image
* to view all images `docker images` / `docker images -a`
* to view all containers `docker ps -a`
* to remove container `docker rm container_id`
* to remove image `docker rmi image_id`, `-f` for force removing 
* to build a container `"docker build -t prady_docker .` 
  * This builds a docker image with the docker file mentioned in this repo
* to pull a docker image from repo: `docker pull image_name`
* to run a docker image: `docker run image_name`
  * interactive mode `docker run -it image_name`
  * to open bash with the image `docker run -it image_name /bin/bash`
* to remove dangling images `docker rmi $(docker images --filter "dangling=true" -q --no-trunc)`
* to commit a container as an image after changes `docker commit --author "korivip" --message "Added Python installation" container_id`
  * We can run an image and then update certain things in container - maybe new installation or addition of files. Then they can be committed as new versions
  * This committed image is without name and tag
  * Add tag and names `docker tag image_id korivip/repository_name:tag`
    * `docker tag dde9ea8fa21a korivip/prady_docker:v2`
* to check differences in a container compared to base `docker diff container_id`
* to push to docker hub `docker push repository:tag`
  * `docker push korivip/prady_docker:v2`
* Mount local drive to docker to access the file system
  * `docker run -it --rm -v local_data_folder:docker_folder docker_image:tag`
    * `docker run -it --rm -v ~/Desktop/learnings/docker/hello_world/test_dir:/home/test korivip/prady_docker:v2`
