/*
Write C++ program to draw a concave polygon and fill it with desired color using scan fill algorithm.
*/

#include<iostream>
#include<graphics.h>
#include<stdlib.h>
using namespace std;
class POINT
{
  public:
	int x,y;
};
class poly
{
  private:
	int vertices; // no. of vertices of polygon
	POINT vertex[10];
	int xmin,xmax,ymin,ymax;
	int ISarray[20]; //size of intersection array
	int count;
	int currentx;
  public:
	void readVertices();
	void drawPolygon();
	void scanline();
	void intersection(int currenty);
	void fill(int currenty);
};

void poly::intersection(int currenty)
{
  int x1,y1,x2,y2;
  int temp;
  count = 0;
  float m; //slope
  for(int i=0 ; i<vertices ; i++)
  {
	x1 = vertex[i].x;
	y1 = vertex[i].y;
	x2 = vertex[i+1].x;
	y2 = vertex[i+1].y;

	if(y2 < y1)
	{
	  temp = y1;
	  y1 = y2;
	  y2 = temp;

	  temp = x1;
	  x1 = x2;
	  x2 = temp;
	}

	if(currenty >= y1 && currenty <= y2)
	{
	  if((y1 - y2) == 0)
	  currentx = x1;
	  else
	  {
		currentx = ((x2-x1)*(currenty-y1)/(y2-y1));
		currentx = currentx + x1;
	  }
	  if(currentx >= xmin && currentx <= xmax)
		ISarray[count++] = currentx;
	}
  }
}

void poly::fill(int currenty)
{
  //draw Polygon
  for(int i = 0;i < vertices;i++)
  {
	line(vertex[i].x,vertex[i].y,vertex[i+1].x,vertex[i+1].y);
  }
  delay(100);
  //fill Polygon
  for(int i=0 ; i < count-1;i++)
  {
	line(ISarray[i],currenty,ISarray[i+1],currenty);
  }
}

void poly::scanline()
{
  //to find xmin,xmax,ymin,ymax
  ymin = ymax = vertex[0].y;
  xmin = xmax = vertex[0].x;
  for(int i=1 ; i<vertices ; i++)
  {
	if(ymin > vertex[i].y)
	 ymin = vertex[i].y;
	if(ymax < vertex[i].y)
	 ymax = vertex[i].y;
	if(xmin > vertex[i].x)
	 xmin = vertex[i].x;
	if(xmax < vertex[i].x)
	 xmax = vertex[i].x;
  }
  int currenty = ymin + 1;
  while(currenty <= ymax)
  {
	intersection(currenty);
	delay(100);
	fill(currenty);
	currenty++;
  }
}

void poly::drawPolygon()
{
  for(int i=0;i<vertices;i++)
  {
	line(vertex[i].x,vertex[i].y,vertex[i+1].x,vertex[i+1].y);
  }

}

void poly::readVertices()
{
 int i;

  cout<<"\nEnter the no. of vertices of polygon:: ";
  cin>>vertices;
  if (vertices<=2)
  {
	cout<<"Polygon should have three vertices minimum ";
	getch();
	exit(0);
  }
  for(i =0 ; i < vertices;i++)
  {
	cout<<"Enter the x and y coordinates of vertex :: "<<(i+1)<<" ";
	cin>>vertex[i].x>>vertex[i].y;
  }
  //store first point at the last location of array
  vertex[i].x = vertex[0].x;
  vertex[i].y = vertex[0].y;
}

int main()
{
    poly p;
  p.readVertices();

  int gd = DETECT,gm;
  initgraph(&gd,&gm,NULL);
  cleardevice();
  p.drawPolygon();
  p.scanline();
  getch();
  closegraph();
  return 0;
}
