#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<alloc.h>

union REGS in,out;

void initmouse()
{
 in.x.ax=0;
 int86(0X33,&in,&out);
}

void showmouse()
{
 in.x.ax=1;
 int86(0X33,&in,&out);
}

void mouseposi(int *click,int *xpos,int *ypos)
{
 in.x.ax=3;
 int86(0x33,&in,&out);
 *click=out.x.bx;
 *xpos=out.x.cx;
 *ypos=out.x.dx;
}

void hidemouse()
{
 in.x.ax=2;
 int86(0x33,&in,&out);
}

int main(){
  int gdriver=DETECT,gmode,gerr,xold,yold,click,xpos,ypos,x,y,portx1,porty1,portx2,porty2;
  void *pict;
  unsigned int psize;
  initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
  initmouse();
  showmouse();
  mouseposi(&click,&xpos,&ypos);
  while(click!=1){
     mouseposi(&click,&xpos,&ypos);
  }
  hidemouse();
  x=xpos;
  y=ypos;
  while(click==1){
     setcolor(BLACK);
     line(x,y,xpos,y);
     line(x,y,x,ypos);
     line(xpos,y,xpos,ypos);
     line(x,ypos,xpos,ypos);
     mouseposi(&click,&xpos,&ypos);
     setcolor(GREEN);
     line(x,y,xpos,y);
     line(x,y,x,ypos);
     line(xpos,y,xpos,ypos);
     line(x,ypos,xpos,ypos);
  }
  portx1=x;
  portx2=xpos;
  porty1=y;
  porty2=ypos;
  psize=imagesize(portx1,porty2,portx2,porty1);
  pict=malloc(psize);
  mouseposi(&click,&xpos,&ypos);
  y=ypos;
  x=xpos;
  showmouse();
  while(click!=2){
     while(click!=1&&click!=2){
       mouseposi(&click,&xpos,&ypos);
     }
     y=ypos;
     x=xpos;
     while(click==1)
     {
     //	hidemouse();
	setcolor(BLACK);
	line(x,y,xpos,ypos);
	setcolor(GREEN);
	rectangle(portx1,porty1,portx2,porty2);
	mouseposi(&click,&xpos,&ypos);
	delay(5);
	setcolor(WHITE);
	line(x,y,xpos,ypos);
      }
      showmouse();
   }
   hidemouse();
   getimage(portx1,porty2,portx2,porty1,pict);
   cleardevice();
   putimage(portx1,porty1,pict,XOR_PUT);
   showmouse();
   delay(1000);
   getch();
   return 0;
}
