
#include "lem_in.h"

static void		fh_strt(t_lm *lm)
{
	if (lm->way->name)
		free(lm->way->name);
}

static void		free_wsd(t_ph *wsd)
{
	if (wsd)
		free(wsd);
}

static void		f_strt(t_lm *lm)
{
	t_lnk	*wst;
	t_ph	*wsd;

	if (lm)
	{
		if (lm->em_count_on_trk)
			free(lm->em_count_on_trk);
		while (lm->way)
		{
			if (lm->way->lnk)
			{
				while (lm->way->lnk)
				{
					wst = lm->way->lnk;
					lm->way->lnk = lm->way->lnk->nxt;
					if (wst)
						free(wst);
				}
			}
			fh_strt(lm);
			wsd = lm->way;
			lm->way = lm->way->nxt;
			free_wsd(wsd);
		}
	}
}

void			error_e(t_lm *lm, int error)
{
	f_strt(lm);
	if (error)
		ft_putstr("ERROR\n");
	exit(0);
}

void			w_d(t_w *way)
{
	t_w	*wst;

	if (way)
	{
		while (way->prev)
		{
			if (way->prev)
				way = way->prev;
		}
		while (way)
		{
			wst = way;
			way = way->nxt;
			free(wst);
			wst = NULL;
		}
	}
}