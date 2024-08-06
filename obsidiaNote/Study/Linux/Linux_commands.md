# which
`which ls` is used to locate the executable file of a given command, by searching the directories listed in the PATH 
# pwd
stands for print working directory for understand where you are
# ls command
ls means list storage, show files and directory inside, this command is there `/usr/bin/ls`, and in terminal by default is `ls --color=auto` for color the files of directories.
## ls -l
give us a long listing, add information like:
permission / user that own file / group of the user / length file / date creation / name:
`rw-r--r-- 1 juser users 3804 May 28 10:40 abusive.c`
### permissions
`d`for folders like `drwxr-xr-x` 
`-`for files  like `-rwxr-xr-x`
## ls -lh
`-h` is used for see the file size in human readable
## ls -a
allow to view hidden files 
## ls -F
it is used for understand if it is a directory because will put a `/`at the end
## ls -r
this option is used for reverse the order
## ls -t
is used for sort time by modification time from to the most recent to the last recent
## ls -C
is used for set the items inside in columns 
# echo
`echo` command is used for display text or variables on the terminal; for example:
`echo "Hello, world"
`>> Hello, word` 

We can also print variables:
`MY_VAR="hello, world"`
`echo $MY_VAR`
`>> hello, world`
## -e
this option is used for enables interpretation of backslash escapes. For example:
`echo -e "line1\nline2"`
`>> line1`
`>> line2`
## -n
this option is used for suppress the trailing new character. For example:
`echo -n "No newline here"`
`>> No newline here`
## display output command
we put the command date inside this string, using `$()`
`prtrp@fedora:~$ echo "the current date and time is: $(date)"`
`>> the current date and time is: Mon Jul 15 01:45:42 PM CEST 2024`
## create file with content
You can redirect the output of echo to create files with specific content.
`echo "This is a line of text" > file.txt`

## add content in file
Using the `>>` operator, you can append text to an existing file.
`echo "This is an additional line of text" >> file.txt`

# grep
prints the lines from a file or input stream that match an expression.
`cat /etc/ssh/sshd_config | grep Port`
it will give us all string that match wit Port. 
## -v
it means that will give us everything that don't match with the argument, for example:
`sudo cat /etc/ssh/sshd_config | grep -v Port`
`[|]`is used for pass the output of the precedent command as input to the next command.
## -n 
it add number to the rows, for show the line number where the word are founded 
`[prtrp@fedora ~]$ fc-list | grep -n "Symbols"`
`84:/usr/share/fonts/urw-base35/StandardSymbolsPS.otf: Standard Symbols PS:style=Regular`
## -c
show us the time that the option was found int the file 
`[prtrp@fedora ~]$ fc-list | grep -c "Symbols"
10`
## -i
not care about case sensitivity of the input, because grep is case sensitive by default
## -r
recursive search, also inside other directory 
`grep -r "a"`