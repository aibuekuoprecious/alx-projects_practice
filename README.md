Now we know;
-Who designed and implemented the original Unix operating system
-Who wrote the first version of the UNIX shell
-Who invented the B programming language (the direct predecessor to the C programming language)
-Who is Ken Thompson
-How does a shell work
-What is a pid and a ppid
-How to manipulate the environment of the current process
-What is the difference between a function and a system call
-How to create processes
-What are the three prototypes of main
-How does the shell use the PATH to find the programs
-How to execute another program with the execve system call
-How to suspend the execution of a process until one of its children terminates
-What is EOF / “end-of-file”?


Here is a list of the files and their contents:
-main.c: contains the main function that displays the prompt and reads and executes the user input
-read_line.c: contains the  read_line function which returns a pointer to the line, or NULL on error or EOF
-split_line.c: contains the split_line function that splits a line into tokens
-execute.c: contains the execute function that executes a program with arguments
-find_path.c: contains the find_path function that finds the full path of a program
-launch.c: contains the launch function that launches a program with arguments
-builtin.c: contains the is_builtin and run_builtin functions;
-The is_builtin function that checks if a command is a built-in
-The run_builtin function that runs a built-in command
-cd_builtin.c: contains the cd_builtin function that changes the current directory
-exit_builtin.c: contains the exit_builtin function that exits the shell
-env_builtin.c: contains the env_builtin function that prints the environment variables
-setenv_builtin.c: contains the setenv_builtin function that sets or modifies an environment variable
-unsetenv_builtin.c: contains the unsetenv_builtin function that removes an environment variable
-get_line.c: contains the get_line function that reads a line from a file descriptor
