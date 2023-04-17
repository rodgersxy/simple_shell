# simple_shell

Rodgers and Keith Collabration on buliding a simple shell using C programming language.
1. flowchart
<<<<<<< HEAD

<<<<<<< HEAD
2. Compilation
This shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
3. Testing
Your shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main_shell.c buffer.c  etc
($)
($) exit
$
4. Simple Shell should:
a. 
(i). Display a prompt and wait for the user to type a command. A command line always ends with a new line.
(ii). The prompt is displayed again each time a command has been executed.
(iii). The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
(iv). The command lines are made only of one word. No arguments will be passed to programs.
(v). If an executable cannot be found, print an error message and display the prompt again.
(v) Handle errors.
(vi) You have to handle the “end of file” condition (Ctrl+D)
b. 
Simple shell 0.1 +

Handle command lines with arguments
c.
Simple shell 0.2 +

Handle the PATH
fork must not be called if the command doesn’t exist
d. 
Simple shell 0.3 +

Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit
e. 
Simple shell 0.4 +

Implement the env built-in, that prints the current environment
5. Simple Shell Process Flow
a. when the user runs the shell program, the main function main_shell.c is executed
b. the function initializes the variables and the start of infinite loop that will read the user's input
c. For each iterarion, the prompt() will be called and displayed for the user to put the command
d. the command will be stored in temporary location
e. the command is then parsed to individual token
f. the first command is checked to deterrmine the type of command eg cd, exit or other the function exits if it is called to do that
g. If it is neither of that, the function is called to create a child process and execute the command
h. The parent process(shell) wait for the child process to end usinf wait() system call
i. the loop continue untill the progrm ends

6. General

Allowed editors: vi, vim, emacs

 Authors:
           Rodgers Mogaka and Keith Koki ALX Students
=======

[FLOWCHART.odt](https://github.com/rodgersxy/simple_shell/files/11248414/FLOWCHART.odt)
>>>>>>> 6ba46f4dd47cb3b67d729a559d70e7b07a420146
=======
>>>>>>> 8e7d4cdc1ff36ce74705054622b7cc89c988fac4
