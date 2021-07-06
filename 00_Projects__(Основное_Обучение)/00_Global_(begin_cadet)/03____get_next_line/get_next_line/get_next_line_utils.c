#include "get_next_line.h"

void	*ft_calloc(int size)
{
	char	*res;
	int		i;

	if (size == 0)
		return (NULL);
	i = -1;
	res = (char *)malloc(size);
	if (!res)
		return (NULL);
	while (++i < size)
		res[i] = 0;
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	long	i;
	long	j;
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return ((char *)s2);
	else if (s2 == NULL)
		return ((char *)s1);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = *(s1 + i);
	while (s2[++j])
		str[i + j] = *(s2 + j);
	str[i + j] = '\0';
	free((void *)s1);
	return (str);
}

void	*ft_memchr(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)str;
	while (i < n)
	{
		if ((unsigned char)c == s[i])
			return (&s[i]);
		i++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (!n || dst == src)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

void	*ft_memset(void *dest, int c, size_t size)
{
	size_t			i;
	unsigned char	*de;

	i = 0;
	de = (unsigned char *)dest;
	while (i < size)
		de[i++] = c;
	return (dest);
}
