#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	size_t	len_stash;
	size_t	len_buffer;
	size_t	i;
	size_t	j;
	char	*str;

	len_stash = ft_strlen(stash);
	len_buffer = ft_strlen(buffer);
	str = malloc(len_stash + len_buffer + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (stash && stash[i])
	{
		str[i] = stash[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		str[i] = buffer[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}