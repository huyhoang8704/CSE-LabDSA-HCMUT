class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	void dfs(int v, Adjacency* result, bool* visited){
	    if(visited[v] == false){
	        visited[v] = true;
	       result->push(v);
          for(int i = 0 ; i < adj[v].getSize(); i++){
                int tmp = adj[v].getElement(i);
                dfs(tmp, result, visited);
                 visited[tmp] = true;
            }	        
	    }
	}
	
	Adjacency *DFS(int v)
    {
        bool visited[V] = {false};
        Adjacency* result = new Adjacency();
        //visited[v] = true;
        dfs(v, result, visited);
        
        return result;
        // v is a vertex we start DFS
	}
};