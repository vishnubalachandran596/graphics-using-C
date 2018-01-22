#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
    void xaxis_shear()
    {
      int xa,ya,xb,yb,sx;
      int x1,y1,x2,y2;
      printf("\n\n\nEnter the coordinates of line AB:");
      printf("\nA:");
      scanf("%d %d",&xa,&ya);
      printf("\nB:");
      scanf("%d %d",&xb,&yb);
      printf("\nEnter X axis shear factor:");
      scanf("%d",&sx);
      setcolor(4);
      line(xa+320,240-ya,xb+320,240-yb);
      x1=xa+(sx*ya);
      y1=ya;
      x2=xb+(sx*yb);
      y2=yb;
      sleep(2);
      setcolor(7);
      line(x1+320,240-y1,x2+320,240-y2);
    }
    void yaxis_shear()
    {
      int xa,ya,xb,yb,sy;
      int x1,y1,x2,y2;
      printf("\n\n\nEnter the coordinates of line AB:");
      printf("\nA:");
      scanf("%d %d",&xa,&ya);
      printf("\nB:");
      scanf("%d %d",&xb,&yb);
      printf("\nEnter X axis shear factor:");
      scanf("%d",&sy);
      setcolor(4);
      line(xa+320,240-ya,xb+320,240-yb);
      x1=xa;
      y1=ya+(xa*sy);
      x2=xb;
      y2=yb+(xb*sy);
      sleep(2);
      setcolor(7);
      line(x1+320,240-y1,x2+320,240-y2);
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
        printf("\nSCALING\n******\n");
        printf("\nEnter shear reference");
        printf("\n1-X axis shear\n2-Y axis shear\n3-Exit");
        printf("\nEnter your option:");
        scanf("%d",&n);
        switch(n)
        {
          case 1:xaxis_shear();
    	     break;
          case 2:yaxis_shear();
    	     break;
          case 3:break;
          default:break;
        }
        printf("\nDo you want to continue?(0/1)");
        scanf("%d",&ch);
      }while(ch==1);
      getch();
      closegraph();
    }
