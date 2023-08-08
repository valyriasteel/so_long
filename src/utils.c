#include "../inc/so_long.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

int	wordcounter(const char *p, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*p)
	{
		if (*p != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*p == c)
			trigger = 0;
		p++;
	}
	return (i);
}

char	*worddup(const char *s, int start, int end)
{
	size_t	i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	char	**split;
	size_t	i;
	size_t	a;
	int		start;

	if (!s)
		return (NULL);
	i = -1;
	a = 0;
	start = -1;
	split = malloc(sizeof(char *) * (wordcounter(s, c) + 1));
	if (!split)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			split[a++] = worddup(s, start, i);
			start = -1;
		}
	}
	split[a] = 0;
	return (split);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (str + i);
	return (NULL);
}


int	ft_arrlen(char **arrays)
{
	int i;

	i = 0;
	while (arrays[i])
		i++;
	return (i);
}
