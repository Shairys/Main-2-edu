#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long licznik = 0;
    int samochody, zera=0, mnoznik=0, typ;
    cin>>samochody;
    while(samochody--)
    {
        cin>>typ;
        if(!typ)
            mnoznik++;
        else
            licznik+=mnoznik;
    }
    cout<<licznik;



}
