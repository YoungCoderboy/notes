# Introduction to Git

- Git is an version control software which allows use to track the change and allows better collaboration
- Git is software and Github is service which is web hosted

- Make the atomic commits , these are the way to make sure that each commit is self contained also give order to code as message
- `.gitignore` will contain the files and folders which will ignore by github
- `.gitkeep` if you want to track empty folder
- Each commit in the project is stored in .git folder in the form of a commit object. A commit object contains the following information:
  - Tree Object
  - Parent Commit Object
  - Author
  - Committer
  - Commit Message
- Tree Object is a container for all the files and folders in the project. It contains the following information:
  - File Mode
  - File Name
  - File Hash
  - Parent Tree Object
- Everything is stored as key-value pairs in the tree object. The key is the file name and the value is the file hash.
- Blob Object is present in the tree object and contains the actual file content. This is the place where the file content is stored.

- The HEAD is a pointer to the current branch that you are working on

# Commands

- `git --version` : Give the version
- `git status` : command will show you the current state of your repository
- `git config --list`
- `git init` : init the git repos
- `git add` : add files to staging area
- `git commit` : add the check point
- `git restore--staged <file>` : to unstage
- `git commit -m <message>` : add the checkout point with message
- `git log` : very vast use man to know more
  - `git log --oneline` : simplify the logs
- `git branch` list all branch
- `git branch <branch_name>` to create the branch
- `git switch <branch_name>` to switch to branch_name
- `git switch -c <new_branch>` use to create branch
- `git branch -m <old-branch-name> <new-branch-name>` rename the branch
- `git branch -d <branch-name>` delete the branch

# Info Commands

- `git show -s --pretty=raw <commit-hash>`
- `git ls-tree <tree-id>`
- `git show <blob-id>`
- `git cat-file -p <commit-id>`
