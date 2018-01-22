#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void scale_rect(int xa,int ya,int xb,int yb,int xc,int yc,int xd,int yd,int sx,int sy)
{
  int x1,y1,x2,y2,x3,y3,y4,x4;
  setcolor(4);
  line(xa+320,240-ya,xb+320,240-yb);
  line(xb+320,240-yb,xc+320,240-yc);
  line(xc+320,240-yc,xd+320,240-yd);
  line(xd+320,240-yd,xa+320,240-ya);
  x1=xa*sx;
  y1=ya*sy;
  x2=xb*sx;
  y2=yb*sy;
  x3=xc*sx;
  y3=yc*sy;
  x4=xd*sx;
  y4=yd*sy;
  sleep(2);
  setcolor(7);
  line(x1+320,240-y1,x2+320,240-y2);
  line(x2+320,240-y2,x3+320,240-y3);
  line(x3+320,240-y3,x4+320,240-y4);
  line(x4+320,240-y4,x1+320,240-y1);
}
void main()
{
  int xa,ya,xb,yb,xc,yc,xd,yd,sx,sy;
  int gmode,gdriver=DETECT,xmax,ymax;
  clrscr();
  initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
  xmax=getmaxx();
  ymax=getmaxy();
  line(0,ymax/2,xmax,ymax/2);
  line(xmax/2,0,xmax/2,ymax);
  printf("\n\n\nEnter the coordinates of the rectangle ABCD");
  printf("\nA:");scanf("%d %d",&xa,&ya);
  printf("\nB:");scanf("%d %d",&xb,&yb);
  printf("\nC:");scanf("%d %d",&xc,&yc);
  printf("\nD:");scanf("%d %d",&xd,&yd);
  printf("\nEnter X and Y scaling factors:");
  scanf("%d %d",&sx,&sy);
  scale_rect(xa,ya,xb,yb,xc,yc,xd,yd,sx,sy);
  getch();
  closegraph();
}