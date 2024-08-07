# Docker
- It is an open source container Runtime 
- Command Line tool
- Dockerfile file format for building container images
## Commands
1. docker pull (service_name)
2. docker run (service_name)
3. docker ps { List of Running Containers  }
4. docker run -d (service_name)  {Starts New Container with Detached Mode}
5. docker stop (container_id)
6. docker start (container_id)
7. docker ps -a {Lists running and stopped containers}
8. docker run -p host_port:from_port
9. docker logs (container_id)
10. docker run -d -p 6001:6373 --name (any_name) (service_name)
11. docker exec -it (container_id) /bin/bash
12. docker images
13. docker network ls
14. docker network create (network_name)
15. docker run -p (port):(port) -d -e (environment_var) --name (custom_name) --net (network_name) (service_name)

<hr/>

### Docker Compose

16. docker compose build {build the images}
17. docker compose start  {starts the containers}
18. docker compose stop {stops the containers}
19. docker compose up -d {Build and start }
20. docker compose ps {Lists what is running}
21. docker compose rm {Remove from the Memory}
22. docker compose logs
23. docker compose exec (container) bash
24. docker compose --project-name test1 up -d {run the instance as a project}
25. docker compose -p test1 up -d {shortcut}
26. docker compose ls {Lists running projects}
27. docker compose logs -f (service_name)


<hr/>

18. docker build -t (image_name):(tag) (docker_file location)
19. docker rm (container_name)
20. docker rmi (image_name)
21. docker info {Display System Information}
22. docker version
23. docker login {Login to docker registry }
24. docker image inspect (image_name)
25. docker run --memory="256m" (image_name) {Set Max Memory}
26. docker run --cpus=".5" (image_name) {Set Max CPU'S}
<hr />

### Volumes

27. docker create volume (volume_name) {Create New Volumes}
28. docker volume ls {List of Volumes}
29. docker volume inspect (volume_name) {Display Volume info}
30. docker volume rm (volume_name)
31. docker volume prune {Delete all unmounted volumes}
32. docker run -d --name test -v myvolue:/app (image_name) {/app is logical address in container}



## What is Container

- A way to package application with all the necessary dependencies and configuration 
- Portable artifact, easily shared and moved around
- Makes development and deployment process easier
- Each Container have there own isolated environment and packaged with all needed configuration
- Container contain all necessary things to run code , Runtime , System Tools , System Library 
- Container are ephemerous and stateless 
- We don't generally store data in Containers
    - So When Container Destroyed then Data inside them as well
- To Store Data We Should Store data outside the container also called as Volume
- Volumes Map is mapped to logical folder (maps a folder on host to logical Folder in Containers) 

### Why Container?

- Move fast by deploying small units
- use few Resources 
- Fit more in same host
- Fast Automation 
- Portability 
- Isolation



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
- Define and run multi-container applications
- Define using YAML files
- Use For WorkLoads that don't required a full orchestrator 
- Development and testing 

```YAML (Use of Networking)
version: '3.8'  # Specify the version of docker-compose

services:
  mongodb:
    image: mongo:latest  # Use the latest MongoDB image
    container_name: mongodb_container
    ports:
      - "27017:27017"  # Map port 27017 on the host to port 27017 in the container
    environment:
      - MONGO_INITDB_ROOT_USERNAME=admin
      - MONGO_INITDB_ROOT_PASSWORD=admin
    networks:
      - my_network  # Connect to the custom network

  nodeapp:
    image: node:latest  # Use the latest Node.js image
    container_name: nodeapp_container
    ports:
      - "3000:3000"  # Map port 3000 on the host to port 3000 in the container
    depends_on:
      - mongodb  # Ensure MongoDB starts before this service
    networks:
      - my_network  # Connect to the custom network

networks:
  my_network:
    driver: bridge  # Use the default bridge driver
```
- We use depends_on to Make sure that it run after dependency is full filled

### Docker Compose Features

- we can define reservation of Resources and limits of Resources as well 
- We can Access the Environment Variable using ${ENV_VAR}


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


## Monolithic Architecture 

- Build as single unit
- Deployed as single unit 
- For scaling Duplicate on each server


## Microservice Architecture 

- A variant of service-oriented architecture (SOA) structural style 
- arranges an application as collection of loosely coupled services
- In microservice architecture , services are fine-grained and the protocol are light weight 
- Segregates functionality into smaller separated services each with a single responsibility 
- scale out by deploying each service independently 
- Each Services are loosely coupled
- Enables autonomous development by different teams , languages and platforms 
- CI/CD: continuous Integration and Deployment 

### Microservices Benefits 
- improved fault isolation 
- Eliminate vendor or technology Lock in 
- Ease to understand 
- smaller and faster to deploy 

### Microservices Drawbacks 
- Complexity is added to resolve issues
- One update in microservice may impact other microservices 
- Manage multiple database  
- Latency Issues 
- Transient Error 
- Multiple Point of Failure 
- Security Issues

## Cloud Native 

- Its an new way of thinking about building complex system 
- widely popular in open source communities 
- Cloud native foundation empowers organization to build and run scalable application in modern and dynamic environment such as public , private and hybrid clouds 
- Cloud native refers to software applications, technologies, and architectures designed from the ground up to optimize the use of cloud computing characteristics, such as scalability, resilience, and automation. These systems leverage cloud-native technologies like containers, microservices, serverless functions, and immutable infrastructure to build and deploy scalable, flexible, and resilient applications that can be easily managed and monitored.

### Application Architecture
1. Kubernetes pattern
2. Microservices pattern
3. Domain Driven Design 
4. Clean Code
- infrastructure become immutable and disposal 
### Objectives
1. Containerization 
2. CI/CD: Continuous Integration / Continuous Delivery 
3. Orchestration and application definition 
4. Analysis 
5. Service Proxy, Discovery and Mesh
6. Networking and Security Policies 

## YAML
- YAML aren't markup language 
- Human friendly data Serialization Standard
- Used by docker compose and kubernetes 



