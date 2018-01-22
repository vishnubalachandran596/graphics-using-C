//DJIKSTRAS ALGORITHM

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<iostream.h>
#include<graphics.h>

int cnt=0,ne=0,strt,scnt=0,qcnt=0;
int s[25],q[20];

struct ad
{
    int wt,node;
};

struct node
{

   struct ad adj[10];
   int no,adjn,x,y,d,parent;
}nd[20];
struct edge
{
   struct node n1,n2;
   int wt;
}e[30];

union REGS in,out;
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
  int x=0,y=0,click=0;//flg=0;
  int i=0;
  int xmax, ymax,xmid,ymid;
  initmouse();
  showmouse();
  mouseposi(click,x,y);
  i=1;
  setcolor(1);
 // flg=0;
  char c[2];
  while(click!=2 && i<=cnt)
  {
  mouseposi(click,x,y);
	if(click==1)
	{
	  nd[i].x=x;
	  nd[i].y=y;
	  hidemouse();
	  setcolor(BLUE);
	  circle(x,y,10);
	  showmouse();
	 itoa(nd[i].no,c,10);
	  outtextxy(x-10,y-10,c);//n[i].name)
	  i++;
	  delay(200);
    }

  }
  hidemouse();
 return 0 ;

}

void initialise_single_src()
{
   for(int i=1;i<=cnt;i++)
   {
      nd[i].d=999;
      nd[i].parent=0;
   }
   nd[strt].d=0;


}

void init_q()
 {
     for(int i=1;i<=cnt;i++)
     {
	q[i]=nd[i].no;
     }
     qcnt=cnt;
  }

void relax(int u, int v, int w)
{
     if(nd[v].d>(nd[u].d+w))
     {
	 nd[v].d=nd[u].d+w;
	 nd[v].parent=u;
     }
}

int extract_min()
{   int min=9999,min_nd,p;
    for(int i=1;i<=cnt;i++)
    {   p=q[i];
	if(min>nd[i].d && p!=-1)
	{
	   min=nd[i].d;
	   min_nd=i;
	}
    }
    q[min_nd]=-1;
    qcnt--;
    return min_nd;
}

int main()
   {
   int gd=DETECT,gm,maxx,maxy,a,button,prevx,prevy;
   initgraph(&gd,&gm,"C:\\TC\\BGI");
   int j=0;
   cout<<"\nEnter the number of nodes:";
   cin>>cnt;
   int noe=0;
   char ch;
   for(int i=1;i<=cnt;i++)
      {
      cout<<"\nNode no:";
      cin>>nd[i].no;
      cout<<"\nno of adjacent nodes :";
      cin>>nd[i].adjn;
      cout<<"\nAdjacent nodes and weights:";
      for(j=0;j<nd[i].adjn;j++)
	 {
	 cin>>nd[i].adj[j].node>>nd[i].adj[j].wt;
	 e[noe].n1.no=nd[i].no;
	 e[noe].n2.no=nd[i].adj[j].node;
	 e[noe++].wt=nd[i].adj[j].wt;
	 }
      }
   cout<<"\nEnter the start node :";
   cin>>strt;
   mouse_main();
   setcolor(GREEN);
   int p=0;
   int x1,y1;
   char c[2];
   for(i=1;i<=cnt;i++)
      {
      for(j=0;j<nd[i].adjn;j++)
	  {
	  p=nd[i].adj[j].node;
	  cout<<"("<<nd[i].no<<","<<nd[p].no<<")";
	  line(nd[i].x,nd[i].y,nd[p].x,nd[p].y);
	  x1=(nd[i].x+nd[p].x)/2;
	  y1=(nd[i].y+nd[p].y)/2;
	  itoa(nd[i].adj[j].wt,c,10);
	  outtextxy(x1,y1+10,c);
	  }
     }
   initialise_single_src();
   scnt=0;
   init_q();
   for(i=0;i<qcnt;i++)
     cout<<q[i]<<" ";
   int u;
   cout<<"\nShortest path\n";
   while(qcnt!=0)
      {
      u=extract_min();
      setcolor(WHITE);
      itoa(nd[u].d,c,10);
      outtextxy(nd[u].x-10,nd[u].y+5,c);
      cout<<"  "<<nd[u].no;
      for(j=0;j<nd[u].adjn;j++)
	  {
	  relax(nd[u].no,nd[u].adj[j].node,nd[u].adj[j].wt);
	  }
      }
   getch();
   closegraph();
   return 0;
   }