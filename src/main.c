/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:22:52 by lryst             #+#    #+#             */
/*   Updated: 2020/03/06 15:28:40 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
int deal_key(int key, void *param)
{
    ft_putchar('X');
    return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	parsing(open(av[1], O_RDONLY));
	
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "coucou");
    mlx_pixel_put(mlx_ptr, win_ptr, 250,250, 0xFFFFFF);
    mlx_key_hook(win_ptr, deal_key, (void *)0);
    mlx_loop(mlx_ptr);
	
	//printf("%d\n", atoi("223,45,0"));
	//system("leaks a.out");
}