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
    int indegree[MAX_VERTICES];

public:
    Graph() {
        for (int i = 0; i < MAX_VERTICES; ++i) {
            adjList[i] = NULL;
            indegree[i] = 0;
        }
    }

    void addEdge(int src, int dest, int weight) {
        Node* newNode = new Node;
        newNode->dest = dest;
        newNode->weight = weight;
        newNode->next = adjList[src];
        adjList[src] = newNode;
        indegree[dest]++; // Increase in-degree of the destination vertex
    }

    void topologicalSort() {
        queue<int> q;
        for (int i = 0; i < MAX_VERTICES; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        vector<int> result;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);

            Node* temp = adjList[u];
            while (temp != NULL) {
                int v = temp->dest;
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
                temp = temp->next;
            }
            count++;
        }

        if (count != MAX_VERTICES) {
            cout << "Graph has a cycle! Topological sort not possible." << endl;
            return;
        }

        cout << "Topological Sort: ";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Graph g;

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 4, 3);
    g.addEdge(4, 5, 3);

    g.topologicalSort();

    return 0;
}

