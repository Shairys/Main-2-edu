#include <iostream>
#include <vector>
using namespace std;
int binary_search1(vector<int> & test, int x)
{
int p=0, k=test.size()-1;
int srodek=0;
while(p<k)
    {
        srodek=(p+k)/2;
        if(test[srodek]>=x)
            k=srodek;
        else
            p=srodek+1;
    }
    if(test[p]==x)
        return p;
    else
        return -1;

}

int binary_search2(vector<int> & test, int x)
{
int p=0, k=test.size()-1;
int srodek=0;
while(p<k)
    {
        srodek=(p+k+1)/2;
        if(test[srodek]<=x)
            p=srodek;
        else
            k=srodek-1;
    }
    if(test[p]==x)
        return p;
    else
        return -1;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> cz;
    int tmp, tmp2;
    int p, k;
    cin>>tmp;
    while(tmp--)
    {
        cin>>tmp2;
        cz.push_back(tmp2);
    }
    cin>>tmp;
    while(tmp--)
    {
        cin>>tmp2;
        p=binary_search1(cz, tmp2);
        if(p<0)
            cout<<0 <<"\n";
        else
        {
            k=binary_search2(cz, tmp2);
            cout<<k-p+1 <<"\n";
        }
    }
}


