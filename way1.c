
#include "lem_in.h"

static void		l_w(t_ws *wys)
{
	t_ws	*wst_ways;
	t_w	*wst_way;

	wst_ways = wys;
	while (wst_ways)
	{
		wst_way = wst_ways->way;
		while (wst_way)
		{
			if (wst_way->prev_link)
				wst_way->prev_link->lock = 1;
			wst_way = wst_way->nxt;
		}
		wst_ways = wst_ways->nxt;
	}
}

void			w_rl(t_lm *lm, t_ws *wys)
{
	t_lnk	*wst;
	t_ph	*wsd;

	wsd = lm->way;
	while (wsd)
	{
		wst = wsd->lnk;
		while (wst)
		{
			wst->lock = 0;
			wst = wst->nxt;
		}
		wsd = wsd->prev;
	}
	l_w(wys);
}

void			w_fs(t_lm *lm)
{
	t_lnk	*wst;
	t_ph	*wsd;

	wsd = lm->way;
	while (wsd)
	{
		wst = wsd->lnk;
		while (wst)
		{
			wst->lock = 0;
			wst = wst->nxt;
		}
		wsd = wsd->prev;
	}
}