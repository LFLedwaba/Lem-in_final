
#include "lem_in.h"

void			pt_f_m(t_lm *lm, t_ws *wys)
{
	t_em	**em_tb;

	em_tb = mk_em_tb(lm, wys);
	mm_wp(lm, em_tb);
	rm_em_tb(lm, em_tb);
}

void			pt_p(t_lm *lm, t_w *way, int debug)
{
	t_w	*print;

	print = way;
	while (!ft_strequ(print->rum->name, lm->end->name))
	{
		if (debug)
		{
			ft_putstr(print->rum->name);
			ft_putstr(" -> ");
		}
		print = print->prev;
	}
	if (debug)
	{
		ft_putstr(lm->end->name);
		ft_putstr("\n");
	}
}

void			pt_em_w(t_lm *lm, t_ws *wys)
{
	t_ws	*print;

	print = wys;
	while (print)
	{
		while (print->way->nxt)
			print->way = print->way->nxt;
		pt_p(lm, print->way, 0);
		print = print->nxt;
	}
}

int				em_dn(t_em **em_tb, t_lm *lm)
{
	int		em;

	em = 0;
	while (em < lm->ems)
	{
		if (!(em_tb[em]->gtt_end))
			return (1);
		em++;
	}
	return (0);
}