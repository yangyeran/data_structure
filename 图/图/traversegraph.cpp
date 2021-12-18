//图的基本操作实现
//【实验目的】
//1．掌握图的深度优先遍历算法。
//2．掌握图的广度优先遍历算法。
//【实验内容】
//编写程序traversegraph.cpp，实现图的遍历运算，并在此基础上设计主程序main.cpp，完成如下功能：
//1．输出下图从顶点0开始的深度优先遍历序列（递归算法）；
//2．输出下图从顶点0开始的广度度优先遍历序列（递归算法）。
//
//【参考代码】
//头文件graph.h
#include <stdio.h>
#include <malloc.h>
typedef int InfoType;
#define	MAXV 100			//最大顶点个数
#define INF 32767			//INF表示∞
int visited[MAXV];				//全局数组
typedef struct {		//邻接矩阵顶点类型
	int no;					//顶点编号
	InfoType info;			//顶点其他信息
} VertexType;
typedef struct {		//图的邻接矩阵定义
	int edges[MAXV][MAXV]; //邻接矩阵
	int n, e;   				//顶点数，边数
	VertexType vexs[MAXV];	//存放顶点信息
} MGraph;
typedef struct ANode {		//邻接表边的节点结构类型(补)
	InfoType adjvex;
	struct ANode* nextarc;
	InfoType info;
} ArcNode;
typedef int Vertex;
typedef struct Vnode {		//邻接表头节点的类型
	Vertex data;           //顶点信息
	ArcNode* firstarc;     	//指向第一条边
} VNode;
typedef VNode AdjList[MAXV];	//AdjList是邻接表类型
typedef struct {		//图的邻接表定义
	AdjList adjlist;       	//邻接表
	int n, e;        			//图中顶点数n和边数e
} ALGraph;

void DFS(ALGraph * G, int v) {		//递归深度优先算法
	ArcNode* p;
	visited[v] = 1;              	//置已访问标记
	printf("%3d", v); 				//输出被访问顶点的编号
	p = G->adjlist[v].firstarc;   	//p指向顶点v的第一条弧的弧头结点
	while (p != NULL) {
		if (visited[p->adjvex] == 0)		//若p->adjvex顶点未访问，递归访问它
			DFS(G, p->adjvex);
		p = p->nextarc;         		//p指向顶点v的下一条弧的弧头结点
	}
}
void BFS(ALGraph* G, int v) {		//广度优先算法
	ArcNode* p;
	int queue[MAXV], front = 0, rear = 0;		//定义循环队列并初始化
	int visited[MAXV];            		//定义存放结点的访问标志的数组
	int w, i;
	for (i = 0; i < G->n; i++)
		visited[i] = 0;						//访问标志数组初始化
	printf("%3d", v); 						//输出被访问顶点的编号
	visited[v] = 1;              			//置已访问标记
	rear = (rear + 1) % MAXV;
	queue[rear] = v;             		//v进队
	while (front != rear) {       			//若队列不空时循环
		front = (front + 1) % MAXV;
		w = queue[front];       			//出队并赋给w
		p = G->adjlist[w].firstarc; 			//找与顶点w邻接的第一个顶点
		while (p != NULL) {
			if (visited[p->adjvex] == 0) { 	//若当前邻接顶点未被访问
				printf("%3d", p->adjvex); 	//访问相邻顶点
				visited[p->adjvex] = 1;		//置该顶点已被访问的标志
				rear = (rear + 1) % MAXV;		//该顶点进队
				queue[rear] = p->adjvex;
			}
			p = p->nextarc;              	//找下一个邻接顶点
		}
	}
	printf("\n");
}
void MatToList1(MGraph g, ALGraph*& G) {	//将邻接矩阵g转换成邻接表G
	int i, j;
	ArcNode* p;
	G = (ALGraph*)malloc(sizeof(ALGraph));
	for (i = 0; i < g.n; i++)			//给邻接表中所有头节点的指针域置初值
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i < g.n; i++)			//检查邻接矩阵中每个元素
		for (j = g.n - 1; j >= 0; j--)
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {		//存在一条边（补）
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->info = g.edges[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
	G->n = g.n;
	G->e = g.e;
}
void DispAdj1(ALGraph* G) {		//输出邻接表G
	int i;
	ArcNode* p;
	for (i = 0; i < G->n; i++) {
		p = G->adjlist[i].firstarc;
		printf("%3d：", i);
		while (p != NULL) {
			printf("%3d(%d)", p->adjvex, p->info);
			p = p->nextarc;
		}
		printf("\n");
	}
}
int main() {
	int i, j;
	MGraph g;
	ALGraph* G;
	int A[MAXV][6] = {
		{0,5,INF,7,INF,INF},
		{INF,0,4,INF,INF,INF},
		{8,INF,0,INF,INF,9},
		{INF,INF,5,0,INF,6},
		{INF,INF,INF,5,0,INF},
		{3,INF,INF,INF,1,0} };
	g.n = 6;
	g.e = 10;
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
			g.edges[i][j] = A[i][j];
	G = (ALGraph*)malloc(sizeof(ALGraph));
	MatToList1(g, G);				//图G的邻接矩阵转换成邻接表
	printf("图G的邻接表：\n");
	DispAdj1(G);
	printf("从顶点0开始的DFS(递归算法)：\n");
	DFS(G, 0); printf("\n");
	printf("从顶点0开始的BFS(递归算法)：\n");
	BFS(G, 0);
	printf("\n");
}