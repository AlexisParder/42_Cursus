*This project has been created as part of the 42 curriculum by achauvie.*

# philosophers
[🇫🇷 French](./README.md)
- [philosophers](#philosophers)
	- [Description](#description)
	- [Instructions](#instructions)
	- [Bonus](#bonus)
	- [Use of AI](#use-of-ai)
	- [Resources](#resources)

## Description
A concurrency-focused project based on the classic Dining Philosophers problem. The objective is to simulate multiple philosophers sharing limited resources while avoiding deadlocks, starvation, and race conditions. The implementation relies on threads (or processes), mutexes, precise time management, and synchronized access to shared data. The project demands rigorous control over timing constraints, clean thread lifecycle management, and accurate state logging. This project develops a deep understanding of multithreading, synchronization primitives, concurrent programming pitfalls, and performance-sensitive logic under strict real-time constraints.

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