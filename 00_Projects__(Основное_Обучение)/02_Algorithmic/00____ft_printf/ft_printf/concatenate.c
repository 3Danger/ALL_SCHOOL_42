#include "printf_header.h"

char	*concatenate(char *s1, char *s2)
{
	char	*res;
	int		len1;
	int		len2;
	int		i;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	res = (char *)ft_strnew(len1 + len2 + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len1)
		res[i] = s1[i];
	i = -1;
	while (++i < len2)
		res[len1 + i] = s2[i];
	free(s1);
	free(s2);
	return (res);
}

char	*concat_fr2(char *s1, char *s2)
{
	char	*res;
	int		len1;
	int		len2;
	int		i;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	res = (char *)ft_strnew(len1 + len2 + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len1)
		res[i] = s1[i];
	i = -1;
	while (++i < len2)
		res[len1 + i] = s2[i];
	free(s2);
	return (res);
}

char	*concatenate_fr1(char *s1, int size1, char *s2, int size2)
{
	char	*res;
	int		i;

	res = (char *)ft_strnew(size1 + size2 + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < size1)
		res[i] = s1[i];
	i = -1;
	while (++i < size2)
		res[size1 + i] = s2[i];
	free(s1);
	s1 = NULL;
	return (res);
}

char	*concatenate_frbth(char *s1, int size1, char *s2, int size2)
{
	char	*res;
	int		i;

	res = (char *)ft_strnew(size1 + size2 + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < size1)
		res[i] = s1[i];
	i = -1;
	while (++i < size2)
		res[size1 + i] = s2[i];
	free(s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
	return (res);
}
