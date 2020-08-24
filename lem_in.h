
#ifndef lm_IN_H
# define lm_IN_H

# include "libft.h"

typedef struct		s_lnk
{
	struct s_ph	*trk;
	int				lock;
	struct s_lnk	*nxt;
}					t_lnk;

typedef struct		s_ph
{
	char			*name;
	int				coords[2];
	int				lock;
	int				span;
	int				block_span;
	struct s_lnk	*lnk;
	struct s_ph	*nxt;
	struct s_ph	*prev;
}					t_ph;

typedef struct		s_lm
{
	struct s_ph	*way;
	struct s_ph	*start;
	struct s_ph	*end;
	int				ems;
	int				w_cnt;
	int				*em_count_on_trk;
	int				l_oa;
	int				max_ems;
}					t_lm;

typedef struct		s_w
{
	struct s_ph	*rum;
	struct s_lnk	*prev_link;
	int				len;
	struct s_w	*prev;
	struct s_w	*nxt;
}					t_w;

typedef struct		s_ws
{
	struct s_w	*way;
	int				num;
	int				delete;
	struct s_ws	*nxt;
	struct s_ws	*prev;
}					t_ws;

typedef struct		s_em
{
	int				number;
	int				gtt_end;
	struct s_w	*way;
}					t_em;

t_ph				*n_p(char *name, int x, int y);
t_lnk				*n_l(t_ph *rum);
t_w				*n_w(void);
t_ws				*n_ws(t_w *way, t_ws *prev);
t_em				*mk_em(int em_number, t_w *way);
t_em				**mk_em_tb(t_lm *lm, t_ws *way);
void				rm_em_tb(t_lm *lm, t_em **em_tb);
void				init_lm(t_lm *lm);

void				error_e(t_lm *lm, int error);
void				r_w(t_ws *wys);
void				w_d(t_w *way);
void				rm_oo_w(t_ws *wys);
void				rm_o_w(t_ws *wys);

t_w				*w_read(t_lm *lm);
void				f_w(t_w *way);
t_w				*w_s(t_w *way, t_lm *lm);
void				w_fs(t_lm *lm);
void				w_rl(t_lm *lm, t_ws *wys);

void				read_map(t_lm *lm, int ret, int fd, char **map);
void				fe_s(char **str);
int					f_ln(t_lm *lm, char *str, int ln_n);
void				bf_err(t_lm *lm, int start, int end);
void				a_map(char **map, char *str);
void				a_l(t_lm *lm, char *str);
void				load_r(t_lm *lm, char **str,
						const int *start, const int *end);
t_w				*ch_map(t_lm *lm);

int					fc_w(t_ws **wys, t_lm *lm);
void				rm_se(t_ws *wys);
void				read_tlen(t_ws *wys);
void				f_sn(t_ws *wys);
int					fl_a(t_lm *lm, t_ws *wys);
void				rm_o(t_ws **wys, t_lm *lm);
void				len_srt(t_ws **wys);

void				fm_em(t_lm *lm, t_ws *wys);
void				mv_pt(int em_number, char *rum);
void				pt_f_m(t_lm *lm, t_ws *wys);
void				pt_o_p(t_lm *lm);
int					o_p(t_lm *lm);
int					em_dn(t_em **em_tb, t_lm *lm);
void				mm_wp(t_lm *lm, t_em **em_tb);

void				em_al(t_lm *lm, t_w *first, char *map);
void				pt_em_w(t_lm *lm, t_ws *wys);
char				*ft_str2(char *s1, char *s2);
char				*ft_str1(char *s1, char *s2);

#endif