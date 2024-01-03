#include <iostream>
using namespace std;
class ArrayList {
private:
    int* arr;
    int capacity;
    int size;

public:
    ArrayList(int cap = 10) : capacity(cap), size(0) {
        arr = new int[capacity];
    }

    void add(int value) {
        if (size < capacity) {
            arr[size++] = value;
        } else {
            cout << "Array is full. Resize logic needed." << endl;
        }
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Graph {
private:
    int vertices;
    ArrayList* adjList;

public:
    Graph(int v) : vertices(v) {
        adjList = new ArrayList[v];
    }

    void addEdge(int start, int end) {
        adjList[start].add(end);
        adjList[end].add(start); // For an undirected graph
    }

    void display() {
        for (int i = 0; i < vertices; ++i) {
            cout << "Adjacency list of vertex " << i << ": ";
            adjList[i].display();
        }
    }
};

int main() {
    int V = 5;  // Number of vertices
    int E = 7;  // Number of edges

    Graph graph(V);

    // Predefined set of edges
    int edges[][2] = {{0, 1}, {0, 4}, {4, 1}, {4, 3}, {1, 3}, {1, 2}, {3, 2}};

    // Adding edges to the graph
    for (int i = 0; i < E; ++i) {
        graph.addEdge(edges[i][0], edges[i][1]);
    }

    // Print the adjacency list
    cout << "Adjacency List:" << endl;
    graph.display();

}

