
#include "lem_in.h"

static t_ws	*ch_del(t_ws *sngl, t_ws *duo, t_lm *lm)
{
	t_w	*x;
	t_w	*y;

	x = sngl->way;
	while (x)
	{
		y = duo->way;
		while (y)
		{
			if (x->rum == y->rum &&
			!(x->rum == lm->start || x->rum == lm->end))
			{
				if (x->len > y->len)
					return (sngl);
				else
					return (duo);
			}
			y = y->nxt;
		}
		x = x->nxt;
	}
	return (NULL);
}

static void		fc_wh(t_ws **wys, t_ws *delete)
{
	*wys = (delete == *wys) ? (*wys)->nxt : *wys;
	if (delete != *wys && delete->prev)
		delete->prev->nxt = delete->nxt;
	if (delete->nxt)
		delete->nxt->prev = delete->prev;
	rm_oo_w(delete);
}

int				fc_w(t_ws **wys, t_lm *lm)
{
	t_ws	*wst;
	t_ws	*chk;
	t_ws	*delete;

	wst = *wys;
	chk = *wys;
	delete = NULL;
	while (wst)
	{
		chk = (chk == wst) ? chk->nxt : chk;
		while (chk)
		{
			if ((delete = ch_del(wst, chk, lm)))
			{
				fc_wh(wys, delete);
				lm->w_cnt--;
				return (fc_w(wys, lm));
			}
			chk = chk->nxt;
		}
		wst = wst->nxt;
	}
	return (0);
}