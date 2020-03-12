#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
using namespace std;

void cartesianCircle(int X,int Y,int r)
{
    int x,y;
    for(x=r-X; x<=r+X; x++)
    {
        y=Y+sqrt((r*r-(x-X)*(x-X)));
        putpixel(x,y, RED);
        y=Y-sqrt((r*r-(x-X)*(x-X)));
        putpixel(x,y, RED);
    }
}

void trigonometricCircle(int X,int Y,int r)
{
    int x,y,theta;
    for(theta=0; theta<=360; theta++)
    {
        x = (int)(X+(r*cos(theta)));
        y = (int)(Y+(r*sin(theta)));
        putpixel(x,y, RED);
    }
}

int main()
{
    int gd=DETECT, gm,x,y,r,ch;
    initgraph(&gd,&gm, ".C:\\TURBOC3\\BGI");
    cout<<"Enter the coordinates of center and the radius : "<<endl;
    cin>>x>>y>>r;
    cout<<"Enter 1 : Cartesian 2 : Trigonometric "<<endl;
    cin>>ch;
    if(ch == 1)
        cartesianCircle(x,y,r);
    else if(ch == 2)
        trigonometricCircle(x,y,r);
    else
         cout<<"Wrong Choice !"<<endl;
    getch();
    closegraph();
}
