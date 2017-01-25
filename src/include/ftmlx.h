#ifndef FTMLX_H
# define FTMLX_H

# include <mlx.h>
# include <unistd.h>

# include "dlst.h"

typedef struct			s_mlx
{
	void	*mlx;
	void	*mlx_win;
	int		win_height;
	int		win_width;
	t_dlst	keybinds;
	void	*update_var;
	void	(*f_update)(void *);
	void	*close_var;
	void	(*f_close)(void *);
	t_dlst	imglst;
	t_img	**imgs;
}						t_mlx;

/*
** t_img - mlx image
** Using img_make we get all the mlx image datas
** with mlx_get_data_addr only once and not every time
** we want to draw a single point, faster processing
** ** ******************* **
** img		- mlx image pointer
** data		- pointer to the image datas
** bbp		- bytes per point
** lsize	- line size
** end		- endian
** ** ******************* **
*/
typedef struct			s_img
{
	void	*img;
	char	*data;
	int		bbp;
	int		lsize;
	int		end;
	int		width;
	int		height;
	t_mlx	*mlx;
}						t_img;

typedef struct			s_keybind
{
	int		key;
	void	*ext;
	void	(*f)(t_mlx*, void*);
}						t_keybind;

typedef	unsigned char	t_col;

typedef union			u_rgba
{
	int		col;
	t_col	c[3];
	char	a[4];
}						t_rgba;

# endif
