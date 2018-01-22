//PGM 6(a) GRAPHICS LAB
//Pranav P Pillai R8132
//Write a pgm to implement 
//	(a) Reflection of a point and a line

#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
    void xaxis_line_reflect()
    {
      int xa,ya,xb,yb,sx;
      int x1,y1,x2,y2;
      printf("\n\n\nEnter the coordinates of line AB:");
      printf("\nA:");
      scanf("%d %d",&xa,&ya);
      printf("\nB:");
      scanf("%d %d",&xb,&yb);
      setcolor(4);
      line(xa+320,240-ya,xb+320,240-yb);
      x1=xa;
      y1=(-ya);
      x2=xb;
      y2=(-yb);
      sleep(2);
      setcolor(7);
      line(x1+320,240-y1,x2+320,240-y2);
    }
    void yaxis_line_reflect()
    {
      int xa,ya,xb,yb,sy;
      int x1,y1,x2,y2;
      printf("\n\n\nEnter the coordinates of line AB:");
      printf("\nA:");
      scanf("%d %d",&xa,&ya);
      printf("\nB:");
      scanf("%d %d",&xb,&yb);
      setcolor(4);
      line(xa+320,240-ya,xb+320,240-yb);
      x1=(-xa);
      y1=ya;
      x2=(-xb);
      y2=yb;
      sleep(2);
      setcolor(7);
      line(x1+320,240-y1,x2+320,240-y2);
    }
    void xaxis_pt_reflect()
    {
      int xa,ya;
      int x1,y1;
      printf("\n\n\nEnter the coordinates of the point:");
      printf("\nA:");
      scanf("%d %d",&xa,&ya);
      setcolor(4);
      putpixel(xa+320,240-ya,4);
      x1=xa;
      y1=(-ya);
      sleep(2);
      setcolor(7);
      putpixel(320+x1,240-y1,7);
    }
    void yaxis_pt_reflect()
    {
      int xa,ya;
      int x1,y1;
      printf("\n\n\nEnter the coordinates of the point:");
      printf("\nA:");
      scanf("%d %d",&xa,&ya);
      setcolor(4);
      putpixel(xa+320,240-ya,4);
      x1=(-xa);
      y1=ya;
      sleep(2);
      setcolor(7);
      putpixel(x1+320,240-y1,7);
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
        printf("3-Reflection of point about X axis\n");
        printf("4-Reflection of point about Y axis\n");
        printf("5-Exit");
        printf("\nEnter your option:");
        scanf("%d",&n);
        switch(n)
        {
          case 1:xaxis_line_reflect();
    	     break;
          case 2:yaxis_line_reflect();
    	     break;
          case 3:xaxis_pt_reflect();
    	     break;
          case 4:yaxis_pt_reflect();
    	     break;
          case 5:break;
          default:break;
        }
        printf("\nDo you want to continue?(0/1)");
        scanf("%d",&ch);
      }while(ch==1);
      getch();
      closegraph();
    }
