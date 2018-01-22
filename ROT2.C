/*	CIRCLE ROTATION

*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
float xc,yc,r,xr,yr,r1,rc;
float deg;
int ch;
void rot();
void around_point()
{
	setcolor(getmaxcolor());
	line(getmaxx()/2,0,getmaxx()/2,getmaxy());
	line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	printf("Enter the coordinates of the center: ");
	scanf("%f%f",&xc,&yc);
	printf("Enter the radius: ");
	scanf("%f",&r);
	setcolor(GREEN);
	circle(xc+getmaxx()/2,getmaxy()/2-yc,r);
	printf("Enter the pivot point: ");
	scanf("%f%f",&xr,&yr);
	putpixel(xr+getmaxx()/2,getmaxy()/2-yr,RED);
	r1=sqrt(pow(xc-xr,2)+pow(yc-yr,2))-r;
	printf("Enter the angle of rotation in degrees: ");
	scanf("%f",&deg);
	deg=(deg*3.14)/180;
	getch();
	rot();
	getch();
}
void around_circle()
{
	setcolor(getmaxcolor());
	line(getmaxx()/2,0,getmaxx()/2,getmaxy());
	line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	printf("Enter the coordinates of the center: ");
	scanf("%f%f",&xc,&yc);
	printf("Enter the radius: ");
	scanf("%f",&r);
	setcolor(GREEN);
	circle(xc+getmaxx()/2,getmaxy()/2-yc,r);
	printf("Enter the centre of base circle: ");
	scanf("%f%f",&xr,&yr);
	putpixel(xr+getmaxx()/2,getmaxy()/2-yr,RED);
	r1=sqrt(pow(xc-xr,2)+pow(yc-yr,2))-r;
	printf("Enter the angle of rotation in degrees: ");
	scanf("%f",&deg);
	deg=(deg*3.14)/180;
	getch();
	rot();
	getch();
}
void rot()
{
	float x=xc,y=yc,i,p=0;
	i=3.14/180;
	while(p<=deg)
	{
		setcolor(0);
		circle(xc+getmaxx()/2,getmaxy()/2-yc,r);
		x=xr+(xc-xr)*cos(i)-(yc-yr)*sin(i);
		y=yr+(xc-xr)*sin(i)+(yc-yr)*cos(i);
		xc=x;
		yc=y;
		setcolor(getmaxcolor());
		line(getmaxx()/2,0,getmaxx()/2,getmaxy());
		line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
		if(ch==1)
		 putpixel(xr+getmaxx()/2,getmaxy()/2-yr,RED);
		if(ch==2)
		{
		setcolor(GREEN);
		circle(xr+getmaxx()/2,getmaxy()/2-yr,r1);
		}
		setcolor(MAGENTA);
		circle(xc+getmaxx()/2,getmaxy()/2-yc,r);
		delay(10);
		p+=i;
	}
}
void main()
{
	int gdriver = DETECT, gmode, errorcode;
	clrscr();
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1);
	}
	printf("1. Rotation of circle around a point\n");
	printf("2. Rotation of circle around a circle\n");
	printf("Enter your choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
	 case 1:
		around_point();
		break;
	 case 2:
		around_circle();
		break;
	}
	getch();
}