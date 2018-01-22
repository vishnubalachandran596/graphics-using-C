#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
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

void flood(int x,int y)
{
	if(getpixel(x,y)==0)
	{
		putpixel(x,y,4);
		delay(1);
		flood(x+1,y);
		flood(x-1,y);
		flood(x,y+1);
		flood(x,y-1);

	}
}

void boundr(int x,int y)
{
	int cur;
	cur=getpixel(x,y);
	if(cur!=15&&cur!=4)
	{
		putpixel(x,y,4);
		delay(1);
		boundr(x+1,y);
		boundr(x-1,y);
		boundr(x,y+1);
		boundr(x,y-1);

	}
}
void main()
{
	do
	{
	int x1=0,y1,x2,y2,x,y,cl,a,b,click=0,ch;
	int gd=DETECT,gm;
	clrscr();
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	a=100;
	b=400;
	Initmouse();
	setposi(&a,&b);
	Showmouse();
	while(click!=1)
	{
		mouseposi(&click,&x,&y);
		if(click==2)
		{
			if(x1==0)
			{
				x1=x;
				x2=x;
				y1=y;
				y2=y;
			}
			else
			{

				hidemouse();
				line(x1,y1,x,y);
				x1=x;
				y1=y;
				Showmouse();
			}
		}
	}
	hidemouse();
	line(x1,y1,x2,y2);
	mouseposi(&click,&x,&y);
	printf("\n1.Floodfill\n2.Boundary Fill");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	if(ch==1)
		flood(x,y);
	else if(ch==2)
		boundr(x,y);
	printf("\nDo you want to continue : ");
	}while(getche()=='y');;
}