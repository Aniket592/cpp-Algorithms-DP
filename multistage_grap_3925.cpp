#include<bits/stdc++.h>
using namespace std;

typedef struct graph{
	int src,des,wt;
}graph;

int multistage(graph* g,int v,int e)
{
	int cost[v],path[v];
	for(int i=0;i<v;i++)
	{
		cost[i]=INT_MAX;
		path[i]=INT_MAX;
	}
	cost[v-1]=0;
	path[v-1]=v-1;
	for(int i=v-1;i>=0;i--)
	{
		for(int j=0;j<e;j++)
		{
			if(g[j].des==i)
			{
				int j1=cost[g[j].src];
				cost[g[j].src]=min((cost[i]+g[j].wt),cost[g[j].src]);
				if(cost[g[j].src]<j1)
				{
					path[g[j].src]=i;
				}	
			}
		}
	}
	cout<<"\n\nPath ->  ";
	int i=0;
	cout<<"0"<<" -> ";
	while(path[i]<(v-1))
	{
		cout<<path[i]<<" -> ";
		i=path[i];
	}
	cout<<path[i];
	cout<<endl;
	return cost[0];
}

int main()
{
	int v,e;
	cout<<"Enter the number of vertices:- ";
	cin>>v;
	cout<<"\nEnter the number of edges:- ";
	cin>>e; 
	graph g[e];
	cout<<"\nEnter the source - destination - weight of each edge:- \n";
	for(int i=0;i<e;i++)
	{
		cin>>g[i].src>>g[i].des>>g[i].wt;
	}
	int m=multistage(g,v,e);
	cout<<"\nShortest path distance :- "<<m<<endl;

	return 0;
}


/*
input & output

Enter the number of vertices:- 12

Enter the number of edges:- 21

Enter the source - destination - weight of each edge:- 
0 1 9
0 2 7
0 3 3
0 4 2
1 5 4
1 6 2
1 7 1
2 5 2
2 6 7
3 7 11
4 6 11
4 7 8
5 8 8
5 9 5
6 8 4
6 9 3
7 9 5
7 10 8
8 11 4
9 11 2
10 11 5


Path ->  0 -> 2 -> 5 -> 9 -> 11

Shortest path distance :- 16


*/
