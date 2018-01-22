#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void circle_poly(int xc,int yc,int r)
{
  int x1,x2,a,b,c,x,y;
  int gmode,gdriver=DETECT,xmax,ymax;
  initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
  xmax=getmaxx();
  ymax=getmaxy();
  line(0,ymax/2,xmax,ymax/2);
  line(xmax/2,0,xmax/2,ymax);
  x1=xc-r;
  x2=xc+r;
  for(x=x1;x<x2;x++)
  {
    c=sqrt(pow(r,2)-pow(xc-x,2));
    y=yc+c;
    putpixel(x+320,240-y,4);
    y=yc-c;
    putpixel(x+320,240-y,4);
  }
  getch();
  closegraph();
}
void circle_plot(int xc,int yc,int x,int y);
void circle_mid(int xc,int yc,int r)
{
  int x=0;
  int y=r;
  int p=1-r;
  int gmode,gdriver=DETECT,xmax,ymax;
  initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
  xmax=getmaxx();
  ymax=getmaxy();
  line(0,ymax/2,xmax,ymax/2);
  line(xmax/2,0,xmax/2,ymax);
  circle_plot(xc,yc,x,y);
  while(x<y)
  {
    x++;
    if(p<0)
      p+=(2*x)+1;
    else
    {
      y--;
      p+=(2*(x-y))+1;
    }
    circle_plot(xc,yc,x,y);
  }
  getch();
  closegraph();
}
void circle_plot(int xc,int yc,int x,int y)
{
  putpixel(xc+x+320,240-(yc+y),5);
  putpixel(xc-x+320,240-(yc+y),5);
  putpixel(xc+x+320,240-(yc-y),5);
  putpixel(xc-x+320,240-(yc-y),5);
  putpixel(xc+y+320,240-(yc+x),5);
  putpixel(xc-y+320,240-(yc+x),5);
  putpixel(xc+y+320,240-(yc-x),5);
  putpixel(xc-y+320,240-(yc-x),5);
}
void circle_trg(int xc,int yc,int r)
{
  int gmode,gdriver=DETECT,xmax,ymax;
  int a,b,c,x,y,i;
  initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
  xmax=getmaxx();
  ymax=getmaxy();
  line(0,ymax/2,xmax,ymax/2);
  line(xmax/2,0,xmax/2,ymax);
  for(i=0;i<=360;i++)
  {
    a=r*cos(i);
    x=xc+a;
    b=r*sin(i);
    y=yc+b;
    putpixel(x+320,240-y,4);
  }
  getch();
  closegraph();
}
void main()
{
  int xc,yc,r,a,b;
  clrscr();
  printf("\nEnter the center coordinates of the circle:");
  scanf("%d %d",&xc,&yc);
  printf("\nEnter the radius of the circle:");
  scanf("%d",&r);
  do
  {
    printf("\nEnter your opton\n");
    printf("\n1-polynomial\n2-trignometric\n3-mid point\n4-exit");
    scanf("%d",&a);
    switch(a)
    {
      case 1:circle_poly(xc,yc,r);
	     break;
      case 2:circle_trg(xc,yc,r);
	     break;
      case 3:circle_mid(xc,yc,r);
	     break;
      default:break;
    }
    printf("\nDo you want to continue??(0/1)");
    scanf("%d",&b);
  }while(b);
  getch();
}
