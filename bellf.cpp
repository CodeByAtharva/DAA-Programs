#include <iostream>
#include <climits>
using namespace std;

// Function implementing Bellman-Ford algorithm
bool bellmanFord(int source, int edges[][3], int V, int e, int dist[]) {
    // Step 1: Initialize all distances to infinity
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[source] = 0; // Distance from source to itself = 0

    // Step 2: Relax all edges (V - 1) times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edges[j][0];   // Start vertex
            int v = edges[j][1];   // End vertex
            int w = edges[j][2];   // Weight of the edge

            // If the source vertex distance is not infinite and
            // a shorter path to 'v' is found via 'u', then update it
            if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int j = 0; j < e; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        // If we can still relax an edge, a negative cycle exists
        if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
            return true;
    }

    return false; // No negative cycle found
}

int main() {
    int V, e;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> e;

    int edges[e][3]; // ✅ Declared after knowing 'e'

    // Input edges
    cout << "\nEnter each edge as: StartVertex EndVertex Weight\n";
    for (int i = 0; i < e; i++) {
        cout << "Edge " << i + 1 << ": ";
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int source;
    cout << "\nEnter the source vertex: ";
    cin >> source;

    int dist[V];
    bool isCycle = bellmanFord(source, edges, V, e, dist);

    // Print shortest distances
    cout << "\nShortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << "Vertex " << i << " is unreachable.\n";
        else
            cout << "Distance to vertex " << i << " = " << dist[i] << endl;
    }

    // Print cycle information
    if (isCycle)
        cout << "\n Negative weight cycle detected in the graph.\n";
    else
        cout << "\n No negative weight cycle found.\n";

    return 0;
}
