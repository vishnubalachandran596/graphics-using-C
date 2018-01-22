//PGM 3 ALGORITHM LAB
//Pranav P Pillai R8132
//Kruskal's Algorithm

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
   int set_no;
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
int a_add(int b, int c){
   int i, flag = 0 ;
   for(i=0; i <= a_ind; ++i){
      if(a[i] == b){
	 flag = 1;
	 break;
      }
   }
   if(flag == 1)
      a[++a_ind] = b;

   if(a_ind == n_nodes)
      return 1;

   flag = 0;
   for(i=0; i <= a_ind; ++i){
      if(a[i] == c){
	 flag = 1;
	 break;
      }
   }
   if(flag == 1)
      a[++a_ind] = c;

   if(a_ind == n_nodes)
      return 1;

   return -1;
}

void sortedges(){
  edge temp;
  int i;
  for( i =0; i <n_edges; ++i){
    for(int j = i; j < n_edges-1; ++j){
       if(edges[j].wt > edges[j+1].wt){
	  temp = edges[j];
	  edges[j] = edges[j+1];
	  edges[j+1] = temp;
       }
    }
  }

 /* for(i=0; i<n_edges;++i)
    cout<<edges[i].wt<<" ";   */
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

void makeset(){
    //assign each node to a diff set
    for(int i=0; i < n_nodes; ++i){
       graph[i].set_no = i;
    }

}

void update_set_no(int oldno,int newno){
   for(int i =0; i< n_nodes; ++i){
       if(graph[i].set_no == oldno){
	  graph[i].set_no = newno;
       }
   }
}
void union_nodes(int a, int b){
    if(a < b){
	//graph[b].set_no = graph[a].set_no;
	update_set_no(graph[b].set_no,graph[a].set_no);
    }
    else{
	update_set_no(graph[a].set_no ,graph[b].set_no);
    }
}

void krusk(){
    int i,k;
    a_ind = -1;
    makeset();
    sortedges();
    setcolor(YELLOW);
    cout<<"\nWeights :";
    for(i=0; i<n_edges;++i){
      delay(500);
      if(graph[edges[i].a].set_no != graph[edges[i].b].set_no){
	cout<<edges[i].wt<<" ";
	k = a_add(edges[i].a,edges[i].b);
	union_nodes(edges[i].a,edges[i].b);
	line(graph[edges[i].a].xco,graph[edges[i].a].yco,graph[edges[i].b].xco,graph[edges[i].b].yco);
	if(k == 1)
	  return;
      }
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
   sortedges();
   cout<<"Kruskals Spanning tree...";
   //cin>>start;
   krusk();
   getch();
}
