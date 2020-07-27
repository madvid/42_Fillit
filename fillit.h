/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:42:07 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/16 17:27:34 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define POINT "\033[38;5;15;48;2;192;192;192m.\033[0m"
# define A "\033[38;5;15;48;2;255;102;102mA\033[0m"
# define B "\033[38;5;15;48;2;255;140;102mB\033[0m"
# define C "\033[38;5;15;48;2;255;179;102mC\033[0m"
# define D "\033[38;5;15;48;2;255;217;102mD\033[0m"
# define E "\033[38;5;15;48;2;255;255;102mE\033[0m"
# define F "\033[38;5;15;48;2;217;255;102mF\033[0m"
# define G "\033[38;5;15;48;2;179;255;102mG\033[0m"
# define H "\033[38;5;15;48;2;140;255;102mH\033[0m"
# define I "\033[38;5;15;48;2;102;255;102mI\033[0m"
# define J "\033[38;5;15;48;2;102;255;140mJ\033[0m"
# define K "\033[38;5;15;48;2;102;255;179mK\033[0m"
# define L "\033[38;5;15;48;2;102;255;217mL\033[0m"
# define M "\033[38;5;15;48;2;102;255;255mM\033[0m"
# define N "\033[38;5;15;48;2;102;217;255mN\033[0m"
# define O "\033[38;5;15;48;2;102;179;255mO\033[0m"
# define P "\033[38;5;15;48;2;102;140;255mP\033[0m"
# define Q "\033[38;5;15;48;2;102;102;255mQ\033[0m"
# define R "\033[38;5;15;48;2;140;102;255mR\033[0m"
# define S "\033[38;5;15;48;2;179;102;255mS\033[0m"
# define T "\033[38;5;15;48;2;217;102;255mT\033[0m"
# define U "\033[38;5;15;48;2;255;102;255mU\033[0m"
# define V "\033[38;5;15;48;2;255;102;140mV\033[0m"
# define W "\033[38;5;15;48;2;255;255;255mW\033[0m"
# define X "\033[38;5;15;48;2;179;179;179mX\033[0m"
# define Y "\033[38;5;15;48;2;102;102;102mY\033[0m"
# define Z "\033[38;5;15;48;2;015;015;015mZ\033[0m"

typedef struct		s_point
{
	int		y;
	int		x;
}					t_point;

typedef struct		s_tetri
{
	t_point			point[4];
	char			c;
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_mappy
{
	char			**map;
	int				size_map;
}					t_mappy;

int					ft_check(int *fd);
int					ft_check_form(char *buffer);
int					ft_check_nb_blocs(char *buffer);
int					ft_check_tetramino(char **buffer);
void				ft_free_tabint(int **table, int nb_l);
void				ft_table_int_init(int **table, int nb_l, int nb_c);
int					**ft_table_int(int nb_l, int nb_c);
int					ft_blocs_updown(char *buffer, int i);
int					ft_blocs_leftright(char *buffer, int i);
int					ft_table_neighbours(int **table, char *buffer);
void				ft_set_point(char *buffer, t_tetri *new_element);
t_tetri				*lstadd(char *buffer, t_tetri *element, char c);
t_tetri				*ft_parsing(char *av);
int					map_min(int	size);
char				**mapper(int size);
int					bck_trck(t_tetri *lst_tetri, t_mappy map);
void				ft_display(t_mappy map);
void				ft_free_grid(t_mappy *grid);
void				ft_display_unicorn(t_mappy map);
void				ft_free_chain(t_tetri *lst);

#endif
