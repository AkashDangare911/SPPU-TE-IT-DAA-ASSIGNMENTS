#include<bits/stdc++.h>
using namespace std;

int dynamic(vector<int> &profit , vector<int> &weight, int index , int capacity,int n,vector<vector<int>> &dp)
{
    //base case
    if(index == 0)
    {
        if(weight[0] <= capacity) 
            return profit[0];

        return 0;
    }

    if(dp[index][capacity] != -1)
        return dp[index][capacity];
    // if we not taken the item then there is no reduction in the weights and also not any profit increment

    int Nontaken = 0 + dynamic(profit,weight,index-1,capacity,n,dp);

    int taken = INT_MIN;

    if(weight[index] <= capacity)    // capcity is reduced and profit is added
    {
        taken = profit[index] + dynamic(profit,weight,index-1,capacity - weight[index] ,n,dp);
    }

    return dp[index][capacity] = max(taken,Nontaken);
}

int solve( vector<int> profit,  vector<int> weight, int capacity,int n)
{
    vector<vector<int>> dp(n,vector<int>(capacity+1,-1));

    return dynamic(profit,weight,n-1,capacity,n,dp);
}

int main()
{   
    cout<<"Enter the total items : ";
    int items = 0; cin>>items;

    vector<int> profit(items,0);
    vector<int> weights(items,0);

    for (int i = 0; i < items; i++)
    {
        cout<<"Enter the "<<i+1<<" element \n";
        cout<<"profit  : "<<"weight\n";
        cin>>profit[i] >> weights[i];
    }


    int cap = 0;
    cout<<"Enter the capacity " ; cin>>cap;


    int maxp = solve(profit,weights,cap,items);

    cout<<"Maximum profit " <<maxp<<endl;

    return 0;
}