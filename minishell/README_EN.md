*This project has been created as part of the 42 curriculum by achauvie and tjourdai.*

# minishell
![42 Cursus](https://img.shields.io/badge/42-Cursus-blue?style=for-the-badge)
![Projects](https://img.shields.io/badge/Projects-Common_Core-success?style=for-the-badge)
<!-- [![Score](https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus/tree/main/minishell)<br> -->
[🇫🇷 French](./README.md)
- [minishell](#minishell)
	- [Description](#description)
	- [Instructions](#instructions)
	- [Roadmap](#roadmap)
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

## Roadmap
- [ ] Display a prompt when waiting for a new command.
- [ ] Have a working history.
- [ ] Search and launch the right executable (based on the PATH variable or using a
relative or an absolute path).
- [ ] Use at most one global variable to indicate a received signal. Consider the
implications: this approach ensures that your signal handler will not access your
main data structures.
- [ ] Not interpret unclosed quotes or special characters which are not required by the
subject such as `\` (backslash) or `;` (semicolon).
- [ ] Handle `’` (single quote) which should prevent the shell from interpreting the meta-
characters in the quoted sequence.
- [ ] Handle `"` (double quote) which should prevent the shell from interpreting the meta-
characters in the quoted sequence except for `$` (dollar sign).
- [ ] Implement the following redirections:
	- `<` should redirect input.
	- `>` should redirect output.
	- `<<` should be given a delimiter, then read the input until a line containing the
delimiter is seen. However, it doesn’t have to update the history!
	- `>>` should redirect output in append mode.
- [ ] Implement pipes (`|` character). The output of each command in the pipeline is
connected to the input of the next command via a pipe.
- [ ] Handle environment variables (`$` followed by a sequence of characters) which
should expand to their values.
- [ ] Handle `$?` which should expand to the exit status of the most recently executed
foreground pipeline.
- [ ] Handle `ctrl-C`, `ctrl-D` and `ctrl-\` which should behave like in bash.
- [ ] In interactive mode:
	- `ctrl-C` displays a new prompt on a new line.
	- `ctrl-D` exits the shell.
	- `ctrl-\` does nothing.
- [ ] Your shell must implement the following built-in commands:
	- echo with option `-n`
	- cd with only a relative or absolute path
	- pwd with no options
	- export with no options
	- unset with no options
	- env with no options or arguments
	- exit with no options

## Use of AI
<!-- Artificial intelligence was used as a support to understand and consolidate the key concepts of the project, notably forks, pipes, and other system mechanisms. -->

## Resources
<!-- - [Unix Processes in C](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
- [Pipes, Forks & Dups by Roslyn McConnell](https://www.rozmichelle.com/pipes-forks-dups/) -->
- [libft](https://github.com/AlexisParder/42_Cursus/tree/main/libft)