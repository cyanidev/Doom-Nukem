#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdio.h> //print
# include <stdlib.h> //malloc
# include <string.h> 
# include <unistd.h> // read
# include <fcntl.h> //open

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
void	ft_read(int fd, char **save, char **tmp);
char	*ft_saving(char *tmp);
char	*ft_splitn(char **save, char **tmp);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free(char **str, char **str2, char **str3);
char	*ft_strdup(const char *s);
char	*ft_strchr_gnl(char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

#endif