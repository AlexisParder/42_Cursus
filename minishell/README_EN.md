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
- Use the `make` command to compile the program.
- Use the `./minishell` command to start program.
- Execute commands like in bash.

## Roadmap
- [x] Display a prompt when waiting for a new command.
- [x] Have a working history.
- [x] Search and launch the right executable (based on the PATH variable or using a
relative or an absolute path).
- [x] Use at most one global variable to indicate a received signal. Consider the
implications: this approach ensures that your signal handler will not access your
main data structures.
- [x] Not interpret unclosed quotes or special characters which are not required by the
subject such as `\` (backslash) or `;` (semicolon).
- [x] Handle `’` (single quote) which should prevent the shell from interpreting the meta-
characters in the quoted sequence.
- [x] Handle `"` (double quote) which should prevent the shell from interpreting the meta-
characters in the quoted sequence except for `$` (dollar sign).
- [x] Implement the following redirections:
	- `<` should redirect input.
	- `>` should redirect output.
	- `<<` should be given a delimiter, then read the input until a line containing the
delimiter is seen. However, it doesn’t have to update the history!
	- `>>` should redirect output in append mode.
- [x] Implement pipes (`|` character). The output of each command in the pipeline is
connected to the input of the next command via a pipe.
- [x] Handle environment variables (`$` followed by a sequence of characters) which
should expand to their values.
- [x] Handle `$?` which should expand to the exit status of the most recently executed
foreground pipeline.
- [x] Handle `ctrl-C`, `ctrl-D` and `ctrl-\` which should behave like in bash.
- [x] In interactive mode:
	- `ctrl-C` displays a new prompt on a new line.
	- `ctrl-D` exits the shell.
	- `ctrl-\` does nothing.
- [x] Your shell must implement the following built-in commands:
	- [x] echo with option `-n`
	- [x] cd with only a relative or absolute path
	- [x] pwd with no options
	- [x] export with no options
	- [x] unset with no options
	- [x] env with no options or arguments
	- [x] exit with no options

## Use of AI
Artificial intelligence was used as a support to understand and consolidate the key concepts of the project.

## Resources
- [Unix Processes in C](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
- [Pipes, Forks & Dups by Roslyn McConnell](https://www.rozmichelle.com/pipes-forks-dups/)
- Bash
- [libft](https://github.com/AlexisParder/42_Cursus/tree/main/libft)