/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandtn <dbrandtn@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:48:13 by dbrandtn          #+#    #+#             */
/*   Updated: 2022/07/08 14:20:55 by dbrandtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
	{
		ft_putstr_fd("Error! - Please enter one argument [username]!\n", FD_STDERR);
		return (1);
	}
	data = cub3d_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D", argv[1]);
	if (data == NULL)
	{
		ft_putstr_fd("Error! - init() failed!\n", FD_STDERR);
		return (1);
	}
	if (read_input_file(data, 1) != 0 || parse_textures(data) != 0)
	{
		ft_putstr_fd("Error! - reading the input files failed!\n", FD_STDERR);
		cub3d_cleanup(&data);
		return (1);
	}
	mlx_loop(data->mlx);
	cub3d_cleanup(&data);
	exit(0);
}
