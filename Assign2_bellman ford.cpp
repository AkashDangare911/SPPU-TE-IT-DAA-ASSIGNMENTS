#include<bits/stdc++.h>
using namespace std;

struct graph 
{
    int u;
    int v;
    int wt; 

    graph(int first, int second, int weight) 
    {
        u  = first;
        v  = second;
        wt = weight;
    }
};

bool checkNegativeEdge(vector<graph> edges , int Nodes, vector<int> dp )
{
    bool negEdge = false; 

    for(auto it : edges) 
    {
        if(dp[it.u] + it.wt < dp[it.v]) 
        {
            negEdge = true; 
            break; 
        }
    }

    return negEdge;
}

void bellman(vector<graph> edges , int Nodes)
{
    int src=0;
    int inf = INT_MAX; 

    vector<int> dp(Nodes, inf); 

    dp[src] = 0; 

    for(int i=1; i<=Nodes-1; i++) 
    {
        for(auto it : edges)
        {
            if(dp[it.u] + it.wt < dp[it.v]) 
            {
                dp[it.v] = dp[it.u] + it.wt; 
            }
        }
    }

   bool ret = checkNegativeEdge(edges,Nodes,dp);

     if(ret == false) 
    {
        cout<<"Source \tDestination\tWeight\n";
        for(int i = 0;i<Nodes;i++) 
        {
            cout << 0<<"\t"<<i<<"\t\t"<<dp[i]<<endl;
        }
    }
    else
    {
        cout<<"The graph is having negative cycle !";
    }

}

int main()
{
    int Nodes = 0;
    cout<<"Enter no of nodes : ";
    cin>>Nodes;

    int edge = 0;
    do{
        cout<<"Enter total no of edges : ";     
        cin>> edge;
        if(edge < Nodes-1)
            cout<<"Minimum edges must be greater than or equal to  "<<Nodes-1<<endl;
    }
    while(edge<Nodes-1);


    vector <graph> edges;

    for(int i=0;i<edge;i++)
    {
        int node1 = 0;
        int node2 = 0;
        int wt = 0;

        cout<<"Source : Destination  "<<endl;
        cin>>node1>>node2;

        cout<<"Enter edge weight between "<<node1<<" and "<<node2<<" both nodes : ";  cin>>wt;

        edges.push_back(graph(node1,node2,wt));
    }

    
    bellman(edges,Nodes);

    return 0;
}