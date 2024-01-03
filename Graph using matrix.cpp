#include <iostream>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

const int MAX_VERTICES = 10;

class Graph {
private:
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

public:
    Graph(int vertices) {
        this->numVertices = vertices;

        for (int i = 0; i < MAX_VERTICES; ++i) {
            for (int j = 0; j < MAX_VERTICES; ++j) {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int src, int dest, int weight) {
        adjacencyMatrix[src][dest] = weight;
        adjacencyMatrix[dest][src] = weight; // For undirected graphs
    }

    void removeEdge(int src, int dest) {
        adjacencyMatrix[src][dest] = 0;
        adjacencyMatrix[dest][src] = 0;
    }

    bool isEdge(int src, int dest) {
        return adjacencyMatrix[src][dest] != 0;
    }

    void display() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void BFS(int startVertex) {
        bool visited[MAX_VERTICES] = {false};
        queue<int> q;

        visited[startVertex] = true;
        cout << "BFS starting from vertex " << startVertex << ":\n";
        cout << startVertex << " ";

        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();

            for (int i = 0; i < numVertices; ++i) {
                if (isEdge(currentVertex, i) && !visited[i]) {
                    cout << "-> " << i << " ";
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << "\n";
    }

    void DFS(int startVertex) {
        bool visited[MAX_VERTICES] = {false};
        stack<int> s;

        visited[startVertex] = true;
        cout << "DFS starting from vertex " << startVertex << ":\n";
        cout << startVertex << " ";

        s.push(startVertex);

        while (!s.empty()) {
            int currentVertex = s.top();
            s.pop();

            for (int i = 0; i < numVertices; ++i) {
                if (isEdge(currentVertex, i) && !visited[i]) {
                    cout << "-> " << i << " ";
                    visited[i] = true;
                    s.push(i);
                }
            }
        }
        cout << "\n";
    }

    bool hasPath(int src, int dest) {
        bool visited[MAX_VERTICES] = {false};
        stack<int> s;

        visited[src] = true;
        s.push(src);

        while (!s.empty()) {
            int currentVertex = s.top();
            s.pop();

            for (int i = 0; i < numVertices; ++i) {
                if (isEdge(currentVertex, i) && !visited[i]) {
                    if (i == dest) {
                        return true; // Path found
                    }
                    visited[i] = true;
                    s.push(i);
                }
            }
        }
        return false; // No path found
    }

    void dijkstra(int startVertex, int endVertex) {
        int distance[MAX_VERTICES];
        bool visited[MAX_VERTICES] = {false};
        int parent[MAX_VERTICES];

        for (int i = 0; i < numVertices; ++i) {
            distance[i] = INT_MAX;
            parent[i] = -1;
        }

        distance[startVertex] = 0;

        for (int i = 0; i < numVertices - 1; ++i) {
            int minDistance = INT_MAX, minIndex;

            for (int j = 0; j < numVertices; ++j) {
                if (!visited[j] && distance[j] < minDistance) {
                    minDistance = distance[j];
                    minIndex = j;
                }
            }

            visited[minIndex] = true;

            for (int j = 0; j < numVertices; ++j) {
                if (!visited[j] && isEdge(minIndex, j) && distance[minIndex] != INT_MAX &&
                    distance[minIndex] + adjacencyMatrix[minIndex][j] < distance[j]) {
                    distance[j] = distance[minIndex] + adjacencyMatrix[minIndex][j];
                    parent[j] = minIndex;
                }
            }
        }

        // Print the shortest path and its weight
        cout << "Shortest Path from vertex " << startVertex << " to vertex " << endVertex << ":\n";
        printPath(startVertex, endVertex, parent);
        cout << "Weight: " << distance[endVertex] << "\n";
    }

    void printPath(int startVertex, int endVertex, int parent[]) {
        if (endVertex == -1)
            return;

        printPath(startVertex, parent[endVertex], parent);

        cout << endVertex;
        if (endVertex != startVertex)
            cout << " -> ";
    }
};

int main() {
    Graph graph(6);

    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 3, 4);
    graph.addEdge(2, 3, 7);
    graph.addEdge(4, 5, 1); // Disconnected vertex

    graph.display();

    graph.BFS(0);
    graph.DFS(0);

    cout << "Path from 0 to 3: " << (graph.hasPath(0, 3) ? "Yes" : "No") << "\n";
    cout << "Path from 0 to 5: " << (graph.hasPath(0, 5) ? "Yes" : "No") << "\n";

    graph.removeEdge(1, 3);
    cout << "Edge between 1 and 3 removed.\n";

    graph.display();

    cout << "Path from 0 to 3: " << (graph.hasPath(0, 3) ? "Yes" : "No") << "\n";

    graph.dijkstra(0, 3);

    return 0;
}

