
#include "lem_in.h"

int				o_p(t_lm *lm)
{
	t_ph	*trks;
	t_lnk	*links;

	trks = lm->way;
	while (trks)
	{
		if (ft_strequ(trks->name, lm->start->name))
		{
			links = trks->lnk;
			while (links)
			{
				if (ft_strequ(links->trk->name, lm->end->name))
					return (1);
				links = links->nxt;
			}
		}
		trks = trks->prev;
	}
	return (0);
}

void			pt_o_p(t_lm *lm)
{
	int em;

	em = 1;
	while (em < lm->ems + 1)
	{
		ft_putstr("\n");
		mv_pt(em, lm->end->name);
		em++;
	}
	ft_putstr("\n");
}

void			mv_pt(int em_number, char *rum)
{
	char	*move;

	move = ft_str2("L", ft_itoa(em_number));
	move = ft_str1(move, "-");
	move = ft_str1(move, rum);
	move = ft_str1(move, " ");
	ft_putstr(move);
	free(move);
}

void			rm_em_tb(t_lm *lm, t_em **em_tb)
{
	int		i;

	if (em_tb)
	{
		i = 0;
		while (i < lm->ems)
		{
			free(em_tb[i]);
			em_tb[i] = NULL;
			i++;
		}
		free(em_tb);
	}
}