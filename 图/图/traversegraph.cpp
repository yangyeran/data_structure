//ͼ�Ļ�������ʵ��
//��ʵ��Ŀ�ġ�
//1������ͼ��������ȱ����㷨��
//2������ͼ�Ĺ�����ȱ����㷨��
//��ʵ�����ݡ�
//��д����traversegraph.cpp��ʵ��ͼ�ı������㣬���ڴ˻��������������main.cpp��������¹��ܣ�
//1�������ͼ�Ӷ���0��ʼ��������ȱ������У��ݹ��㷨����
//2�������ͼ�Ӷ���0��ʼ�Ĺ�ȶ����ȱ������У��ݹ��㷨����
//
//���ο����롿
//ͷ�ļ�graph.h
#include <stdio.h>
#include <malloc.h>
typedef int InfoType;
#define	MAXV 100			//��󶥵����
#define INF 32767			//INF��ʾ��
int visited[MAXV];				//ȫ������
typedef struct {		//�ڽӾ��󶥵�����
	int no;					//������
	InfoType info;			//����������Ϣ
} VertexType;
typedef struct {		//ͼ���ڽӾ�����
	int edges[MAXV][MAXV]; //�ڽӾ���
	int n, e;   				//������������
	VertexType vexs[MAXV];	//��Ŷ�����Ϣ
} MGraph;
typedef struct ANode {		//�ڽӱ�ߵĽڵ�ṹ����(��)
	InfoType adjvex;
	struct ANode* nextarc;
	InfoType info;
} ArcNode;
typedef int Vertex;
typedef struct Vnode {		//�ڽӱ�ͷ�ڵ������
	Vertex data;           //������Ϣ
	ArcNode* firstarc;     	//ָ���һ����
} VNode;
typedef VNode AdjList[MAXV];	//AdjList���ڽӱ�����
typedef struct {		//ͼ���ڽӱ���
	AdjList adjlist;       	//�ڽӱ�
	int n, e;        			//ͼ�ж�����n�ͱ���e
} ALGraph;

void DFS(ALGraph * G, int v) {		//�ݹ���������㷨
	ArcNode* p;
	visited[v] = 1;              	//���ѷ��ʱ��
	printf("%3d", v); 				//��������ʶ���ı��
	p = G->adjlist[v].firstarc;   	//pָ�򶥵�v�ĵ�һ�����Ļ�ͷ���
	while (p != NULL) {
		if (visited[p->adjvex] == 0)		//��p->adjvex����δ���ʣ��ݹ������
			DFS(G, p->adjvex);
		p = p->nextarc;         		//pָ�򶥵�v����һ�����Ļ�ͷ���
	}
}
void BFS(ALGraph* G, int v) {		//��������㷨
	ArcNode* p;
	int queue[MAXV], front = 0, rear = 0;		//����ѭ�����в���ʼ��
	int visited[MAXV];            		//�����Ž��ķ��ʱ�־������
	int w, i;
	for (i = 0; i < G->n; i++)
		visited[i] = 0;						//���ʱ�־�����ʼ��
	printf("%3d", v); 						//��������ʶ���ı��
	visited[v] = 1;              			//���ѷ��ʱ��
	rear = (rear + 1) % MAXV;
	queue[rear] = v;             		//v����
	while (front != rear) {       			//�����в���ʱѭ��
		front = (front + 1) % MAXV;
		w = queue[front];       			//���Ӳ�����w
		p = G->adjlist[w].firstarc; 			//���붥��w�ڽӵĵ�һ������
		while (p != NULL) {
			if (visited[p->adjvex] == 0) { 	//����ǰ�ڽӶ���δ������
				printf("%3d", p->adjvex); 	//�������ڶ���
				visited[p->adjvex] = 1;		//�øö����ѱ����ʵı�־
				rear = (rear + 1) % MAXV;		//�ö������
				queue[rear] = p->adjvex;
			}
			p = p->nextarc;              	//����һ���ڽӶ���
		}
	}
	printf("\n");
}
void MatToList1(MGraph g, ALGraph*& G) {	//���ڽӾ���gת�����ڽӱ�G
	int i, j;
	ArcNode* p;
	G = (ALGraph*)malloc(sizeof(ALGraph));
	for (i = 0; i < g.n; i++)			//���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i < g.n; i++)			//����ڽӾ�����ÿ��Ԫ��
		for (j = g.n - 1; j >= 0; j--)
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {		//����һ���ߣ�����
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->info = g.edges[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
	G->n = g.n;
	G->e = g.e;
}
void DispAdj1(ALGraph* G) {		//����ڽӱ�G
	int i;
	ArcNode* p;
	for (i = 0; i < G->n; i++) {
		p = G->adjlist[i].firstarc;
		printf("%3d��", i);
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
	MatToList1(g, G);				//ͼG���ڽӾ���ת�����ڽӱ�
	printf("ͼG���ڽӱ�\n");
	DispAdj1(G);
	printf("�Ӷ���0��ʼ��DFS(�ݹ��㷨)��\n");
	DFS(G, 0); printf("\n");
	printf("�Ӷ���0��ʼ��BFS(�ݹ��㷨)��\n");
	BFS(G, 0);
	printf("\n");
}