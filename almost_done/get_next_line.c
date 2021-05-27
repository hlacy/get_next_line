#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*res;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((str = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	res = str;
	while (*s1)
	{
		*str = *s1;
		str++;
		s1++;
	}
	while (*s2)
	{
		*str = *s2;
		str++;
		s2++;
	}
	*str = '\0';
	return (res);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

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
			ft_strclr(rem);
		}
	else
		*line = ft_strnew(1);
	return (ptr);
}



int	ft_get_line(int fd, char **line, char *rem)
{
	char	buf[BUFFER_SIZE + 1];
	int		byte_was_read;
	char	*ptr;
	char	*tmp;

	//byte_was_read = read(fd, buf, 10);
	//while (f && byte_was_read)
	if (!line || BUFFER_SIZE < 1)
		return (-1);
	ptr = ft_check(rem, line);
	while (!ptr && (byte_was_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byte_was_read] = '\0';// why does a trash appear without ='\0'
		//ptr = ft_strchr(buf, '\n');
		//if (ptr)
		if (ptr = ft_strchr(buf, '\n'))
		{
			*ptr = '\0';
			ptr++;
			rem = ft_strdup(ptr); 
		}
		tmp = *line;
		//*line = ft_strjoin(tmp, buf);
		if (!(*line = ft_strjoin(*line, buf)) || byte_was_read < 0)
			return (-1);
		free(tmp);
		//byte_was_read = read(fd, buf, 10);
	}

	if (rem || byte_was_read)
		return (1);
	else
		return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_gnl	*head;
	t_gnl	*tmp;

	if (fd < 0 || !line)
		return (-1);
	if (head == NULL)
	{
		head = (t_gnl *)malloc(sizeof(t_gnl));
		head->fd = fd;
		head->next = NULL;
	}
	tmp = head;
	while (tmp->fd != fd)
	{
		if (!(tmp->next))//it may be out of while-cicle, it needs to try
			{
				tmp = (t_gnl *)malloc(sizeof(t_gnl));
				tmp->fd = fd;
				tmp->next = NULL;
			}
		tmp = tmp->next;
	}
	return (ft_get_line(tmp->fd, line, tmp->rem));
}

/*int get_next_line(int fd, char **line)
{
	static t_gnl	*head;
	t_gnl	*tmp;

	if (fd < 0 || !line)
		return (-1);
	if (head == NULL)
		head = ft_newlistel(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (!(tmp->next))//it may be out of while-cicle, it needs to try
			tmp->next = ft_newlistel(fd);
		tmp = tmp->next;
	}
	return (ft_get_line(tmp->fd, line, tmp->rem));
}

t_gnl	ft_newlistel(int fd)
{
	t_gnl	*new;

	new = (t_gnl *)malloc(sizeof(t_gnl));
	new->fd = fd;
	new->next = NULL;
	return (new);
}*/
	

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