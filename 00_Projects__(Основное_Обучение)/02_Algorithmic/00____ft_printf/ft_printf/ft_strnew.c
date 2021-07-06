#include "printf_header.h"

char	*ft_strnew(size_t size)
{
	char	*res;

	res = (char *)malloc(size + 1);
	if (!res)
		return (NULL);
	ft_memset(res, 0, sizeof(char) * (size + 1));
	return (res);
}
