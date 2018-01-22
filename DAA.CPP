#include <graphics.h>
#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include<dos.h>

#define round(x) (int)(x+0.5)


void dda(int,int,int,int);

int ex(int x){
	return(x+(getmaxx()/2));
}

int ey(int y){
	return((getmaxy()/2)-y);
}


int main()
 {  int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    int dx,dy,steps;
    float xinc,yinc,x,y,xa,xb,ya,yb,m;
    clrscr();
    setbkcolor(BLACK);

    cout<<"Enter the coordinates of a :";
    cin>>xa>>ya;
    cout<<"Enter the coordinates of b :";
    cin>>xb>>yb;


    dda(xa,ya,xb,yb);

   getch();

   return 0;

}



void dda(int xa,int ya,int xb,int yb)
{
  int dx,dy,steps;
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

    setcolor(GREEN);
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());

    putpixel(ex(round(x)),ey(round(y)),WHITE);

    for(int k=0;k<steps;k++)
     { x=x+xinc;
       y=y+yinc;

       putpixel(ex(round(x)),ey(round(y)),RED);
     }



}