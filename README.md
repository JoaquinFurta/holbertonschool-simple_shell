<h1 align="center">Simple Shell Project</h1>

This was a group project wich was about the implementation of a Simple Shell. In this project we learn how exactly the Shell works and all the commands and function wich were useful for the different tasks all along the project.


## Learning Objectives.
At the end of Simple Shell Project we should have a solid understanding of the following concepts:

* [X] Who designed and implemented the original Unix operating system.
* [X] Who wrote the first version of the UNIX shell
* [X] Who invented the B programming language (the direct predecessor to the C programming language)
* [X] Who is Ken Thompson
* [X] How does the shell work
* [X] What is a pid and a ppid
* [X] How to manipulate the environment of the current process
* [X] What is the difference between a function and a system call
* [X] How to create processes
* [X] What are the three prototypes of ```main```
* [X] How does the shell use the PATH to find the programs
* [X] How to execute another program with the ```execve``` system call
* [X] How to suspend the execution of a process until one of its children terminates
* [X] What is ```EOF```  / “end-of-file”?
                                         

## Resources 
[What is the shell ?](https://en.wikipedia.org/wiki/Unix_shell)

[What is the thompson shell ](https://en.wikipedia.org/wiki/Thompson_shell)

[Who is Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)

## Flowchart
(pending)


## List of allowed functions and system calls 
These are the  standard library functions wich were allowed to use in this project (used ones with an 'X'):

~~~c
access
chdir
close
closedir
[X]execve
[X]exit
_exit
fflush
[X]fork
[X]free
getcwd
[x]getline
getpid
[X]isatty
kill
[X]malloc
open
opendir
[X]perror
read
readdir
signal
[X]stat
lstat
fstat
[X]strtok
[X]wait
waitpid
wait3
wait4
write
~~~

## Functions implemented
~~~c
int gt(char **); - Function to get the command line and count the number of arguments
int Pfind(char **); - Function to find the PATH
int _strlen(char *); - Function to count the length of a string
int _strcmp(const char *, const char *); - Function to compare two strings
char *_strcat(char *, char *); - Function to concatenate two strings
char *_strcpy(char *, char *); - Function to copy a string
char *_strdup(char *); - Function to duplicate a string
char *_getenv(const char *); - Function to search for the enviroment string pointed by the passed argument
int die_free(char *, ...); - Function to free allocated memory
~~~


## Compilation
The shell should be compiled this way:

~~~bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o a.out
~~~

## Testing

In our programm we should see something like this: 


~~~
$ ./a.out
($) /bin/ls
a.out simp_shell.c func.c str_func.c shell.h
($)
($) exit
$
~~~

but also in non-interactive mode 

~~~

$ echo "/bin/ls" | ./a.out
a.out simp_shell.c func.c str_func.c shell.h test_shell
$
$ cat test_shell
/bin/ls
/bin/ls
$
$ cat test_shell | ./a.out
a.out simp_shell.c func.c str_func.c shell.h test_shell
a.out simp_shell.c func.c str_func.c shell.h test_shell
$
~~~

## Contributors
[Joaquin Furtado](https://github.com/JoaquinFurta)

[Gabriel Blasina](https://github.com/gabrielblasina)
