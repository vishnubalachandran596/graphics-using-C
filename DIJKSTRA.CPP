

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#define INF 2000

// graphics
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



enum col { WH, GR, BL};

struct node{
   int id;
   int d,inq;
   int xco, yco;
};

struct edge{
   int a, b;
   int wt;
};

int n_nodes, n_edges;//num of nodes in graph
int t;
node *graph;
edge *edges;
int **set;

int a[50],a_ind;
int a_add(int b){
   int i, flag = 0 ;
   for(i=0; i <= a_ind; ++i){
      if(a[i] == b){
	 flag = 1;
	 break;
      }
   }
   if(flag == 0)
      a[++a_ind] = b;

   if(a_ind == n_nodes)
      return 1;
   return -1;
}



void createGraph(){
   int numlinks;
   int j,i;
   int cx, cy, click;
   char c[5],t;


   setcolor(RED);
   cout<<"Graph Creation :";
   cout<<"\nNumber of Nodes:";
   cin>>n_nodes;
   graph = new node[n_nodes];
   for(i =0; i<n_nodes; ++i){
      showmouse();
      click = -1;
      //numlinks = 0;
      graph[i].id = i;
      while(click <1)
	  mouseposi(click,cx,cy);
      graph[i].xco = cx;
      graph[i].yco = cy;
      hidemouse();
      circle(cx,cy,10);
      itoa(i,c,10);
      outtextxy(cx-5,cy-5,c);
      getch();
   }
   //read links
   cout<<"Enter no of edges ";
   cin>>n_edges;
   edges = new edge[n_edges];
   cout<<"Enter edge nodes and weight\n";
   for(i=0; i<n_edges; ++i){
     cout<<i<<":";
      cin>>edges[i].a>>edges[i].b>>edges[i].wt;
   }
   //draw links in graph
   setcolor(GREEN);
   for(i=0; i<n_edges; ++i){
       cx =  (graph[edges[i].a].xco + graph[edges[i].b].xco)/2;
       cy =  (graph[edges[i].a].yco + graph[edges[i].b].yco)/2;
       itoa(edges[i].wt,c,10);
       line(graph[edges[i].a].xco,graph[edges[i].a].yco,graph[edges[i].b].xco,graph[edges[i].b].yco);
       outtextxy(cx-5,cy-5,c);
   }

}

int minid(){
   int k = -1,mink = 1000;
   for(int i=0; i<n_nodes;++i){
     if((graph[i].inq == 1) && (graph[i].d < mink)){
	k = i;
	mink = graph[i].d;
     }
   }
   return k;
}

void diji(){
   int i,aa,source,bigvalue = 100,f=0,u,v;
   char c[10];
   a_ind = -1;
   cout<<"Source:";
   cin>>source;
   //initialize node distances
   for(i=0;i<n_nodes;++i){
      graph[i].d = bigvalue;
      graph[i].inq = 1;
   }
   graph[source].d = 0;
   //a[++a_ind] = source;
 //  cout<<"\nShortest Path:";
   u = minid();
   while(u != -1){
      //aa = a_add(u);
      //do relax....
   //   cout<<u<<" -> ";
      for(i=0; i < n_edges;++i){
	 if(edges[i].a == u){
	     if(graph[edges[i].b].d >graph[edges[i].a].d + edges[i].wt){
		graph[edges[i].b].d = graph[edges[i].a].d + edges[i].wt;

	     }
	 }
	 if(edges[i].b == u){
	     if(graph[edges[i].a].d >graph[edges[i].b].d + edges[i].wt){
		graph[edges[i].a].d = graph[edges[i].b].d + edges[i].wt;
	     }
	 }
      }
      graph[u].inq = -1;
      if(f==1)
	 break;
      u = minid();
   }
   setcolor(YELLOW);
   for(int k=0; k < n_nodes;++k){
     // cout<<" ";
      itoa(graph[k].d,c,10);
      outtextxy(graph[k].xco-5,graph[k].yco-20,c);
   }
}


void main(){
   clrscr();
   int start;
   int gd=DETECT,gm,maxx,maxy,x,y,button,prevx,prevy;
   //initgraph(&gd,&gm,"");
   initgraph(&gd,&gm,"C:\\TC\\BGI");
   initmouse();
   showmouse();
   createGraph();
   cout<<"Djikstra's Shortest Path\n";
   //cin>>start;
   diji();
   getch();
}

