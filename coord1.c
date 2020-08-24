
#include "lem_in.h"

t_em			*mk_em(int em_number, t_w *way)
{
	t_em	*em;

	em = (t_em *)malloc(sizeof(t_em));
	em->number = em_number;
	em->gtt_end = 0;
	em->way = way;
	return (em);
}

static t_em	**mt_em(int ems)
{
	t_em	**em_tb;

	em_tb = (t_em **)malloc(sizeof(t_em) * ems);
	if (!em_tb)
		return (NULL);
	return (em_tb);
}

static void		mk_em_th(t_ws *wst,
	t_em **em_tb, int *em)
{
	if (!wst->prev && !wst->nxt && wst->way)
	{
		em_tb[*em - 1] = mk_em(*em, wst->way->prev);
		(*em)++;
	}
}

static void		ft_em(t_ws *wst, t_em **em_tb,
	int *em, int *pat)
{
	em_tb[*em - 1] = mk_em(*em, wst->way->prev);
	if (wst->num == 1)
		(*pat)++;
	(*em)++;
}

t_em			**mk_em_tb(t_lm *lm, t_ws *wys)
{
	int		em;
	t_ws	*wst;
	t_em	**em_tb;
	int		pat;

	pat = 0;
	em = 1;
	em_tb = mt_em(lm->ems);
	while (em < lm->ems + 1)
	{
		wst = wys;
		mk_em_th(wst, em_tb, &em);
		while (wst)
		{
			if (pat >= wst->way->len - wys->way->len
				|| wst->num == 1)
			{
				if (em > lm->ems)
					break ;
				ft_em(wst, em_tb, &em, &pat);
			}
			wst = wst->nxt;
		}
	}
	return (em_tb);
}