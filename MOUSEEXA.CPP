
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>

union REGS in,out;
//int poly5[100],poly6[100];

int initmouse(void)
{
  in.x.ax=0;
  int86(0x33,&in,&out);
  return out.x.ax;
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

void mouseposi(int &click,int &xpos,int &ypos)
{
  in.x.ax=3;
  int86(0x33,&in,&out);
  click=out.x.bx;
  xpos=out.x.cx;
  ypos=out.x.dx;
}


 mouse_main()
{
  int x=0,y=0,click=0,flg=0;
  int i=0,px[50],py[50];
  int xmax, ymax,xmid,ymid;

  initmouse();
  showmouse();
  mouseposi(click,x,y);
  i=0;
  setcolor(1);
  flg=0;
  while(click!=2)
  {
  mouseposi(click,x,y);
	if(click==1)
	{

	  px[i]=x;
	  py[i]=y;
	  i++;
	  delay(200);

	  if(flg!=0)
	  {
	setcolor(DARKGRAY);
	hidemouse();
	line(px[i-2],py[i-2],px[i-1],py[i-1]);
	showmouse();
	  }
	  flg=1;
	  }

  }
  hidemouse();
  line(px[i-1],py[i-1],px[0],py[0]);
  px[i]=px[0];py[i]=py[0];
  return 0 ;
}

main ()
{
int gd=DETECT,gm,maxx,maxy,x,y,button,prevx,prevy;
initgraph(&gd,&gm,"");

mouse_main();

getch();
return 0;
}
