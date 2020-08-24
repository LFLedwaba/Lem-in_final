
#include "lem_in.h"

void	fe_s(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

int		f_ln(t_lm *lm, char *str, int ln_n)
{
	ssize_t num;

	num = ft_atoi(str);
	if (num <= 0 || num > 2147483647)
		error_e(lm, 1);
	lm->ems = num;
	return (ln_n + 1);
}

void	bf_err(t_lm *lm, int start, int end)
{
	if (!start || !end || !lm->ems || !lm->way)
		error_e(lm, 1);
}

void	a_map(char **map, char *str)
{
	*map = ft_str1(*map, str);
	*map = ft_str1(*map, "\n");
}
