#include <iostream>
#include <vector>
using namespace std;

//  function to display graph
void printGraph_list(vector<pair<int,int> > adj[], int V){
    int v, w;
    for(int u = 0; u < V; u++){
        cout << u;
        for(auto it = adj[u].begin(); it!=adj[u].end(); it++){
            v = it->first;
            w = it->second;
            cout << "\t-> \t" << v << "\tweight: " << w << "\n";
        }
        cout << "\n";
    }
}

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void MaxPath(vector<pair<int, int>> adj[], int u, int V, vector<bool>& visited, int& maxCost, vector<int>& currentPath, vector<int>& maxPath) {
    visited[u] = true;
    currentPath.push_back(u);

    if (u == V - 1) { // Reached the destination vertex
        int cost = 0;
        for (int i = 0; i < currentPath.size() - 1; ++i) {
            int u = currentPath[i];
            int v = currentPath[i + 1];
            for (auto edge : adj[u]) {
                if (edge.first == v) {
                    cost += edge.second;
                    break;
                }
            }
        }

        if (cost > maxCost) {
            maxCost = cost;
            maxPath = currentPath;
        }
    }

    for (auto edge : adj[u]) {
        int v = edge.first;
        if (!visited[v]) {
            MaxPath(adj, v, V, visited, maxCost, currentPath, maxPath);
        }
    }

    visited[u] = false;
    currentPath.pop_back();
}

int main() {
    vector<pair<int, int>> adj[9];
    // add edge to graph
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    cout << "\tGraph Information" << endl;
    printGraph_list(adj, 9);
    
    vector<bool> visited(9, false);
    vector<int> currentPath, maxPath;
    int maxCost = 0;

    MaxPath(adj, 0, 9, visited, maxCost, currentPath, maxPath);

    cout << "Maximum cost path: ";
    for (int vertex : maxPath) {
        cout << vertex << " ";
    }
    cout << endl;
    cout << "Total cost = " << maxCost << endl;

    return 0;
}
