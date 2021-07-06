#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//  # define BUFFER_SIZE 42
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

void	*ft_calloc(int size);
int		get_next_line(int fd, char **line);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strlen(const char *s1);
void	*ft_memchr(void *str, int c, size_t n);
void	*ft_memset(void *dest, int c, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif