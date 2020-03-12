#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
using namespace std;

void symmetricCircle(int X,int Y,int r)
{
    int x=0,y=r;
    int d = 3 - 2*r;
    while(x<=(int)(r/sqrt(2)))
    {
        if(d >= 0)
        {
            x=x+1;
            y=y-1;
            d=d+4*(x-y)+10;
        }
        else
        {
            x=x+1;
            d=d+4*x+6;
        }
        putpixel(x+X,y+Y,RED);
        putpixel(-x+X,y+Y,RED);
        putpixel(x+X,-y+Y,RED);
        putpixel(-x+X,-y+Y,RED);
        putpixel(y+X,x+Y,RED);
        putpixel(-y+X,x+Y,RED);
        putpixel(y+X,-x+Y,RED);
        putpixel(-y+X,-x+Y,RED);
    }
}

void symmetricCircleColored(int X,int Y,int r)
{
    int x=0,y=r;
    int d = 3 - 2*r;
    while(x<=(int)(r/sqrt(2)))
    {
        if(d >= 0)
        {
            x=x+1;
            y=y-1;
            d=d+4*(x-y)+10;
        }
        else
        {
            x=x+1;
            d=d+4*x+6;
        }
        putpixel(x+X,y+Y,RED);
        putpixel(-x+X,y+Y,BLUE);
        putpixel(x+X,-y+Y,GREEN);
        putpixel(-x+X,-y+Y,WHITE);
        putpixel(y+X,x+Y,LIGHTGRAY);
        putpixel(-y+X,x+Y,LIGHTCYAN);
        putpixel(y+X,-x+Y,LIGHTMAGENTA);
        putpixel(-y+X,-x+Y,YELLOW);
    }
}

int main()
{
    int gd=DETECT, gm,x,y,r,ch;
    initgraph(&gd,&gm, ".C:\\TURBOC3\\BGI");
    cout<<"Enter the coordinates of center and the radius : "<<endl;
    cin>>x>>y>>r;
    cout<<"Enter 1 : Symmetric Circle 2 : Symmetric Circle Colored "<<endl;
    cin>>ch;
    if(ch == 1)
        symmetricCircle(x,y,r);
    else if(ch == 2)
        symmetricCircleColored(x,y,r);
    else
         cout<<"Wrong Choice !"<<endl;
    getch();
    closegraph();
}
