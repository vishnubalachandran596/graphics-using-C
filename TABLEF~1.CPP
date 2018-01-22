#include<iostream.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>
int xmid,ymid;
void main()
{
int gDriver=DETECT,gMode,x=1000,stangle=0,endangle=30,i;
initgraph(&gDriver,&gMode,"C:\\TC\\BGI");
xmid=getmaxx() / 2;
ymid=getmaxy() / 2;
scanf("%d",&i);
clrscr();
while(x>0)
{
circle(xmid,ymid,15);
circle(xmid,ymid,65);
arc(xmid,ymid,stangle,endangle,60);
arc(xmid,ymid,stangle,endangle,50);
arc(xmid,ymid,stangle,endangle,40);
arc(xmid,ymid,stangle,endangle,30);
arc(xmid,ymid,stangle,endangle,20);
arc(xmid,ymid,stangle+120,endangle+120,60);
arc(xmid,ymid,stangle+120,endangle+120,50);
arc(xmid,ymid,stangle+120,endangle+120,40);
arc(xmid,ymid,stangle+120,endangle+120,30);
arc(xmid,ymid,stangle+120,endangle+120,20);
arc(xmid,ymid,stangle+240,endangle+240,60);
arc(xmid,ymid,stangle+240,endangle+240,50);
arc(xmid,ymid,stangle+240,endangle+240,40);
arc(xmid,ymid,stangle+240,endangle+240,30);
arc(xmid,ymid,stangle+240,endangle+240,20);
delay(i);
cleardevice();
stangle++;
endangle++;
x--;
}
getch();
closegraph();
}