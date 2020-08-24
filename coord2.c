
#include "lem_in.h"

static t_ws	*em_mvt(t_lm *lm, t_em **em_tb,
	int *array, t_ws *chk)
{
	t_ws	*new;
	t_ws	*wst;

	new = NULL;
	wst = chk;
	while (wst)
	{
		if (wst->way == em_tb[array[2]]->way)
			return (NULL);
		wst = wst->nxt;
	}
	if (!em_tb[array[2]]->gtt_end)
	{
		mv_pt(em_tb[array[2]]->number,
			em_tb[array[2]]->way->rum->name);
		new = n_ws(em_tb[array[2]]->way, NULL);
		array[3]++;
	}
	if (ft_strequ(em_tb[array[2]]->way->rum->name, lm->end->name))
		em_tb[array[2]]->gtt_end = 1;
	if (em_tb[array[2]]->way->prev)
		em_tb[array[2]]->way = em_tb[array[2]]->way->prev;
	return (new);
}

static void		i_arr(int *array)
{
	array[1] = 0;
	array[2] = 0;
	array[3] = 0;
}

static void		mv_wh(t_lm *lm, int *array, t_em **em_tb)
{
	array[0] += lm->w_cnt;
	i_arr(array);
	while (em_tb[array[2]]->gtt_end)
		array[2]++;
}

static void		f_strt(t_ws **curr, t_ws **new, int *array)
{
	(*curr)->nxt = (*new);
	(*curr) = (*curr)->nxt;
	array[1]++;
}

void			mm_wp(t_lm *lm, t_em **em_tb)
{
	int		array[4];
	t_ws	*chk;
	t_ws	*curr;
	t_ws	*new;

	array[0] = 0;
	while (em_dn(em_tb, lm))
	{
		chk = n_ws(NULL, NULL);
		curr = chk;
		mv_wh(lm, array, em_tb);
		while (array[1] < array[0])
		{
			if (array[3] >= lm->max_ems)
				break ;
			if (array[2] == lm->ems)
				break ;
			if ((new = em_mvt(lm, em_tb, array, chk)))
				f_strt(&curr, &new, array);
			array[2]++;
		}
		rm_o_w(chk);
		ft_putstr("\n");
	}
}