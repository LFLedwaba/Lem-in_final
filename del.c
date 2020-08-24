
#include "lem_in.h"

static void		s_e(t_w *a, t_w *b)
{
	t_lnk	*wst_link;
	t_w	*swp;

	if (a->rum == b->rum && a->nxt->rum == b->prev->rum)
	{
		swp = a->nxt;
		a->nxt = b->nxt;
		b->nxt->prev = a;
		wst_link = a->rum->lnk;
		while (wst_link->trk != b->nxt->rum)
			wst_link = wst_link->nxt;
		b->nxt->prev_link = wst_link;
		b->prev->nxt = swp->nxt;
		swp->nxt->prev = b->prev;
		wst_link = swp->rum->lnk;
		while (wst_link->trk != swp->nxt->rum)
			wst_link = wst_link->nxt;
		swp->nxt->prev_link = wst_link;
	}
}

static void		rs_eal(t_ws *wst, t_ws *chk)
{
	t_w	*a;
	t_w	*b;

	a = wst->way;
	while (a)
	{
		b = chk->way;
		while (b)
		{
			if (!(a->nxt) || !(b->prev) || !(a->nxt->nxt))
			{
				b = b->nxt;
				continue;
			}
			s_e(a, b);
			b = b->nxt;
		}
		a = a->nxt;
	}
}

void			rm_se(t_ws *wys)
{
	t_ws	*wst;
	t_ws	*chk;

	wst = wys;
	while (wst)
	{
		chk = wys;
		if (chk == wst)
			chk = chk->nxt;
		while (chk)
		{
			rs_eal(wst, chk);
			chk = chk->nxt;
		}
		wst = wst->nxt;
	}
}
