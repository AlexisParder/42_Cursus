*This project has been created as part of the 42 curriculum by achauvie.*

# pipex
[🇫🇷 French](./README.md)
- [pipex](#pipex)
	- [Description](#description)
	- [Instructions](#instructions)
	- [Bonus](#bonus)
	- [Use of AI](#use-of-ai)
	- [Resources](#resources)

## Description
A project aimed at reproducing the behavior of Unix pipelines by redirecting input/output streams between multiple commands. The program must correctly fork processes, set up pipes, manage file descriptors, and execute commands through PATH resolution, all while ensuring strict error handling and memory safety. The bonus involves handling multiple pipes and heredoc functionality. This project reinforces mastery of processes, system calls, I/O redirection, environment variables, and inter-process communication, while teaching how to orchestrate complex data flows at the system level.

## Instructions
- Use the `make` command to generate the program.
- Use the `./pipex file1 cmd1 cmd2 file2` command to start program.
	- **file1** and **file2** are file names.
	- **cmd1** and **cmd2** are shell commands with their parameters.
	- **Exemple:** ``./pipex infile "ls -l" "wc -l" outfile``

## Bonus

## Use of AI

## Resources
- [libft](https://github.com/AlexisParder/42_Cursus/tree/main/libft)