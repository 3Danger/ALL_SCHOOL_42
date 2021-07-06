#include "printf_header.h"

char	*ft_hex_gen_long(long dec)
{
	long	i;
	int		j;
	char	res[64];
	char	*hex_code;

	if (dec == 0)
		return (ft_strdup("0"));
	j = 0;
	hex_code = "0123456789abcdef";
	i = (sizeof(dec) << 3) - 4;
	while (dec >> i == 0)
		i -= 4;
	while (i >= 0)
	{
		res[j++] = hex_code[(dec >> i) & 0xf];
		i -= 4;
	}
	res[j] = '\0';
	return (ft_strdup(res));
}

char	*ft_hex_gen_int(int dec, char c)
{
	long	i;
	int		j;
	char	res[64];
	char	*hex_code;

	if (dec == 0)
		return (ft_strdup("0"));
	j = 0;
	if (c == 'X')
		hex_code = "0123456789ABCDEF";
	else
		hex_code = "0123456789abcdef";
	i = (sizeof(dec) << 3) - 4;
	while (dec >> i == 0)
		i -= 4;
	while (i >= 0)
	{
		res[j++] = hex_code[(dec >> i) & 0xf];
		i -= 4;
	}
	res[j] = '\0';
	return (ft_strdup(res));
}
