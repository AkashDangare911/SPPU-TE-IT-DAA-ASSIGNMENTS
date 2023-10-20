#include<bits/stdc++.h>
using namespace std;

// sort the value per weight in desending order
// so maximum profit comes first

struct Item
{
    int profit;
    int weights;
    double itemsget;
};

// item 1 and item 2

bool comp(Item it1, Item it2)
{
    double It1ratio = (double)it1.profit / (double)it1.weights;
    double It2ratio = (double)it2.profit / (double)it2.weights;

    if(It1ratio < It2ratio) // in this case we need to sort
        return false;
    else
        return true;
}

double findMaxProfit(Item arr[], int capacity,int n)
{
    sort(arr,arr+n,comp);

    double maxProfit = 0.0;

    for (int i = 0; i < n; i++)
    {
        if(arr[i].weights <= capacity) 
        { // take whole profit
            maxProfit = maxProfit+  (double)arr[i].profit;
            arr[i].itemsget=1;

            capacity = capacity-arr[i].weights; // reduce the capacity of  bag
        }

        else
        {
            // take portion of weights profit
            double remained = (double)capacity * (double)arr[i].profit / (double)arr[i].weights;

            maxProfit = maxProfit+ remained;
            arr[i].itemsget = (double)capacity/(double)arr[i].weights;
            break;
        }
    }

    return maxProfit;
    
}

int main()
{
    int items = 0;
    cout<<"Enter the total Items : \n"; cin>>items;

    Item arr[items];

    for(int i = 0; i<items; i++)
    {
        cout<<"Enter the "<<i+1<<" item \n";

        cout<<"profit  : "<<"weight\n";

        cin>>arr[i].profit >> arr[i].weights;
        arr[i].itemsget = 0;
       
    }

    cout<<"Enter capacity\n";
    int cap = 0; cin>>cap;
    cout<<"======================================\n";

    cout<<"profit  : "<<"weight\n";
    cout<<"======================================\n";

    for(int i = 0; i<items; i++)
    {
        cout<<arr[i].profit <<"\t"<< arr[i].weights<<endl;
       
    }

    cout<<"Capcity : "<<cap<<endl;

    cout<<"======================================\n";

    double ret = findMaxProfit(arr,cap,items);

    for(int i = 0; i<items; i++)
    {
        cout<<arr[i].profit <<"\t"<< arr[i].weights<<"\t"<<arr[i].itemsget<<endl;
       
    }
    cout<<"Maximum profit is : "<< ret<<endl;

    return 0;
}