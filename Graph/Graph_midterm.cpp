#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int v, w;
};

class Graph {
public:
    vector<vector<int>> adjList;
    Graph(vector<Edge> const& edges, int n) {
        adjList.resize(n);
        for (auto& edge : edges) {
            adjList[edge.v].push_back(edge.w);
            adjList[edge.w].push_back(edge.v);
        }
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void removeEdge(int src, int dest) {
        for (int i = 0; i < adjList[src].size(); i++) {
            if (adjList[src][i] == dest) {
                adjList[src].erase(adjList[src].begin() + i);
                break;
            }
        }
        for (int i = 0; i < adjList[dest].size(); i++) {
            if (adjList[dest][i] == src) {
                adjList[dest].erase(adjList[dest].begin() + i);
                break;
            }
        }
    }

    void printGraph(Graph const& graph, int n) {
        for (int i = 0; i < n; i++) {
            cout << i << " -> ";
            for (int v : graph.adjList[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void BFS(int startVertex) const {
        vector<bool> visited(adjList.size(), false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            cout << currentVertex << " ";

            for (int adjacentVertex : adjList[currentVertex]) {
                if (!visited[adjacentVertex]) {
                    visited[adjacentVertex] = true;
                    q.push(adjacentVertex);
                }
            }
        }
    }
};

int main() {
    vector<Edge> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 3}, {1, 4}, {2, 3}, {3, 4}};
    int n = 5;
    Graph graph(edges, n);

    cout << "Initial Adjacency List:" << endl;
    graph.printGraph(graph, n);

    cout << "\nAdding edge (2, 4)..." << endl;
    graph.addEdge(2, 4);
    graph.printGraph(graph, n);

    cout << "\nRemoving edge (3, 4)..." << endl;
    graph.removeEdge(3, 4);
    graph.printGraph(graph, n);

    cout << "\nBreadth-First Search starting from vertex 3: ";
    graph.BFS(3);
    cout << endl;

    return 0;
}
