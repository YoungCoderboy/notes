# Introduction to Vim

## Vim modes

There are four types of vim mode

1. Command Mode
2. Command line mode
3. Insert Mode
4. Visual Mode

## Command Mode

- This is default mode of Vim, You can switch to other modes using this mode
- The commands that you run without any prefix indicate that you are running the command mode

## Insert Mode

- you can access this mode using `i` command mode
- to exit the command mode use `esc`

## Command line mode

- you can use this mode to play around with some commands
- Command in this mode is prefix to this column

## Visual Mode

- visually select some text and run commands over that section of code. You can switch to this mode by pressing `v` from the command mode.
- prefacing a movement command with a number will execute that movement multiple times. So, if you want to move up six lines, enter 6k and Vim will move the cursor up six lines. If you want to move over five words, enter 5w. To move 10 words back, use 10b.

## Commands

- `:edit sample.txt` use to create or edit file in vim
- `:w` to save the file in command line mode
- `:q` to close the file
- `:wq` to save and quit
- `:q!` to quit the vim without saving the changes
- `vim -R sample.txt` open file in read only mode
- `0` or `enter` move the cursor to beginning of file
- `$` moves cursor to end of line
- `w` moves cursor forward by one word `b` moves backward
- `G` moves to end of file and `gg` to the top of file
- `. move to the last edit.
- `I` insert mode in start of line
- `a` to append text after cursor
- `A` switch to insert mode and move cursor to end of line
- `o` switch to insert mode and move cursor to new line
- `O` switch to insert mode and move cursor above and create new line
- `s` switch to insert mode and delete the char (Substitute text)
- `S` switch to insert mode and delete entire line (Substitute text)
- `cc` switch to insert mode and delete entire line (Substitute text)
- `C` switch to insert mode and delete entire front of cursor (Substitute text)
- `p` to paste after cursor
- `P` to paste before cursor
- `R` to replace single char
- `:n` jump to nth line
- `w` jump to start of next word `N` for next occurrence and `n` for previous occurrence
- `e` jump to end of current word
- `b` jump to beginning of previous word
- `:swapname` Swap area is a file created by Vim to store buffer contents periodically. While editing file our changes may be lost because of any reasons and Vim provides swap files to provide data recovery
- `x` delete char from cursor pos
- `X` delete previous char from cursor pos
- `dw` delete word from cursor position a
- `D` delete entire line from cursor pos
- `dd` delete entire line
- `y` copy entire line
- `u` to undo changes
- `/` to search expression in forward direction
  - `n` for next occurrence and `N` for previous occurrence
  - `//` repeat previous forward search
- `?` to search expression n backward direction
  - `N` for next occurrence and `n` for previous occurrence
  - `??` repeat previous backward search
- `*` when on word shift cursor to next occurrence `#` to previous word

## How to Find and Replace Text in Vim

Finding text and replacing it with some other text is simple and straightforward in Vim. There's a one-line command that simplifies this entire process.

Here's the syntax:

`:[range]s/{pattern}/{string}/[flags]`

Let's dismantle each part and understand how it all works.

- [range] indicates that you can pass the range of lines. Pass % to find and replace in all lines. The range is separated by a comma. To find and replace between lines 5 to 10, pass 5,10. Use . to represent the current line and $ the last line of the file.
- {pattern} indicates the pattern to find the text. You can pass regex patterns here.
- {string} is the string to replace in the found text.
- [flags] indicates if you wish to pass any additional flags (for example, the flag c is passed to confirm before replacing the text). By default, this does a case-sensitive search. You can change it to do a case-insensitive search by passing a i flag.
