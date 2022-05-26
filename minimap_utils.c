/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 01:47:20 by alistair          #+#    #+#             */
/*   Updated: 2022/05/26 01:53:52 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	color_rect(t_data *data, t_vec_i pix_pos, int color)
{
	t_vec_i	square;
	t_rect	temp;

	square.x = (SCREEN_WIDTH / 4) / data->map.x;
	square.y = (SCREEN_HEIGHT / 4) / data->map.y;
	temp.width = square.x;
	temp.height = square.y;
	temp.x0 = pix_pos.x + (SCREEN_WIDTH - data->minimap.width) - 20;
	temp.y0 = pix_pos.y + 20;
	temp.color = color;
	render_rect(&data->image, temp);
}

int	render_rect(t_image *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y0;
	while (i < rect.y0 + rect.height)
	{
		j = rect.x0;
		while (j < rect.x0 + rect.width)
			cub3d_mlx_pixel_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	select_square_color(t_data *data, t_vec_i map, t_vec_i pix_pos)
{
	if (data->map.info[map.y][map.x].visible == 1)
	{
		if (data->map.data[map.y][map.x] == MAP_TYPE_EMPTY_SPACE)
			color_rect(data, pix_pos, create_trgb(0, data->map.flr.r, \
				data->map.flr.g, data->map.flr.b));
		if (data->map.data[map.y][map.x] == MAP_TYPE_WALL || \
			data->map.data[map.y][map.x] == MAP_TYPE_WALL_SPRITE)
			color_rect(data, pix_pos, 0xFFFFFFF);
		if (data->map.data[map.y][map.x] == MAP_TYPE_DOOR)
			color_rect(data, pix_pos, 0xCC6600);
	}
}