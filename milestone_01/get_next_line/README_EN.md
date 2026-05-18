*This project has been created as part of the 42 curriculum by achauvie.*

# get_next_line
![42 Cursus](https://img.shields.io/badge/42-Cursus-blue?style=for-the-badge)
![Projects](https://img.shields.io/badge/Projects-Common_Core-success?style=for-the-badge)
[![Score](https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus/tree/main/get_next_line)<br>
[🇫🇷 French](./README.md)
- [get\_next\_line](#get_next_line)
	- [Description](#description)
	- [Example of usage](#example-of-usage)

## Description
A project focused on creating a function capable of reading any file, input stream, or stdin one line at a time.
The implementation must manage internal buffers, preserve unread data between calls, handle arbitrary BUFFER_SIZE values, and ensure full memory safety.
The optional bonus adds multi-file descriptor handling.
This project reinforces knowledge of file descriptors, dynamic memory, static variables, buffer logic, and robust edge-case management.

## Example of usage
```c
#include <get_next_line.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("path_of_file.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("%s", line); // You can replace by printf function.
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
```