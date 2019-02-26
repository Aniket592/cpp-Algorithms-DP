#include<bits/stdc++.h>
using namespace std;

typedef struct graph{
	int src,des,wt;
}graph;


int main()
{
	int v,e;
	cout<<"Enter the number of vertices:- ";
	cin>>v;
	cout<<"\nEnter the number of edges:- ";
	cin>>e; 
	int d[v],p[v];
	graph g[e];
	cout<<"\nEnter the source - destination - weight of each edge:- \n";
	for(int i=0;i<v;i++)
	{
		d[i]=INT_MAX;
		p[i]=-1;
	}
	int src_pt;
	for(int i=0;i<e;i++)
	{
		cin>>g[i].src>>g[i].des>>g[i].wt;
	}
	cout<<"\nEnter the starting point:- ";
	cin>>src_pt;
	d[src_pt]=0;
	p[src_pt]=src_pt;

	for(int i=0;i<(v-1);i++)
	{
		for(int j=0;j<e;j++)
		{
			if(d[g[j].src]!=INT_MAX && d[g[j].src]+g[j].wt<d[g[j].des])
			{
				d[g[j].des]=d[g[j].src]+g[j].wt;
				p[g[j].des]=g[j].src;
			}
		}
	}

	for(int j=0;j<e;j++)
	{
		if(d[g[j].src]!=INT_MAX && d[g[j].src]+g[j].wt<d[g[j].des])
		{
			cout<<"\nNegative Cycle is Present";
			return 0;
		}
	}
	cout<<"\ndest^n "<<"d[v] "<<"source"<<endl;
	for(int i=0;i<v;i++)
	{
		cout<<" "<<i<<"      "<<d[i]<<"     "<<p[i]<<endl;
	}
	return 0;
}


/*
input & output

Enter the number of vertices:- 5

Enter the number of edges:- 6

Enter the source - destination - weight of each edge:- 
4 3 2
4 1 4
1 0 3
3 1 1
3 2 4
0 2 4

Enter the starting point:- 4

dest^n d[v] source
 0      6     1
 1      3     3
 2      6     3
 3      2     4
 4      0     4
*/