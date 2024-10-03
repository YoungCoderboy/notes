The concourse is open-source pipeline based CI system. It is most commonly use for CI/CD and is build to scale any kind of automatic pipeline from simple to complex

Build on simple mechanics of resources, tasks and jobs, Concourse presents a general approach to automation that make it great for CI/CD

## Important points

- The concourse is written in GoLang
- It uses postgres for backend
- Use container to run the task

```yml
resources:
  - name: book
    type: git
    source: { url: "https://github.com/vito/book" }

jobs:
  - name: unit
    plan:
      - get: book
        trigger: true # automatically check for update in repo
      - task: test
        file: book/ci/test.yml
```
 
- Resources: are the heart and soul of concourse. They represent all the external inputs to and outputs of jobs in the pipeline 
- Jobs: determine the action of your pipeline. They determine how resource progress through it and how the pipeline is visualized 
- Tasks: is the smallest configurable unit in concourse pipeline. A task can be thought of as function from task.inputs to tasks.outputs that can be either success or failed 