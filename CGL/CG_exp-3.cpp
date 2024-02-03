// Draw pattern using DDA line and Bresenham circle

#include <iostream>
#include <graphics.h>
using namespace std;

class DDA
{
	int x1,y1,x2,y2;
	public:
	DDA(int xx1,int yy1,int xx2,int yy2)
	{
		x1=xx1;
		y1=yy1;
		x2=xx2;
		y2=yy2;
	}
	void read(){
		cout <<"Enter x and y coordinates of start point:: ";
		cin >> x1>> y1;
		cout <<"Enter x and y coordinates of end point:: ";
		cin >> x2>> y2;
	}
	void drawline();
};
void DDA::drawline()
{
	float dx = x2-x1;
	float dy = y2-y1;

	float length;
	if ( abs(dx) >= abs(dy) )
		length = abs(dx);
	else
		length = abs(dy);

	float xi = dx/length;
	float yi = dy/length;

	float x = x1;
	float y = y1;
	for(int i=1;i<=length;i++)
	{
		putpixel(x,y,WHITE);
		x += xi;
		y += yi;
	}
}
class brcircle
{
	int r,xc,yc;
public:
	brcircle(int rr,int x1, int y1)
	{
		r = rr;
		xc= x1;
		yc= y1;
	}
	void read()
	{
		cout <<"Enter the radius: ";
		cin >> r;
		cout <<"Enter the x and y coordinates: ";
		cin >> xc>>yc;
	}
	void drawCircle();
	void plot8WaySymmetry(int,int);
};

void brcircle :: plot8WaySymmetry(int x,int y)
{
	putpixel(x+xc,y+yc,WHITE);
	putpixel(y+yc,x+xc,WHITE);
	putpixel(xc-x,y+yc,WHITE);
	putpixel(y+yc,xc-x,WHITE);
	putpixel(x+xc,yc-y,WHITE);
	putpixel(yc-y,x+xc,WHITE);
	putpixel(xc-x,yc-y,WHITE);
	putpixel(yc-y,xc-x,WHITE);
}
void brcircle::drawCircle(){
	int x=0,y=r;
	int S = 3 - 2*r;
	putpixel(xc,yc,WHITE);
	while(x<=y){
		if (S<=0){
			S = S+4*x+6;
			x++;

		}
		else{
			S = S +4*(x-y)+10;
			x++;
			y--;
		}

		plot8WaySymmetry(x,y);

	}
}

int main()
{
	
	int gd = DETECT, gm;
	initgraph(&gd,&gm,NULL);
	// To draw first shape
	brcircle ci(50,120,120),co(100,120,120);
	DDA l1(34,170,120,20),l2(206,170,120,20),l3(206,170,30,170);
	ci.drawCircle();
	co.drawCircle();
	l1.drawline();
	l2.drawline();
	l3.drawline();
	// To draw second shape
	brcircle c1(45,350,350);
	DDA l11(250,300,450,300),l22(450,300,450,400),l33(450,400,250,400),l44(250,400,250,300);
	DDA l55(350,300,450,350),l66(450,350,350,400),l77(350,400,250,350),l88(250,350,350,300);
	c1.drawCircle();
	l11.drawline();
	l22.drawline();
	l33.drawline();
	l44.drawline();
	l55.drawline();
	l66.drawline();
	l77.drawline();
	l88.drawline();
	getch();
	closegraph();
	return 0;
}

