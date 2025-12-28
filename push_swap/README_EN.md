*This project has been created as part of the 42 curriculum by achauvie.*

# push_swap
[🇫🇷 French](./README.md)
- [push\_swap](#push_swap)
	- [Description](#description)
	- [Allowed Operations](#allowed-operations)
	- [Instructions](#instructions)
	- [Resources](#resources)

## Description
A highly algorithmic project where the goal is to sort a list of integers using two stacks and a restricted set of operations.
The challenge is to design and implement an optimized sorting strategy that produces the fewest possible instructions, especially for large datasets (100–500 elements).
Common approaches include small-dataset sorting, chunk-based strategies, and radix sort.
This project develops algorithmic thinking, time/operation optimization, data structure manipulation, and implementation of complex logic under strict constraints.

## Allowed Operations
The list below shows all the operations permitted to sort the numbers in the `push_swap` project.
You must use only these operations to manipulate the stacks and achieve a sorted list.
- **sa (swap a)**
	- Swap the first 2 elements at the top of stack a.
	- Do nothing if there is only one element or none.
- **sb (swap b)**
	- Swap the first 2 elements at the top of stack b.
	- Do nothing if there is only one element or none.
- **ss**
	- sa and sb at the same time.
- **pa (push a)**
	- Take the first element at the top of b and put it at the top of a.
	- Do nothing if b is empty.
- **pb (push b)**
	- Take the first element at the top of a and put it at the top of b.
	- Do nothing if a is empty.
- **ra (rotate a)**
	- Shift up all elements of stack a by 1.
	- The first element becomes the last one.
- **rb (rotate b)**
	- Shift up all elements of stack b by 1.
	- The first element becomes the last one.
- **rr**
	- ra and rb at the same time.
- **rra (reverse rotate a)**
	- Shift down all elements of stack a by 1.
	- The last element becomes the first one.
- **rrb (reverse rotate b)**
	- Shift down all elements of stack b by 1.
	- The last element becomes the first one.
- **rrr**
	- rra and rrb at the same time.

## Instructions
- Use the `make` command to generate the program.
- Use the `./push_swap <list of unordered numbers>` command to sort the list.
	- ⚠️ The program does not return the sorted list. It only displays the instructions it uses to sort the list.
	- Using the command `./push_swap <list of unordered numbers> | wc -l` shows the number of instructions used to sort the list.

## Resources
- [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [libft](https://github.com/AlexisParder/42_Cursus/tree/main/libft)