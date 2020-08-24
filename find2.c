
#include "lem_in.h"

static int		*ip_len(t_ws *wys, t_lm *lm, int *em_count)
{
	t_ws	*wst;
	int		*len_of_trk;
	int		a;

	if (!(len_of_trk = (int *)malloc(sizeof(int) * lm->w_cnt)))
	{
		r_w(wys);
		if (em_count)
			free(em_count);
		error_e(lm, 1);
	}
	wst = wys;
	a = -1;
	while (wst && a++ < lm->w_cnt - 1)
	{
		len_of_trk[a] = wst->way->len;
		wst = wst->nxt;
	}
	return (len_of_trk);
}

static int		*ic_em(t_lm *lm,
		int *l_oa, int *ems, t_ws *wys)
{
	int		*em_count_on_trk;
	int		a;

	*l_oa = 0;
	*ems = lm->ems;
	if (!(em_count_on_trk = (int *)malloc(sizeof(int) * lm->w_cnt)))
	{
		r_w(wys);
		error_e(lm, 1);
	}
	a = -1;
	while (a++ < lm->w_cnt - 1)
		em_count_on_trk[a] = 0;
	return (em_count_on_trk);
}

static int		ex_n(t_lm *lm, int **em_count_on_trk,
		int l_oa, int **len_of_trk)
{
	free(lm->em_count_on_trk);
	lm->em_count_on_trk = *em_count_on_trk;
	lm->l_oa = l_oa;
	free(*len_of_trk);
	return (1);
}

static int		ex_z(int **em_count_on_trk, int **len_of_trk)
{
	if (*em_count_on_trk)
		free(*em_count_on_trk);
	if (*len_of_trk)
		free(*len_of_trk);
	return (0);
}

int				fl_a(t_lm *lm, t_ws *wys)
{
	int		*len_of_trk;
	int		*em_count;
	int		a;
	int		ems;
	int		l_oa;

	em_count = ic_em(lm, &l_oa, &ems, wys);
	len_of_trk = ip_len(wys, lm, em_count);
	while (ems > 0)
	{
		a = 0;
		while (a < lm->w_cnt)
		{
			if (len_of_trk[a] + em_count[a] < l_oa)
			{
				em_count[a]++;
				ems--;
			}
			a++;
		}
		l_oa++;
	}
	if (lm->l_oa > l_oa || !(lm->l_oa))
		return (ex_n(lm, &em_count, l_oa, &len_of_trk));
	return (ex_z(&em_count, &len_of_trk));
}