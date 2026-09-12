
#include "get_next_line.h"

static char	*ft_clean(char *buffer, char *stash)
{
	free(buffer);
	free(stash);
	return (NULL);
}

static char	*ft_read_stash(int fd, char *stash) //копирует всё до \n включительно.
{
	char		*buffer;
	char		*tmp;
	ssize_t		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_clean(NULL, stash));
	while (!ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_clean(buffer, stash));
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buffer);
		if (!tmp)
			return (ft_clean(buffer, stash));
		free(stash);
		stash = tmp;
	}
	free(buffer);
	return (stash);
}

static char	*ft_get_line(char *stash)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*ft_new_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (NULL);
	i++;
	new_stash = malloc(ft_strlen(stash + i) + 1);
	if (!new_stash)
		return (NULL);
	j = 0;
	while (stash[i])
	{
		new_stash[j] = stash[i];
		i++;
		j++;
	}
	new_stash[j] = '\0';
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_stash(fd, stash);
	if (!stash || !stash[0])
		return (stash = ft_clean(NULL, stash));
	line = ft_get_line(stash);
	if (!line)
		return (stash = ft_clean(NULL, stash));
	tmp = ft_new_stash(stash);
	if (ft_strchr(stash, '\n') && !tmp)
	{
		free(line);
		return (stash = ft_clean(NULL, stash));
	}
	free(stash);
	stash = tmp;
	return (line);
}