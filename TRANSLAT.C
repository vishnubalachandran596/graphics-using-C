#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
void scale_line()
{
  int xa,ya,xb,yb,sx,sy;
  int x1,y1,x2,y2;
  printf("\n\n\nEnter the coordinates of line AB:");
  printf("\nA:");
  scanf("%d %d",&xa,&ya);
  printf("\nB:");
  scanf("%d %d",&xb,&yb);
  printf("\nEnter X and Y translation distance:");
  scanf("%d %d",&sx,&sy);
  setcolor(4);
  line(xa+320,240-ya,xb+320,240-yb);
  x1=xa+sx;
  y1=ya+sy;
  x2=xb+sx;
  y2=yb+sy;
  sleep(2);
  setcolor(7);
  line(x1+320,240-y1,x2+320,240-y2);
}
void scale_rect()
{
  int xa,ya,xb,yb,xc,yc,xd,yd,sx,sy;
  int x1,y1,x2,y2,x3,y3,y4,x4;
  printf("\n\n\nEnter the coordinates of rectangle ABCD");
  printf("\nA:");scanf("%d %d",&xa,&ya);
  printf("\nB:");scanf("%d %d",&xb,&yb);
  printf("\nC:");scanf("%d %d",&xc,&yc);
  printf("\nD:");scanf("%d %d",&xd,&yd);
  printf("\nEnter X and Y translation distance:");
  scanf("%d %d",&sx,&sy);
  setcolor(4);
  line(xa+320,240-ya,xb+320,240-yb);
  line(xb+320,240-yb,xc+320,240-yc);
  line(xc+320,240-yc,xd+320,240-yd);
  line(xd+320,240-yd,xa+320,240-ya);
  x1=xa+sx;
  y1=ya+sy;
  x2=xb+sx;
  y2=yb+sy;
  x3=xc+sx;
  y3=yc+sy;
  x4=xd+sx;
  y4=yd+sy;
  sleep(2);
  setcolor(7);
  line(x1+320,240-y1,x2+320,240-y2);
  line(x2+320,240-y2,x3+320,240-y3);
  line(x3+320,240-y3,x4+320,240-y4);
  line(x4+320,240-y4,x1+320,240-y1);
}
void scale_trg()
{
  int xa,ya,xb,yb,xc,yc,sx,sy;
  int x1,y1,x2,y2,x3,y3;
  printf("\n\n\nEnter the coordinates of triangle ABC");
  printf("\nA:");scanf("%d %d",&xa,&ya);
  printf("\nB:");scanf("%d %d",&xb,&yb);
  printf("\nC:");scanf("%d %d",&xc,&yc);
  printf("\nEnter X and Y translation distance:");
  scanf("%d %d",&sx,&sy);
  setcolor(4);
  line(xa+320,240-ya,xb+320,240-yb);
  line(xb+320,240-yb,xc+320,240-yc);
  line(xc+320,240-yc,xa+320,240-ya);
  x1=xa+sx;
  y1=ya+sy;
  x2=xb+sx;
  y2=yb+sy;
  x3=xc+sx;
  y3=yc+sy;
  sleep(2);
  setcolor(7);
  line(x1+320,240-y1,x2+320,240-y2);
  line(x2+320,240-y2,x3+320,240-y3);
  line(x3+320,240-y3,x1+320,240-y1);
}
void main()
{
  int ch,n;
  int gmode,gdriver=DETECT,xmax,ymax;
  clrscr();
  do
  {
    initgraph(&gdriver,&gmode,"../BGI");
    xmax=getmaxx();
    ymax=getmaxy();
    line(0,ymax/2,xmax,ymax/2);
    line(xmax/2,0,xmax/2,ymax);
    printf("\nSCALING\n******\n");
    printf("\nEnter object to be scaled");
    printf("\n1-LINE\n2-TRIANGLE\n3-RECTANGLE\n4-EXIT");
    printf("\nEnter your option:");
    scanf("%d",&n);
    switch(n)
    {
      case 1:scale_line();
	     break;
      case 2:scale_trg();
	     break;
      case 3:scale_rect();
	     break;
      default:break;
    }
    printf("\nDo you want to continue?(0/1)");
    scanf("%d",&ch);
  }while(ch==1);
  getch();
  closegraph();
}

