// BFS traversal also called Level Order Traversal
// uses queue 

class Solution
{
public:
	vector<int> bfsOfGraph(int V, vector<int> adj[]) {
		vector<int> bfs;
		// for 1 base indxing V+1
		vector<int> vis(V+1, 0);

		for(int i=1; i<V; i++){
			if(!vis[i]) {
				// insert the first ele in the queue 
				queue<int> q;
				q.push(i);
				vis[i] = 1;
				while(!q.empty())
				{
					int node = q.front();
					q.pop();
					bfs.push_back(node);
					// move to all the adjacent nodes of it 	
					for(auto it : adj[node]){
						if(!vis[it]){
							q.push(it);
							vis[it] = 1;
						}
					}
				}
			}
		}
		return bfs;
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
	result = obj.bfsOfGraph(V, adj);
	
	for(int i=0; i<result.size(); i++)
	{
		cout<<result[i]<< " ";
	}
	return 0;
}