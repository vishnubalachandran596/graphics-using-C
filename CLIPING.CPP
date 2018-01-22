#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<alloc.h>
union REGS in,out;

int callmouse()
{
in.x.ax=1;
int86(51,&in,&out);
return 1;
}
void showmouse(void)
	{
	in.x.ax=1;
	int86(0x33,&in,&out);
	}
void hidemouse(void)
	{
	in.x.ax=2;
	int86(0x33,&in,&out);
	}
/*
void res_mouse(int x1,int y1,int x2,int y2)
{
in.x.ax=7;
in.x.cx=x1;
in.x.dx=x2;
int86(51,&in,&out);
in.x.ax=8;
in.x.cx=y1;
in.x.dx=y2;
int86(51,&in,&out);
}
  */
void getpos(int &click,int &xpos,int &ypos)
{
in.x.ax=3;
int86(51,&in,&out);
click=out.x.bx;
xpos=out.x.cx;
ypos=out.x.dx;
}
//void draw_car(int x,int y)
//{

// }
int main()
{
 int x,y,xsave,ysave,xpos,ypos,click,cnt=0;
 void * pict;
 unsigned int p_size;
 int g=DETECT,gm;
  clrscr();
 initgraph(&g,&gm,"C:\\TC\\BGI");
 p_size=imagesize(x-50,y+50,x+50,y-50);
 pict= malloc(p_size);
 x = getmaxx()/2;
 y = getmaxy()/2;
 callmouse();
 //res_mouse(100,100,550,400);
 line(getmaxx()/2,0,getmaxx()/2,getmaxy());
 line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
 rectangle(x-50,y-50,x+50,y+50);
 do{
 getpos(click,xpos,ypos);
 if(click==1)
 {
  ++cnt;
  if(cnt==1)
  {
  xsave=xpos;
  ysave=ypos;
  hidemouse();
  putpixel(xsave,ysave,3);
  showmouse();
  }
  if(cnt==2)
    {   setcolor(3);
	hidemouse();
	line(xsave,ysave,xpos,ypos);
	showmouse();
	cnt=0;
      }
  }
  if(click==2)
  {
  setfillstyle(SOLID_FILL, getmaxcolor());
  floodfill(xpos,ypos,0);
  }
  } while(!kbhit());

 rectangle(x-50,y-50,x+50,y+50);
 hidemouse();
 getimage(x-50,y+50,x+50,y-50,pict);
 cleardevice();
 putimage(getmaxx()/2,getmaxy()/2,pict,XOR_PUT);
 showmouse();
 delay(100);
 getch();
 getch();
 }



