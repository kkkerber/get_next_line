#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*tmp;
	ssize_t		bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
	return (NULL);

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);

    while (!ft_strchr(stash, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            free(buffer);
            free(stash);
            stash = NULL; //не пон
            return (NULL); //не пон
        }
        if (bytes_read == 0)
            break ;
        buffer[bytes_read] = '\0';
        tmp = ft_strjoin(stash, buffer);
        if (!tmp)
        {
            free(buffer);
            free(stash);
            stash = NULL;
            return (NULL);
        }
        free(stash);
        stash = tmp;
    }
}

char	*ft_get_line(char *stash)
{
    size_t i;
    size_t j;
    char *cpy;

    i = 0;
    while(stash[i] || stash[i] != '\n')
    {
        i++;
    }
    if (stash[i] == '\n')
	    i++;

    j = 0;
    cpy = malloc(i + 1);
    while (j < i)
    {
        cpy[j] = stash[j];
        j++;
    }
    cpy[j] = '\0';
    return (cpy);
}
char	*ft_new_stash(char *stash);