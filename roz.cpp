#include <iostream>

const int n = 31623;
bool liczba[n];
void sito()
{
    for(int i = 2; i<n; i++)
        liczba[i] = true;

    for(int i = 2; i*i<n; i++)
        if(liczba[i])
        {
            for(int y = i*i; y<n; y+=i)
                liczba[y] = false;
        }
}

int next(int i)
{
    for(int y = i+1; y<n; y++)
        if(liczba[y])
            return y;
    return -1;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    sito();
    int t, l;
    std::cin >> t;
    while(t--)
    {
        std::cin >> l;
        int licznik = 0;
        int pierwsza = 2;
        std::cout << l << " = ";
        while(l != 1)
        {
            while(l%pierwsza == 0)
            {
                l /= pierwsza;
                licznik++;
            }
            if(licznik > 0)
                std::cout << pierwsza;
            if(licznik > 1)
                std::cout << "^" << licznik;
            if(l != 1 && licznik > 0)
                std::cout << "*";
            licznik = 0;
            pierwsza = next(pierwsza);
            if(pierwsza == -1)
                pierwsza = l;
        }
        std::cout << "\n";
    }
}
