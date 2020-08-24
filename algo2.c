
#include "lem_in.h"

void			f_sn(t_ws *wys)
{
	t_ws	*wst;
	int		a;

	wst = wys;
	a = 1;
	while (wst)
	{
		wst->num = a;
		a++;
		wst = wst->nxt;
	}
}

void			rm_o(t_ws **wys, t_lm *lm)
{
	t_ws	*wst;
	t_ws	*remove;

	wst = *wys;
	while (wst)
	{
		if (wst->delete)
		{
			if (wst->prev)
				wst->prev->nxt = wst->nxt;
			if (wst->nxt && wst->prev)
				wst->nxt->prev = wst->prev;
			remove = wst;
			if (!wst->prev)
				*wys = wst->nxt;
			wst = wst->nxt;
			rm_oo_w(remove);
			(lm->w_cnt)--;
			continue ;
		}
		wst = wst->nxt;
	}
}

static void		ws(t_ws *chk, t_ws *wst)
{
	t_ws	*swp;

	if (chk->prev && chk->prev != wst)
		chk->prev->nxt = wst;
	if (wst->prev && wst->prev != chk)
		wst->prev->nxt = chk;
	swp = chk->nxt;
	chk->nxt = (wst->nxt == chk) ? wst : wst->nxt;
	if (wst->nxt && wst->nxt != chk)
		wst->nxt->prev = chk;
	wst->nxt = (swp == wst) ? chk : swp;
	if (swp)
		swp->prev = wst;
	swp = chk->prev;
	chk->prev = (wst->prev == chk) ? wst : wst->prev;
	wst->prev = (swp == wst) ? chk : swp;
}

void			len_srt(t_ws **wys)
{
	t_ws	*wst;
	t_ws	*chk;

	wst = *wys;
	while (wst)
	{
		chk = wst->nxt;
		while (chk)
		{
			if (chk->way->len < wst->way->len)
			{
				ws(chk, wst);
			}
			chk = chk->nxt;
		}
		wst = wst->nxt;
	}
	while ((*wys)->prev)
		(*wys) = (*wys)->prev;
}

void			f_w(t_w *way)
{
	t_w	*new;
	t_w	*curr;
	t_lnk	*lnk;

	curr = way;
	while (curr->nxt)
		curr = curr->nxt;
	lnk = way->rum->lnk;
	while (lnk)
	{
		if (!(lnk->lock) && !(way->rum->block_span == 1 &&
		lnk->trk->block_span == 0) && !(way->rum->block_span == 1
		&& lnk->trk->span < way->rum->span && lnk->trk->span))
		{
			if (way->rum->block_span == 1 && lnk->trk->block_span == 1)
				lnk->trk->block_span = 0;
			new = n_w();
			new->prev = way;
			new->rum = lnk->trk;
			lnk->lock = 1;
			curr->nxt = new;
			curr = curr->nxt;
		}
		lnk = lnk->nxt;
	}
}