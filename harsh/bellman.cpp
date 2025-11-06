#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// struct Edge {
//     int u, v, w; // u->v with weight w
// };

// int main() {
//     int V, E, source;
//     cout << "Enter number of vertices: ";
//     cin >> V;
//     cout << "Enter number of edges: ";
//     cin >> E;

//     vector<Edge> edges(E);

//     cout << "Enter edges in format (u v w):" << endl;
//     for (int i = 0; i < E; i++) {
//         cin >> edges[i].u >> edges[i].v >> edges[i].w;
//     }

//     cout << "Enter source vertex: ";
//     cin >> source;

//     vector<int> dist(V, INT_MAX);
//     vector<int> parent(V, -1);

//     dist[source] = 0;

//     // Relax edges V-1 times
//     for (int i = 1; i <= V - 1; i++) {
//         for (int j = 0; j < E; j++) {
//             int u = edges[j].u;
//             int v = edges[j].v;
//             int w = edges[j].w;

//             if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
//                 dist[v] = dist[u] + w;
//                 parent[v] = u;
//             }
//         }
//     }

//     // Check for negative weight cycle
//     bool negCycle = false;
//     for (int j = 0; j < E; j++) {
//         int u = edges[j].u;
//         int v = edges[j].v;
//         int w = edges[j].w;

//         if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
//             negCycle = true;
//             break;
//         }
//     }

//     if (negCycle) {
//         cout << "Graph contains a negative weight cycle!" << endl;
//     } else {
//         cout << "\nVertex\tDistance\tParent" << endl;
//         for (int i = 0; i < V; i++) {
//             cout << i << "\t";
//             if (dist[i] == INT_MAX) 
//                 cout << "INF\t\t";
//             else
//                 cout << dist[i] << "\t\t";
            
//             if (parent[i] == -1)
//                 cout << "None";
//             else
//                 cout << parent[i];
//             cout << endl;
//         }
//     }

//     return 0;
// }
// struct edge{
//     int u,v,w;
// };
// int main(){
//     int V,E;
//     int source;
//     cout<<"Enter the no. of vertices in graph :";
//     cin>>V;
    
//     cout<<"Enter the no. of edges in graph :";
//     cin>>E;

//     vector<edge> edges(E);

//     for(int i=0;i<E;i++){
//         cout<<"Enter source of edge "<<i+1<<" :";
//         cin>>edges[i].u;

//         cout<<"Enter dest of edge "<<i+1<<" :";
//         cin>>edges[i].v;

//         cout<<"Enter weight of edge "<<i+1<<" :";
//         cin>>edges[i].w;
//     }
//     cout<<"Enter the source :";
//     cin>>source;
//     vector<int> dist(V,INT_MAX);
//     vector<int> parent(V,-1);
//     dist[source]=0;
//     for(int i=0;i<V-1;i++){
//         for(int j=0;j<E;j++){
//             int u=edges[j].u;
//             int v=edges[j].v;
//             int w=edges[j].w;

//             if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
//                 dist[v]=dist[u]+w;
//                 parent[v]=u;
//             }
//         }
//     }
//     bool isneg=false;
//     for(int j=0;j<E;j++){
//         int u=edges[j].u;
//         int v=edges[j].v;
//         int w=edges[j].w;

//         if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
//             isneg=true;
//         }
//     }
//     if(isneg){
//         cout<<"there exist a negative edge cycle in graph";
//     }
//     else{
//         cout<<"vertex  distance  parent"<<endl;
//         for(int i=0;i<V;i++){
//             cout<<"   "<<i<<"      "<<(dist[i]==INT_MAX)?dist[i]:"INF"<<"      "<<parent[i]<<endl;
//         }
//     }
//     return 0;
// }
struct edge{
    int u;
    int v;
    int w;
};
int main(){
    int V,E;
    cout<<"Enter the no. of vertices in the graph :";
    cin>>V;
    cout<<"Enter the no. of edges in the graph :";
    cin>>E;
    edge e[E];
    for(int i=0;i<E;i++){
        cout<<"Enter edge no. :"<<i+1<<endl;
        cout<<"Enter the start vertex:";
        cin>>e[i].u;
        cout<<"Enter the end vertex :";
        cin>>e[i].v;
        cout<<"Enter the weight :";
        cin>>e[i].w;
    }
    int source;
    cout<<"Enter the source vertex :";
    cin>>source;
    int dist[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
    }
    dist[source]=0;
    for(int i=0;i<=V-1;i++){
        for(int j=0;j<E;j++){
            int u=e[j].u;
            int v=e[j].v;
            int w=e[j].w;
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
            }
        }
    }
    bool negCycle=false;
    for(int j=0;j<E;j++){
        int u=e[j].u;
        int v=e[j].v;
        int w=e[j].w;
        if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
            negCycle=true;
        }
    }
    if(!negCycle){
        cout<<"node        dist"<<endl;
        for(int i=0;i<V;i++){
            cout<<i<<"            "<<dist[i]<<endl;
        }
    }
    else{
        cout<<"Graph contain negative edge cycle !";
    }
    return 0;
}