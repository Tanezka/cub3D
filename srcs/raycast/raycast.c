/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:54:40 by bbosnak           #+#    #+#             */
/*   Updated: 2024/04/01 16:54:41 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../library/mlx/mlx.h"
#include <math.h>
#include <stdio.h>

int		check_ray_collision(t_cub *cube, double x, double y)
{
	double	x_pos;
	double	y_pos;

	x_pos = cube->pos.x + x;
	y_pos = cube->pos.y + y;
	if (cube->map[(int)round(y_pos)][(int)round(x_pos)] == '1')
	{
		printf("i found a Wall found at %f, %f\n", round(x_pos), round(y_pos));
		return (0);
	}
	else
	{
		//printf("no wall at %f, %f\n", round(x_pos), round(y_pos));
		return (1);
	}
}

void	find_wall(t_cub *cube, double radian, double *x, double *y)
{
	double	i;
	double	distance;
	double	x_multip;
	double	y_multip;

	x_multip = *x;
	y_multip = *y;
	distance = 0.5f;
	while (check_ray_collision(cube, *x, *y))
	{
		(*x) += x_multip;
		(*y) += y_multip;
	}
}

int	check_height(t_cub *cube, double h)
{
	if (cube->map_height >= (int)h && h >= 0)
		return (1);
	else
		return (0);
}

int	check_width(t_cub *cube, double	w)
{
	if (cube->map_width >= (int)w && w >= 0)
		return (1);
	else
		return (0);
}

void	draw_wall(t_cub *cube, double x, double y, double radian, int index)
{
	double	x_vector;
	double	y_vector;
	double	intersec_x;
	double	intersec_y;
	double	distance;

	if (0 < x)
		x_vector = 1.0f;
	else
		x_vector = -1.0f;
	if (0 > y)
		y_vector = 1.0f;
	else
	 	y_vector = -1.0f;
	//printf("calculation: %f\n", (round(cube->pos.x + x) - cube->pos.x) * tan(radian) * y_vector);
	if ((round(cube->pos.x + x) - cube->pos.x) * tan(radian) * y_vector > round(y))
	{
		printf("x is last x:%f\n", x);
		distance = fabs((round(cube->pos.x + x) - cube->pos.x) / cos(radian));
		printf("distance %f\n", distance);
	}
	else
	{
		printf("y is last %f\n", y);
		distance = fabs((round(cube->pos.y + y) - cube->pos.y) / sin(radian));
		printf("distance %f\n", distance);
	}
	draw_rectangle(cube->frame, index * 15, 540, 15, 540 - (distance - 1)* 54);
	draw_rectangle(cube->frame, index * 15, 540, 15, -(540 - (distance - 1)* 54));
}

double  vert_first_area(t_cub *cube, double angle, int index, double radian)
{
	double	distance;
	double	test;
	double	x;
	double	y;

	x = cube->pos.x;
	y = cube->pos.y;
    x += (int)(x + 1) - x;
    y -= tan(radian) * (x - cube->pos.x);
	if (check_height(cube, y - 0.000001f) && check_width(cube, x))
	{
		if (cube->map[(int)(y - 0.000001f)][(int)x] == '1')
		//printf("X %f Y %f\n", x, y);
		return (fabs((x - cube->pos.x) / cos(radian)));
	    while (check_height(cube, y - 0.000001f) && check_width(cube, x) && cube->map[(int)(y - 0.000001f)][(int)x] != '1')
		{
			x += 1;
			y -= (tan(radian));
		}
		//printf("Vert: wall detected at X %f Y %f\n", x, y);
	    if (!(check_height(cube, y - 0.000001f) && check_width(cube, x)) || x > 99999)
			return ('\0');
		return (fabs((x - cube->pos.x) / cos(radian)));
    }
	//printf("Patladı: X %f Y %f\n", x, y);
	return ('\0');
}

double  vert_second_area(t_cub *cube, double angle, int index, double radian)
{
	double	distance;
	double	test;
	double	x;
	double	y;

	x = cube->pos.x;
	y = cube->pos.y;
    x -=  x - (int)(x);
    y -= tan(radian) * (x - cube->pos.x);
	if (check_height(cube, y - 0.000001f) && check_width(cube, x - 0.000001f))
	{
		if (cube->map[(int)(y - 0.000001f)][(int)(x - 0.000001f)] == '1')
		//printf("X %f Y %f\n", x, y);
		return (fabs((x - cube->pos.x) / cos(radian)));
        while (check_height(cube, y - 0.000001f) && check_width(cube, x - 0.000001f) && cube->map[(int)(y - 0.000001f)][(int)(x - 0.000001f)] != '1')
		{
			x -= 1;
			y += (tan(radian));
		}
		//printf("Vert: wall detected at X %f Y %f\n", x, y);
	    if (!(check_height(cube, y - 0.000001f) && check_width(cube, x - 0.000001f)))
			return ('\0');
		return (fabs((x - cube->pos.x) / cos(radian)));
    }
	//printf("Patladı: X %f Y %f\n", x, y);
	return ('\0');
}

double  vert_third_area(t_cub *cube, double angle, int index, double radian)
{
	double	distance;
	double	test;
	double	x;
	double	y;

	x = cube->pos.x;
	y = cube->pos.y;
    x -=  x - (int)(x);
    y -= tan(radian) * (x - cube->pos.x);
	if (check_height(cube, y) && check_width(cube, x - 0.000001f))
	{
		if (cube->map[(int)(y)][(int)(x - 0.000001f)] == '1')
		//printf("X %f Y %f\n", x, y);
		return (fabs((x - cube->pos.x) / cos(radian)));
        while (check_height(cube, y) && check_width(cube, x - 0.000001f) && cube->map[(int)y][(int)(x - 0.000001f)] != '1')
		{
			x -= 1;
			y += (tan(radian));
		}
		//printf("Vert: wall detected at X %f Y %f\n", x, y);
	    if (!(check_height(cube, y) && check_width(cube, x - 0.000001f)))
			return ('\0');
		return (fabs((x - cube->pos.x) / cos(radian)));
    }
	//printf("Patladı: X %f Y %f\n", x, y);
	return ('\0');
}

double  vert_forth_area(t_cub *cube, double angle, int index, double radian)
{
	double	distance;
	double	test;
	double	x;
	double	y;

	x = cube->pos.x;
	y = cube->pos.y;
    x += (int)(x + 1) - x;
    y -= tan(radian) * (x - cube->pos.x);
    //printf("maps x:%f y:%f*\n", cube->map_width, cube->map_height);
	//printf("X %f Y %f\n", x, y);
	if (check_height(cube, y) && check_width(cube, x))
	{
		if (cube->map[(int)(y)][(int)x] == '1')
        {
		    //printf("X %f Y %f\n", x, y);
			return (fabs((x - cube->pos.x) / cos(radian)));
        }
        while (check_height(cube, y) && check_width(cube, x) && cube->map[(int)(y)][(int)x] != '1')
		{
           // printf("check: ");
	    //printf("X %f Y %f\n", x, y);
			x += 1;
			y -= (tan(radian));
        //printf("stopp\n");
		}
        //printf("stopp\n");
		//printf("Vert: wall detected at X %f Y %f\n", x, y);
	    if (!(check_height(cube, y) && check_width(cube, x)))
		    return ('\0');
	    return (fabs((x - cube->pos.x) / cos(radian)));
    }
	//printf("Patladı: X %f Y %f\n", x, y);
	return ('\0');
}

double  hori_first_area(t_cub *cube, double angle, int index, double radian)
{
	double	distance;
	double	test;
	double	x;
	double	y;

    y = (int)(cube->pos.y);
	x = cube->pos.x - ((y - cube->pos.y) / tan(radian));
	if (check_height(cube, y) && check_width(cube, x))
	{
		if (cube->map[(int)(y - 0.000001f)][(int)x] == '1')
		//printf("X %f Y %f\n", x, y);
		return (fabs((y - cube->pos.y) / sin(radian)));
	    while (check_height(cube, y) && check_width(cube, x) && cube->map[(int)(y - 0.000001f)][(int)x] != '1')
		{
			y -= 1;
			x -= 1/tan(radian);
		}
		//printf("Hori: wall detected at X %f Y %f\n", x, y);
	    if (!(check_height(cube, y - 0.000001f) && check_width(cube, x)))
			return ('\0');
		return (fabs((y - cube->pos.y) / sin(radian)));
    }
	//printf("Patladı: X %f Y %f\n", x, y);
	return ('\0');
}

double  hori_second_area(t_cub *cube, double angle, int index, double radian)
{
	double	distance;
	double	test;
	double	x;
	double	y;

    y = (int)cube->pos.y;
	x = cube->pos.x - ((y - cube->pos.y) / tan(radian));
	if (check_height(cube, y - 0.000001f) && check_width(cube, x - 0.000001f))
	{
		if (cube->map[(int)(y - 0.000001f)][(int)(x - 0.000001f)] == '1')
		//printf("X %f Y %f\n", x, y);
		return (fabs((y - cube->pos.y) / sin(radian)));
	    while (check_height(cube, y - 0.000001f) && check_width(cube, x - 0.000001f) && cube->map[(int)(y - 0.000001f)][(int)(x - 0.000001f)] != '1')
		{
			y -= 1;
			x += 1/tan(radian);
		}
		//printf("Hori: wall detected at X %f Y %f\n", x, y);
	    if (!(check_height(cube, y - 0.000001f) && check_width(cube, x - 0.000001f)))
			return ('\0');
		return (fabs((y - cube->pos.y) / sin(radian)));
    }
	//printf("Patladı: X %f Y %f\n", x, y);
	return ('\0');
}

double  hori_third_area(t_cub *cube, double angle, int index, double radian)
{
	double	distance;
	double	test;
	double	x;
	double	y;

    y = (int)(cube->pos.y + 1);
	x = cube->pos.x - ((y - cube->pos.y) / tan(radian));
	if (check_height(cube, y) && check_width(cube, x - 0.000001f))
	{
		if (cube->map[(int)y][(int)(x - 0.000001f)] == '1')
		//printf("X %f Y %f\n", x, y);
		return (fabs((y - cube->pos.y) / sin(radian)));
	    while (check_height(cube, y) && check_width(cube, x - 0.000001f) && cube->map[(int)y][(int)x] != '1')
		{
			y += 1;
			x += 1/tan(radian);
		}
		//printf("Hori: wall detected at X %f Y %f\n", x, y);
	    if (!(check_height(cube, y) && check_width(cube, x - 0.000001f)))
			return ('\0');
		return (fabs((y - cube->pos.y) / sin(radian)));
    }
	//printf("Patladı: X %f Y %f\n", x, y);
	return ('\0');
}

double  hori_forth_area(t_cub *cube, double angle, int index, double radian)
{
	double	distance;
	double	test;
	double	x;
	double	y;

    y = (int)(cube->pos.y + 1);
	x = cube->pos.x - ((y - cube->pos.y) / tan(radian));
	if (check_height(cube, y) && check_width(cube, x))
	{
		if (cube->map[(int)y][(int)x] == '1')
		//printf("X %f Y %f\n", x, y);
		return (fabs((y - cube->pos.y) / sin(radian)));
	    while (check_height(cube, y) && check_width(cube, x) && cube->map[(int)y][(int)x] != '1')
		{
			y += 1;
			x -= 1/tan(radian);
		}
		//printf("Hori: wall detected at X %f Y %f\n", x, y);
	    if (!(check_height(cube, y) && check_width(cube, x)))
			return ('\0');
		return (fabs((y - cube->pos.y) / sin(radian)));
    }
	//printf("Patladı: X %f Y %f\n", x, y);
	return ('\0');
}

double	vertical_calculation(t_cub *cube, double angle, int index, double radian)
{
	double	distance;
	double	test;
	double	x;
	double	y;

	x = cube->pos.x;
	y = cube->pos.y;
	if (angle < 270 && angle > 90)
	{
		printf("Sol\n");
		x -= (int)x - x + 1;
		y += tan(radian) * (x - cube->pos.x);
		if (cube->map[(int)(y - 0.000001f)] && cube->map[(int)(y - 0.000001f)][(int)x])
		{
			if (cube->map[(int)(y - 0.000001f)][(int)x] == '1')
			{
				printf("Vert: wall detected at X %f Y %f\n", x, y);
				return (fabs((x - cube->pos.x) / fabs(cos(radian))));
			}
			while(cube->map[(int)(y - 0.000001f)] && cube->map[(int)(y - 0.000001f)][(int)x] && cube->map[(int)(y - 0.000001f)][(int)x] != '1')
			{
				x += -1;
				y += (tan(radian));
			}
			printf("Vert: wall detected at X %f Y %f\n", x, y);
			if (!(cube->map[(int)(y - 0.000001f)] && cube->map[(int)(y - 0.000001f)][(int)x]))
				return ('\0');
			return (fabs((x - cube->pos.x) / cos(radian)));
		}
	}
	else
	{
		x += (int)x - x + 1;
		y -= tan(radian) * (x - cube->pos.x);
		if (cube->map[(int)(y - 0.000001f)] && cube->map[(int)(y - 0.000001f)][(int)x])
		{
			if (cube->map[(int)(y - 0.000001f)][(int)x] == '1')
			//printf("X %f Y %f\n", x, y);
			return (fabs((x - cube->pos.x) / cos(radian)));
			while(cube->map[(int)(y - 0.000001f)] && cube->map[(int)(y - 0.000001f)][(int)x] && cube->map[(int)(y - 0.000001f)][(int)x] != '1')
			{
				x += 1;
				y -= fabs(tan(radian));
			}
			printf("Vert: wall detected at X %f Y %f\n", x, y);
			if (!(cube->map[(int)(y - 0.000001f)] && cube->map[(int)(y - 0.000001f)][(int)x]))
				return ('\0');
			return (fabs((x - cube->pos.x) / cos(radian)));
		}
		return(0);
	}
}


double	horizontal_calculation(t_cub *cube, double angle, int index, double radian)
{
	double	distance;
	double	multip;
	double	x;
	double	y;

	multip = 1;
	x = cube->pos.x;
	y = cube->pos.y;
	if (angle < 180 && angle > 0)
	{
		//printf("Yukarı\n");

	}
	else
	{
	//	printf("Aşağı\n");
		multip = -1;
	}
	y += ((int)y - y) * multip;
	x += (y - cube->pos.y) / tan(radian);
	//printf("test %f %f\n", fabs(y - cube->pos.y), x);
	if (check_height(cube ,(y - (0.01f * multip))) && check_width(cube, x))
	{
		if (cube->map[(int)(y - (0.01f * multip))][(int)x] == '1')
		{
		//	printf("y %f x%f\n", y, x);
			return (fabs(y - cube->pos.y) / fabs(sin(radian)));
		}
		while ((check_height(cube ,(y - (0.01f * multip))) && check_width(cube, x) && cube->map[(int)(y - 0.000001f)][(int)x] != '1'))
		{
			y += -1 * multip;
			x += 1 / (tan(radian));
		}
		//printf("Hori: wall detected at X %f Y %f\n", x, y);
		if (!(check_height(cube ,(y - (0.000001f * multip))) && check_width(cube, x)))
			return ('\0');
		return (fabs((y - cube->pos.y) / fabs(sin(radian))));
	}
	return ('\0');
}

void	hit_detect(t_cub *cube, double angle, int index, double radian)
{
	double	vert;
	double	hori;
    double  test_radian;

	test_radian = *cube->angle * 3.14159265 / 180;
    if (angle > 0 && angle < 90)
    {
        printf("First area\n");
	    vert = vert_first_area(cube, angle, index, radian);
	    hori = hori_first_area(cube, angle, index, radian);
        if ((hori == '\0' && vert != '\0') || vert < hori)
        {
			draw_line(cube->frame, index, 50000, 540 - ((vert * fabs(cos(radian - test_radian))) - 1) * 54);
		    //draw_rectangle(cube->frame, index * 15, 540, 50000, 540 - ((vert * fabs(cos(radian))) - 1)* 54);
		    //draw_rectangle(cube->frame, index * 15, 540, 50000, -(540 - ((vert * fabs(cos(radian)) - 1)* 54)));
        }
        else
        {
			draw_line(cube->frame, index, 5000000, 540 - ((hori * fabs(cos(radian - test_radian))) - 1) * 54);
		    //draw_rectangle(cube->frame, index * 15, 540, 5000000, 540 - ((hori * fabs(cos(radian))) - 1) * 54);
		    //draw_rectangle(cube->frame, index * 15, 540, 5000000, -(540 - ((hori * fabs(cos(radian)) - 1) * 54)));
        }
    }
    else if (angle > 90 && angle < 180)
    {
        printf("Second area\n");
	    vert = vert_second_area(cube, angle, index, radian);
	    hori = hori_second_area(cube, angle, index, radian);
        if ((hori == '\0' && vert != '\0') || vert < hori)
        {
			draw_line(cube->frame, index, 30000, 540 - ((vert * fabs(cos(radian-test_radian))) - 1) * 54);
		    //draw_rectangle(cube->frame, index * 15, 540, 30000, 540 - ((vert * fabs(cos(radian))) - 1)* 54);
		    //draw_rectangle(cube->frame, index * 15, 540, 30000, -(540 - ((vert * fabs(cos(radian)) - 1)* 54)));
        }
        else
        {
			draw_line(cube->frame, index, 5000000, 540 - ((hori * fabs(cos(radian-test_radian))) - 1) * 54);
		    //draw_rectangle(cube->frame, index * 15, 540, 5000000, 540 - ((hori * fabs(cos(radian))) - 1)* 54);
		    //draw_rectangle(cube->frame, index * 15, 540, 5000000, -(540 - ((hori * fabs(cos(radian)) - 1)* 54)));
        }
    }
    else if (angle > 180 && angle < 270)
    {
        printf("Third area\n");
	    vert = vert_third_area(cube, angle, index, radian);
	    hori = hori_third_area(cube, angle, index, radian);
        if ((hori == '\0' && vert != '\0') || vert < hori)
        {
			draw_line(cube->frame, index, 30000, 540 - ((vert * fabs(cos(radian-test_radian))) - 1) * 54);
		    //draw_rectangle(cube->frame, index * 15, 540, 30000, 540 - ((vert * fabs(cos(radian))) - 1)* 54);
		    //draw_rectangle(cube->frame, index * 15, 540, 30000, -(540 - ((vert * fabs(cos(radian)) - 1)* 54)));
        }
        else
        {
			draw_line(cube->frame, index, 300000, 540 - ((hori * fabs(cos(radian-test_radian))) - 1) * 54);
		    //draw_rectangle(cube->frame, index * 15, 540, 300000, 540 - ((hori * fabs(cos(radian))) - 1)* 54);
		    //draw_rectangle(cube->frame, index * 15, 540, 300000, -(540 - ((hori * fabs(cos(radian)) - 1)* 54)));
        }
    }
	else if (angle > 270 && angle < 360)
    {
        printf("Forth area\n");
	    vert = vert_forth_area(cube, angle, index, radian);
	    hori = hori_forth_area(cube, angle, index, radian);
        if ((hori == '\0' && vert != '\0') || vert < hori)
        {
			draw_line(cube->frame, index, 50000, 540 - ((vert * fabs(cos(radian - test_radian))) - 1) * 54);
		    //draw_rectangle(cube->frame, index * 15, 540, 50000, 540 - ((vert * fabs(cos(radian))) - 1)* 54);
		    //draw_rectangle(cube->frame, index * 15, 540, 50000, -(540 - ((vert * fabs(cos(radian)) - 1)* 54)));
        }
        else
        {
			draw_line(cube->frame, index, 300000, 540 - ((hori * fabs(cos(radian - test_radian))) - 1) * 54);
		    //draw_rectangle(cube->frame, index * 15, 540, 300000, 540 - ((hori * fabs(cos(radian))) - 1)* 54);
		    //draw_rectangle(cube->frame, index * 15, 540, 300000, -(540 - ((hori * fabs(cos(radian)) - 1)* 54)));
        }
    }
	printf("Vert: %f hori: %f\n", vert, hori);
    if ((hori == '\0' && vert != '\0') || vert < hori)
    {
        printf("vert %f * %f = %f\n", vert, cos(radian-test_radian), vert * (cos(radian-test_radian)));
    }
    else
    {
        printf("hori %f * %f = %f\n", hori, cos(radian-test_radian), hori * (cos(radian-test_radian)));
    }
}

void	ray_calculator(t_cub *cube, double angle, int index)
{
	static int	k = 0;
	double	distance;
	double	x;
	double	y;
	double	radian;

	if (k >= 0)
	{
		radian = (angle *(3.14159265f/180));
		hit_detect(cube, angle, index, radian);
		//printf("Distance is %f\n Radian is %f\n", distance, cos(radian));
		//draw_rectangle(cube->frame, index * 15, 540, 15, 540 - ((distance * fabs(cos(radian))) - 1)* 54);
		//draw_rectangle(cube->frame, index * 15, 540, 15, -(540 - ((distance * fabs(cos(radian)) - 1)* 54)));
		printf("=================\n");
	}
}

void	ray_casting(t_cub *cube, double angle, int index)
{
	/*if (angle > 0 && angle < 90)
		x_pos_y_pos(cube, angle, index);
	else if (angle > 90 && angle < 180)
		x_neg_y_pos(cube, angle, index);
	else if (angle > 180 && angle < 270)
		x_neg_y_neg(cube, angle, index);
	else if (angle > 270 && angle < 360)
		x_pos_y_neg(cube, angle, index);*/
	printf("angle is this %f\n", angle);
    if (angle < 0)
        angle = 360 + angle;
	if (angle == 0)
	{
		printf("wont do nothing\n");
		//east_ray(cube, index);
	}
	else if (angle == 90 || angle == -270)
	{
		printf("wont do nothing\n");
	}
	else if (angle == 180 || angle == -180)
	{
		printf("wont do nothing\n");
	}
	else if (angle == 270 || angle == -90)
	{
		printf("wont do nothing\n");
	}
	else
		ray_calculator(cube, angle, index);
	
}

/*
			typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

{
	t_data img;

	((int *)img.addr)[0];
}
*/
void	fill_black(t_cub *cube)
{
	int	i;
	int	y;

	y = 0;
	while(y < 1080)
	{
		i = 0;
		while(i < 1920)
		{
            if (y > 540)
			    pixel(cube->frame, i, y, 0xFF0000);
            else
			    pixel(cube->frame, i, y, 0xFFFF00);
			i++;
		}
		y++;
	}
}

void	caster(t_cub *cube)
{
	double i;
	double	limit;
	int	index;
	static	int	as = 0;

	index = 0;
	//*cube->angle = 30.0f;
	//cube->pos.y += 0.5f;
	i = *cube->angle + 60.0f;
	limit = *cube->angle - 60.0f;
	//i = 57;
	while (i > limit && as >= 0 && index < 6000)
	{
		ray_casting(cube, i, index);
		i -= 0.0625f;
		index++;
	}
    /*if (as > 0)
        return ;
		ray_casting(cube, 30, index);
		index++;
		ray_casting(cube, 60, index);
		index++;
		ray_casting(cube, 120, index);
		index++;
		ray_casting(cube, 150, index);
		index++;
		ray_casting(cube, 210, index);
		index++;
		ray_casting(cube, 240, index);
		index++;
		ray_casting(cube, 300, index);
		index++;
		ray_casting(cube, 330, index);*/
	as++;
}

void	draw_line_test(t_cub *cube, t_ray *ray)
{
	int i;
	int	color;

	if (*ray->side == 0)
	{
		if (*ray->dir_x == 1)
			color = 100000;
		else
			color = 1000000;
	}
	else
	{
		if (*ray->dir_y == 1)
			color = 500000;
		else
			color = 5000000;
	}
	i = *ray->draw_start;
	//printf("index: %d\ndraw_start: %d\ndraw_end: %d\n", *ray->index, *ray->draw_start, *ray->draw_end);
	//draw_line(cube->frame, 5, 5000000, 300);
	//pixel(cube->frame, 15, 15, 500000);
	while(i <= *ray->draw_end)
	{
		pixel(cube->frame, *ray->index, i, color);
		i++;
	}
}

void	ray_dda(t_cub *cube, t_ray *ray)
{
	//printf("test [%d]\n", *ray->pos_x);
	while (*ray->hit == 0)
	{
		if ((*ray->side_dist_x) < (*ray->side_dist_y))
		{
			//ft_printf("[x %d < y%d]\n", (int)*ray->side_dist_x, (int)*ray->side_dist_y);
			//printf("[x %f, y%f]\n", *ray->side_dist_x, *ray->side_dist_y);
			*ray->side_dist_x = *ray->side_dist_x + *ray->delta_dist_x;
			*ray->pos_x = *ray->pos_x + *ray->step_x;
			*ray->side = 0;
			//printf("x [%f, %f]\n", *ray->side_dist_x, *ray->delta_dist_x);
		}
		else
		{
			//printf("[x %f > y%f]\n", *ray->side_dist_x, *ray->side_dist_y);
			*ray->side_dist_y = *ray->side_dist_y + *ray->delta_dist_y;
			*ray->pos_y = *ray->pos_y + *ray->step_y;
			*ray->side = 1;
			//printf("y [%f, %f]\n", *ray->side_dist_y, *ray->delta_dist_y);
		}
		if (cube->map[*ray->pos_y][*ray->pos_x] == '1')
		{
			printf("[x %d, y%d]\n", *ray->pos_x, *ray->pos_y);
			*ray->hit = 1;
		}
	}
	//printf("[x %f, y%f]\n=================\n", *ray->side_dist_x, *ray->side_dist_y);
	//printf("test [%f, %f]\n", *ray->delta_dist_x, *ray->delta_dist_y);
	if (*ray->side == 0)
		*ray->perp_wall_dist = (*ray->side_dist_x - *ray->delta_dist_x);
	else
		*ray->perp_wall_dist = (*ray->side_dist_y - *ray->delta_dist_y);
	*ray->line_height = (int)(S_HEIGHT / *ray->perp_wall_dist);
	*ray->draw_start = -(*ray->line_height) / 2 + S_HEIGHT / 2;
	if (*ray->draw_start < 0)
		*ray->draw_start = 0;
	*ray->draw_end = *ray->line_height / 2 + S_HEIGHT / 2;
	if (*ray->draw_end >= S_HEIGHT)
		*ray->draw_end = S_HEIGHT - 1;
	draw_line_test(cube, ray);
}

void	ray_malloc(t_ray *ray)
{
	ray->dir_y = ft_calloc(1, sizeof(double));
	ray->dir_x = ft_calloc(1, sizeof(double));
	ray->pos_x = ft_calloc(1, sizeof(int));
	ray->pos_y = ft_calloc(1, sizeof(int));
	ray->side_dist_x = ft_calloc(1, sizeof(double));
	ray->side_dist_y = ft_calloc(1, sizeof(double));
	ray->delta_dist_x = ft_calloc(1, sizeof(double));
	ray->delta_dist_y = ft_calloc(1, sizeof(double));
	ray->perp_wall_dist = ft_calloc(1, sizeof(double));
	ray->step_x = ft_calloc(1, sizeof(int));
	ray->step_y = ft_calloc(1, sizeof(int));
	ray->hit = ft_calloc(1, sizeof(int));
	ray->side = ft_calloc(1, sizeof(int));
	ray->line_height = ft_calloc(1, sizeof(int));
	ray->draw_start = ft_calloc(1, sizeof(int));
	ray->draw_end = ft_calloc(1, sizeof(int));
	ray->camera_x = ft_calloc(1, sizeof(double));
	ray->index = ft_calloc(1, sizeof(int));
}

t_ray	*ray_initiator(t_cub *cube, int index)
{
	t_ray	*ray;

	ray = ft_calloc(1, sizeof(t_ray));
	ray_malloc(ray);
	*ray->index = index;
	*ray->camera_x = 2 * index / (double)S_WIDTH - 1;
	//printf("[x %f, y%f]\n", cube->pos.x, cube->pos.y);
	*ray->dir_x = (*cube->dir_x) + ((*cube->plane_x) * (*ray->camera_x));
	*ray->dir_y = (*cube->dir_y) + ((*cube->plane_y) * (*ray->camera_x));
	*ray->pos_x = (int)cube->pos.x;
	*ray->pos_y = (int)cube->pos.y;
	if (*ray->dir_x == 0)
		*ray->delta_dist_x = 1;
	else
		*ray->delta_dist_x = fabs(1 / *ray->dir_x);
	if (ray->dir_y == 0)
		*ray->delta_dist_y = 1;
	else
		*ray->delta_dist_y = fabs(1 / *ray->dir_y);
	//*ray->delta_dist_x = sqrt(1 + (*ray->dir_y * *ray->dir_y) / (*ray->dir_x * *ray->dir_x));
	//*ray->delta_dist_y = sqrt(1 + (*ray->dir_x * *ray->dir_x) / (*ray->dir_y * *ray->dir_y));
	*ray->hit = 0;
	if (*ray->dir_x < 0)
	{
		*ray->step_x = -1;
		*ray->side_dist_x = (cube->pos.x - *ray->pos_x) * *ray->delta_dist_x;
	}
	else
	{
		*ray->step_x = 1;
		*ray->side_dist_x = (*ray->pos_x + 1.0f - cube->pos.x) * *ray->delta_dist_x;
	}
	if (*ray->dir_y < 0)
	{
		*ray->step_y = -1;
		*ray->side_dist_y = (cube->pos.y - *ray->pos_y) * *ray->delta_dist_y;
	}
	else
	{
		*ray->step_y = 1;
		*ray->side_dist_y = (*ray->pos_y + 1.0 - cube->pos.y) * *ray->delta_dist_y;
	}
	//printf("[x %f, y%f]\n", *ray->side_dist_x, *ray->side_dist_y);
	ray_dda(cube, ray);
	return (ray);
}

void	fill_ray_array(t_cub *cube)
{
	int	index;

	index = 0;
	cube->ray_array = ft_calloc(S_WIDTH, sizeof(t_ray *));
	while(index < S_WIDTH)
	{
		cube->ray_array[index] = ray_initiator(cube, index);
		index++;
	}
}

void	caster_v2(t_cub *cube)
{
	fill_ray_array(cube);
}

int	raycasting(t_cub *cube)
{
	int			x;
	int			y;
	int			z;
	void		*test;

	//ft_bzero(cube->img.addr, 1920 * 1080 * cube->img.bits_per_pixel / 8);
	fill_black(cube);
	caster_v2(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->frame->img, 0, 0);
	//printf("0000000000\n");
	//width = 15;
	//height = 15;
	//mlx_get_data_addr(cube->text[3].img.img, &x, &y, &z);
	//printf("%d, %d, %d\n", x, y, z);
	//mlx_put_image_to_window(cube->mlx, cube->win, cube->img.img, 0, 0);
	return (1);
}
