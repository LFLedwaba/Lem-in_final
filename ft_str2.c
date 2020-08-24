#include "lem_in.h"

char	*ft_str2(char *s1, char *s2)
{
	char	*result;

	if (!s2)
		return (s1);
	result = ft_strjoin(s1, s2);
	free(s2);
	return (result);
}