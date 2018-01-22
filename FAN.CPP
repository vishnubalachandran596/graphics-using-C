
//#include<iostream.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>

int xmid,ymid,stangle=0,endangle=20,clr;
union REGS in,out;

int Initmouse(void)
{
	in.x.ax=0;
	int86(0x33,&in,&out);
	return  out.x.ax;
}

void Showmouse(void)
{
	in.x.ax=1;
	int86(0x33,&in,&out);
}

void hidemouse(void)
{
	in.x.ax=2;
	int86(0x33,&in,&out);
}

void mouseposi(int *click,int *xpos,int *ypos)
{
	in.x.ax=3;
	int86 (0x33,&in,&out);
	*click=out.x.bx;
	*xpos=out.x.cx;
	*ypos=out.x.dx;
}

void setposi(int *xpos,int *ypos)
{
	in.x.ax=4;
	in.x.cx=*xpos;
	in.x.dx=*ypos;
	int86(51,&in,&out);
}



void fanrot(int x)
{
cleardevice();

circle(xmid,ymid,15);
circle(xmid,ymid,65);

arc(xmid,ymid,stangle,endangle,60);
arc(xmid,ymid,stangle+120,endangle+120,60);
arc(xmid,ymid,stangle+240,endangle+240,60);

arc(xmid,ymid,stangle,endangle,55);
arc(xmid,ymid,stangle+120,endangle+120,55);
arc(xmid,ymid,stangle+240,endangle+240,55);

arc(xmid,ymid,stangle,endangle,50);
arc(xmid,ymid,stangle+120,endangle+120,50);
arc(xmid,ymid,stangle+240,endangle+240,50);

arc(xmid,ymid,stangle,endangle,45);
arc(xmid,ymid,stangle+120,endangle+120,45);
arc(xmid,ymid,stangle+240,endangle+240,45);

arc(xmid,ymid,stangle,endangle,40);
arc(xmid,ymid,stangle+120,endangle+120,40);
arc(xmid,ymid,stangle+240,endangle+240,40);

arc(xmid,ymid,stangle,endangle,35);
arc(xmid,ymid,stangle+120,endangle+120,35);
arc(xmid,ymid,stangle+240,endangle+240,35);

arc(xmid,ymid,stangle,endangle,30);
arc(xmid,ymid,stangle+120,endangle+120,30);
arc(xmid,ymid,stangle+240,endangle+240,30);

arc(xmid,ymid,stangle,endangle,25);
arc(xmid,ymid,stangle+120,endangle+120,25);
arc(xmid,ymid,stangle+240,endangle+240,25);

arc(xmid,ymid,stangle,endangle,20);
arc(xmid,ymid,stangle+120,endangle+120,20);
arc(xmid,ymid,stangle+240,endangle+240,20);

arc(xmid,ymid,stangle,endangle,15);
arc(xmid,ymid,stangle+120,endangle+120,15);
arc(xmid,ymid,stangle+240,endangle+240,15);

arc(xmid,ymid,stangle,endangle,10);
arc(xmid,ymid,stangle+120,endangle+120,10);
arc(xmid,ymid,stangle+240,endangle+240,10);
delay(x);
stangle++;
endangle++;
}


void fan()
{

cleardevice();
circle(xmid,ymid,15);
circle(xmid,ymid,65);
arc(xmid,ymid,stangle,endangle,60);
arc(xmid,ymid,stangle+120,endangle+120,60);
arc(xmid,ymid,stangle+240,endangle+240,60);

arc(xmid,ymid,stangle,endangle,55);
arc(xmid,ymid,stangle+120,endangle+120,55);
arc(xmid,ymid,stangle+240,endangle+240,55);

arc(xmid,ymid,stangle,endangle,50);
arc(xmid,ymid,stangle+120,endangle+120,50);
arc(xmid,ymid,stangle+240,endangle+240,50);

arc(xmid,ymid,stangle,endangle,45);
arc(xmid,ymid,stangle+120,endangle+120,45);
arc(xmid,ymid,stangle+240,endangle+240,45);

arc(xmid,ymid,stangle,endangle,40);
arc(xmid,ymid,stangle+120,endangle+120,40);
arc(xmid,ymid,stangle+240,endangle+240,40);

arc(xmid,ymid,stangle,endangle,35);
arc(xmid,ymid,stangle+120,endangle+120,35);
arc(xmid,ymid,stangle+240,endangle+240,35);

arc(xmid,ymid,stangle,endangle,30);
arc(xmid,ymid,stangle+120,endangle+120,30);
arc(xmid,ymid,stangle+240,endangle+240,30);

arc(xmid,ymid,stangle,endangle,25);
arc(xmid,ymid,stangle+120,endangle+120,25);
arc(xmid,ymid,stangle+240,endangle+240,25);

arc(xmid,ymid,stangle,endangle,20);
arc(xmid,ymid,stangle+120,endangle+120,20);
arc(xmid,ymid,stangle+240,endangle+240,20);

arc(xmid,ymid,stangle,endangle,15);
arc(xmid,ymid,stangle+120,endangle+120,15);
arc(xmid,ymid,stangle+240,endangle+240,15);

arc(xmid,ymid,stangle,endangle,10);
arc(xmid,ymid,stangle+120,endangle+120,10);
arc(xmid,ymid,stangle+240,endangle+240,10);

}

void main()
{
int gDriver=DETECT,gMode,a,b,speed=0,click=0,x,y;
initgraph(&gDriver,&gMode,"C:\\TC\\BGI");
xmid=getmaxx() / 2;
ymid=getmaxy() / 2;
fan();
printf("fan works with speed 0,1,2 and 3. give input thru keyboard.");
printf("\nmouse is not used. exit from output screen not possible :P");
printf("\nspeed:");
scanf("%d",&speed);
a=100;
b=400;
Initmouse();
setposi(&a,&b);
Showmouse();

while(click!=2)
{
while(!kbhit())
{
  if(speed==0)
    fan();
  if(speed==1)
    fanrot(20);
  else if(speed==2)
    fanrot(6);
  else if(speed==3)
    fanrot(1);
 else if(speed==9)
    exit(0);
}
printf("speed:");
scanf("%d",&speed);

}






getch();
closegraph();

}
