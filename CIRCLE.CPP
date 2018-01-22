#include <graphics.h>
#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <math.h>

void poly(int x,int y,int r);
void trig(int x, int y,int r);
void midpt(int xc,int yc,int r);
void plotpts(int xc,int yc,int x,int y);

int ex(int x){
	return(x+(getmaxx()/2));
}

int ey(int y){
	return((getmaxy()/2)-y);
}


int main()
 {  int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setcolor(BLUE);
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    int xc,yc,r;

    cout<<"\n Enter the coordinates of centre: ";
    cin>>xc>>yc;

    cout<<"\n Enter radius : ";
    cin>>r;

    cout<<"\n Using Polynomial";
    poly(xc,yc,r);
    sleep(1);
    cout<<"\n Using Trignometric";
    trig(xc,yc,r);
    sleep(1);
    cout<<"\n Using Midpoint ";
    midpt(xc,yc,r);

    getch();
    return 0;
 }

 void poly(int x,int y,int r)
 {
    for(int i=x-r; i<=x+r; i++)
     { float j=y+sqrt(pow(r,2)-pow(x-i,2));
       putpixel(ex(i*.75),ey((int)j),RED);
       j=y-sqrt(pow(r,2)-pow(x-i,2));
       putpixel(ex(i*.75),ey((int)j),RED);
       delay(10);
     }
 }

 void trig(int x, int y,int r)
 {
   for(float i=0;i<6.28;i+=0.02)
    {
      float x1=x+(r*cos(i));
      float y1=y+(r*sin(i));
      putpixel(ex((int)x1*.75),ey((int)y1),WHITE);
      delay(10);
    }


 }

void plotpts(int xc,int yc,int x,int y)
{
  putpixel(ex(xc+x*.75),ey(yc+y),GREEN);
  putpixel(ex(xc-x*.75),ey(yc+y),GREEN);
  putpixel(ex(xc+x*.75),ey(yc-y),GREEN);
  putpixel(ex(xc-x*.75),ey(yc-y),GREEN);

  putpixel(ex(xc+y*.75),ey(yc+x),GREEN);
  putpixel(ex(xc-y*.75),ey(yc+x),GREEN);
  putpixel(ex(xc+y*.75),ey(yc-x),GREEN);
  putpixel(ex(xc-y*.75),ey(yc-x),GREEN);
}

void midpt(int xc,int yc,int r)
{
  int x=0,y=r;
  int p=1-r;

  while(x<y)
  { x++;
    if(p<0)
      { p+=2*x+1;
      }
    else
     { p+=2*(x-y)+1;
       y--;
     }
     delay(10);
     plotpts(xc,yc,x,y);
    }

}