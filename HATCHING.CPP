
// POLYGON HATCHING

#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<iostream.h>
#include<graphics.h>

union REGS in,out;

int px[50], py[50], cx, cy ,p=0;

int initmouse()
{
	in.x.ax = 0;
	int86(0x33,&in,&out);
	return out.x.ax;
}

void showmouse()
{
	in.x.ax = 1;
	int86(0x33,&in,&out);
}

void hidemouse()
{
	in.x.ax = 2;
	int86(0x33,&in,&out);
}

void mousepost(int &click,int &xpos,int &ypos)
{
	in.x.ax = 3;
	int86(0x33,&in,&out);
	click = out.x.bx;
	xpos = out.x.cx;
	ypos = out.x.dx;
}

void mouse_main()
{
	int x=0, y=0, click=0, flag=0;
	int i=0;
	int xmax, ymax, xmid, ymid;

	initmouse();
	showmouse();
	mousepost(click,x,y);
	while(click != 2)
	{
		mousepost(click,x,y);
		if(click == 1)
		{
			px[i] = x;
			py[i] = y;
			i++;
			delay(200);
			if(flag != 0)
			{
				setcolor(BLUE);
				hidemouse();
				line(px[i-2],py[i-2],px[i-1],py[i-1]);
				showmouse();
			}
			flag = 1;
		}
	}
	hidemouse();
	line(px[i-1],py[i-1],px[0],py[0]);
	px[i] = px[0];
	py[i] = py[0];
	initmouse();
	showmouse();
	mousepost(click,x,y);
	while(1)
	{
		mousepost(click,x,y);
		if(click == 1)
		{
			cx = x;
			cy = y;
			break;
		}

	}
	hidemouse();
}

void fill_right(int x, int y, int fill, int boundary)
{
	int current = getpixel(x,y);
	if(current != boundary && current != fill)
	{  //setcolor(p++);
		//delay(1);
		putpixel(x,y,p++);
		fill_right(++x,y,fill,boundary);
		x = x-1;
		fill_right(x,y+1,fill,boundary);
		fill_right(x,y-1,fill,boundary);
	}
}

void fill_left(int x, int y, int fill, int boundary)
{
	int current = getpixel(x,y);
	if(current != boundary && current != fill)
	{      //delay(1) ;
		//setcolor(p++);
		putpixel(x,y,p++);
		fill_left(--x,y,fill,boundary);
		x = x+1;
		fill_left(x,y+1,fill,boundary);
		fill_left(x,y-1,fill,boundary);
	}
}

void fill(int cx, int cy, int fill, int boundary)
{
	fill_right(cx,cy,fill,boundary);

	fill_left(cx-1,cy,fill,boundary);
}

void hatch_right(int x, int y, int fill, int old)
{
	int current = getpixel(x,y);
	if(current == old)
	{
		putpixel(x,y,fill);
		delay(1);
		hatch_right(++x,y,fill,old);
		x = x-1;
		hatch_right(x,y+5,fill,old);
		hatch_right(x,y-5,fill,old);
	}
}

void hatch_left(int x, int y, int fill, int old)
{
	int current = getpixel(x,y);
	if(current == old)
	{
		putpixel(x,y,fill);
		delay(1);
		hatch_left(--x,y,fill,old);
		x = x+1;
		hatch_left(x,y+5,fill,old);
		hatch_left(x,y-5,fill,old);
	}
}

void hatch(int x, int y, int fill, int old)
{
	hatch_right(x,y,fill,old);
	hatch_left(x-1,y,fill,old);
}

int main()
{
	int i,n,gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
	clearviewport();
	cout<<"Draw a Polygon using the mouse and click on a point within the polygon";
	mouse_main();
	fill(cx,cy,YELLOW,BLUE);
	cout<<"\nEnter 1 to begin with hatching:";
	cin>>n;
	if(n==1)
	  hatch(cx,cy,WHITE,BLACK);
	cout<<"\nHATCHING COMPLETED\n";
	getch();
	return 0;
}
