
#include "lem_in.h"

static void		e_span(t_w *way)
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
		if (!(lnk->trk->lock))
		{
			new = n_w();
			new->prev = way;
			new->rum = lnk->trk;
			if (new->rum->span < new->prev->rum->span + 1)
				new->rum->span = new->prev->rum->span + 1;
			new->rum->lock = 1;
			curr->nxt = new;
			curr = curr->nxt;
		}
		lnk = lnk->nxt;
	}
}

static void		span_a_m(t_lm *lm)
{
	t_w	*way;

	way = n_w();
	way->rum = lm->end;
	way->rum->span = 1;
	while (way->nxt)
	{
		e_span(way);
		if (way->nxt)
			way = way->nxt;
	}
	w_d(way);
	w_fs(lm);
}

t_w			*ch_map(t_lm *lm)
{
	t_w	*wst;
	t_w	*way;
	t_w	*first;

	way = w_read(lm);
	wst = way;
	while (wst)
	{
		if (ft_strequ(wst->rum->name, lm->end->name))
			break ;
		wst = wst->nxt;
	}
	if (!wst)
		error_e(lm, 1);
	if (!(ft_strequ(wst->rum->name, lm->end->name)))
		error_e(lm, 1);
	first = w_s(wst, lm);
	w_d(way);
	w_fs(lm);
	span_a_m(lm);
	return (first);
}
