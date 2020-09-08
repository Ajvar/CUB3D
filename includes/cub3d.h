/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:02:46 by jcueille          #+#    #+#             */
/*   Updated: 2020/09/08 17:53:15 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./struct.h"
# include "./libft_light.h"
# include "./get_next_line.h"

# ifdef __unix__

typedef enum	e_keycode {
	UP = 119,
	DOWN = 115,
	LEFT = 97,
	RIGHT = 100,
	KEY_RIGHT = 65363,
	KEY_LEFT = 65361,
	ESC = 65307,
	KEY_SHIFT = 65505,
	KEY_ONE = 38,
	KEY_TWO = 233
}				t_keycode;

# endif

# define KEYPRESS 2
# define KEYPRESS_MASK 1
# define KEYRELEASE 3
# define KEYRELEASE_MASK 2

/*
** PARSING
*/
char	**ft_split(char const *s, char c);
void	ft_res_correction(t_info *map, t_mlx *mlx);
void	ft_error(char *s);
void	ft_space_skip(char *s, int *i);
void	ft_check_id(char *line, t_info *info_map, int fd);
char	**ft_map_filler(t_info *info_map);
void	ft_is_map_valid(t_info *info_map);
void	ft_error_map_fill(char **tmp, char *s, int i);
void	ft_error_free(char *s, t_info *info_map);
void	ft_parse(t_info *info_map, int *fd);

/*
** GAME
*/
void	ft_save(t_info *info_map, t_mlx *mlx);
void	ft_sprite_count(t_info *info_map);
void	ft_pos_sprite(t_info *info_map, t_master *master);
void	ft_sprite(t_master *m, t_sprite *sprite, int sprite_nb);
int		ft_check_rgb(int nb[4], int n);
void	ft_free_tab(char **tab);
int		ft_rgb_space(char **tab, int i);
char	*ft_strcpy(char *dest, char *src);
int		get_next_line(int fd, char **line);
int		ft_pos_check(char c);
int		ft_print_img(t_master *master);
int		ft_resolution(char *s, t_info *info_map);
int		ft_texture_path_north_south(char *s, t_info *info_map);
int		ft_texture_path_west_east(char *s, t_info *info_map);
int		ft_colors(char *s, t_info *info_map);
void	ft_init_struct_infomap(t_info *info_map);
void	ft_init_struct_move(t_move *move);
void	ft_init_struct_player(t_player *player);
void	ft_init_ray(t_ray *ray);
void	ft_init_pos_player(t_master *master, t_player *player);
void	ft_init_master(t_info *info_map, t_mlx *mlx,
t_player *player, t_master *master);
void	ft_fill_master(t_move *move, t_ray *ray, t_master *master, int save);
int		ft_exit_prog(t_master *master);
int		ft_key_release(int keycode, t_move *move);
int		ft_key_press(int keycode, t_move *move);
void	ft_player_pos_cam(t_master *master, t_player *player);
void	ft_raycaster(t_master *master, t_ray *ray);
int		ft_init_texture(t_master *master, t_texture *texture, int w, int h);
void	ft_texture(t_master *master, t_ray *ray, int x);
void	ft_draw_wall_color(t_master *master, t_ray *ray, int x);
void	ft_draw_texture_sn(t_master *m, t_texture *texture,
t_text_info *text_i, int x);
void	ft_draw_texture_ew(t_master *m, t_texture *texture,
t_text_info *text_i, int x);
int					ft_exit_prog_esc(t_master *m);
void ft_error_parse(char *s, t_info *info_map, char *line, int fd);

#endif
