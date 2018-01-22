#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<alloc.h>
#include<stdlib.h>

typedef unsigned char BYTE;    //0 to 255 ie 0xff
BYTE pointcheck(int x,int y);
BYTE bit1check(int p);
BYTE bit2check(int p);
BYTE bit3check(int p);
BYTE bit4check(int p);
int endprog(void);

int main(void)
{
//Graphics mode initialization to 640x480 res
int gd=VGA,gm=VGAHI;
float x,y,xmin,ymin,xmax,ymax;
float xn1,xn2,yn1,yn2,x1,y1,x2,y2;
initgraph(&gd,&gm,"..\\BGI");
//widow defined

xmax=540;
ymax=380;
xmin=100;
ymin=100;
//Line end points defined

int p1,p2;
x1=120;y1=12;x2=300;y2=390;
//printf("Enter End points of a line (x1,y1) (x2,y2)");
//printf("x1 y1:");
//scanf("%d %d",&x1,&y1);
//printf("x2 y2:");
//scanf("%d %d",&x2,&y2);
//draw initial situation
setcolor(1);
rectangle(xmin,ymin,xmax,ymax);
setcolor(2);
line(x1,y1,x2,y2);
// Program of clipping begins here
float m=(y2-y1)/(x2-x1);  //float is calculated
// getting binary conversion of points
p1=pointcheck(x1,y1);
p2=pointcheck(x2,y2);
// printing libne position
int bit1,bit2,bit3,bit4;
bit1=bit1check(p1);
bit2=bit2check(p1);
bit3=bit3check(p1);
bit4=bit4check(p1);
printf("Point p1is %d =%d%d%d%d",p1,bit4,bit3,bit2,bit1);
bit1=bit1check(p1);
bit2=bit2check(p1);
bit3=bit3check(p1);
bit4=bit4check(p1);
printf("Point p2is %d =%d%d%d%d",p2,bit4,bit3,bit2,bit1);
//if the line lies outside exit the program
if(bit1check(p1)&bit1check(p2)==1) endprog();
if(bit2check(p1)&bit2check(p2)==1) endprog();
if(bit3check(p1)&bit3check(p2)==1) endprog();
if(bit4check(p1)&bit4check(p2)==1) endprog();
if (p1==0 &p2==0)
{
printf("\nline lies within the window");
getch();
return 0;
}
else printf("\n Clipping ....");
//Cliping required from intersecting points .Calculating that ...
int pointcount=0;
if(pointcheck(x1,y1)==0)
{
xn1=x1;
yn1=y1;
pointcount=pointcount+1;
p1=p2;
}
if(bit1check(p1)==1) //it crosses xmin
{
x=xmin;
y=y1+m*(xmin-x1);
putpixel(x,y,3);
setcolor(3);
circle(x,y,4);
if(pointcount>0)
{
 xn2=x; yn2=y;
}

else{
	xn1=x;
	yn1=y;
	pointcount=pointcount+1;
}
p1=p2;
}
if(bit2check(p1)==1) //it crosses xmax
{
x=xmin;
y=y1+m*(xmax-x1);
putpixel(x,y,3);
setcolor(3);
circle(x,y,4);
if(pointcount>0)
{
 xn2=x; yn2=y;
}

else{
	xn1=x;
	yn1=y;
	pointcount=pointcount+1;
}
p1=p2;
}
if(bit3check(p1)==1) //it crosses ymin
{
y=ymin;
x=x1+(ymin-y1)/m;
putpixel(x,y,3);
setcolor(3);
circle(x,y,4);
if(pointcount>0)
{
 xn2=x; yn2=y;
}

else{
	xn1=x;
	yn1=y;
	pointcount=pointcount+1;
}
p1=p2;
}
if(bit4check(p2)==1) //it crosses ymin
{
y=ymax;
x=x1+(ymax-y1)/m;
putpixel(x,y,3);
setcolor(3);
circle(x,y,4);
if(pointcount>0)
{
 xn2=x; yn2=y;
}

else{
	xn1=x;
	yn1=y;
	pointcount=pointcount+1;
}

}
getch();
setcolor(0);
line(x1,y1,x2,y2);
setcolor(4);
line(xn1,yn1,xn2,yn2);
getch();
closegraph();
return 0;
}
int endprog(void)
{
printf("\n Line lies outside the window ");
getch();
closegraph();
return 0;
}
BYTE pointcheck(int x,int y)
{
int val=0x00;
if((x-100)<0) val=val|0x01;
if((540-x)<0) val=val|0x02;
if((y-100)<0) val=val|0x04;
if((380-y)<0) val=val|0x08;
return val;
}
BYTE bit1check(int a)
{
a=a&1;
return a;
}
BYTE bit2check(int b)
{
b=b&2;
b=b>>1;
return b;
}
BYTE bit3check(int c)
{
 c=c&4;
 c=c>>2;
 return c;
 }
BYTE bit4check(int d)
{
 d=d>>3;
 return d;
 }