int parent[100000];

int rank[100000];

void makeSet(){
    for(int i=1; i<=n; i++)
    {
        parent[i] = i;
        rank[i] = 0
    }
}
/* simple Union by Rank without path compression
int findPar(int node)
{
    if(node == parent[node])
        return node;
    return findPar(parent[node]);
}
*/
// path compression 
// by making root all node as ultimate parent 
int findPar(int node)
{
    if(node == parent[node])
        return node;
    return parent[nodoe] = findPar(parent[node]);
}

void union(int u, int v){
    u = findPar(u);
    v = findPar(v);
// component having smaller rank will always point to larger one.
// if the ranks are equal both can point to anyone and rank will increased by 1
    if(rank[u]<rank[v])
        parent[u] = v;
    else if(rank[v] < rank[u])
        parent[v] = u;
    else{
        parent[v] = u;
        rank[u]++;
    }
}
vod main()
{
    makeSet();
    int m;
    cin>>m;
    while(m--){
        int u, v;
        union(u, v);
    }
    if(findPar[2] != findPar(3)){
        cout<<"Different Component";
    }else{
        cout<<"Same Component";
    }
}