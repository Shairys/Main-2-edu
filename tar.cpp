#include <iostream>
#include <vector>
using namespace std;
void binary_search(long long p, long long q)
{
long long x=0, y=q;
long long srodek=0;
while(x<y)
    {
        srodek=(x+y)/2;
        if( (srodek*srodek*srodek)+p*srodek>=q)
            y=srodek;
        else
            x=srodek+1;
    }
    if( (x*x*x)+p*x==q)
        cout<<x<<"\n";
    else
        cout<<"NIE"<<"\n";

}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tmp;
    long long p, q;
    cin>>tmp;
    while(tmp--)
    {
        cin>>p>>q;
        binary_search(p, q);
    }
}



