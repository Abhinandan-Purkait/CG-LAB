#include<iostream>
#include<graphics.h>
using namespace std;

void boundaryFill(int x, int y, int fill_color,int boundary_color)
{
    if(getpixel(x, y) != boundary_color &&
       getpixel(x, y) != fill_color)
    {
        putpixel(x, y, fill_color);
        boundaryFill(x + 1, y, fill_color, boundary_color);
        boundaryFill(x, y + 1, fill_color, boundary_color);
        boundaryFill(x - 1, y, fill_color, boundary_color);
        boundaryFill(x, y - 1, fill_color, boundary_color);
    }
}

void midPointCircle(int X, int Y, int r)
{
    int x = r;
    int y = 0;
    int p = 1-r;
    while (x >= y)
    {
        putpixel(X + x, Y + y, 7);
        putpixel(X + y, Y + x, 7);
        putpixel(X - y, Y + x, 7);
        putpixel(X - x, Y + y, 7);
        putpixel(X - x, Y - y, 7);
        putpixel(X - y, Y - x, 7);
        putpixel(X + y, Y - x, 7);
        putpixel(X + x, Y - y, 7);
        if (p <= 0)
        {
            y += 1;
            p += 2*y + 1;
        }

        if (p > 0)
        {
            x -= 1;
            p -= 2*x + 1;
        }
    }
    boundaryFill(X,Y,WHITE,7);
}

void midPointCircleColored(int X, int Y, int r)
{
    int x = r;
    int y = 0;
    int p = 1-r;

    line(X,Y,x+X,y+Y);
    line(X,Y,x+X,-y+Y);
    line(X,Y,-x+X,-y+Y);
    line(X,Y,-y+X,x+Y);
    line(X,Y,y+X,-x+Y);
    //line(X,Y,-y+X,-x+Y);

    while (x >= y)
    {
        putpixel(X + x, Y + y, BLUE);
        putpixel(X + y, Y + x, RED);
        putpixel(X - y, Y + x, YELLOW);
        putpixel(X - x, Y + y, LIGHTGRAY);
        putpixel(X - x, Y - y, LIGHTMAGENTA);
        putpixel(X - y, Y - x, GREEN);
        putpixel(X + y, Y - x, DARKGRAY);
        putpixel(X + x, Y - y, WHITE);
        if (p <= 0)
        {
            y += 1;
            p += 2*y + 1;
        }
        if (p > 0)
        {
            x -= 1;
            p -= 2*x + 1;
        }
    }
    line(X,Y,x+X,y+Y);
    line(X,Y,-x+X,y+Y);
    line(X,Y,x+X,-y+Y);
    line(X,Y,-x+X,-y+Y);
}

int main()
{
	int gd=DETECT, gm, error, x, y, r;
	initgraph(&gd,&gm, ".C:\\TURBOC3\\BGI");

	cout<<"Enter radius of circle: ";
	cin>>r;

	cout<<"Enter co-ordinates of center(x and y): ";
	cin>>x>>y;
	//midPointCircle(x, y, r);
	midPointCircleColored(x, y, r);
    getch();
    closegraph();
	return 0;
}

