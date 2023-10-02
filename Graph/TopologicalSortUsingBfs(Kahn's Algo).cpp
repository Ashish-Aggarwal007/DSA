#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> topoSort(int N, vector<int> adj[]) {
        queue<int> q; 
        // here finding out the all incoming edges to every node
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	// for every node having zero indegree or No incoming Edges
    // push it to queue
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
        // vector topo store the element of toposorting
	    vector<int> topo;
	    while(!q.empty()) {
            // take the front node (first node) of graph and 
            // push it into the vector topo
	        int node = q.front(); 
            // removing the node 
	        q.pop(); 
	        topo.push_back(node);
            // and traverse all of its adjacent node and 
            // substract the indegree by 1 or remove the dependency of that 
            // to the adjacent node and if indegree of that node is 0. just push
            // it into the queue.
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return topo;
	}
};



int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
        vector<int> result = obj.topoSort(V, adj);
    	for(auto node : result){
            cout<<node<<" ";
        }
    }

    return 0;
}

/*
Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.

Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).
*/