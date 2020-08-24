
#include "lem_in.h"

int		main(int argc, char **argv)
{
	int		rturn;
	char	*mp;
	t_lm	lm;
	t_w	*f_wy;

	if (argc > 1 && argv[1])
		exit(0);
	else
	{
		rturn = 1;
		mp = ft_strnew(0);
		init_lm(&lm);
		if (argc == 1)
			read_map(&lm, rturn, 0, &mp);
		f_wy = ch_map(&lm);
		em_al(&lm, f_wy, mp);
		error_e(&lm, 0);
	}
}
