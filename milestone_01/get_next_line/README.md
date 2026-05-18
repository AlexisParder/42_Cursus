*Ce projet a été créé dans le cadre du cursus 42 par achauvie.*

# get_next_line
![42 Cursus](https://img.shields.io/badge/42-Cursus-blue?style=for-the-badge)
![Projects](https://img.shields.io/badge/Projects-Common_Core-success?style=for-the-badge)
[![Score](https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge)](https://github.com/AlexisParder/42_Cursus/tree/main/get_next_line)<br>
[🇬🇧 English](./README_EN.md)
- [get\_next\_line](#get_next_line)
	- [Description](#description)
	- [Exemple d’utilisation](#exemple-dutilisation)

## Description
Un projet axé sur la création d’une fonction capable de lire n’importe quel fichier, flux d’entrée ou l’entrée standard (stdin) ligne par ligne.
L’implémentation doit gérer des buffers internes, conserver les données non lues entre les appels, prendre en charge des valeurs arbitraires de BUFFER_SIZE et garantir une sécurité mémoire totale.
Le bonus optionnel ajoute la gestion de plusieurs descripteurs de fichiers simultanément.
Ce projet renforce les connaissances sur les descripteurs de fichiers, la mémoire dynamique, les variables statiques, la logique de buffer et la gestion robuste des cas limites.

## Exemple d’utilisation
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
		ft_printf("%s", line); // Peut être remplacé par printf.
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
```