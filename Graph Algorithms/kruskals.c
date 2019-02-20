#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int n;

int visited[MAX];
int uf[MAX];


int ind = 0;

struct edge
{
    int u;
	int v;
    int w;
};

typedef struct edge edge;

edge *Edges[MAX];

edge *outputEdges[MAX];
int opInd = 0;

void init()
{
	for(int i = 0; i < MAX; i++)
	{
		visited[i] = 0;	
        uf[i] = i;

	}
}

int root(int i)
{
    while(uf[i] != i)
        i = uf[i];
    return i;
}

int Find(int a, int b)
{
    if(root(a) == root(b))
        return 1;
    else
        return 0;
}

int Union(int a ,int b)
{
    int root_a;
    int root_b;
    root_a = root(a);
    root_b = root(b);
    uf[ root_a ] = root_b ;
}

void read_graph()
{
	printf("Enter number of vertices : ");
	scanf("%d",&n);

	int num;

	for(int i = 0; i < n; i++)
	{
		printf("\nEnter number of vertices adjacent to %d : ",i);
		scanf("%d",&num);
		int v;
        int u = i;
        int w;
		
		if(num != 0)
			printf("\nEnter the Vertices Number adjacent to %d and Weight associated with it : ",i);
		for(int j = 0; j < num; j++)
		{
			scanf("%d%d",&v,&w);

			if(v > -1 && v < n)
			{
				edge *ed = (edge*)malloc(sizeof(edge));

				ed->v = v;
                ed->u = u;
                ed->w = w;

                Edges[ind++] = ed;

			}			
			else
			{
				printf("Invalid edge\n");
				j--;
			}
		}

	}
}

void swap(edge *a, edge *b)
{
    edge *temp = (edge*)malloc(sizeof(edge));

    temp->u = a->u;
    temp->v = a->v;
    temp->w = a->w;

    a->u = b->u;
    a->v = b->v;
    a->w = b->w;

    b->u = temp->u;
    b->v = temp->v;
    b->w = temp->w;
}


void sortEdges()
{
    for(int i = 0; i < ind; i++)
    {
        for(int j = i + 1; j < ind; j++)
        {
            //printf("In sortEdges...\n");

            if(Edges[i]->w >= Edges[j]->w)
                swap(Edges[i],Edges[j]);
        }
    }
}

void kruskal()
{
    int doneEdge = 0;

    while(doneEdge != (ind - 1))
    {
        if(Find(Edges[doneEdge]->u,Edges[doneEdge]->v) != 1)
        {
            Union(Edges[doneEdge]->u, Edges[doneEdge]->v);

            edge *ed = (edge*)malloc(sizeof(edge));

            ed->u = Edges[doneEdge]->u;
            ed->v = Edges[doneEdge]->v;
            ed->w = Edges[doneEdge]->w;

            outputEdges[opInd++] = ed;

            printf("Edge %d is %d %d and W : %d\n",doneEdge+1, ed->u,ed->v,ed->w);
        }
        doneEdge++;
    }
}

int main()
{
	init();

	read_graph();
	
    sortEdges();

    kruskal();

	return 0;
}

