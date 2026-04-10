# 42 Cursus
[![Repo size](https://img.shields.io/github/repo-size/AlexisParder/42_Cursus?style=for-the-badge&logo=github)](https://github.com/AlexisParder/42_Cursus)
[![Languages count](https://img.shields.io/github/languages/count/AlexisParder/42_Cursus?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus)
[![Top language](https://img.shields.io/github/languages/top/AlexisParder/42_Cursus?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus)
[![Last commit](https://img.shields.io/github/last-commit/AlexisParder/42_Cursus?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus)<br>
[🇫🇷 French](./README.md)<br>
- [42 Cursus](#42-cursus)
	- [libf](#libf)
	- [ft\_print](#ft_print)
	- [get\_next\_line](#get_next_line)
	- [born2beroot](#born2beroot)
	- [push\_swap](#push_swap)
	- [so\_long](#so_long)
	- [pipex](#pipex)
	- [philosophers](#philosophers)
	- [minishell](#minishell)
	- [cub3d](#cub3d)

## libf
A foundational project from the 42 curriculum.
Libft consists of recreating a custom version of the standard C library by implementing a wide set of essential functions for memory manipulation, string handling, character checks, and linked list operations.
This library becomes a core dependency for all subsequent projects (get_next_line, ft_printf, push_swap, minishell, etc.) and establishes strong fundamentals in low-level programming, memory management, and clean code structure.

[Go to libft](https://github.com/AlexisParder/42_Cursus/tree/main/libft)

## ft_print
A full reimplementation of the iconic printf function in C.
The project aims to handle formatted output by parsing format strings and supporting variadic arguments using stdarg.h.
It covers all mandatory conversions (c, s, p, d, i, u, x, X, %) and focuses on building a modular, well-structured, and efficient formatting engine.
This project strengthens skills in parsing logic, base conversions, buffer management, and function architecture.

[Go to ft_printf](https://github.com/AlexisParder/42_Cursus/tree/main/ft_printf)

## get_next_line
A project focused on creating a function capable of reading any file, input stream, or stdin one line at a time.
The implementation must manage internal buffers, preserve unread data between calls, handle arbitrary BUFFER_SIZE values, and ensure full memory safety.
The optional bonus adds multi-file descriptor handling.
This project reinforces knowledge of file descriptors, dynamic memory, static variables, buffer logic, and robust edge-case management.

[Go to get_next_line](https://github.com/AlexisParder/42_Cursus/tree/main/get_next_line)

## born2beroot
A system-administration project centered around installing and configuring a secure Linux virtual machine from scratch. The goal is to enforce strict security and compliance rules, including user/group management, minimum password policies, a hardened SSH setup, and a custom firewall configuration. The project also requires monitoring system resources through a custom script and documenting the entire setup using rigorous guidelines. This project strengthens understanding of Linux fundamentals, privilege management, security hardening, virtualization, and reproducible system configuration.

[Go to born2beroot](https://github.com/AlexisParder/42_Cursus/tree/main/born2beroot)

## push_swap
A highly algorithmic project where the goal is to sort a list of integers using two stacks and a restricted set of operations.
The challenge is to design and implement an optimized sorting strategy that produces the fewest possible instructions, especially for large datasets (100–500 elements).
Common approaches include small-dataset sorting, chunk-based strategies, and radix sort.
This project develops algorithmic thinking, time/operation optimization, data structure manipulation, and implementation of complex logic under strict constraints.

[Go to push_swap](https://github.com/AlexisParder/42_Cursus/tree/main/push_swap)

## so_long
A graphical project focused on building a small 2D game using the MiniLibX library. The objective is to implement map parsing, collision logic, sprite rendering, and event handling, while respecting a strict set of rules regarding map validity, movement constraints, and asset management. The challenge increases with the need to create smooth player interactions, handle animation cycles, and ensure proper resource cleanup. This project develops skills in low-level graphics, event-driven programming, input handling, file parsing, and memory/resource management within a constrained C environment.

[Go to so_long](https://github.com/AlexisParder/42_Cursus/tree/main/so_long)

## pipex
A project aimed at reproducing the behavior of Unix pipelines by redirecting input/output streams between multiple commands. The program must correctly fork processes, set up pipes, manage file descriptors, and execute commands through PATH resolution, all while ensuring strict error handling and memory safety. The bonus involves handling multiple pipes and heredoc functionality. This project reinforces mastery of processes, system calls, I/O redirection, environment variables, and inter-process communication, while teaching how to orchestrate complex data flows at the system level.

[Go to pipex](https://github.com/AlexisParder/42_Cursus/tree/main/pipex)

## philosophers
A concurrency-focused project based on the classic Dining Philosophers problem. The objective is to simulate multiple philosophers sharing limited resources while avoiding deadlocks, starvation, and race conditions. The implementation relies on threads (or processes), mutexes, precise time management, and synchronized access to shared data. The project demands rigorous control over timing constraints, clean thread lifecycle management, and accurate state logging. This project develops a deep understanding of multithreading, synchronization primitives, concurrent programming pitfalls, and performance-sensitive logic under strict real-time constraints.

[Go to philosophers](https://github.com/AlexisParder/42_Cursus/tree/main/philosophers)

## minishell
A comprehensive systems programming project that consists of recreating a simplified Unix shell from scratch. The program must parse and execute user commands, manage environment variables, handle built-in commands, support pipes and redirections, and correctly propagate exit statuses. The challenge lies in accurately tokenizing input, managing process creation, handling signals (Ctrl-C, Ctrl-D, Ctrl-\\), and reproducing Bash-like behavior within defined limits. This project builds strong expertise in process control, parsing logic, file descriptor management, signal handling, and robust error recovery in a low-level C environment.

[Go to minishell](https://github.com/AlexisParder/42_Cursus/tree/main/minishell)

## cub3d
A graphics programming project inspired by early raycasting engines like Wolfenstein 3D. The objective is to build a pseudo-3D renderer using a 2D map and raycasting techniques to simulate a first-person perspective. The implementation involves parsing map files, handling player movement and camera rotation, performing real-time ray calculations, and rendering textured walls with correct depth and perspective.

Additional challenges include managing sprites, collision detection, and optimizing performance for smooth rendering. This project develops strong skills in computer graphics fundamentals, trigonometry, real-time rendering, low-level optimization, and structured game engine design within a constrained C environment.

[Go to cub3d](https://github.com/AlexisParder/42_Cursus/tree/main/cub3d)