# kubernetes 

## Commands
1. kubectl cluster-info
2. kubectl config current-context {Get the Current Context}
3. kubectl config get-contexts {List all the Context}
4. kubectl config use-context (context_name) {Set the Current Context}
5. kubectl config delete-context (context_name) 
6. kubectl config rename-context (old_context_name) (new_context_name) 
7. kubectl create deployment (deployment_name) --image=(image_name)
8. kubectl get deploy
9. kubectl create -f example.yaml
10. kubectl get ns
11. kubectl config set-context --current --namespace=(name_space_name) {set current context to use a namespace}
12. kubectl create ns (namespaceName)
13. kubectl delete ns (namespaceName)
14. kubectl get pods --all-namespaces {list all pods in all namespace}
15. kubectl get pods 
16. kubectl get nodes
17. kubectl describe node (node_name)
18. kubectl create -f (pod_definition.yaml) {create pods}
19. kubectl get pods {List the Running pods}
20. kubectl get pods -o wide {same but with more info}
21. kubectl get pod (pod_name) -o yaml> file.yaml {extract the pod definition in yaml file and save it}
22. kubectl exec -it (pod_name) -- sh {interactive mode}
23. kubectl config set-context my-context --cluster=my-cluster --user=my-user --namespace=my-namespace
24. kubectl get eq (service_name)
25. kubectl port-forward service/myservice 8080:80
26. kubectl create -f rs-example.yaml
27. kubectl get rs
28. kubectl describe rs rs-example
29. kubectl create deploy (deployment_name) --image=busybox --replica=3 --port=80
30. kubectl create -f (file_name.yaml)
31. kubectl get deploy  
32. kubectl describe deploy (deploy_name)
33. kubectl delete deploy (deploy_name)
34. kubectl create job (job_name)   --image=busybox
35. kubectl create -f (file_name)
36. kubectl get job
37. kubectl describe job (job_name)
38. kubectl logs (pod_name)
39. kubectl create cronjob (job_name) --image=(image_name) --schedule="* * * *" -- bin/sh -c "date"
40. kubectl create -f (file_name)
41. kubectl get cj
42. kubectl describe cj (job_name)
43. kubectl apply -f (file_name)
44. kubectl rollout status {get the progress of updates}
45. kubectl rollout history deployment (deployment_name) {get the history of deployment}
46. kubectl rollout undo (deployment_name) {rollback a deployment}
47. kubectl expose po (pod_name) --port=80 --target-port=8080 --name=frontend {Create the Service expose a pod}
47. kubectl expose deploy (deploy_name) --port=(expose_port) --target-port=(container_port) --name=frontend {create the service to expose a deployment}
48. kubectl apply -f (file_name)
49. kubectl get svc
50. kubectl get svc -o wide
51. kubectl describe sve (service_name)
52. kubectl get pv
53. kubectl get pvc
54. kubectl describe pv (pv_name)
55. kubectl describe pvc (pvc_name)
56. kubectl get cm


- a.k.a K8s
- Originated By Google 
- K8 is leading containers orchestration tool
- Designed as loosely coupled collection of Components Centred around deployment , maintaining and scaling workloads  
- Vendor Neutral
## What Kubernetes Can Do?
- Service discovery and load balancing
- Storage Orchestration (Local or Cloud Based)
- Automatic Rollout and rollback    
- Self Healing 
- Secret and configuration Management
- Use same API across on-premise and every cloud provider
- Service discovery and load balancing Kubernetes can expose a container using the DNS name or using their own IP address. If traffic to a container is high, Kubernetes is able to load balance and distribute the network traffic so that the deployment is stable.
- Storage orchestration Kubernetes allows you to automatically mount a storage system of your choice, such as local storages, public cloud providers, and more.
- Automated rollouts and rollbacks You can describe the desired state for your deployed containers using Kubernetes, and it can change the actual state to the desired state at a controlled rate. For example, you can automate Kubernetes to create new containers for your deployment, remove existing containers and adopt all their resources to the new container.
- Automatic bin packing You provide Kubernetes with a cluster of nodes that it can use to run containerized tasks. You tell Kubernetes how much CPU and memory (RAM) each container needs. Kubernetes can fit containers onto your nodes to make the best use of your resources.
- Self-healing Kubernetes restarts containers that fail, replaces containers, kills containers that don't respond to your user-defined health check, and doesn't advertise them to clients until they are ready to serve.
- Secret and configuration management Kubernetes lets you store and manage sensitive information, such as passwords, OAuth tokens, and SSH keys. You can deploy and update secrets and application configuration without rebuilding your container images, and without exposing secrets in your stack configuration.
- Batch execution In addition to services, Kubernetes can manage your batch and CI workloads, replacing containers that fail, if desired.
- Horizontal scaling Scale your application up and down with a simple command, with a UI, or automatically based on CPU usage.
- IPv4/IPv6 dual-stack Allocation of IPv4 and IPv6 addresses to Pods and Services
- Designed for extensibility Add features to your Kubernetes cluster without changing upstream source code.


## What K8 can't Do?

- Does not deploy Source Code
- Does not build your application 
- Does not provide application-level services 
    - Message busses , database , Caches etc

## K8 Architecture

- It consist of Kubernetes Master (Control Plane) and Kubernetes Nodes
- Worker nodes run container deployed in Cluster 
- Container Runs in `POD` and `POD` Runs in `Node` and All `Node` Form single Clusterx
- Kubernetes provides you with a framework to run distributed systems resiliently. It takes care of scaling and failover for your application, provides deployment patterns, and more. For example: Kubernetes can easily manage a canary deployment for your system.
- Control Plan contorls and runs Kubernetes Services and Controllers 
- Worker node runs containers which you deployed in cluster  
- the kubernetes api server is service running on master node it also exposes REST API that is only point of communication to kubernetes cluster, If there are some desire state we want we specify in YAML file and using kubernetes CLI we send that desire state of Cluster via REST API
- kubectl is use to communicate with apiServer and Its Connection information is store in ${Home}/.kube/config

## K8 Context

- A Context is group of access parameter to K8 cluster
- Contains a Kubernetes Cluster , a User , and a Namespace
- The Current context is the cluster that is currently the default for KubeCtl
    - All kubectl command run against that cluster
- if there are multiple cluster running then the command you run will run in default cluster set in current Context
- kubectx is helper tool to quickly switch between context 

- There are two ways to create the resources 
1. Declarative
    - Use Kubectl commands, issue a series of commands to create the resources  
2. Imperative
    - Using kubectl and YAML manifest file defining the resource that you needs


```YAML
apiVersion : v1
kind : Pod {type of object}
metadata : {metadata.name : Unique name  for the object}
    {metadata.namespace: scoped environment name}
    name: myapp-pod
    labels: 
        app: myapp
        type: front-end
spec: {desired State}
    containers:
    - name : nginx-containers
    image: nginx
```


## NameSpace
- allows you to group resources
- k8 create the default namespace called as default 
- objects in one namespace can access object in different one 
- deleting one namespace will delete all its child objects
- you first define the namespace then you use/specify that namespace when defining the objects 
- you can also define network policy and Resource quata

## Master Node

- nodes are physical or virtual machines , together they forms the cluster
- master node is also called as control plane
- master node contains kubernetes controllers , cloud controllers , kube api servers, kube schedular ,and etcd
- etcd is key value datastore for cluster state data
- the api servers is only component to communicate with etcd

### kube-api server
- REST interface
- Save state in data storage (etcd)
- All client interact with it, never directly with etcd     

### etcd
- Act as the cluster datastore for storing state
- key-value store
- Not a database or datastore for application to use
- Single Source of truth 

### kube Controller manager

- The controller of controller
- It runs controllers
    - Node controllers
    - Replication Controller
    - Endpoint Controller
    - Service account and token controllers

### Cloud Control Manager
- Interact with cloud providers controllers 
    - Node
        - For checking the cloud provider to determine if a node has been deleted in the cloud after it stop responding
    - Route
        - For setting up route in the underlying cloud infrastructure
    - Service
        - For Creating , updating and deleting cloud provider load balancer
    - Volume
        - For Creating , attaching and mounting volumes and interacting with cloud providers to orchestrate volume

### kube Schedular

- watches newly created pods that have no node assigned and select node for them to run on
- Factors taken into account for scheduling decision include
    - Individual and collective resources requirement 
    - Hardware and Software constrains
    - Data locality 

## Worker Nodes
- Nodes running the containers are called as worker nodes
- When the worker nodes is added to cluster some kubernetes services are install directly like container runtime , kubelet , kube-proxy . These are services necessary to run pods and these are manage by master nodes

### kubelet
- It manages the pods lifecycle 
- Ensure the container describing in pod specification are running and healthy 

### kube-proxy
- A network proxy
- Manages network rules on nodes
- all network traffic goes through network proxy
### container Runtime 
- K8 support several container runtime 
- Must implement k8 container runtime interface 
- CRI : Container Runtime Specification 

## NOTE

before 1.19 Moby container runtime and it receive the CRI call through docker shim because it not fully implement the interface

Now a days moby is no longer install , What change is that what you can do inside the cluster
- you can no longer access the docker engine inside the cluster
- docker commands wont run if you ssh into a node   
- use crictl instead 

## NODE Pool 
- a node pool is group of virtual machines all with same size 
- a cluster can have many node pools    
    - these node pools can host different size of VMs
    - Each pool can be auto scaled independently from the other pools
- docker desktop is limited to one node 

## PODS

- Atomic unit of the smallest unit of work of k8s
- Encapsulate the application container
- Represent the unit of deployment   
- pods can run one or more containers
- containers within the pods share
    - Ip add , mounted volumes
- containers within the pods can communicate using localhost and IPC
- Deploying the pods are atomic operation 
- If pods fails , it is replaced with new one with shiny new IP
- you don't update the pods, you replace with new one
- you scaled by adding more pods , not more containers in same pod
- node can run multiple pods 
- if pod contains multiple containers then one of them is main workers and other are called sidecar or helper containers


### State of POD
- Pending {Accepted but not yet created }
- Running {bounded to node}
- Succeed {Exited with status of 0}
- Failed {All Container Exited  }
- Un-Know {Communication Issue with pods}
- CrashLoopBackOff


### Creating the pods
- you create YAML file with resource kind as pod
- specify the image location 
- set container listening port
- we can also add labels which is use to identify , describe and group related set of objects or resource
- we can also set env variables as well

## Init Container

- This is use when we have dependency between the containers
- init a pod before the application container runs
- the init container run before the application run and this init container will make sure that certain configuration is done
- Each init containers must complete Successfully before the next one starts
- If it failed, Kubelet repeatedly restart it until it Succeed unless we mention not to in restart policy

```YAML
apiVersion : 1
kind : Pod
metadata: 
    name: myapp-pod
    labels: 
        app: myapp

spec:
# App Container
    containers:
    -name : myapp-container
    image:busybox
# Init Containers
    initContainer:
    -name : init-myService
    image: busybox:1.28
    command: ['sh' ,'-c' , "Until nslookup "]

```

## Selectors

### Labels
- key-value pairs used to identify , describe , and group related set of objects or resources
- selector use labels to filter or Select objects
- 'nodeSelector' is used to filter or Select Objects

## Networking

- All Container within the pod can communicate with each other
- All Pods can Communicate with each other
- All nodes can communicate with pods
- pods are given an IP address (ephemeral)
- Services are given Persistent IP
- two pods can communicate using service 

## Workloads

- workload is application running on kubernetes
- all container running in cluster must run in work load
- pod is atomic workload which represent set of running containers
- Replica Set and Deployment provide the extra function to pods

### Replica Set 
- primary method of managing pod replica and their lifecycle to provide self healing capability
- There job is to always ensure the desire number of pods are running 
- While you can create Replica Set , The recommended way is to create Deployments
- TO define the replica Set we take the pod definition except version and kind and replace this value in template section of replica Set

### Deployment

- pods don't 
    - self heal
    - scale
    - update
    - rollback 
- Deployment manages Single pod template
- You Create a deployment for each microservice
    - front-end
    - back-end

- Deployment create the replica set in background
- Don't interact replica directly 
- Deployment Set add the functionality of Rolling update and rollbacks
- Create the yaml File with kind of Deployment
    - replica:
        - No of pods instances
    - RevisionHistoryLimit
        -  Number of previous iteration to keep
    - Strategy
        - Rolling Update
            - Cycle through updating pods
        - Recreate
            - All existing pods are killed  before new one are created

- same as Replica set we paste the pod definition in template section of Deployment Set

## Daemon Sets
- Ensure all Node (or a Subset) run an instance of Pod
- Schedule by Schedule Controller and run by daemon Controller
- As Nodes are added to cluster, Pods are added to them 
- Used In
    - Running a Cluster Storage Daemon 
    - Running a Log Collection Demon on every node
    - Running a node monitoring demon on every node 

## StateFul Sets
- Useful for pods which need to maintain the state
- Stateful set maintains a sticky identity for each of their pods
- Each has a persistent identifier
- if pods dies then it get replaced by another pod with same identifier
- Create the pod in sequence and delete in reverse order

## Jobs
- Workloads for short lived tasks
- Creates one or more pods and ensure that a specific number of them successfully get Terminated
- As pods successfully complete the job tracks the successful completion 
- When Specific number of job completion is reached the job competes

## CronJob

- An extension of the job
- Provide a method of executing jobs on a cron like schedular
- UTC only

## Rolling Updates
- There are two update way in kubernetes
    1. Rolling Update : Cycle through updating pods
    2. Recreate : All existing pods are killed before new one is created
        - There is small period of time where our microservice might not be responsive


- Using rolling update a pod is create and replaced by new one 
- there are two values of rolling update
    1. maxSurge
        - Max number of pods that can be created over the desired number of pods
    2. maxUnavailable 
        - Max number of pods that can be unavailable during the update process
    
# Services

- Services is another k8 objects
- pod ip is unreliable but services IPs are Durable (unlike pods)
    - Static IP address
    - Static DNS name
    - [service_name].[namespace].svc.cluster.local
- Services are way to access pods
- Uses selector to target pods
- Services provide three way to connect 
1. Cluster IP (default)
    - It visibility is Cluster Internal
    - port : The port the service is listening to
    - Target Port : Redirected to port the pod are listening to 
    - Load is balancing using round robin
    - Use when to provide the durable way to communicate the pods inside the cluster
2. Node Port
    - It visibility is Cluster Internal and External
    - port range : 30000 - 32767
    - Port : The port the service is listening to internally
    - Target Port: Redirect the port Pod is listening on 
    - Must have public IP address
3. Load Balancer
    - L4 (level 4 load balancer)
    - operate at transport layer
    - unable to make decision based on content
    - simple algorithm such as round robin routing   
    
4. Ingress
    - L7 Load Balancer
    - able to make decision based on actual content of each message
    - operate at application layer
    - More intelligent load balancer decision

# Storage and Persistence 
- Container are ephemerous and stateless
- data is destroyed with its containers
- Volume let containers to store data in external storage system 
- Vendors create plugins for their storage system according to Container Storage Interface
- There are two way
    1. Static
    2. Dynamic

## Static

- Persistent Volumes (PV)
    - Represent a storage resource 
    - Cluster Wide
    - Provision by administrator
- Persistent Volume Claim (PVC)
    - a one to one mapping to persistent volumes
- one or more pods can use a Persistent volume Claim
- Can be consume by any of the containers within the pods
- PV uses the cloud storage resources to build the storage volume then we use PVC to claim the portion of Storage Class and then pods can use that claim  
- BY default the Reclaim policy is on Delete not on retain ie the date gets deleted as soon as pods get deleted we need to change the policy to retain

### Access Modes

- ReadWriteMany
    - The Volume can be mounted as read-write by many pods
- ReadOnlyMany
    - The Volume ca be mounted as read only by many pods
- ReadWriteOnce
    - The Volume can be mounted as read-write by single pod
    - The other pods are in read only mode
    - The one who has mounted the volume first will be able to write 

### Persistent Volume States
- Available
    - A free resource that is not yet bound to claim
- Bound
    - Volume is bound to claim
- Released
    - The claim has been deleted , but the resource is not yet reclaimed by the cluster
- Failed
    - The volume has failed its automatic Reclamation

## Dynamic 

- Describe the classes of storage offered by admin
- An abstraction on top of external storage Resources
- No need to set the capacity 

- Here we create Storage Class without the capacity and then use pvc to claim the portion of storage Class

It have same access mode as Static Mode

## ConfigMap

- Allows you to decoupled and externalize the configuration 
- Reference as Env Variables
- Created From 
    - Manifest
    - Files
    - Directories
- These are static that if you changes values, the containers will have to be restarted to get them
- we create yaml file with kind of ConfigMap and place key value pair in data section
- when using env variable we specify as follow

```yaml
    env: 
    - name: STATE
      valueFrom:
        configMapKeyRef:
            name: (config_map_name)
            key: (key_to_reference)

```

- to Solve the static issue of restarting the pods
- we uses the volumes to make change in value reflect in container
- Each key/value pair is seen as file in mounted directory
```yaml

apiVersion: v1
kind: ConfigMap
metadata:
    name: cm-example
data:
    state: Maharashtra
    city: Pune


# Pod file

apiVersion: v1
kind: Pod
metadata: 
    name: pod-example
spec:
    volumes:
    - name: volmap
     configMap:
        name: cm-example
containers:     
    - name: test-container
    image: nginx
    volumeMounts:
    - name: volmap
      mountPath: /etc/config 

```

## Observability  

- if pod crashes then the pod gets restart but if the container inside the pod get crashed then the pods don't get restart since kubernetes see pod up and running fine that don't know pod in not working internally so we use concept of probes     

### probes
- hers are some time of probes
1. startup probes
    - to know when containers has started
2. Readiness probes 
    - to know when containers is ready to accept traffic
    - failing readiness probes will stop the application from receiving traffic
3. Liveness Probes
    - Indicates whether the code is running or not
    - A failing liveness probes will restart the containers

### probing the container (Liveness Probes)
- the kubelet check periodically the containers using probes
- Exec Action 
    - Execute a command inside the containers   
- TCPSocketAction
    - Check if TCP socket port is open
- HTTPGetAction
    - perform an HTTP GET against specific port and path
