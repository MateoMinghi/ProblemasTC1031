#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, const vector<int>& costs, int& minCost) {
    
    visited[node] = true; //saber qué nodos ya visitamos
    minCost = min(minCost, costs[node]); //mantenemos conocimiento del mínimo

    /*iteramos en todos los vecinos en la lista de adyacencia y se hace la llamada
    recursiva*/
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, costs, minCost);
        }
    }

    
}

int main() {
    int n, m;
    cin >> n >> m;


    //lista de costos
    vector<int> costs(n);
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    //construimos la lista de adyacencia
    vector<vector<int>> adj(n);
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;  
        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    //vector para saber qué nodos se han visitado (estén conectados o no)
    vector<bool> visited(n, false);
    long long totalCost = 0; //suma cumulativa del costo

    //aplicamos el DFS a cada nodo
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int minCost = costs[i];
            dfs(i, adj, visited, costs, minCost);
            totalCost += minCost;  
        }
    }

    
    cout << totalCost << endl;

    return 0;
}
