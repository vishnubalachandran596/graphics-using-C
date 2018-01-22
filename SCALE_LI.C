#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
#define ROUND(a) ((int)(a+.5))
void dda(int xa,int ya,int xb,int yb,int color)
{
  int dx=xb-xa,dy=yb-ya,steps,k;
  float xinc,yinc,x=xa,y=ya;
  if(abs(dx)>abs(dy))
	steps=abs(dx);
  else
	steps=abs(dy);
  xinc=dx/(float)steps;
  yinc=dy/(float)steps;
  putpixel(ROUND(x),ROUND(y),color);
  for(k=0;k<steps;k++)
  {
	x+=xinc;
	y+=yinc;
	putpixel(ROUND(x),ROUND(y),color);
  }
}
void scale(int xa,int ya,int xb,int yb,int sx,int sy)
{
  int x1,y1,x2,y2;
  dda(xa+320,240-ya,xb+320,240-yb,4);
  x1=xa*sx;
  y1=ya*sy;
  x2=xb*sx;
  y2=yb*sy;
  sleep(2);
  dda(x1+320,240-y1,x2+320,240-y2,7);
}
void main()
{
  int xa,ya,xb,yb,sx,sy;
  int gmode,gdriver=DETECT,xmax,ymax;
  clrscr();
  initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
  xmax=getmaxx();
  ymax=getmaxy();
  line(0,ymax/2,xmax,ymax/2);
  line(xmax/2,0,xmax/2,ymax);
  printf("\n\n\nEnter the starting point:");
  scanf("%d %d",&xa,&ya);
  printf("\nEnter the ending point:");
  scanf("%d %d",&xb,&yb);
  printf("\nEnter X and Y scaling factors:");
  scanf("%d %d",&sx,&sy);
  scale(xa,ya,xb,yb,sx,sy);
  getch();
  closegraph();
}