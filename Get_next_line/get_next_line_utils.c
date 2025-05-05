#include "get_next_line.h"

void	ft_free_all(char *s1, char *s2, char *s3)
{
	free(s1);
	free(s2);
	free(s3);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(char *str, char nl)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == nl)
			return (str);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(sizeof(char) * (i + 1));
	if (!joined)
		return (ft_free_all(s1, s2, NULL), NULL);
	i = 0;
	while (s1 && s1[i])
		joined[i] = s1[i++];
	j = 0;
	while (s2 && s2[j])
		joined[i + j] = s2[j++];
	joined[i + j] = '\0';
	return (ft_free_all(s1, s2, NULL), joined);
}