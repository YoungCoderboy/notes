# Linux Commands

## System Information

- `whoami` : Display current username
- `id` : Return User identity
- `hostname` : Sets or print name of current host
- `uname` : print basic information about system name and hardware
- `pwd` : present working dir
- `ifconfig` : utility tool for networking
- `ip` : ip is utility to show or manipulate the routing , network devices , interface and tunnels
- `netstat` : show network status
- `ss` : utility to investigate sockets
- `ps` : show process status
- `who` : display who is login
- `env` : Prints environment variables
- `lsblk` : list block devices
- `lsusb` : list usb devices
- `lsof` : list opened files
- `lspci` : list pci devices

# Working with file directory

- `touch <name>` to create new file
- `mkdir <name>` to create new folder
- `mkdir -p /path/to/dir` this will create the nested dir
- `tree .` to see whole structure
- `touch ./apple/ball.txt` to create the file inside the folder
- `mv <file/directory> <renamed file/directory>` use to move and rename the file and dir
  - `mv information.txt readme.txt Storage/` move information and readme to storage folder
- `cp <file/directory> <renamed file/directory>` use to copy file and folder

# Find Files and Directories

- `which python` This allows us to determine if specific programs, like `cURL, netcat, wget, python, gcc,` are available on the operating system.
- `find <location> <options>` use to locate the file and folder

## Option for find command

<table class="table table-striped text-left">
<thead>
<tr>
<th><strong>Option</strong></th>
<th><strong>Description</strong></th>
</tr>
</thead>
<tbody>
<tr>
<td><code>-type f</code></td>
<td>Hereby, we define the type of the searched object. In this case, '<code>f</code>' stands for '<code>file</code>'.</td>
</tr>
<tr>
<td><code>-name *.conf</code></td>
<td>With '<code>-name</code>', we indicate the name of the file we are looking for. The asterisk (<code>*</code>) stands for 'all' files with the '<code>.conf</code>' extension.</td>
</tr>
<tr>
<td><code>-user root</code></td>
<td>This option filters all files whose owner is the root user.</td>
</tr>
<tr>
<td><code>-size +20k</code></td>
<td>We can then filter all the located files and specify that we only want to see the files that are larger than 20 KiB.</td>
</tr>
<tr>
<td><code>-newermt 2020-03-03</code></td>
<td>With this option, we set the date. Only files newer than the specified date will be presented.</td>
</tr>
<tr>
<td><code>-exec ls -al {} \;</code></td>
<td>This option executes the specified command, using the curly brackets as placeholders for each result. The backslash escapes the next character from being interpreted by the shell because otherwise, the semicolon would terminate the command and not reach the redirection.</td>
</tr>
<tr>
<td><code>2&gt;/dev/null</code></td>
<td>This is a <code>STDERR</code> redirection to the '<code>null device</code>', which we will come back to in the next section. This redirection ensures that no errors are displayed in the terminal. This redirection must <code>not</code> be an option of the 'find' command.</td>
</tr>
</tbody>
</table>

## locate command

- `locate` is faster command than `find` since it uses the local db to search
- `sudo updatedb` to update the dir database
- `>` to forward output
- `2>` to forward `STDERR`
- `1>` to forward `STDOUT`
- `<` to give input to something
- `>>` is use to append result since `>` will override the results
- `cat << EOF > stream.txt` we will use the cat command to read our streaming input through the stream and direct it to a file called "stream.txt."
- Another way to redirect STDOUT is to use pipes `(|)`.
- These are useful when we want to use the STDOUT from one program to be processed by another. One of the most commonly used tools is grep
- `find /etc/ -name *.conf 2>/dev/null | grep systemd`
- The redirections work, not only once. We can use the obtained results to redirect them to another program. For the next example, we will use the tool called wc, which should count the total number of obtained results.
- `head /etc/password`
- `tail /etc/password`
- `tail -f /etc/log`
- `cat /etc/passwd | grep "/bin/bash"` use -v flag in grep for excluding the result
- `cat /etc/passwd | sort` sort the output
- `cat /etc/passwd | grep -v "false\|nologin" | cut -d":" -f1`
  - Specific results with different characters may be separated as delimiters. Here it is handy to know how to remove specific delimiters and show the words on a line in a specified position. One of the tools that can be used for this is cut. Therefore we use the option "-d" and set the delimiter to the colon character (:) and define with the option "-f" the position in the line we want to output.
- `cat /etc/passwd | grep -v "false\|nologin" | tr ":" " "`
  - Another possibility to replace certain characters from a line with characters defined by us is the tool tr. As the first option, we define which character we want to replace, and as a second option, we define the character we want to replace it with. In the next example, we replace the colon character with space.
- `cat /etc/passwd | grep -v "false\|nologin" | tr ":" " " | column -t`
  - Since search results can often have an unclear representation, the tool column is well suited to display such results in tabular form using the "-t
- `cat /etc/passwd | grep -v "false\|nologin" | tr ":" " " | awk '{print $1, $NF}'`
  - As we may have noticed, the line for the user "postgres" has one column too many. To keep it as simple as possible to sort out such results, the (g)awk programming is beneficial, which allows us to display the first ($1) and last ($NF) result of the line.
- `cat /etc/passwd | grep -v "false\|nologin" | tr ":" " " | awk '{print $1, $NF}' | sed 's/bin/HTB/g'`

  - There will come moments when we want to change specific names in the whole file or standard input. One of the tools we can use for this is the stream editor called sed. One of the most common uses of this is substituting text. Here, sed looks for patterns we have defined in the form of regular expressions (regex) and replaces them with another pattern that we have also defined. Let us stick to the last results and say we want to replace the word "bin" with "HTB."

  - The "s" flag at the beginning stands for the substitute command. Then we specify the pattern we want to replace. After the slash (/), we enter the pattern we want to use as a replacement in the third position. Finally, we use the "g" flag, which stands for replacing all matches.

- `grep -e "pattern"` -e flag is use for pattern

# Permission Management
