#include <iostream>
#include <string>
#include <algorithm>
struct osoba
{
    std::string nazwisko;
    int liczba;
    bool operator < (const osoba & o) const
    {
        return this->liczba < o.liczba;
    }
    osoba(std::string na, int s)
    {
        this->nazwisko = na;
        this->liczba = s;
    }
    osoba()
    {
        this->nazwisko = "";
        this->liczba = 0;
    }
};

bool bin(osoba * o, int q, int s)
{
    int p = 0, h;
    q --;
    while(p<q)
    {
        h = (p+q)/2;
        if(o[h].liczba >= s)
            q = h;
        else
            p = h+1;
    }
    if(o[p].liczba != s)
        return false;
    else
    {
        std::cout << o[p].nazwisko << " ";
        return true;
    }

}


int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n, s, l;
    std::string na;
    std::cin >> n >> s;
    osoba * uczestnicy = new osoba[n];
    for(int i = 0; i<n; i++)
    {
        std::cin >> na >> l;
        uczestnicy[i] =  osoba(na, l);
    }
    std::sort(uczestnicy, uczestnicy+n);
    bool znaleziony = false;
    for(int i = 0; i<n && !znaleziony; i++)
    {
        znaleziony = bin(uczestnicy, n, s-uczestnicy[i].liczba);
        if(znaleziony)
        {
            std::cout<< uczestnicy[i].nazwisko << "\n";
            break;
        }
    }
    if(!znaleziony)
        std::cout << "NIE" << "\n";
    delete[] uczestnicy;


}
