#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../push_swap.h"
int		get_next_line(int fd, char **line);
#endif
