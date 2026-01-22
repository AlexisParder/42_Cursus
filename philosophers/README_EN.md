*This project has been created as part of the 42 curriculum by achauvie.*

# philosophers
![42 Cursus](https://img.shields.io/badge/42-Cursus-blue?style=for-the-badge)
![Projects](https://img.shields.io/badge/Projects-Common_Core-success?style=for-the-badge)
<!-- [![Score](https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus/tree/main/philosophers)<br> -->
[🇫🇷 French](./README.md)
- [philosophers](#philosophers)
	- [Description](#description)
	- [Instructions](#instructions)
		- [Mandatory](#mandatory)
		- [Bonus](#bonus)
	- [Bonus](#bonus-1)
	- [Use of AI](#use-of-ai)
	- [Resources](#resources)

## Description
A concurrency-focused project based on the classic Dining Philosophers problem. The objective is to simulate multiple philosophers sharing limited resources while avoiding deadlocks, starvation, and race conditions. The implementation relies on threads (or processes), mutexes, precise time management, and synchronized access to shared data. The project demands rigorous control over timing constraints, clean thread lifecycle management, and accurate state logging. This project develops a deep understanding of multithreading, synchronization primitives, concurrent programming pitfalls, and performance-sensitive logic under strict real-time constraints.

## Instructions
### Mandatory
- Go to the `philo` folder to compile the basic program.
- Use the `make` command to compile the program.
<!-- - Use the `./philo ...` command to run the program. -->
### Bonus
- Go to the `philo_bonus` folder to compile the program with the bonus features.
- Use the `make bonus` command to compile the program with the bonus features

## Bonus
- [ ] All the forks are put in the middle of the table.
- [ ] They have no states in memory, but the number of available forks is represented by a semaphore.
- [ ] Each philosopher must be represented as a separate process. However, the main process should not act as a philosopher.

## Use of AI
<!-- Artificial intelligence was used as a support to understand and consolidate the key concepts of the project, notably forks, pipes, and other system mechanisms. -->

## Resources
<!-- - [Unix Processes in C](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
- [Pipes, Forks & Dups by Roslyn McConnell](https://www.rozmichelle.com/pipes-forks-dups/) -->