#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

 struct Edge{
        int u,v,w;
    };


int main(){

    int V,E,source;
    cout << "Enter the number of vettices: ";
    cin>>V;

    cout<<"Enter the number of Edges: ";
    cin>>E;
    
    vector<Edge> edge(E);
    cout<<"\nEnter the input in the format (u v w):\n";
    for(int i=0;i<E;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }

    cout<<"\nEnter the source Vertex";
    cin>>source;

    while(source<0 || source>V){
        cout<<"Invalid source the value should be between 0 and "<<V;
        cout<<"\nEnter the source Vertex";
        cin>>source;
    }

    vector<int> dist(V,INT_MAX);
    vector<int> Parent(V,-1);

    for(int i=0;i<V-1;i++){
        for(int j=0;j<E;j++){
            int u=edge[j].u;
            int v=edge[j].v;
            int w=edge[j].w;
            if(dist[u]!=INT_MAX || (dist[u]+w) < dist[v] ){
                dist[v]=dist[u]+w;
                Parent[v]=u;
            }
        }
    }


    bool isCycle=false;
        for(int j=0;j<E;j++){
            int u=edge[j].u;
            int v=edge[j].v;
            int w=edge[j].w;
            if(dist[u]!=INT_MAX || (dist[u]+w)<dist[v]){
                isCycle=true;
            }
    }

    if(isCycle){
        cout<<"There is a negative Edge cycle in the graph";
    }else {
        cout << "\nVertex\tDistance\tParent" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << "\t";
            if (dist[i] == INT_MAX) 
                cout << "INF\t\t";
            else
                cout << dist[i] << "\t\t";
            
            if (Parent[i] == -1)
                cout << "None";
            else
                cout << Parent[i];
            cout << endl;
        }
    }

    return 0;

}