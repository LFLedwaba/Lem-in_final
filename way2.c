
#include "lem_in.h"

t_w			*w_read(t_lm *lm)
{
	t_w	*way;
	t_w	*start_way;

	way = n_w();
	start_way = way;
	way->rum = lm->start;
	while (way)
	{
		if (ft_strequ(start_way->rum->name, lm->end->name))
			break ;
		f_w(way);
		way = way->nxt;
	}
	return (start_way);
}

static t_lnk	*p_l(t_w *way, t_w *new)
{
	t_lnk	*lnk;

	lnk = way->rum->lnk;
	while (lnk->trk != new->rum)
		lnk = lnk->nxt;
	return (lnk);
}

static t_w	*w_len(t_w *way, int num)
{
	t_w	*wst;

	wst = way;
	while (wst)
	{
		wst->len = num;
		wst = wst->nxt;
	}
	return (way);
}

static void		h_w_s(t_w *wst, t_lm *lm)
{
	if (!ft_strequ(wst->rum->name, lm->start->name))
		wst->rum->block_span = 1;
}

t_w			*w_s(t_w *way, t_lm *lm)
{
	t_w	*new;
	t_w	*curr;
	t_w	*wst;
	int		a;

	a = 1;
	new = n_w();
	new->rum = way->rum;
	way = way->prev;
	new->prev_link = p_l(way, new);
	curr = new;
	while (way)
	{
		wst = n_w();
		wst->rum = way->rum;
		h_w_s(wst, lm);
		way = way->prev;
		if (way)
			wst->prev_link = p_l(way, wst);
		wst->prev = curr;
		curr->nxt = wst;
		curr = curr->nxt;
		a++;
	}
	return (w_len(new, a));
}