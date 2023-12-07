int savingMoney(int n, int scr, int dst, int K, vector<vector<int>> &trains)
{
    vector<pair<int,int>> adj[n];
    for(auto it:trains)
    {
        adj[it[0]].push_back({it[1],it[2]});
    }

    vector<int> minCost(n,1e9);
    minCost[scr]=0;

    queue< pair<int, pair<int,int> > > q;   //{stops,{node, money}}
    q.push({0,{scr,0}});

    while(!q.empty())
    {
        int stops = q.front().first;
        int node = q.front().second.first;
        int dis = q.front().second.second;
        q.pop();

        if(stops>K) continue;
        for(auto it:adj[node])
        {
            int adjNode = it.first;
            int wt = it.second;
            if(minCost[adjNode] > dis + wt){
                minCost[adjNode] = dis + wt;
                q.push({stops+1,{adjNode,minCost[adjNode]}});
            }
        }
    }

    if(minCost[dst]==1e9) return -1;
    return minCost[dst];
}
