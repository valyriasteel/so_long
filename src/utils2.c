#include "../inc/so_long.h"

static void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = c;
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;
	size_t	total;

	total = count * size;
	if (size && count > 2147483647 / size)
		return (0);
	dst = (unsigned char *)malloc(total);
	if (!dst)
		return (NULL);
	ft_memset(dst, 0, total);
	return (dst);
}