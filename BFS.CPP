

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
#define INF 2000
#define QUE 30
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

int queue[QUE],qfront,qrear;

void enqueue(int a){
  if(qrear== qfront && qrear == -1){
     qrear = qfront = 0;
     queue[qrear] = a;
  }
  else if(qrear<QUE-1){
     queue[++qrear]=a;
  }
  else{
    cout<<"Que Error";
  }
}
int dequeue(){
   int retval;
   if(qfront==-1){
     retval = -1;
     cout<<"Queue empty";
   }
   else{
      retval = queue[qfront];
      if(qfront == qrear)
	qfront = qrear = -1;
      else
	qfront++;
   }
   return retval;
}
enum col { WH, GR, BL};

struct node{
   int id;
   int xco, yco;
   int d;
   int pid;
   int color;
   int links[10];
};

int n;//num of nodes in graph

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
   cout<<"Enter number of links and links of node: ";
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

void bfs(node graph[],int start=0){
   int s,u,v,j;
   char c[5];
   //initialize nodes in graph(already done while saving)
   s = start;
   graph[s].color = GR;
   //queue empty
   qfront = qrear = -1;
   enqueue(s);
   graph[s].d = 0;
   while(qfront != -1){
      u = dequeue();
      cout<<u;
      j = 0;
      while(graph[u].links[j] != -1){
	 v = graph[u].links[j];
	 if(graph[v].color == WH){
	    graph[v].color = GR;
	    graph[v].pid = u;
	    graph[v].d = graph[u].d+1;
	    enqueue(v);
	 }
	 j++;
      }
      graph[u].color = BL;
   }

   //updating distance
   setcolor(YELLOW);
   for(int i=0; i < n; ++i){
      itoa(graph[i].d,c,10);
      outtextxy(graph[i].xco-5,graph[i].yco+15,c);
   }
}

void main(){
   clrscr();
   int start;
   int gd=DETECT,gm,maxx,maxy,x,y,button,prevx,prevy;
   node *graph;
   //initgraph(&gd,&gm,"");
   initgraph(&gd,&gm,"C:\\TC\\BGI");
   initmouse();
   showmouse();
   graph = createGraph();
   cout<<"BFS...";
   cout<<"Start node:";
   cin>>start;
   bfs(graph,start);
   getch();
}
