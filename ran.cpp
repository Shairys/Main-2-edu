#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct osoba
{
    string imie;
    int liczba;
    bool operator < (const osoba &b) const
    {
        return this->liczba < b.liczba;
    }

    osoba(string s, int i) : imie(s), liczba(i)
    {

    }
};


int main()
{
    int k, wygrana, tmp;
    string s;
    vector<osoba> uczestnicy;
    cin>>k >>wygrana;
    for(int i = 0; i<k; i++)
    {
        cin>>s>>tmp;
        uczestnicy.push_back(osoba(s, tmp) );
    }
    sort(uczestnicy.begin(), uczestnicy.end());
    vector<int> liczby;
    for(int i = 0; i < k; i++)
    {
        vector<osoba>::iterator it = lower_bound(uczestnicy.begin(), uczestnicy.end(), osoba("", wygrana-uczestnicy[i].liczba));
        if(it->liczba == wygrana-uczestnicy[i].liczba)
        {
            cout<< uczestnicy[i].imie <<" " << it->imie<<"\n";
            return 0;
        }
    }

        cout<<"NIE"<<"\n";

}
