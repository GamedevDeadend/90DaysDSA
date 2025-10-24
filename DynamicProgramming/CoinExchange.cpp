#include"bits/stdc++.h"
using namespace std;

long long getWays(vector<int>& coins, int totalCoins, int value, int i);
int main()
{
    static int value = 0;
    static int numOfCoins = 0;
    cout<<"Enter total value"<<endl;
    cin>>value;
    cout<<"Enter number of coins"<<endl;
    cin>>numOfCoins;

    vector<int> coins(numOfCoins);

    cout<<"Enter the coins"<<endl;
    for(auto &x: coins)
    {
        cin>>x;
    }

    cout<<"Total number of ways to make change for "<<value<<" is (Recursion): "<<getWays(coins, numOfCoins, value, 0)<<endl;
}
    
long long getWays(vector<int>& coins, int totalCoins, int value, int i)
{
        if(value == 0)
        {
            return 1;
        }
        
        if(value < 0)
        {
            return 0;
        }
        
        if(i == totalCoins)
        {
            return 0;
        }
        
        return ( getWays(coins, totalCoins, value-coins[i], i) + getWays(coins, totalCoins, value, i+1));
}


long long getWaysMem()
{
   
}