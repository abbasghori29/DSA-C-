#include <iostream>
using namespace std;
#define MAX_VERTICES 10
#define MAX_EDGES 10
#define INT_MAX 999999

// Node structure to represent vertices and edges in the graph
struct Node {
    char vertex;
    int weight;
};

// Dynamic array structure
struct ArrayList {
    Node arr[MAX_EDGES];
    int size;
};

// Graph class to represent a weighted undirected graph
struct Graph {
    ArrayList adjList[MAX_VERTICES];
    int vertices;

    Graph() {
        vertices = 0;
    }

    void addEdge(char u, char v, int weight) {
        int idx = findIndex(u);
        if (idx == -1) {
            adjList[vertices].size = 0;
            adjList[vertices].arr[adjList[vertices].size++] = {u, 0};
            idx = vertices++;
        }
        adjList[idx].arr[adjList[idx].size++] = {v, weight};

        idx = findIndex(v);
        if (idx == -1) {
            adjList[vertices].size = 0;
            adjList[vertices].arr[adjList[vertices].size++] = {v, 0};
            idx = vertices++;
        }
        adjList[idx].arr[adjList[idx].size++] = {u, weight};
    }

    int findIndex(char v) {
        for (int i = 0; i < vertices; ++i) {
            if (adjList[i].arr[0].vertex == v) {
                return i;
            }
        }
        return -1;
    }

    int dijkstra(char start, char end) {
        int distance[MAX_VERTICES];
        bool visited[MAX_VERTICES];

        for (int i = 0; i < vertices; ++i) {
            distance[i] = INT_MAX;
            visited[i] = false;
        }

        int startIdx = findIndex(start);
        if (startIdx == -1) return -1;

        distance[startIdx] = 0;

        while (true) {
            int minDist = INT_MAX;
            int u = -1;

            for (int i = 0; i < vertices; ++i) {
                if (!visited[i] && distance[i] < minDist) {
                    minDist = distance[i];
                    u = i;
                }
            }

            if (u == -1) break;

            visited[u] = true;

            for (int i = 1; i < adjList[u].size; ++i) {
                char v = adjList[u].arr[i].vertex;
                int weight = adjList[u].arr[i].weight;

                int vIdx = findIndex(v);
                if (!visited[vIdx] && distance[vIdx] > distance[u] + weight) {
                    distance[vIdx] = distance[u] + weight;
                }
            }
        }

        int endIdx = findIndex(end);
        if (endIdx != -1) {
            return distance[endIdx];
        } else {
            return -1;
        }
    }
};

int main() {
    Graph g;

    // Adding edges to the graph
    g.addEdge('s', 'a', 4);
    g.addEdge('s', 'b', 2);
    g.addEdge('a', 'b', 5);
    g.addEdge('a', 'c', 10);
    g.addEdge('b', 'e', 3);
    g.addEdge('e', 'c', 4);
    g.addEdge('c', 'd', 3);
    g.addEdge('d', 'e', 7);

    char start = 's';
    char end = 'e';

    int shortestDistance = g.dijkstra(start, end);

    if (shortestDistance != -1) {
        cout << "Shortest distance from " << start << " to " << end << " is: " << shortestDistance << "\n";
    } else {
        cout << "No path from " << start << " to " << end << " found." << "\n";
    }

    return 0;
}

