
#include "lem_in.h"

void	init_lm(t_lm *lm)
{
	lm->ems = -1;
	lm->w_cnt = 1;
	lm->max_ems = 0;
	lm->l_oa = 0;
	lm->em_count_on_trk = NULL;
	lm->start = NULL;
	lm->end = NULL;
	lm->way = NULL;
}

t_ph	*n_p(char *name, int x, int y)
{
	t_ph	*new;

	if ((new = (t_ph *)malloc(sizeof(t_ph))))
	{
		new->lock = 0;
		new->span = 0;
		new->block_span = 0;
		new->lnk = NULL;
		new->nxt = NULL;
		new->prev = NULL;
		new->name = name;
		new->coords[0] = x;
		new->coords[1] = y;
	}
	return (new);
}

t_lnk	*n_l(t_ph *rum)
{
	t_lnk	*new;

	if ((new = (t_lnk *)malloc(sizeof(t_lnk))))
	{
		new->trk = rum;
		new->lock = 0;
		new->nxt = NULL;
	}
	return (new);
}

t_w	*n_w(void)
{
	t_w	*new;

	if ((new = (t_w *)malloc(sizeof(t_w))))
	{
		new->rum = NULL;
		new->prev_link = NULL;
		new->nxt = NULL;
		new->prev = NULL;
		new->len = 0;
	}
	return (new);
}

t_ws	*n_ws(t_w *way, t_ws *prev)
{
	t_ws	*new;

	if ((new = (t_ws *)malloc(sizeof(t_ws))))
	{
		new->way = way;
		new->prev = prev;
		new->nxt = NULL;
		new->delete = 0;
		new->num = 0;
	}
	return (new);
}