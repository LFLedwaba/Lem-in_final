
#include "lem_in.h"

void		fm_em(t_lm *lm, t_ws *wys)
{
	t_ws	*wst;
	int		max_ems;

	wst = wys;
	max_ems = 0;
	while (wst)
	{
		max_ems += wst->way->len - 1;
		wst = wst->nxt;
	}
	lm->max_ems = max_ems;
}

void		read_tlen(t_ws *wys)
{
	t_ws	*wst;
	t_w	*read;
	int		a;

	wst = wys;
	while (wst)
	{
		a = 0;
		read = wst->way;
		while (read)
		{
			read = read->nxt;
			a++;
		}
		read = wst->way;
		while (read)
		{
			read->len = a;
			read = read->nxt;
		}
		wst = wst->nxt;
	}
}