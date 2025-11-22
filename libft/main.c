// ft_atoi
#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	if (ac == 2)
		printf("ft_atoi: %d\natoi: %d\n", ft_atoi(av[1]), atoi(av[1]));
	return (0);
}

// ft_itoa
#include <stdio.h>
int	main(void)
{
	int n = -123;
	printf("ft_itoa: %s\n", ft_itoa(n));
	return (0);
}

// ft_bzero
#include <stdio.h>
#include <strings.h>
int	main(void)
{
	size_t	n = 5;
	size_t	i = 0;
	void	*s = malloc(n);
	void	*s2 = malloc(n);
	
	ft_bzero(s, n);
	bzero(s2, n);
	printf("ft_bzero - bzero\n");	
	while (i < n)
	{
		printf("%d - %d\n", ((char *)s)[i], ((char *)s2)[i]);	
		i++;
	}
	free(s);
	free(s2);
	return (0);
}

// ft_calloc
#include <stdio.h>          
int main() {

    int i = 0;
    int *pointer = calloc(10, sizeof(int));
    int *ft_pointer = ft_calloc(10, sizeof(int));

    if (!pointer || !ft_pointer)
		return (1);
	i = 0;
	while (i < 10)
	{
		printf("%d - %d\n", pointer[i], ft_pointer[i]);
		i++;
	}
	free(pointer);
	free(ft_pointer);

    return 0;
}

// ft_strncmp
#include <stdio.h> 
#include <string.h> 
int main(void)
{
	const char *s1 = "Phrase 1";
	const char *s2 = "Phrase 2";
	size_t		n = 12;

	printf("ft_strncmp: %d\nstrncmp: %d\n", ft_strncmp(s1, s2, n), strncmp(s1, s2, n));
	return (0);
}

// ft_strnstr
#include <stdio.h> 
#include <bsd/string.h> 
int main(void)
{
	const char *big = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam elementum elit rutrum porta rutrum.";
	const char *little = "adi";
	size_t		n = 44;

	printf("ft_strnstr: %s\nstrnstr: %s\n", ft_strnstr(big, little, n), strnstr(big, little, n));
	return (0);
}

// putchar_fd
int	main(void)
{
	int	fd;

	fd = open("ft_putchar_fd.txt", O_WRONLY | O_CREAT, 0777);	
	if (fd <= -1)
		return (1);
	ft_putchar_fd('z', fd);
	close(fd);
}

// putendl_fd
int	main(void)
{
	int	fd;

	fd = open("ft_putendl_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);	
	if (fd <= -1)
		return (1);
	ft_putendl_fd("CECI EST UNE PHRASE !", fd);
	close(fd);
}

// putnbr_fd
int	main(void)
{
	int	fd;

	fd = open("ft_putnbr_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);	
	if (fd <= -1)
		return (1);
	ft_putnbr_fd(-2147483648, fd);
	close(fd);
}

// putstr_fd
int	main(void)
{
	int	fd;

	fd = open("ft_putstr_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);	
	if (fd <= -1)
		return (1);
	ft_putstr_fd("CECI EST UNE PHRASE !", fd);
	close(fd);
}

// split
#include <stdio.h>
int	main(void)
{
	int	i = 0;
	char **res = ft_split(NULL, 'e');

	while (res[i] != NULL)
	{
		printf("%s\n", res[i]);
		free(res[i]);
		i++;
	}
	printf("%s\n", res[i]);
	free(res);
	return (0);
}

// strdup
#include <stdio.h>
#include <string.h>
int	main(int ac, char **av)
{
	{
		if (ac == 2)
		{
			char *src_cpy = ft_strdup(av[1]);
			printf("ft_strdup: %s\n", src_cpy);
			free(src_cpy);
		}
	}
	{
		if (ac == 2)
		{
			char *src_cpy = strdup(av[1]);
			printf("strdup: %s\n", src_cpy);
			free(src_cpy);
		}
	}
}

// striteri
void	inv_low_upp(unsigned int i, char *s)
{
	if (ft_isalpha(s[i]))
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = ft_toupper(s[i]);
		else
			s[i] = ft_tolower(s[i]);
	}
}
#include <stdio.h>
int main(void)
{
	char	str[] = "Ceci Est Une Phrase !";

	printf("%s\n", str);
	ft_striteri(str, inv_low_upp);
	printf("%s", str);
	return (0);
}

// strjoin
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		char	*new = ft_strjoin(av[1], av[2]);
		printf("ft_strjoin: %s", new);
		free (new);
	}
	return (0);
}

// strmapi
char	chr_add_i(unsigned int i, char c)
{
	c += i;
	return (c);
}
#include <stdio.h>
int main(void)
{
	char	*str = "Ceci est une phrase !";
	char 	*new_str = ft_strmapi(str, chr_add_i);

	printf("%s\n%s", str, new_str);
	free(new_str);
	return (0);
}

// strtrim
#include <stdio.h>
int main(void)
{
	char *str = ft_strtrim("--------Ceci est une phrase--------", "-");
	printf("ft_strtrim: %s\n", str);
	free (str);
}

// substr
#include <stdio.h>
int main(void)
{
	char *subs = ft_substr("Ceci est une phrase", 4, 5);
	printf("ft_substr: %s\n", subs);
	free (subs);
}

// ft_strchr
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char *s = "Lorem officia labore reprehenderit exercitation aute Lorem non occaecat ad sit eu.";
	int	c = 'a';
	
	printf("ft_strchr: %s\nstrchr: %s\n", ft_strchr(s, c), strchr(s, c));
	return (0);
}

// ft_strrchr
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char *s = "Lorem officia labore reprehenderit exercitation aute Lorem non occaecat ad sit eu.";
	int	c = 'a';
	
	printf("ft_strrchr: %s\nstrrchr: %s\n", ft_strrchr(s, c), strrchr(s, c));
	return (0);
}

// ft_strlen
#include <stdio.h>
#include <string.h>
int	main(int ac, char **av)
{
	if (ac == 2)
		printf("ft_strlen: %zu\nstrlen: %zu\n", ft_strlen(av[1]), strlen(av[1]));
	return (0);
}

// ft_strlcat
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	{
		char dst[] = "Sint elit magna aliquip fugiat sit aute nisi adipisicing adipisicing.";
		const char src[] = " Aliqua esse laborum dolor labore.";
		size_t size = 39;
		printf("ft_strlcat: %zu\n", ft_strlcat(dst, src, size));
		printf("ft_strlcat: %s\n", dst);
	}
	{
		char dst[] = "Sint elit magna aliquip fugiat sit aute nisi adipisicing adipisicing.";
		const char src[] = " Aliqua esse laborum dolor labore.";
		size_t size = 39;
		printf("strlcat: %zu\n", strlcat(dst, src, size));
		printf("strlcat: %s\n", dst);
	}
	return (0);
}

// ft_memset
#include <stdio.h>
#include <string.h>
int main(void) 
{
	{
		int arr[] = { 11, 12, 13, 14, 15 };
		size_t size = 5;
		size_t i = 0;

		printf("ft_memset (avant):\n");
		while (i < size)
		{
			printf("%d ", arr[i]);
			i++;
		}
		printf("\n\nft_memset (apres):\n");
		ft_memset(arr, 0, size * sizeof(int));
		i = 0;
		while (i < size)
		{
			printf("%d ", arr[i]);
			i++;
		}
		printf( "\n\n" );
	}
	{
		int arr[] = { 11, 12, 13, 14, 15 };
		size_t size = 5;
		size_t i = 0;

		printf("memset (avant):\n");
		while (i < size)
		{
			printf("%d ", arr[i]);
			i++;
		}
		printf("\n\nmemset (apres):\n");
		memset(arr, 0, size * sizeof(int));
		i = 0;
		while (i < size)
		{
			printf("%d ", arr[i]);
			i++;
		}
		printf( "\n" );
	}
    return 0;
}

// ft_memcpy
#include <stdio.h>
#include <string.h>
int main(void) 
{
	 {
		int src[] = {1, 2, 3, 4, 5};
		int *dest = NULL;
		int n = 5;
		int i = 0;
		
		dest = malloc(n * sizeof(int));
		ft_memcpy(dest, src, n * sizeof(int));
			
		printf("ft_memcpy:\n");
		while (i < n)
		{
			printf("%d ", dest[i]);
			i++;
		}
		printf("\n");
			
		free(dest);
	}
    {
		int src[] = {1, 2, 3, 4, 5};
		int *dest = NULL;
		int n = 5;
		int i = 0;
		
		dest = malloc(n * sizeof(int));
		memcpy(dest, src, n * sizeof(int));
			
		printf("memcpy:\n");
		while (i < n)
		{
			printf("%d ", dest[i]);
			i++;
		}
		printf("\n");
			
		free(dest);
	}
    return (0);
}

// ft_memmove
#include <stdio.h>
#include <string.h>
int main(void) 
{
	 {
		int src[] = {1, 2, 3, 4, 5};
		int *dest = NULL;
		int n = 5;
		int i = 0;
		
		dest = malloc(n * sizeof(int));
		ft_memmove(dest, src, n * sizeof(int));
			
		printf("ft_memmove:\n");
		while (i < n)
		{
			printf("%d ", dest[i]);
			i++;
		}
		printf("\n");
			
		free(dest);
	}
    {
		int src[] = {1, 2, 3, 4, 5};
		int *dest = NULL;
		int n = 5;
		int i = 0;
		
		dest = malloc(n * sizeof(int));
		memmove(dest, src, n * sizeof(int));
			
		printf("memmove:\n");
		while (i < n)
		{
			printf("%d ", dest[i]);
			i++;
		}
		printf("\n");
			
		free(dest);
	}
    return (0);
}

// ft_memcmp
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const void *s1 = "Reprehenderit labore exercitation sint proident et.";
	const void *s2 = "Reprehenderit labore 2exercitation sint proident et.";
	size_t		n = 23;
	printf("ft_memcmp: %d\nmemcmp: %d\n", ft_memcmp(s1, s2, n), memcmp(s1, s2, n));
	return (0);
}

// ft_memchr
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const void *s = "Dolor tempor incididunt commodo anim tempor labore.";
	int 		c = 'a';
	size_t		n = 34;
	printf("ft_memchr: %s\nmemchr: %s\n", (char *)ft_memchr(s, c, n), (char *)memchr(s, c, n));
	return (0);
}

// ft_lstnew
#include <stdio.h>
int	main(void)
{
	t_list	*new = NULL;
	new = ft_lstnew("Magna non esse proident nulla voluptate mollit.");
	printf("content: %s\nnext:%s\n", (char *)new->content, (char *)new->next);
}

// ft_lstadd_front
#include <stdio.h>
int	main(void)
{
	t_list	*arr = NULL;
	t_list	*new = NULL;
	t_list	*new2 = NULL;
	
	new = ft_lstnew("Magna non esse proident nulla voluptate mollit.");
	new2 = ft_lstnew("Esse incididunt excepteur dolor ullamco dolor et laborum occaecat do.");
	ft_lstadd_front(&arr, new);
	ft_lstadd_front(&arr, new2);
	while(arr)
	{
		printf("content: %s\nnext:%s\n", (char *)arr->content, (char *)arr->next);
		arr = arr->next;
	}
	return (0);
}

// ft_lstsize
#include <stdio.h>
int	main(void)
{
	t_list	*arr = NULL;
	t_list	*new = NULL;
	t_list	*new2 = NULL;
	
	new = ft_lstnew("Magna non esse proident nulla voluptate mollit.");
	new2 = ft_lstnew("Esse incididunt excepteur dolor ullamco dolor et laborum occaecat do.");
	ft_lstadd_front(&arr, new);
	ft_lstadd_front(&arr, new2);
	printf("size: %d\n", ft_lstsize(arr));
	return (0);
}

// ft_lstlast
#include <stdio.h>
int	main(void)
{
	t_list	*arr = NULL;
	t_list	*new = NULL;
	t_list	*new2 = NULL;
	t_list	*last = NULL;
	
	new = ft_lstnew("Magna non esse proident nulla voluptate mollit.");
	new2 = ft_lstnew("Esse incididunt excepteur dolor ullamco dolor et laborum occaecat do.");
	ft_lstadd_back(&arr, new);
	ft_lstadd_back(&arr, new2);
	last = ft_lstlast(arr);
	printf("(last)\ncontent: %s\nnext: %s\n", (char *)last->content, (char *)last->next);
	return (0);
}

// ft_lstadd_back
#include <stdio.h>
int	main(void)
{
	t_list	*arr = NULL;
	t_list	*new = NULL;
	t_list	*new2 = NULL;
	
	new = ft_lstnew("Magna non esse proident nulla voluptate mollit.");
	new2 = ft_lstnew("Esse incididunt excepteur dolor ullamco dolor et laborum occaecat do.");
	ft_lstadd_back(&arr, new);
	ft_lstadd_back(&arr, new2);
	while(arr)
	{
		printf("content: %s\nnext:%s\n", (char *)arr->content, (char *)arr->next);
		arr = arr->next;
	}
	return (0);
}
