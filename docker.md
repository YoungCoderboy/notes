# Docker
## Commands
1. docker pull (service_name)
2. docker run (service_name)
3. docker ps : List of Running Containers  
4. docker run -d (service_name) : Starts New Container with Detached Mode
5. docker stop (container_id)
6. docker start (container_id)
7. docker ps -a : Lists running and stopped containers
8. docker run -p host_port:from_port
9. docker logs (container_id)
10. docker run -d -p 6001:6373 --name (any_name) (service_name)
11. docker exec -it (container_id) /bin/bash
12. docker images
13. docker network ls
14. docker network create (network_name)
15. docker run -p (port):(port) -d -e (environment_var) --name (custom_name) --net (network_name) (service_name)
16. docker-compose -f (file_name) up
17. docker-compose -f (file_name) down
18. docker build -t (image_name):(tag) (docker_file location)
19. docker rm (container_name)
20. docker rmi (image_name)



 


## What is Container

- A way to package application with all the necessary dependencies and configuration 
- Portable artifact, easily shared and moved around
- Makes development and deployment process easier
- Each Container have there own isolated environment and packaged with all needed configuration


<hr />

Container is

- Layers of Images
- Bottom most is mostly linux based image because of small in size (alpine)
- Application image on top
- Docker image is the actual package 

## Docker Vs Virtual Machine

- Any System can be divided into 3 Section 
    1. Application
    2. Os Kernel
    3. Hardware
- OS manages Application and OS Kernel 
- Docker virtualize Application Layer and Use Kernel of Host
- Virtual Machine Virtualize Application and OS Kernel Both Which is Heavy Task


## Image Vs Container

- Container is running environment for IMAGE
- Image is a read-only template that contains the necessary files and dependencies to run a piece of software.
- Container is an instance of an image that can be run and executed on a host machine.
- Containers are lightweight and share the host machine's operating system kernel, making them more efficient than virtual machines.
- Container provide File System, Environment Configs , Application Image
- Container has port binded to it which make it possible to application running inside the container to talk

## Container port vs host port
- Multiple Containers can run on your host machine 
- Host Have limited Number of port available 
- if the container demanding port is already taken then we use by other container then another open port of host machine is used
- service in same container can talk to each other without using localhost    

## Docker Compose 

```yaml
    version: '3' (version of docker-compose)
    services: 
        mongodb: (new_container_name)
            image: (image_name)
            ports:
                - (port_host):(port_container)
            environment:
                - Mongo_UserName=admin 
```

- Docker composer take care of creating the a common network
- Data present in docker get remove when we restart the docker container


## Dockerfile
- Blueprint for creating docker image


```Dockerfile
FROM node  (install node)
ENV MONGO_DB_USERNAME = admin \
    MONGO_DB_PWD = password
RUN mkdir -p /home/app (RUN can run any linux command)

COPY . /home/app (EXECUTE ON HOST it copy from host to image)

CMD ["node", "server.js"] (act as entry point)

```


## Docker Volumes



 