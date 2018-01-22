#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void linebres(int xa,int ya,int xb,int yb)
{
  int dx=abs(xa-xb),dy=abs(ya-yb);
  int p=(2*dy)-dx;
  int twodx=2*dx,twodxdy=2*(dx-dy),yend;
  int twody=2*dy,twodydx=2*(dy-dx);
  int x,y,xend;
  float m;
  int xmax,ymax;
  xmax=getmaxx();
  ymax=getmaxy();
  line(0,ymax/2,xmax,ymax/2);
  line(xmax/2,0,xmax/2,ymax);
  if(dx==0)
   {if(ya>yb)
     {y=ya;
     ya=yb;
     yb=y;}
    do{
    putpixel(xa+320,240-ya,4);
    ya++;
    }
    while(ya!=yb);
   getch();
   return 0;
   }
   m=(dy/dx);
  if(m<=1)
  {
      m=((yb-ya)/(xb-xa));
     if(m>0)
	 {
	   p=(2*dy)-dx;
	   if(xa>xb)
	      {
		  x=xb;
		  y=yb;
		  xend=xa;
	      }
	   else
	      {
		 x=xa;
		 y=ya;
		 xend=xb;
	      }
	 putpixel(x+320,240-y,4);
	 while(x<xend)
	     {
	      x++;
	      if(p<0)
	      p+=twody;
	      else
	       {
		y++;
		p+=twodydx;
	       }
	      putpixel(x+320,240-y,4);
	     }//m>0 positive slope
    }
    else
       {
	  p=(2*dy)-dx;
	  if(xa>xb)
	     {
		x=xb;
		y=yb;
		xend=xa;
	     }
	  else
	     {
		x=xa;
		y=ya;
		xend=xb;
	     }
	 putpixel(x+320,240-y,4);
	 while(x<xend)
	   {
	    x++;
	    if(p<0)
	       p+=twody;
	    else
	      {
	       y--;
	       p+=twodydx;
	      }
	    putpixel(x+320,240-y,4);
	   }
    }
}

  else //m>1
  {
         m=((yb-ya)/(xb-xa));
         if(m>0)
	  {
            p=((2*dx)-dy);
            if(ya>yb)
            {
	          y=yb;
	          x=xb;
	          yend=ya;
	    }
           else
	     {
	          y=ya;
	          x=xa;
	          yend=yb;

	     }
           putpixel(x+320,240-y,4);
           while(y<yend)
           {
              y++;
              if(p<0)
                  p+=twodx;
              else
	       {
                 x++;
                 p+=twodxdy;
	       }
              putpixel(x+320,240-y,4);
           }
   }
    else
     {
      p=((2*dx)-dy);
      if(ya>yb)
       {
	    y=yb;
	    x=xb;
	    yend=ya;
       }
     else
      {
	    y=ya;
	    x=xa;
	    yend=yb;
      }
      putpixel(x+320,240-y,4);
      while(y<yend)
       {
         y++;
         if(p<0)
            p+=twodx;
         else
	  {
            x--;
            p+=twodxdy;
	  }
         putpixel(x+320,240-y,4);
      }
    }
  }
  getch();
 // closegraph();
}
void main()
{
  int xa,xb,ya,yb;
  int gdriver = DETECT, gmode;
  initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
  clrscr();
  printf("\nEnter the starting point\n");
  scanf("%d %d",&xa,&ya);
  printf("\nEnter the ending point\n");
  scanf("%d %d",&xb,&yb);
  linebres(xa,ya,xb,yb);


  getch();
}
