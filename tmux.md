# Introduction

Tmux is terminal multiplexer

- `tmux` will create the instant session
- `ctrl + b` + `d` detach from the session
- `tmux a` will reattach to most recent session
- `tmux new -s session_name` create the new session with custom name
- `tmux ls` list tmux session
- `tmux a -t index/name` t is for target, this will attach to specific session
- `tmux kill-session -t index/name` to kill specific session
- `ctrl + b` + `%` will split horizontally
- `ctrl + b` + `"` will split vertically
- `ctrl + b` + `q` way to travel between panel
- `ctrl + b` + `ctrl.. + arrow` to change the size
- `ctrl + b` + `alt [1-5]` will have preset template
- `ctrl + b` + `c` will create the new window
- `ctrl + b` + `n` sequentially move between windows
- `ctrl + b` + `,` will use to change the name
- `ctrl + b` + `w` use for navigation
- `ctrl + b` + `x` will kill panel
- `ctrl + b` + `&` will kill the window
- `ctrl + b` + `[` will enter in copy mode and space to copy
- `ctrl + b` + `]` will paste
  tmux have 3 layers

1. session

tmux new -s "session_name"
tmux ls
tmux a -t "index_to_session"
tmux kill-session -t "session_name"

2. Window
   tmux new -t "session_name"
   above command will create the session of session_name with 0 index bash window

3. Panes

split screen horizontal: ctrl + b shift + 5 ie %
split screen vertically: ctrl + b shift + ' ie "

ctrl + b is our prefix key
ctrl + b q to show index to switch window
ctrl + b arrow key to move
ctrl + b q "idx" for switching
ctrl + b and hit ctrl and use arrow to change the size of window use alt plus arrow for doing same thing in bigger steps
ctrl + b alt 1 to 5 have preset layouts
ctrl + b c to create new window
ctrl + b n to change between windows
ctrl + b , to change window name
ctrl + b w to navigate
in window we get after 'w' use x to delete
ctrl + b & to kill entire window
tmux kill-server
ctrl + b { to move to copy mode then move the arrow to place we want to start copy and use space to start
ctrl + b } to exit copy mode and paste the selected

# Commands

- ctrl + b followed by `d` to detach the session
- ctrl + b followed by `a` to attached the session
