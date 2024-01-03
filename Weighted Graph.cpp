#include <iostream>
using namespace std;
struct Edge {
    char destination;
    int weight;
};

class ArrayList {
public:
	Edge* arr;
    int capacity;
    int size;
    ArrayList(int cap = 10) : capacity(cap), size(0) {
        arr = new Edge[capacity];
    }

    void add(char destination, int weight) {
        if (size < capacity) {
            arr[size].destination = destination;
            arr[size].weight = weight;
            size++;
        } else {
            cout << "Array is full. Resize logic needed." << "\n";
        }
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << "(" << arr[i].destination << ", " << arr[i].weight << ") ";
        }
        cout << "\n";
    }
};

class Graph {
private:
    int vertices;
    ArrayList* adjList;
    int vertexCount; // Store the count of vertices added

public:
    Graph(int v) : vertices(v), vertexCount(0) {
        adjList = new ArrayList[vertices];
    }

    int getVertexIndex(char vertex) {
        for (int i = 0; i < vertexCount; ++i) {
            if (adjList[i].size > 0 && adjList[i].arr[0].destination == vertex) {
                return i;
            }
        }
        return -1;
    }

    void addEdge(char start, char end, int weight) {
        int startIndex = getVertexIndex(start);
        if (startIndex == -1) {
            adjList[vertexCount].add(start, 0); // Adding vertex to adjacency list with weight 0
            startIndex = vertexCount;
            vertexCount++;
        }
        
        int endIndex = getVertexIndex(end);
        if (endIndex == -1) {
            adjList[vertexCount].add(end, 0);
            endIndex = vertexCount;
            vertexCount++;
        }

        adjList[startIndex].add(end, weight);
        adjList[endIndex].add(start, weight); // For undirected graph
    }

    void display() {
        for (int i = 0; i < vertexCount; ++i) {
            cout << "Adjacency list of vertex " << adjList[i].arr[0].destination << ": ";
            adjList[i].display();
        }
    }
};

int main() {
    int V = 5;
    int E = 7;

    Graph graph(V);

    // Assuming vertices are represented by any characters
    char edges[][3] = {{'A', 'B', 2}, {'A', 'E', 1}, {'E', 'B', 4}, {'E', 'D', 3}, {'B', 'D', 5}, {'B', 'C', 7}, {'D', 'C', 6}};

    for (int i = 0; i < E; i++) {
        graph.addEdge(edges[i][0], edges[i][1], edges[i][2]);
    }

    cout << "Adjacency List:" << "\n";
    graph.display();

    return 0;
}

