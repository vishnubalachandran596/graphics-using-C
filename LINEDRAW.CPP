#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#define round(x) (int)(x+0.5)


void dda(int,int,int,int);

int ex(int x){
	return(x+(getmaxx()/2));
}

int ey(int y){
	return((getmaxy()/2)-y);
}



int linebres(int xa,int ya,int xb,int yb)
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
    putpixel(ex(xa),ey(ya),4);
    ya++;
    }
    while(ya!=yb);
   getch();
   return 0;
   }//if ends

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
	 putpixel(ex(x),ey(y),4);
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
	      putpixel(ex(x),ey(y),4);
	     }//m>0 positive slope
    }
    else //if m<0 negative slope
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
       putpixel(ex(x),ey(y),4);
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
	    putpixel(ex(x),ey(y),4);
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
	   putpixel(ex(x),ey(y),4);
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
	      putpixel(ex(x),ey(y),4);
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
      putpixel(ex(x),ey(y),4);
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
	 putpixel(ex(x),ey(y),4);
      }
    }
  }
  getch();
 closegraph();
return 0;
}

void dda(int xa,int ya,int xb,int yb)
{
  int dx,dy,steps,k;
    float xinc,yinc,x,y;
  dx=xb-xa;
    dy=yb-ya;

    if( abs(dx) > abs(dy) )
     steps=abs(dx);
    else
     steps=abs(dy);

    xinc=dx/(float)steps;
    yinc=dy/(float)steps;

    x=xa;
    y=ya;


    putpixel(ex(round(x)),ey(round(y)),WHITE);

    for(k=0;k<steps;k++)
     { x=x+xinc;
       y=y+yinc;

       putpixel(ex(round(x)),ey(round(y)),RED);
     }



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
  setcolor(BLUE);
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
  printf("\n DDA METHOD");
  dda(xa,ya,xb,yb);
  getch();
  clrscr();
  getch();
   setcolor(GREEN);
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    printf("\n BRESENHAMS METHOD");
    linebres(xa,ya,xb,yb);

  getch();
}
