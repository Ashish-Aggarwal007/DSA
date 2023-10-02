
class solution
{
public:
	bool checkForCycle(int s, int V, vector<int> adj[]. vector<int>& visited)
	{
		// creates a queue for BFS
		queue<pair<int, int>> q;
		visited[s] = true;
		// initially parent node of source node is taken as -1
		q.push({s, -1});

		while(!q.empty())
		{
			int node = q.front().first;
			int par = q.front().second;
			q.pop();
			// check for every adjacent node visited or not
			for(auto it : adj[node])
			{
				if(!visited[it]){
					visited[it] = true;
					q.push({it, node});
				}
				// if the node is already visited and not a parent node
				// then their is a cycle exists 
				else if(par != it)
				{
					return true;
				}
			}
		}
		return false;
	}
public:
	bool isCycle(int V, vector<int>adj[])
	{
		vector<int> vis(V+1, 0);
		for(int i=1;i<=V;i++)
		{
			if(!vis[i]){
				if(checkForCycle(i, V, adj, vis)) return true;
			}
		}
		return false;
	}
};