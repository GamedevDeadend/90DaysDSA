#include <iostream>
using namespace std;
int WinningPlayer(int n, int k);
int main() 
{
    int Players,Killpos;

    cout<<"Enter No. of player and Killpos"<<endl;
    cin>>Players>>Killpos;

    cout<<"Player Won "<<WinningPlayer(Players,Killpos);
}

WinningPlayer(int n, int k)
{
    if(n==1)
    {
        return 0;
    }

    return (WinningPlayer(n-1,k)+k)%n;
}

// #Problem Base Condition When Only One Player Is Left then return 0 because last player holding gun is winner
// #Relation between sub problems & its Genral relation is winner w(n,k) = (w(n-1,k)+k)%k
