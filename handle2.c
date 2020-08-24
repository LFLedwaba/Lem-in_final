
#include "lem_in.h"

void			a_l_ex(t_ph **curr, t_ph **plus)
{
	t_lnk	*wst;

	if (!((*curr)->lnk))
		(*curr)->lnk = n_l(*plus);
	else
	{
		wst = (*curr)->lnk;
		while (wst->nxt)
			wst = wst->nxt;
		wst->nxt = n_l(*plus);
	}
	if (!((*plus)->lnk))
		(*plus)->lnk = n_l(*curr);
	else
	{
		wst = (*plus)->lnk;
		while (wst->nxt)
			wst = wst->nxt;
		wst->nxt = n_l(*curr);
	}
}

void			a_l(t_lm *lm, char *str)
{
	char	**string;
	t_ph	*curr;
	t_ph	*plus;

	string = ft_strsplit(str, '-');
	if (!string[0] || !string[1] || string[2] || !lm->way)
		error_e(lm, 1);
	curr = (*lm).way;
	while ((!ft_strequ(string[0], curr->name)) && curr->prev)
		curr = curr->prev;
	plus = (*lm).way;
	while ((!ft_strequ(string[1], plus->name)) && plus->prev)
		plus = plus->prev;
	if (!ft_strequ(string[0], curr->name) || !ft_strequ(string[1], plus->name))
		error_e(lm, 1);
	a_l_ex(&curr, &plus);
	free(string[0]);
	free(string[1]);
	free(string);
}

static int		ce_r(t_lm *lm, char *rum_name)
{
	t_ph	*chk;

	chk = lm->way;
	while (chk)
	{
		if (ft_strequ(rum_name, chk->name))
			return (1);
		chk = chk->nxt;
	}
	return (0);
}

void			ef_r(t_lm *lm, const int *start,
		const int *end, t_ph **new)
{
	t_ph *prev;

	prev = NULL;
	if (*start && !lm->start)
		lm->start = *new;
	else if (*end && !lm->end)
		lm->end = *new;
	if (!lm->way)
		lm->way = *new;
	else
	{
		while (lm->way)
		{
			prev = lm->way;
			lm->way = lm->way->nxt;
		}
		lm->way = *new;
		prev->nxt = *new;
	}
	lm->way->prev = prev;
}

void			load_r(t_lm *lm, char **str,
	const int *start, const int *end)
{
	t_ph	*new;
	char	**string;

	string = ft_strsplit(*str, ' ');
	if (!string[0] || !string[1] || !string[2] || string[3]
	|| ce_r(lm, string[0]))
		error_e(lm, 1);
	new = n_p(string[0], ft_atoi(string[1]), ft_atoi(string[2]));
	ef_r(lm, start, end, &new);
	free(string[1]);
	free(string[2]);
	free(string);
}