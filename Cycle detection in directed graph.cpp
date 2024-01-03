#include <iostream>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

const int MAX_VERTICES = 10;

struct Node {
    int dest;
    int weight;
    Node* next;
};

class Graph {
private:
    Node* adjList[MAX_VERTICES];

public:
    Graph() {
        for (int i = 0; i < MAX_VERTICES; ++i) {
            adjList[i] = NULL;
        }
    }

    void addEdge(int src, int dest, int weight) {
        Node* newNode = new Node;
        newNode->dest = dest;
        newNode->weight = weight;
        newNode->next = adjList[src];
        adjList[src] = newNode;
    }

    bool isCyclic() {
        bool visited[MAX_VERTICES] = {false};
        bool recursionStack[MAX_VERTICES] = {false};

        for (int i = 0; i < MAX_VERTICES; ++i) {
            if (!visited[i] && isCyclicUtil(i, visited, recursionStack)) {
                return true;
            }
        }
        return false;
    }

    bool isCyclicUtil(int start, bool visited[], bool recursionStack[]) {
        stack<int> stack;
        stack.push(start);

        while (!stack.empty()) {
            int v = stack.top();
            stack.pop();

            if (!visited[v]) {
                visited[v] = true;
                recursionStack[v] = true;

                Node* current = adjList[v];
                while (current) {
                    int neighbor = current->dest;

                    if (!visited[neighbor]) {
                        stack.push(neighbor);
                    } else if (recursionStack[neighbor]) {
                        return true; // Cycle detected
                    }
                    current = current->next;
                }
            }
            recursionStack[v] = false;
        }
        return false;
    }

    void dijkstra(int start, int end) {
        bool visited[MAX_VERTICES] = {false};
        int dist[MAX_VERTICES];
        int parent[MAX_VERTICES];

        for (int i = 0; i < MAX_VERTICES; ++i) {
            dist[i] = INT_MAX;
            parent[i] = -1;
        }

        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) {
                continue;
            }
            visited[u] = true;

            Node* temp = adjList[u];
            while (temp !=  NULL) {
                int v = temp->dest;
                int w = temp->weight;

                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
                temp = temp->next;
            }
        }

        if (dist[end] == INT_MAX) {
            cout << "There is no path from vertex " << start << " to vertex " << end << ".\n";
            return;
        }

        stack<int> path;
        int current = end;
        while (current != -1) {
            path.push(current);
            current = parent[current];
        }

        cout << "Shortest path from vertex " << start << " to vertex " << end << ":\n";
        while (!path.empty()) {
            cout << path.top() << " ";
            path.pop();
        }
        cout << "\nTotal distance: " << dist[end] << "\n";
    }
};

int main() {
    Graph g;

    // Adding edges to the graph
     g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 0, 3); // Adding an edge to create a cycle (3->0)
    g.addEdge(2, 4, 3);
    g.addEdge(4, 5, 3);

    int startVertex = 0; // Replace with the desired start vertex
    int endVertex = 5;   // Replace with the desired end vertex

    g.dijkstra(startVertex, endVertex);

    if (g.isCyclic()) {
        cout << "Graph contains a cycle";
    }
    
}

