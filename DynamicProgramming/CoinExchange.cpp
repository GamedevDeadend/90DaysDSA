#include"bits/stdc++.h"
using namespace std;

long long getWays(vector<int>& coins, int totalCoins, int value, int i);
long long getWaysMem(vector<int>& coins, int totalCoins, int value, int i);
long long getWaysTab(vector<int>& coins, int totalCoins, int value);
long long getWaysTab1D(vector<int>& coins, int totalCoins, int value);

/// <summary>
/// Memoization array
/// </summary>
vector<vector<long long>> memoizationLookup;
vector<vector<long long>> tabulationLookup;
vector<long long> tabulationLookup1D;

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

	memoizationLookup.assign(numOfCoins, vector<long long>(value + 1, -1));

    cout << "Total number of ways to make change for " << value<< " is (Memoized): " << getWaysMem(coins, numOfCoins, value, 0) << "\n";
    cout<<"Total number of ways to make change for "<<value<<" is (Recursion): "<<getWays(coins, numOfCoins, value, 0)<<endl;
    cout<<"Total number of ways to make change for "<<value<<" is (Tabulation): "<<getWaysTab(coins, numOfCoins, value)<<endl;
    cout<<"Total number of ways to make change for "<<value<<" is (Tabulation with 1D optimization): "<<getWaysTab1D(coins, numOfCoins, value)<<endl;
}
   
/// <summary>
/// Here i is current index of coin being considered
/// We have two choices either we include the coin at index i or we don't include it
/// If we include it we reduce the value by coins[i] and keep the index same
/// If we don't include it we keep the value same and increase the index by 1
/// </summary>
/// <param name="coins"></param>
/// <param name="totalCoins"></param>
/// <param name="value"></param>
/// <param name="i"></param>
/// <returns></returns>
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
        
        return (getWays(coins, totalCoins, value-coins[i], i) + getWays(coins, totalCoins, value, i+1));
}


/// <summary>
/// 
/// </summary>
/// <param name="coins"></param>
/// <param name="totalCoins"></param>
/// <param name="value"></param>
/// <param name="i"></param>
/// <returns></returns>
long long getWaysMem(vector<int>& coins, int totalCoins, int value, int i)
{
    if (value == 0)
    {
		return 1;
    }

    if(i == totalCoins)
    {
        return 0;
    }

    if(value < 0)
    {
        return 0;
    }

    if (memoizationLookup[i][value] != -1)
    {
        return memoizationLookup[i][value];
    }

    memoizationLookup[i][value] = ( getWaysMem(coins, totalCoins, value - coins[i], i) + getWaysMem(coins, totalCoins, value, i + 1) );
    

	return memoizationLookup[i][value];
}


long long getWaysTab(vector<int>& coins, int totalCoins, int value)
{
    tabulationLookup.assign(totalCoins + 1, vector<long long>(value + 1, 0));

    for (int i = 0; i <= totalCoins; i++)
    {
        tabulationLookup[i][0] = 1;
    }

    for (int i = 1; i <= totalCoins; i++)
    {
        for (int j = 1; j <= value; j++)
        {
            if (coins[i - 1] <= j)
            {
                tabulationLookup[i][j] = tabulationLookup[i][j - coins[i - 1]] + tabulationLookup[i - 1][j];
            }
            else
            {
                tabulationLookup[i][j] = tabulationLookup[i - 1][j];
            }
        }
    }

    return tabulationLookup[totalCoins][value];
}

/// @brief Space optimized tabulation approach using 1D array.
/// @brief Here we use only one array to store the number of ways to make change for values from 0 to 'value'.
/// @param coins 
/// @param totalCoins 
/// @param value 
/// @return 
long long getWaysTab1D(vector<int>& coins, int totalCoins, int value)
{
    tabulationLookup1D.assign(value + 1, 0);
    tabulationLookup1D[0] = 1;

    for(int i = 0; i < totalCoins; i++)
    {
        for(int j = coins[i]; j <= value; j++)
        {
            tabulationLookup1D[j] += tabulationLookup1D[j - coins[i]];
        }
    }

    return tabulationLookup1D[value];
}