
#include "lem_in.h"

static void		chk_first(t_lm *lm, char *str,
	int *ln_n, int ret)
{
	if (ret == -1)
		error_e(lm, 1);
	if (!*ln_n)
		*ln_n = f_ln(lm, str, *ln_n);
}

static void		instruc(t_lm *lm, int *start,
	char *str, char **map)
{
	(*start)++;
	if (*start > 1)
		error_e(lm, 1);
	a_map(map, str);
	fe_s(&str);
}

static void		fr_l(t_lm *lm, char *str, int *ln_n, char **map)
{
	if (ft_strchr(str, '-') && str[0] != '#'
		&& str[0] != 'L' && *ln_n > 1)
		a_l(lm, str);
	(*ln_n)++;
	a_map(map, str);
	if (str)
		free(str);
}

void			values(int *start, char **str,
	int *end, int *ln_n)
{
	*start = 0;
	*str = NULL;
	*end = 0;
	*ln_n = 0;
}

void			read_map(t_lm *lm, int ret, int fd, char **map)
{
	int		start;
	int		end;
	int		ln_n;
	char	*str;

	values(&start, &str, &end, &ln_n);
	while ((ret = get_next_line(fd, &str)))
	{
		chk_first(lm, str, &ln_n, ret);
		if (ft_strequ("##start", str))
		{
			instruc(lm, &start, str, map);
			continue ;
		}
		else if (ft_strequ("##end", str))
		{
			instruc(lm, &end, str, map);
			continue ;
		}
		if (!ft_strchr(str, '-') && str[0] != '#'
		&& str[0] != 'L' && ln_n > 1)
			load_r(lm, &str, &start, &end);
		fr_l(lm, str, &ln_n, map);
	}
	bf_err(lm, start, end);
}