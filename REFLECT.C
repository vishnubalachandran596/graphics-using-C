#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

    void xaxis_line_reflect()
    {
      int xa,ya,xb,yb;
      int x1,y1,x2,y2;
      printf("\n\n\nEnter the coordinates of line AB:");
      printf("\nA:");
      scanf("%d %d",&xa,&ya);
      printf("\nB:");
      scanf("%d %d",&xb,&yb);
      setcolor(4);
      line(xa+getmaxx()/2,getmaxy()/2-ya,xb+getmaxx()/2,getmaxy()/2-yb);
      x1=xa;
      y1=(-ya);
      x2=xb;
      y2=(-yb);
      sleep(2);
      setcolor(7);
      line(x1+getmaxx()/2,getmaxy()/2-y1,x2+getmaxx()/2,getmaxy()/2-y2);
    }
    void yaxis_line_reflect()
    {
      int xa,ya,xb,yb;
      int x1,y1,x2,y2;
      printf("\n\n\nEnter the coordinates of line AB:");
      printf("\nA:");
      scanf("%d %d",&xa,&ya);
      printf("\nB:");
      scanf("%d %d",&xb,&yb);
      setcolor(4);
      line(xa+getmaxx()/2,getmaxy()/2-ya,xb+getmaxx()/2,getmaxy()/2-yb);
      x1=(-xa);
      y1=ya;
      x2=(-xb);
      y2=yb;
      sleep(2);
      setcolor(7);
      line(x1+getmaxx()/2,getmaxy()/2-y1,x2+getmaxx()/2,getmaxy()/2-y2);
    }
    void xyaxis_line_reflect()
    {
      int xa,ya,xb,yb;
      int x1,y1,x2,y2;
      printf("\n\n\nEnter the coordinates of line AB:");
      printf("\nA:");
      scanf("%d %d",&xa,&ya);
      printf("\nB:");
      scanf("%d %d",&xb,&yb);
      setcolor(4);
      line(xa+getmaxx()/2,getmaxy()/2-ya,xb+getmaxx()/2,getmaxy()/2-yb);
      x1=ya;
      y1=xa;
      x2=yb;
      y2=xb;
      sleep(2);
      setcolor(7);
      line(x1+getmaxx()/2,getmaxy()/2-y1,x2+getmaxx()/2,getmaxy()/2-y2);
    }
    void _xyaxis_line_reflect()
    {
      int xa,ya,xb,yb;
      int x1,y1,x2,y2;
      printf("\n\n\nEnter the coordinates of line AB:");
      printf("\nA:");
      scanf("%d %d",&xa,&ya);
      printf("\nB:");
      scanf("%d %d",&xb,&yb);
      setcolor(4);
      line(xa+getmaxx()/2,getmaxy()/2-ya,xb+getmaxx()/2,getmaxy()/2-yb);
      x1=(-ya);
      y1=(-xa);
      x2=(-yb);
      y2=(-xb);
      sleep(2);
      setcolor(7);
      line(x1+getmaxx()/2,getmaxy()/2-y1,x2+getmaxx()/2,getmaxy()/2-y2);
    }
    void xaxis_pt_reflect()
    {
      int xa,ya;
      int x1,y1;
      printf("\n\n\nEnter the coordinates of the point:");
      printf("\nA:");
      scanf("%d %d",&xa,&ya);
      setcolor(4);
      putpixel(xa+getmaxx()/2,getmaxy()/2-ya,4);
      x1=xa;
      y1=(-ya);
      sleep(2);
      setcolor(7);
      putpixel(getmaxx()/2+x1,getmaxy()/2-y1,7);
    }
    void yaxis_pt_reflect()
    {
      int xa,ya;
      int x1,y1;
      printf("\n\n\nEnter the coordinates of the point:");
      printf("\nA:");
      scanf("%d %d",&xa,&ya);
      setcolor(4);
      putpixel(xa+getmaxx()/2,getmaxy()/2-ya,4);
      x1=(-xa);
      y1=ya;
      sleep(2);
      setcolor(7);
      putpixel(x1+getmaxx()/2,getmaxy()/2-y1,7);
    }
    void xyaxis_pt_reflect()
    {
      int xa,ya;
      int x1,y1;
      printf("\n\n\nEnter the coordinates of the point:");
      printf("\nA:");
      scanf("%d %d",&xa,&ya);
      setcolor(4);
      putpixel(xa+getmaxx()/2,getmaxy()/2-ya,4);
      x1=ya;
      y1=xa;
      sleep(2);
      setcolor(7);
      putpixel(x1+getmaxx()/2,getmaxy()/2-y1,7);
    }
    void _xyaxis_pt_reflect()
    {
      int xa,ya;
      int x1,y1;
      printf("\n\n\nEnter the coordinates of the point:");
      printf("\nA:");
      scanf("%d %d",&xa,&ya);
      setcolor(4);
      putpixel(xa+getmaxx()/2,getmaxy()/2-ya,4);
      x1=(-ya);
      y1=(-xa);
      sleep(2);
      setcolor(7);
      putpixel(x1+getmaxx()/2,getmaxy()/2-y1,7);
    }
    void main()
    {
      int ch,n;
      int gmode,gdriver=DETECT,xmax,ymax;
      clrscr();
      do
      {
        initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
        xmax=getmaxx();
        ymax=getmaxy();
        line(0,ymax/2,xmax,ymax/2);
        line(xmax/2,0,xmax/2,ymax);
        printf("\nREFLECTION\n******\n");
        printf("\n1-Reflection of line about X axis\n");
        printf("2-Reflection of line about Y axis\n");
	printf("3-Reflection of line about Y=X axis\n");
	printf("4-Reflection of line about Y=-X axis\n");
        printf("5-Reflection of point about X axis\n");
        printf("6-Reflection of point about Y axis\n");
	printf("7-Reflection of point about Y=X axis\n");
	printf("8-Reflection of point about Y=-X axis\n");
        printf("9-Exit");
        printf("\nEnter your option:");
        scanf("%d",&n);
        switch(n)
        {
          case 1:xaxis_line_reflect();
    	     break;
          case 2:yaxis_line_reflect();
    	     break;
          case 3:xyaxis_line_reflect();
    	     break;
          case 4:_xyaxis_line_reflect();
    	     break;
	  case 5:xaxis_pt_reflect();
    	     break;
          case 6:yaxis_pt_reflect();
    	     break;
          case 7:xyaxis_pt_reflect();
    	     break;
          case 8:_xyaxis_pt_reflect();
    	     break;
          case 9:break;
          default:break;
        }
        printf("\nDo you want to continue?(0/1)");
        scanf("%d",&ch);
      }while(ch==1);
      getch();
      closegraph();
    }
