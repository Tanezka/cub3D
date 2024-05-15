#include "../../inc/cub3d.h"
#include <stdio.h>

void	scale_and_cut(void *text, int width, int height, int start_pos[2], int area[2])
{
	int	scale_y;
}

void	handle_neg_scale(int *x, int *width, int *y, int *height)
{
	if (*height < 0)
	{
		*y += *height;
		*height *= -1;
	}
	if (*width < 0)
	{
		*x += *width;
		*width *= -1;
	}
}

void	draw_rectangle (void *frame, int x, int y, int color, int height)
{
	int	limit_x;
	int	limit_y;
    int width;

    width = 15;
	handle_neg_scale(&x, &width, &y, &height);
	limit_x = x + width;
	limit_y = y + height;
	while(y < limit_y)
	{
		while(x < limit_x)
		{
			pixel(frame, x, y, color);
			x++;
		}
		x = limit_x - width;
		y++;
	}
}

void	draw_line (void *frame, int index, int color, int height)
{
	int	limit_y;
	int	y;

	printf("bana gelen height %d\n", height);
	y = S_HEIGHT/2 - height;
	limit_y = S_HEIGHT/2 + height;
	while(y <= limit_y)
	{
		pixel(frame, index, y, color);
		y++;
	}
}
