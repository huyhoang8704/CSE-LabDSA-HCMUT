#include<iostream>

using namespace std;

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
	
	Adjacency *BFS(int v)
    {
        Adjacency * result = new Adjacency();
        list<int> q;
        bool visited[V] = {false};
        q.push_back(v);
        visited[v] = true;
        while(!q.empty()){
            int e = q.front();
            q.pop_front();
            result->push(e);
            //cout << e << endl;
          for(int i = 0 ; i < adj[e].getSize(); i++){
              int tmp = adj[e].getElement(i);
                if(visited[tmp] == false){
                    q.push_back(tmp);
                    visited[tmp] = true;
                }
            }
            
        }
        return result;
	}
};