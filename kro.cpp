#include <iostream>

using namespace std;

int potegowanie(int a, int b)
{
    if(b==1)
        return a%10000;
    if(b%2==0)
    {
        int s=potegowanie(a, b/2);
        return (s*s)%10000;
    }
    else
    {
        int s=potegowanie(a, b-1);
        return (s*a)%10000;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, a, b;
    cin>>i;
    while(i--)
    {
        cin>>a>>b;
        a+=1;
        cout<<potegowanie(a, b)<<"\n";
    }
}
