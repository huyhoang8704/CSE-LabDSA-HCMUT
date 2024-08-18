#include<iostream> 
#include <list>
using namespace std;

class DirectedGraph 
{ 
	int V;
	list<int> *adj;
	bool isCyclicUtil(int v, bool visited[], bool *rs);
public: 
	DirectedGraph(){
        V = 0;
        adj = NULL;
    }
	DirectedGraph(int V)
	{
		this->V = V; 
		adj = new list<int>[V];
	}
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}
	
	bool dfs(int v, bool* visted, int e){
	    int i  = v;
	    if(visted[i] == false){
	        visted[i] = true;
	        bool check = false;
	        for(int i : adj[i]){
	             check =  check || dfs(i, visted, e);
	             if(check) break;
	        }
	        return check;
	    }
	    else if(v == e) return true;
	    return false;
	}
	
	bool isCyclic()
	{
	    for(int i = 0; i < V; i++){
    	    bool visted[V] = {false};
    	    if(dfs(i,visted, i)) return true;
	    }
	    return false;
	}
}; 