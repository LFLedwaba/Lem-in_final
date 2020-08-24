
#include "lem_in.h"

void			r_w(t_ws *wys)
{
	t_ws *wst;

	while (wys)
	{
		wst = wys;
		w_d(wys->way);
		wys = wys->nxt;
		free(wst);
		wst = NULL;
	}
}

void			rm_o_w(t_ws *wys)
{
	t_ws *wst;

	while (wys)
	{
		wst = wys;
		wys = wys->nxt;
		free(wst);
		wst = NULL;
	}
}

void			rm_oo_w(t_ws *wys)
{
	if (wys)
	{
		if (wys->way)
			w_d(wys->way);
		free(wys);
		wys = NULL;
	}
}