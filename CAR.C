#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int s=5,r=4,d=5;
void draw_car(int x,int y)
{
 moveto(x,y);
 line(x,y,x+20*s,y);
 line(x,y,x,y-5*s);
 line(x+5*s,y-5*s,x+5*s,y-8*s);
 line(x+5*s,y-5*s,x+20*s,y-5*s);
 line(x+15*s,y-5*s,x+15*s,y-8*s);
 line(x+5*s,y-8*s,x+15*s,y-8*s);
 line(x,y-5*s,x+5*s,y-5*s);
 line(x+20*s,y-5*s,x+20*s,y);
 circle(x+5*s,y,2*r);
 circle(x+15*s,y,2*r);
 }
void main()
{
int gdriver=DETECT,gmode;/*errorcode*/;
int i,x,y,maxx;
//void * pict;
//unsigned int p_size;
initgraph(&gdriver,&gmode,"C:\\TurboC3\\BGI");
//errorcode = graphresult();
/*if (errorcode != grOk)
{
   printf("Graphics error: %s\n", grapherrormsg(errorcode));

   }*/
maxx = getmaxx();
x = 0;
y = getmaxy() / 2;
draw_car(x,y);
/*p_size=imagesize(x,y+10*s,x+40*s,y-10*s);
pict= malloc(p_size);
getimage(x,y-120,x+120,y+120,pict);
circle(400,50,40);
line(x,y+10,maxx,y+10);
while(!kbhit())
 {
 delay(d);
 putimage(x,y-120,pict,XOR_PUT);
 x=x+10;
 if(x>maxx)
 x=0;
 delay(d);
 putimage(x,y-120,pict,XOR_PUT);
// cleardevice();

 }*/
getch();
//free(pict);
//closegraph();
}