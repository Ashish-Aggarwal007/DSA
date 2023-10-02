// Topological Sorting using DFS Algorithm

class Solution
{
    // DFS Algo 
    void finidTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
    {
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                finidTopoSort(it, vis, st, adj);
            }
        }
        st.push(node);
    }
public:
    vector<int> topoSort(int N, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(N, 0);
        for(int i=0; i<N; i++){
            if(vis[i] == 0){
                finidTopoSort(i, vis, st, adj);
            }
        }
        vector<int> topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
}

/* 
Time Complexity: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.

Space Complexity: O(2N) + O(N) ~ O(2N): O(2N) for the visited array and the stack carried during DFS calls and O(N) for recursive stack space, where N = no. of nodes.

*/