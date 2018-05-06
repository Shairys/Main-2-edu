#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k=0,l=0;
    long long licznik=0;
    cin>>n>>m;
    int *liczby = new int[n];
    bool *tab = new bool[m+1];

    for(int i=0; i<n; i++)
        cin>>liczby[i];
    for(int i=0; i<m+1; i++)
        tab[i]=0;

    for(int i=0; i<n; i++)
    {
        if(!(tab[liczby[i]]))
        {
            l++;
            licznik+=l;
            tab[liczby[i]]=1;
        }
        else
        {
            for(int y=k; y<n; y++)
            {
                if(liczby[y]!=liczby[i])
                {
                    l--;
                    k++;
                    tab[liczby[y]]=0;
                }
                else
                {
                    k++;
                    licznik+=l;
                    break;
                }
            }
        }


    }


    cout<<licznik;


}
