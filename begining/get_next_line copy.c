#include "get_next_line.h"
#include <sys/stat.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

char	*ft_check(char	*rem, char **line)
{
	char	*ptr;

	ptr = NULL;
	if (rem)
		if ((ptr = ft_strchr(rem, '\n')))
		{
			*ptr = '\0';
			*line = ft_strdup(rem);
			ptr++; 
			ft_strcpy(rem, ptr);
		}
		else
		{
			*line = ft_strdup(rem);
			ft_strclear(rem)
		}
	else
		*line = ft_strnew(1)
	return (ptr);
}

int get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	int		byte_was_read;
	char	*ptr;
	static char	*rem;
	char	*tmp;

	//byte_was_read = read(fd, buf, 10);
	//while (f && byte_was_read)
	ptr = ft_check(rem, line);
	while (!ptr && (byte_was_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byte_was_read] = '\0';
		//ptr = ft_strchr(buf, '\n');
		//if (ptr)
		if (ptr = ft_strchr(buf, '\n'))
		{
			*ptr = '\0';
			ptr++;
			rem = ft_strdup(ptr); 
		}
		tmp = *line;
		*line = ft_strjoin(tmp, buf);
		free(tmp);
		//byte_was_read = read(fd, buf, 10);
	}
	if (rem || byte_was_read)
		return (1);
	else
		return (0)
}

int	main()
{
	char	*line;
	int	fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s%%\n", line);

	get_next_line(fd, &line);
	printf("%s%%\n", line);

	/*get_next_line(fd, &line);
	printf("%s%%\n", line);*/
}