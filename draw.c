#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c)
{
    //vertical
    if ((x1 - x0) == 0)
    {
        int x = x0;
        int y;
        if (y0 <= y1)
        {
            y = y0;
        }
        else
        {
            int temp = y1;
            y1 = y0;
            y = temp;
        }
        while (y <= y1)
        {
            plot(s, c, x, y);
            y++;
        }
    }

    //horizontal
    else if (((float)(y1 - y0) / (x1 - x0)) == 0)
    {
        int x;
        int y = y0;
        if (x0 <= x1)
        {
            x = x0;
        }
        else
        {
            int temp = x1;
            x1 = x0;
            x = temp;
        }
        while (x <= x1)
        {
            plot(s, c, x, y);
            x++;
        }
    }

    //Q1 AND Q5 : 0 <= m <= 1
    else if (((float)(y1 - y0) / (x1 - x0)) <= 1 && ((float)(y1 - y0) / (x1 - x0)) > 0)
    {
        if (x0 > x1 || y0 > y1)
        {
            int temp = x0;
            x0 = x1;
            x1 = temp;
            int secondtemp = y0;
            y0 = y1;
            y1 = secondtemp;
        }

        int x = x0;
        int y = y0;
        int a = y1 - y0;
        int b = -(x1 - x0);
        int d = 2 * a + b;

        while (x <= x1)
        {
            plot(s, c, x, y);
            if (d >= 0)
            {
                y++;
                d += (2 * b);
            }
            x++;
            d += (2 * a);
        }
    }

    //Q2 and Q6: 1 <= m < infinity
    else if (((float)(y1 - y0) / (x1 - x0)) > 1)
    {
        if (x0 > x1 || y0 > y1)
        {
            int temp = x0;
            x0 = x1;
            x1 = temp;
            int secondtemp = y0;
            y0 = y1;
            y1 = secondtemp;
        }

        int x = x0;
        int y = y0;
        int a = y1 - y0;
        int b = -(x1 - x0);
        int d = a + 2 * b;

        while (y <= y1)
        {
            plot(s, c, x, y);
            if (d <= 0)
            {
                x++;
                d += (2 * a);
            }
            y++;
            d += (2 * b);
        }
    }
    //Q4 and Q8: -1 < m < 0
    else if (((float)(y1 - y0) / (x1 - x0)) >= -1 && ((float)(y1 - y0) / (x1 - x0)) < 0)
    {
        if (x0 > x1 || y0 < y1)
        {
            int temp = x0;
            x0 = x1;
            x1 = temp;
            int secondtemp = y0;
            y0 = y1;
            y1 = secondtemp;
        }

        int x = x0;
        int y = y0;
        int a = y1 - y0;
        int b = -(x1 - x0);
        int d = 2 * a - b;
        //printf("x:%d,y:%d\n", x, y);

        while (x <= x1)
        {
            plot(s, c, x, y);
            //printf("x:%d y:%d\n",x,y);
            if (d <= 0)
            {
                y--;
                d -= (2 * b);
            }
            x++;
            d += (2 * a);
        }
    }

    //Q7 and Q3 -1 < m < infinity
    else if (((float)(y1 - y0) / (x1 - x0)) < -1)
    {
        if (x0 > x1 || y0 < y1)
        {
            int temp = x0;
            x0 = x1;
            x1 = temp;
            int secondtemp = y0;
            y0 = y1;
            y1 = secondtemp;
        }

        int x = x0;
        int y = y0;
        int a = y1 - y0;
        int b = -(x1 - x0);
        int d = a - 2 * b;
        //printf("x:%d,y:%d\n", x, y);

        while (y >= y1)
        {
            plot(s, c, x, y);
            if (d >= 0)
            {
                x++;
                d += (2 * a);
            }
            y--;
            d -= (2 * b);
        }
    }
}