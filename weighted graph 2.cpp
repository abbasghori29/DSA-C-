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

         newNode = new Node;
         newNode->dest = src;
         newNode->weight = weight;
         newNode->next = adjList[dest];
         adjList[dest] = newNode;
    }

    void display() {
        for (int i = 0; i < MAX_VERTICES; ++i) {
            Node* current = adjList[i];
            cout << "Adjacency List for vertex " << i << ":";
            while (current != NULL) {
                cout << " -> " << current->dest;;
                current = current->next;
            }
            cout << "\n";
        }
    }
 void bfs(){
    	bool visited[MAX_VERTICES]={false};
    	for(int i=0;i<MAX_VERTICES;i++){
    		if(!visited[i]){
    			bfsUtil(i,visited);
			}
		}
	}
	void bfsUtil(int startVertex,bool *visited){
		queue<int> q;
		visited[startVertex]=true;
		q.push(startVertex);
		if(adjList[startVertex]!=NULL){
					cout<<startVertex<" ";

		}
		while(!q.empty()){
			int cuurentVertex=q.front();
			q.pop();
			Node *temp=adjList[cuurentVertex];
			while(temp!=NULL){
				int adjVertex=temp->dest;
				if(!visited[adjVertex]){
					cout<<" "<<adjVertex<<" ";
					visited[adjVertex]=true;
					q.push(adjVertex);
				}
				temp=temp->next;
			}
		}
	}
		void dfs(){
    	bool visited[MAX_VERTICES]={false};
    	for(int i=0;i<MAX_VERTICES;i++){
    		if(!visited[i]){
    			bfsUtil(i,visited);
			}
		}
	}
		void dfsUtil(int startVertex,bool *visited){
		stack<int> s;
		visited[startVertex]=true;
		s.push(startVertex);
		if(adjList[startVertex]!=NULL){
			cout<<startVertex<" ";

		}
		while(!s.empty()){
			int cuurentVertex=s.top();
			s.pop();
			Node *temp=adjList[cuurentVertex];
			while(temp!=NULL){
				int adjVertex=temp->dest;
				if(!visited[adjVertex]){
					cout<<" "<<adjVertex<<" ";
					visited[adjVertex]=true;
					s.push(adjVertex);
				}
				temp=temp->next;
			}
		}
	}
	bool isCycle(){
			bool visited[MAX_VERTICES]={false};
			int parent[MAX_VERTICES]={-1};
		for(int i=0;i<MAX_VERTICES;i++){
			if(isCycleUtil(i,visited,parent)){
				return true;
			}
		}
		return false;
	}
 bool isCycleUtil(int startVertex,bool *visited,int *parent){
 	queue<int> q;
 	q.push(startVertex);
 	visited[startVertex]=true;
 	parent[startVertex]=-1;
 	while(!q.empty()){
 	   	int current=q.front();
 		q.pop();
 		Node *temp=adjList[current];
 		while(temp!=NULL){
 			if(!visited[temp->dest]){
 				q.push(temp->dest);
 				visited[temp->dest]=true;
 				parent[temp->dest]=current;
			 }
			 else if(visited[temp->dest]==true && parent[temp->dest]!=current){
			 	return true;
			 }
			 temp=temp->next;
		 }
 		
 		
	 }
 	return false;
 }
  void dijkstra(int start, int end) {
  	bool visited[MAX_VERTICES];
  	int dist[MAX_VERTICES];
  	 int parent[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; ++i){
      dist[i] = INT_MAX;
      parent[i] = -1;
      visited[i]=false;
   }

  	dist[start]=0;
  	while(!visited[end]){
	  
  		int u=findMinDistanceVertex(dist,visited);
  	    visited[u]=true;
  	    Node *temp=adjList[u];
  	    while(temp!=NULL){
  	    	int v=temp->dest;
  	    	int w= temp->weight;
  	    	if(!visited[v] && dist[u]!=INT_MAX && dist[u]+w<dist[v] ){
  	    		dist[v]=dist[u]+w;
  	    		parent[v]=u;
			  }
			  temp=temp->next;
		  }
	  }
	  printShortestPath(parent,end);
        
    }
     void printShortestPath(int parent[], int j) {
        if (parent[j] == -1) {
            cout << j << " ";
            return;
        }

        printShortestPath(parent, parent[j]);
        cout << j << " ";
    }

  int findMinDistanceVertex(int dist[], bool visited[]) {
    int minDist = INT_MAX, minInd = -1;
    for (int i = 0; i < MAX_VERTICES; ++i) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minInd = i;
        }
    }
    return minInd;
}
void primsMST() {
    int key[MAX_VERTICES];
    int parent[MAX_VERTICES];
    bool inMST[MAX_VERTICES];

    for (int i = 0; i < MAX_VERTICES; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        inMST[i] = false;
    }

    key[0] = 0;  // Start from vertex 0
    int vertices_in_MST = 0;

    for(int i=0;i<MAX_VERTICES-1;i++) {
        int u = findMin(key, inMST);
        if (u == -1) {
            break; // Exit loop if no valid minimum index found
        }
        inMST[u] = true;
        

        Node* temp = adjList[u];
        while (temp != NULL) {
            int v = temp->dest;
            int w = temp->weight;
            if (!inMST[v] && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
            temp = temp->next;
        }
    }

    cout << "Edges of Minimum Spanning Tree:\n";
for (int i = 1; i < MAX_VERTICES; i++) {
    if (parent[i] != -1) {
        cout << "Edge: " << parent[i] << " - " << i << " Weight: " << key[i] << "\n";
    }
}

}

int findMin(int key[], bool inMST[]) {
    int min = INT_MAX, minIndex = -1;
    for (int i = 0; i < MAX_VERTICES; ++i) {
        if (!inMST[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

};

int main() {
    Graph g;

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 0, 3); // Adding an edge to create a cycle (3->0)
    g.addEdge(2, 4, 3);
    g.addEdge(4, 5, 3);

//    g.display();
//g.bfs();
//g.dijkstra(0,5);
g.primsMST();
//cout<<g.isCycle();
    
}

