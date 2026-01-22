*This project has been created as part of the 42 curriculum by achauvie and tjourdai.*

# minishell
![42 Cursus](https://img.shields.io/badge/42-Cursus-blue?style=for-the-badge)
![Projects](https://img.shields.io/badge/Projects-Common_Core-success?style=for-the-badge)
<!-- [![Score](https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus/tree/main/minishell)<br> -->
[🇫🇷 French](./README.md)
- [minishell](#minishell)
	- [Description](#description)
	- [Instructions](#instructions)
	- [Bonus](#bonus)
	- [Use of AI](#use-of-ai)
	- [Resources](#resources)

## Description
A comprehensive systems programming project that consists of recreating a simplified Unix shell from scratch. The program must parse and execute user commands, manage environment variables, handle built-in commands, support pipes and redirections, and correctly propagate exit statuses. The challenge lies in accurately tokenizing input, managing process creation, handling signals (Ctrl-C, Ctrl-D, Ctrl-\\), and reproducing Bash-like behavior within defined limits. This project builds strong expertise in process control, parsing logic, file descriptor management, signal handling, and robust error recovery in a low-level C environment.

## Instructions
<!-- - Use the `make` command to compile the program.
	- Use the `make bonus` command to compile the program with bonus.
- Use the `./pipex file1 cmd1 cmd2 file2` command to start program.
	- **file1** and **file2** are file names.
	- **cmd1** and **cmd2** are shell commands with their parameters.
	- **Exemple:** `./pipex infile "ls -l" "wc -l" outfile`
    	- The equivalent in **bash** would be `< infile ls -l | wc -l > outfile` -->

## Bonus
<!-- - [x] Handle multiple pipes.
	- `./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2`
	- The equivalent in **bash** would be `< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`
- [ ] Support « and » when the first parameter is "here_doc".
	- `./pipex here_doc LIMITER cmd cmd1 file`
	- The equivalent in **bash** would be `cmd << LIMITER | cmd1 >> file` -->

## Use of AI
<!-- Artificial intelligence was used as a support to understand and consolidate the key concepts of the project, notably forks, pipes, and other system mechanisms. -->

## Resources
<!-- - [Unix Processes in C](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
- [Pipes, Forks & Dups by Roslyn McConnell](https://www.rozmichelle.com/pipes-forks-dups/) -->
- [libft](https://github.com/AlexisParder/42_Cursus/tree/main/libft)