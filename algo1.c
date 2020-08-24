
#include "lem_in.h"

static t_w	*f_mw(t_lm *lm)
{
	t_w	*way;
	t_w	*wst;
	t_w	*clear_way;

	clear_way = NULL;
	way = w_read(lm);
	wst = way;
	while (wst)
	{
		if (ft_strequ(wst->rum->name, lm->end->name))
			break ;
		wst = wst->nxt;
	}
	if (!wst)
	{
		w_d(way);
		return (NULL);
	}
	if ((ft_strequ(wst->rum->name, lm->end->name)))
		clear_way = w_s(wst, lm);
	w_d(way);
	return (clear_way);
}

static void		m_alh(t_ws *wys, t_lm *lm)
{
	rm_o(&wys, lm);
	fc_w(&wys, lm);
	f_sn(wys);
	len_srt(&wys);
}

static t_ws	*m_al(t_lm *lm, t_w *first)
{
	t_ws	*wys;
	t_ws	*new;
	t_ws	*curr;
	t_w	*wst;

	wys = n_ws(first, NULL);
	w_rl(lm, wys);
	curr = wys;
	while ((wst = f_mw(lm)))
	{
		new = n_ws(wst, curr);
		lm->w_cnt++;
		curr->nxt = new;
		curr = curr->nxt;
		rm_se(wys);
		w_rl(lm, wys);
		read_tlen(wys);
		if (!(fl_a(lm, wys)))
		{
			new->delete = 1;
			break ;
		}
	}
	m_alh(wys, lm);
	return (wys);
}

void			em_al(t_lm *lm, t_w *first_way, char *map)
{
	t_ws	*wys;

	ft_putendl(map);
	if (o_p(lm))
		pt_o_p(lm);
	else
	{
		wys = m_al(lm, first_way);
		if (!wys)
			error_e(lm, 1);
		pt_em_w(lm, wys);
		fm_em(lm, wys);
		pt_f_m(lm, wys);
		r_w(wys);
	}
}
