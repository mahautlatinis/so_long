/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 12:13:20 by malatini          #+#    #+#             */
/*   Updated: 2021/06/28 08:29:34 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include "./mlx/mlx.h"
# define ERROR -1
# define DONE 0
# define SUCCESS 1
# define BUFFER_SIZE 1
# define M 64
# define A 97
# define W 119
# define D 100
# define S 115
# define ESC 65307
# define SAND 0xF5DCA0
# define BLACK 0xFF000000
# define RIGHT 65361
# define LEFR 65363
# define ESC 65307

/* structure d'une image (voir 42 docs)*/
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

/* structure d'une fenetre (voir 42 docs) */
typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

/* Structure pour checks map */
typedef struct s_map
{
	int	lines;
	int	correct_lines;
	int	col_max;
}				t_map;

typedef struct s_player
{
	t_data	img;
	int		x;
	int		y;
	float	smooth_x;
	float	smooth_y;
	bool	is_found;
}				t_player;

/* Liste chainee pour les collectibles */
typedef struct s_collectible_elem
{
	int							pos_x;
	int							pos_y;
	bool						is_touched;
	struct s_collectible_elem	*next;
}				t_collectible_elem;

typedef struct s_collectible_list
{
	t_collectible_elem	*first;
	bool				is_empty;
	t_data				img;
}				t_collectible_list;

/* Liste chainee pour les exits */
typedef struct s_exit_elem
{
	int					pos_x;
	int					pos_y;
	bool				is_touched;
	struct s_exit_elem	*next;
}				t_exit_elem;

typedef struct s_exit_list
{
	t_data		img;
	t_exit_elem	*first;
	bool		is_empty;
}				t_exit_list;

typedef struct s_v
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	an;
}				t_v;

/* Variables necessaires pour le rapport de proportionnalite */
typedef struct s_draw
{
	int		x;
	int		y;
	float	r_x;
	float	r_y;
	int		color;
	int		pos_x;
	int		pos_y;
	int		p_data_x;
	int		p_data_y;
}				t_draw;

/* Structure generale pour ne perdre aucune reference */
typedef struct s_mem
{
	t_player			*p;
	t_collectible_list	*c;
	t_exit_list			*e;
	t_data				*data;
	t_data				*floor;
	t_data				*bottom;
	t_vars				*vars;
	t_map				*map;
	char				**map2d;
	int					moves;
	unsigned int		frame;
}				t_mem;

void				draw_map(t_mem *mem);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
int					render_next_frame(t_mem *mem);
int					g_init(t_mem *mem);
int					key_hook(int keycode, t_mem *mem);
int					check_empty_line(char *line);
char				*ft_strdup_2d(char *s1, t_mem *mem);
int					initialize_2dmap(int fd, char **argv, t_mem *mem);
int					get_next_line_minimap(int fd, char **line, t_mem *mem);
void				max_x(char *line, int i, t_mem *mem);
int					read_all_map_lines(int fd, char **line, t_mem *mem);
int					check_zero_neighbors(char **map2d, t_mem *mem,
						int i, int j);
int					check_one_neighbors(char **map2d, t_map *map, int i, int j);
int					check_map_walls(char **map2d, t_mem *mem);
int					check_lines_minimap(t_map *map, char *line, int l);
int					mini_map_all_chars(int fd, char *buffer, t_mem *mem);
int					check_mini_map_chars(char *line, t_mem *mem);
int					check_so_long_extension(char *str, char *ext);
int					check_map(char *map, char *argv);
int					valid_char_mini_map(char c);
char				**clean_2dmap(t_map *map, char **map2d);
int					is_player_char(t_mem *mem, char **map2d, int i, int j);
int					ft_strlen(const char *s);
char				*ft_strdup(char *s1, t_mem *mem);
int					ft_hasnewline(char *str);
char				*ft_prep_s(char *s, t_mem *mem);
char				*gnl_strjoin(char *s1, char *s2, t_mem *mem);
char				*ft_newline_minimap(char *s, t_mem *mem);
int					ft_isalnum(int c);
int					get_next_line_2d(int fd, char **line, t_mem *mem);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_isspace(char c);
int					c_atoi(t_map *map, char *line, int *res, int *i);
void				handle_args_error(int fd, t_mem *mem);
void				handle_fd_errors(int fd, t_mem *mem);
void				ft_putstr_fd(char *s, int fd);
void				error_gnl(int fd, char **line, t_mem *mem);
void				error_read(t_mem *mem, char *buffer, int b_read);
bool				is_empty_c_list(t_collectible_list *lst);
int					c_list_length(t_collectible_list *lst);
void				push_end_c_list(t_mem *mem, int x, int y);
void				free_c_list(t_collectible_list *lst);
bool				is_empty_e_list(t_exit_list *lst);
int					e_list_length(t_exit_list *lst);
void				push_end_e_list(t_mem *mem, int x, int y);
void				free_e_list(t_exit_list *lst);
void				initialize_struct_map(t_map *map);
t_mem				*initialize_mem(void);
t_data				*initialize_data(void);
void				free_mem(t_mem *mem);
int					is_empty_line(char *str);
void				handle_error_gnl2(char *line, t_mem *mem, int *i);
void				init_player(t_mem *mem);
void				init_collectibles_list(t_collectible_list *lst);
void				init_exits_list(t_exit_list *lst);
int					is_exit_char(t_mem *mem, char **map2d, int i, int j);
void				check_elements(t_mem *mem);
int					is_collectible_char(t_mem *mem, char **map2d, int i, int j);
void				init_player_images(t_mem *mem);
void				init_collectibles_images(t_mem *mem);
void				init_exit_images(t_mem *mem);
void				init_floor_images(t_mem *mem);
void				init_bottom_images(t_mem *mem);
void				so_long_loop(t_mem *mem);
void				set_background(t_data *data, t_mem *mem);
void				draw_elements(t_mem *mem);
void				draw_player(t_mem *mem);
void				draw_on_img(t_data *img, t_data *s_img,
						int startX, int startY);
int					get_pixel(t_data *img, int x, int y);
void				set_pixel(t_data *data, int x, int y, int color);
void				init_exits_images(t_mem *mem);
int					close_clean(t_mem *mem);
void				locate_collectibles(t_mem *mem);
t_collectible_elem	*get_collectible(t_mem *mem, int i, int j);
void				is_touching_collectibles(t_mem *mem);
int					is_collectible(t_mem *mem, int i, int j);
void				set_to_true(t_mem *mem);
void				locate_exits(t_mem *mem);
int					is_exit(t_mem *mem, int i, int j);
int					c_all_touched(t_mem *mem);
void				free_resolutions(int *res_x, int *res_y);
void				init_data(t_mem *mem);
void				init_vars(t_mem *mem);
void				init_map(t_mem *mem);
void				check_res(t_mem *mem, int *res_x, int *res_y);
void				ft_putnbr_fd(int n, int fd);
t_data				load_image(void *mlx, char *path);
int					render_next_frame_bonus(t_mem *mem);
void				so_long_loop_bonus(t_mem *mem);
void				draw_elements_bonus(t_mem *mem);
void				g_init_bonus(t_mem *mem);
void				first_read(t_mem *mem, char **argv, char **line);
void				second_read(char **line, char **argv, t_mem *mem);
void				initialize_struct_map(t_map *map);
int					initialize_2dmap(int fd, char **line, t_mem *mem);
int					n_size(int n);
char				*create_string(char *str, long nb, long length, long sign);
char				*ft_itoa(int n, t_mem *mem);
void				display_moves_bonus(t_mem *mem);
int					key_hook_bonus(int keycode, t_mem *mem);
void				handle_bad_char(t_mem *mem, char *line);
char				*malloc_buffer(t_mem *mem);
void				no_collectible(t_mem *mem, int found);
void				no_exit_found(t_mem *mem, int found);
void				check_line(char *line, t_mem *mem, int *i);
void				main_errors(t_mem *mem);
int					to_upper(int c);
int					to_upper(int c);
int					key_hook(int key, t_mem *m);
void				ft_bzero(void *s, int n);
int					count_correct_lines(t_mem *mem);

#endif
