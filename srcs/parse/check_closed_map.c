/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:30:35 by tkaraaga          #+#    #+#             */
/*   Updated: 2024/05/18 14:30:35 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static bool	visit(t_cub *cube, int x, int y, bool **visited)
{
	bool	closed;

	if (x < 0 || y < 0 || x >= cube->map_width || y >= cube->map_height)
		return (false);
	if (cube->map[y][x] == '1' || visited[y][x] == true)
		return (true);
	else
		visited[y][x] = true;
	closed = true;
	closed = visit(cube, x + 1, y, visited) && closed;
	closed = visit(cube, x - 1, y, visited) && closed;
	closed = visit(cube, x, y + 1, visited) && closed;
	closed = visit(cube, x, y - 1, visited) && closed;
	return (closed);
}

int	check_closed_map(t_cub *cube)
{
	int		x;
	int		y;
	int		i;
	bool	closed;
	bool	**visited;

	x = (int)cube->pos.x;
	y = (int)cube->pos.y;
	visited = ft_calloc(cube->map_height + 1, sizeof(bool *));
	if (!visited)
		return (ft_printf("Error\nMemory allocation failed"), 0);
	i = -1;
	while (++i < cube->map_height)
	{
		visited[i] = ft_calloc(cube->map_width + 1, sizeof(bool));
		if (!visited[i])
			return (ft_printf("Error\nMemory allocation failed"), 0);
	}
	closed = visit(cube, x, y, visited);
	free_visit(visited, cube->map_height);
	if (!closed)
		return (error_message("Map is not closed"));
	return (1);
}
