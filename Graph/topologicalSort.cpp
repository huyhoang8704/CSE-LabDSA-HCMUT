class Graph {

    int V;
    Adjacency* adj;

public:
    Graph(int V){
        this->V = V;
        adj = new Adjacency[V];
    }
    void addEdge(int v, int w){
        adj[v].push(w);
    }
    
    //Heling functions
    void topologicalSortUtil(int v, bool visited[], list<int>& Stack){
         visited[v] = true;
     
        // Recur for all the vertices
        // adjacent to this vertex
        for(int i = 0; i < adj[v].getSize(); i++){
            int tmp = adj[v].getElement(i);
            if (!visited[tmp])
                topologicalSortUtil(tmp, visited, Stack);
        }
     
        // Push current vertex to stack
        // which stores result
        Stack.push_back(v);       
    }
    
    void topologicalSort(){
        list<int> Stack;
     
        // Mark all the vertices as not visited
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
     
        // Call the recursive helper function
        // to store Topological
        // Sort starting from all
        // vertices one by one
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                topologicalSortUtil(i, visited, Stack);
     
        // Print contents of stack
        while (Stack.empty() == false) {
            cout << Stack.back() << " ";
            Stack.pop_back();
        }
    }
};