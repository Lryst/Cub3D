/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 23:56:58 by lryst             #+#    #+#             */
/*   Updated: 2020/06/14 00:00:18 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	get_inf(t_cub3d *cub, t_texture *tex, void *mlx_ptr, int **tab)
{
	if (mlx_ptr == NULL)
		ft_error("mlx_ptr failed");
	if (tex->texture != NULL)
		ft_error("address textures failed");
	if (!(tex->texture = mlx_xpm_file_to_image(mlx_ptr, tex->path,
	&tex->width, &tex->height)))
	{
		write(1, "\n------>   ", 11);
		write(1, "bad path", 8);
		write(1, "   <------\n\n", 12);
		close_prog(cub);
	}
	*tab = (int*)mlx_get_data_addr(tex->texture, &tex->bits_per_pixel,
	&tex->size_line, &tex->endian);
	free(tex->path);
}

void	set_img(t_cub3d *cub)
{
	if (cub->no.path != NULL)
		get_inf(cub, &cub->no, cub->mlx_ptr, &cub->tab_textures[0]);
	if (cub->ea.path != NULL)
		get_inf(cub, &cub->ea, cub->mlx_ptr, &cub->tab_textures[1]);
	if (cub->we.path != NULL)
		get_inf(cub, &cub->so, cub->mlx_ptr, &cub->tab_textures[2]);
	if (cub->so.path != NULL)
		get_inf(cub, &cub->we, cub->mlx_ptr, &cub->tab_textures[3]);
	if (cub->s.path != NULL)
		get_inf(cub, &cub->s, cub->mlx_ptr, &cub->tab_textures[4]);
}
