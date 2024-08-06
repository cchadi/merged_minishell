#include "../minishell.h"


char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size1;
	size_t	size2;
	char	*str;
	int		j;
	int		i;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	str = malloc((size1 + size2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	// free(s1);
	return (str);
}
