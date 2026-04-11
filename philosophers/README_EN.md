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
	- [Use of AI](#use-of-ai)
	- [Resources](#resources)

## Description
A concurrency-focused project based on the classic Dining Philosophers problem. The objective is to simulate multiple philosophers sharing limited resources while avoiding deadlocks, starvation, and race conditions. The implementation relies on threads (or processes), mutexes, precise time management, and synchronized access to shared data. The project demands rigorous control over timing constraints, clean thread lifecycle management, and accurate state logging. This project develops a deep understanding of multithreading, synchronization primitives, concurrent programming pitfalls, and performance-sensitive logic under strict real-time constraints.

## Instructions
### Mandatory
- Go to the `philo` folder to compile the basic program.
- Use the `make` command to compile the program.
- Use the `./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> <number_of_times_each_philosopher_must_eat>` command to run the program.
	- The times are in milliseconds (ms).
	- The last parameter is optional.

## Use of AI
Artificial intelligence was used as a support to understand and organize the key concepts of the project, notably by creating a list of exercises in order to learn how to use threads and mutexes.
- [View the exercises](https://github.com/AlexisParder/42_Cursus/tree/main/philosophers/thread_exercices/README_EN.md)

## Resources
- [Tester 1](https://github.com/dantonik/42-philosophers-tester)
- [Tester 2](https://github.com/Acholias/Philosophers_tester)
- [(🇫🇷 French) C language #17 (threads)](https://youtu.be/o_GbRujGCnM?list=PLdDeXINE1ViRkmBtqLmC_fu-tIJUl4-Sd)