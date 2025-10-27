#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

struct Edge {
    int u, v, w; // u->v with weight w
};

int main() {
    int V, E, source;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges in format (u v w):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> dist(V, INT_MAX); //The dist array stores the shortest distance from the source vertex to every other vertex.,
                                  // Initializes each element of this vector with INT_MAX.
                                  //dist = [INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX]
    vector<int> parent(V, -1);

    dist[source] = 0;

    // Relax edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    // Check for negative weight cycle
    bool negCycle = false;
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            negCycle = true;
            break;
        }
    }

    if (negCycle) {
        cout << "Graph contains a negative weight cycle!" << endl;
    } else {
        cout << "\nVertex\tDistance\tParent" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << "\t";
            if (dist[i] == INT_MAX) 
                cout << "INF\t\t";
            else
                cout << dist[i] << "\t\t";
            
            if (parent[i] == -1)
                cout << "None";
            else
                cout << parent[i];
            cout << endl;
        }
    }

    return 0;
}