#ifndef	GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

# include <io.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFER_SIZE 10

typedef struct s_gnl
{
	int	*fd;
	char	*rem;
	struct	s_gnl	*next;
}			t_gnl;

char	*ft_strdup(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
void	ft_strclr(char *s);
char	*ft_strnew(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_check(char	*rem, char **line);
int	ft_get_line(int fd, char **line, char *rem);
int	get_next_line(int fd, char **line);


#endif