#include<bits/stdc++.h>
using namespace std;

const int N=4;
int final_path[N+1];
bool visited[N];

int final_result = INT_MAX;


int copyToFinal(int current_path[N])
{
    for(int i=0;i<N;i++)
    {
        final_path[i] = current_path[i];
    }

    final_path[N] = current_path[0];
}

int firstMin(int adj[N][N],int i)
{
    int m = INT_MAX;

    for(int k=0;k<N;k++)
    {
        if(adj[i][k] < m && k!=i)
        {
            m = adj[i][k];
        }
    }
    return m;
}

int secondMin(int adj[N][N],int i)
{
    int first = INT_MAX;
    int second = INT_MAX;

    for(int j=0;j<N;j++)
    {
        if(adj[i][j] <= first && i!=j)
        {
            second = first;
            first = adj[N][N];
        }
        else if(adj[i][j] <= second)
        {
            second = adj[i][j];
        }
    }
    return second;
}

void tspRec(int adj[N][N],int current_bound,int current_weight,int level,int current_path[])
{
    if(level == N)
    {
        


        return;
    }
}
int tsp(int adj[N][N])
{
    int current_path[N+1];
    int current_bound = 0;

    memset(current_path,-1,sizeof(current_path));
    memset(visited,0,sizeof(current_path));

    for(int i=0;i<N;i++)
    {
        current_bound += firstMin(adj,i) + secondMin(adj,i);
    }

    current_bound = (current_bound+1) / 2;

    visited[0] = true;
    current_path[0] = 0;

    tspRec(adj,current_bound,0,1,current_path);

}
int main()
{
    int adj[N][N] = {{0, 10, 15, 20}, // Adjacency matrix for the given graph
					 {10, 0, 35, 25},
					 {15, 35, 0, 30},
					 {20, 25, 30, 0}
                    };
    
    int ans = tsp(adj);

    return 0;
}