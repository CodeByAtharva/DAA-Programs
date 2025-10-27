#include<iostream>
#include <climits>
using namespace std;
bool bellmanFord(int source, int edges[][3], int V, int e, int dist[]) {
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

   
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edges[j][0];
            int dest = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != INT_MAX && dist[dest] > dist[u] + w) {
                dist[dest] = dist[u] + w;
            }
        }
    }

 
    for (int j = 0; j < e; j++) {
        int u = edges[j][0];
        int dest = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != INT_MAX && dist[dest] > dist[u] + w) {
            return true;
        }
    }

    return false;
}
int main(){

	int V = 0;
	int e = 0;
	int edges[e][3];

	cout<<"\nEnter number of edges:";
	cin>>e;
	
	cout<<"\nEnter number of Vertex:";
	cin>>V;
	
	for(int i=0;i<e;i++){
	int u,v,w;
	cout<<"Enter edges no. :"<<i+1<<endl;
	cout<<"Enter the start node :";
	cin>>u;
	
	cout<<"Enter the ending node:";
	cin>>v;

	cout<<"Enter the edge weight:";
	cin>>w;
	
	edges[i][0]=u;
	edges[i][1]=v;
	edges[i][2]=w;
	}

	
	/*
    int edges[10][3] = {
        {0,1,6},
        {0,3,7},
        {1,2,5},
        {1,3,8},
        {1,4,-4},
        {2,1,-2},
        {3,4,9},
        {3,2,-3},
        {4,0,2},
        {4,2,7}
    };*/

    int s = 0;
cout<<"Enter the source node: ";
cin>>s;

int dist[V];
bool isCycle=bellmanFord(s,edges,V,e,dist);
for(int i=0;i<V;i++){
cout<<"distance from "<<s<<" to node "<<i<<" is "<<":"<<dist[i]<<endl;
}
if(isCycle){
cout<<"there exist a  negative edge cycle in graph";
}
else{
cout<<"there doesnt exist a negative edge cycle";
}
return 0;
}
