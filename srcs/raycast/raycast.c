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

void	x_pos_y_pos(t_cub *cube, int angle, int index)
{

}

void	x_neg_y_pos(t_cub *cube, int angle, int index)
{

}

void	x_neg_y_neg(t_cub *cube, int angle, int index)
{

}

void	x_pos_y_neg(t_cub *cube, int angle, int index)
{

}

void	east_ray(t_cub *cube, int index)
{
	double		i;
	double		distance;
	double		value;
	double		x_pos;

	i = cube->pos.x;
	while (cube->map[(int)cube->pos.y][(int)i] != '1')
	{
		i++;
	}
	distance = i - cube->pos.x;

	ft_printf("%d\n", index);


	value =  540 -((distance - 1) * 54); 
	draw_rectangle(cube->frame, index * 15, 540, 15, value);
	draw_rectangle(cube->frame, index * 15, 540, 15, -value);
}

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
			return (9999999);
		return (fabs((x - cube->pos.x) / cos(radian)));
    }
	//printf("Patladı: X %f Y %f\n", x, y);
	return (9999999);
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
			return (9999999);
		return (fabs((x - cube->pos.x) / cos(radian)));
    }
	//printf("Patladı: X %f Y %f\n", x, y);
	return (9999999);
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
			return (9999999);
		return (fabs((x - cube->pos.x) / cos(radian)));
    }
	//printf("Patladı: X %f Y %f\n", x, y);
	return (9999999);
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
		    return (9999999);
	    return (fabs((x - cube->pos.x) / cos(radian)));
    }
	//printf("Patladı: X %f Y %f\n", x, y);
	return (9999999);
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
			return (9999999);
		return (fabs((y - cube->pos.y) / sin(radian)));
    }
	//printf("Patladı: X %f Y %f\n", x, y);
	return (9999999);
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
			return (9999999);
		return (fabs((y - cube->pos.y) / sin(radian)));
    }
	//printf("Patladı: X %f Y %f\n", x, y);
	return (9999999);
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
			return (9999999);
		return (fabs((y - cube->pos.y) / sin(radian)));
    }
	//printf("Patladı: X %f Y %f\n", x, y);
	return (9999999);
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
			return (9999999);
		return (fabs((y - cube->pos.y) / sin(radian)));
    }
	//printf("Patladı: X %f Y %f\n", x, y);
	return (9999999);
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
		if (cube->map[(int)(y - 0.0000001f)] && cube->map[(int)(y - 0.0000001f)][(int)x])
		{
			if (cube->map[(int)(y - 0.0000001f)][(int)x] == '1')
			{
				printf("Vert: wall detected at X %f Y %f\n", x, y);
				return (fabs((x - cube->pos.x) / fabs(cos(radian))));
			}
			while(cube->map[(int)(y - 0.0000001f)] && cube->map[(int)(y - 0.0000001f)][(int)x] && cube->map[(int)(y - 0.0000001f)][(int)x] != '1')
			{
				x += -1;
				y += (tan(radian));
			}
			printf("Vert: wall detected at X %f Y %f\n", x, y);
			if (!(cube->map[(int)(y - 0.0000001f)] && cube->map[(int)(y - 0.000001f)][(int)x]))
				return (9999999);
			return (fabs((x - cube->pos.x) / cos(radian)));
		}
	}
	else
	{
		x += (int)x - x + 1;
		y -= tan(radian) * (x - cube->pos.x);
		if (cube->map[(int)(y - 0.0000001f)] && cube->map[(int)(y - 0.0000001f)][(int)x])
		{
			if (cube->map[(int)(y - 0.0000001f)][(int)x] == '1')
			//printf("X %f Y %f\n", x, y);
			return (fabs((x - cube->pos.x) / cos(radian)));
			while(cube->map[(int)(y - 0.0000001f)] && cube->map[(int)(y - 0.0000001f)][(int)x] && cube->map[(int)(y - 0.0000001f)][(int)x] != '1')
			{
				x += 1;
				y -= fabs(tan(radian));
			}
			printf("Vert: wall detected at X %f Y %f\n", x, y);
			if (!(cube->map[(int)(y - 0.0000001f)] && cube->map[(int)(y - 0.000001f)][(int)x]))
				return (9999999);
			return (fabs((x - cube->pos.x) / cos(radian)));
		}
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
	if (check_height(cube ,(y - (0.0000001 * multip))) && check_width(cube, x))
	{
		if (cube->map[(int)(y - (0.0000001f * multip))][(int)x] == '1')
		{
		//	printf("y %f x%f\n", y, x);
			return (fabs(y - cube->pos.y) / fabs(sin(radian)));
		}
		while ((check_height(cube ,(y - (0.0000001 * multip))) && check_width(cube, x) && cube->map[(int)(y - 0.000001f)][(int)x] != '1'))
		{
			y += -1 * multip;
			x += 1 / (tan(radian));
		}
		//printf("Hori: wall detected at X %f Y %f\n", x, y);
		if (!(check_height(cube ,(y - (0.0000001 * multip))) && check_width(cube, x)))
			return (9999999);
		return (fabs((y - cube->pos.y) / fabs(sin(radian))));
	}
	return (9999999);
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
        if (vert < hori)
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
        if (vert < hori)
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
        if (vert < hori)
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
        if (vert < hori)
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
	if (vert < hori)
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

int	raycasting(t_cub *cube)
{
	int			x;
	int			y;
	int			z;
	void		*test;

	//ft_bzero(cube->img.addr, 1920 * 1080 * cube->img.bits_per_pixel / 8);
	fill_black(cube);
    cube->map_width = 10;
    cube->map_height = 6;
	caster(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->frame->img, 0, 0);
	//printf("0000000000\n");
	//width = 15;
	//height = 15;
	//mlx_get_data_addr(cube->text[3].img.img, &x, &y, &z);
	//printf("%d, %d, %d\n", x, y, z);
	//mlx_put_image_to_window(cube->mlx, cube->win, cube->img.img, 0, 0);
	return (1);
}
