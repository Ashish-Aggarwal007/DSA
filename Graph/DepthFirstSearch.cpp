// DFS (uses stack)
class Solution
{
	void dfs(int node, std::vector<init> &vis, std::vector<int> adj[], std::vector<int> &storeDfs)
	{
		// for first node of graph
		storeDfs.push_back(node);
		vis[node] = 1;
		// check for every next adjacency node 
		for(auto it : adj[node])
		{
			if(!vis[it])
				dfs(it, vis, adj, storeDfs);
		}
	}
public:
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
		vector<int> storeDfs;
		vector<int> vis (V+1, 0);
		for(int i=1; i<=V;i++){
			if(!vis[i]){
				dfs(i, vis, adj, storeDfs);
			}
		}
		return storeDfs;
	}
};

int main()
{
	int V, E;
	cin>>V>>E;

	vector<int> adj[V];

	for(int i=0; i<E; i++){
		int u, v;
		cin>>u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	Solution obj;

	vector<int> result;
	result = obj.dfsOfGraph(V, adj);
	
	for(int i=0; i<result.size(); i++)
	{
		cout<<result[i]<< " ";
	}
	return 0;
}

/*
Time complexity - O(N+E)
space Complexity - O(N+E) + O(N) + O(N)
*/