//PGM 2 ALGORITHM LAB
//DFS

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
   int xco, yco;
   int d;
   int f;
   int pid;
   int color;
   int links[10];
};

int n;//num of nodes in graph
int t;

node* createGraph(){
   int numlinks;
   int j,i;
   int cx, cy, click;
   char c[5],t;
   node *graph;
   setcolor(RED);
   cout<<"Graph Creation :";
   cout<<"\nNumber of Nodes:";
   cin>>n;
   graph = new node[n];
   for(i =0; i<n; ++i){
      showmouse();
      click = -1;
      numlinks = 0;
      graph[i].id = i;
      graph[i].d = INF;
      graph[i].f = INF;
      while(click <1)
	  mouseposi(click,cx,cy);
      graph[i].xco = cx;
      graph[i].yco = cy;
      graph[i].pid = -1;
      graph[i].color = WH;
      hidemouse();
      circle(cx,cy,10);
      itoa(i,c,10);
      outtextxy(cx-5,cy-5,c);
      graph[i].links[0] = -1;
      //cin>>t;
      getch();
   }
   //read links
   cout<<"Enter no of links and links of node ";
   for(i=0; i<n; ++i){
     cout<<"\n"<<i<<":";
      cin>>numlinks;
      for(j=0; j<numlinks;++j)
	cin>>graph[i].links[j];
      for(;j<10;++j)
	graph[i].links[j]=-1;
   }
   //draw links in graph
   setcolor(GREEN);
   for(i=0; i<n; ++i){
      j=0;
      while(graph[i].links[j] != -1){
       line(graph[i].xco,graph[i].yco,graph[graph[i].links[j]].xco,graph[graph[i].links[j]].yco);
       j++;
      }
   }

   return graph;
}

void DFS_Visit(node graph[], int u){
   cout<<u;
   int j=0,v;
   graph[u].color = GR;
   t = t + 1;
   graph[u].d = t;
   while(graph[u].links[j] != -1){
       v = graph[u].links[j];
      if(graph[v].color == WH){
	 graph[v].pid = u;
	 DFS_Visit(graph, v);
      }
      j++;
   }
   graph[u].color = BL;
   graph[u].f = t = t + 1;
}

void dfs(node graph[]){
   int s,u,v,j;
   char c[5],e[5];
   //inintialize nodes in graph(already done while saving)
   t = 0;

   for(u=0; u <n; ++u){
      if(graph[u].color == WH)
	DFS_Visit(graph,u);
   }


   //updating distance

   for(int i=0; i < n; ++i){
      setcolor(YELLOW);
      itoa(graph[i].d,c,10);
      //outtextxy(graph[i].xco-5,graph[i].yco+15,c);
      //setcolor(BLUE);
      itoa(graph[i].f,e,10);
      strcat(c,"/");
      strcat(c,e);
      outtextxy(graph[i].xco-5,graph[i].yco+15,c);
   }
}

void main(){
   clrscr();
   int start;
   int gd=DETECT,gm,maxx,maxy,x,y,button,prevx,prevy;
   node *graph;
   //initgraph(&gd,&gm,"");
   initgraph(&gd,&gm,"..\\BGI");
   initmouse();
   showmouse();
   graph = createGraph();
   cout<<"DFS...";
   cout<<"Start node: 0 \n";
   //cin>>start;
   dfs(graph);
   getch();
}
