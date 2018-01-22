#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define ROUND(a) ((int)(a+.5))
void linedda(int xa,int ya,int xb,int yb)
{
  int dx=xb-xa,dy=yb-ya,steps,k;
  float xinc,yinc,x=xa,y=ya;
  int gdriver = DETECT, gmode,xmax,ymax;
  initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
  xmax=getmaxx();
  ymax=getmaxy();
  line(0,ymax/2,xmax,ymax/2);
  line(xmax/2,0,xmax/2,ymax);
  if(abs(dx)>abs(dy))
	steps=abs(dx);
  else
	steps=abs(dy);
  xinc=dx/(float)steps;
  yinc=dy/(float)steps;
  putpixel(ROUND(x),ROUND(y),4);
  for(k=0;k<steps;k++)
  {
	x+=xinc;
	y+=yinc;
	putpixel(ROUND(x),ROUND(y),4);
  }

  getch();
  closegraph();
}
void main()
{

  int xa,ya,xb,yb;
  clrscr();
  printf("\nEnter the starting point of the line\n");
  scanf("%d %d",&xa,&ya);
  printf("\nEnter the ending point of the line\n");
  scanf("%d %d",&xb,&yb);
  linedda((xa+320),(240-ya),(xb+320),(240-yb));
}
