#include <iostream>

const int n = 2000000;
bool liczba[n];
long long suma[n];

void sito()
{
    for(int i = 2; i<n; i++)
        liczba[i] = true;

    for(int i = 2; i*i<n; i++)
        if(liczba[i])
        {
            for(int y = i*i; y<=n; y+=i)
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

void preprocessing()
{
    sito();
    int pierwsza = 2;
    suma[0] = 0;
    for(int i = 1; i < n; i++)
    {
        suma[i] = suma[i-1];
        if(pierwsza == i)
        {
            suma[i] += pierwsza;
            pierwsza = next(pierwsza);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    preprocessing();
    int t, a, b;
    std::cin >> t;
    while(t--)
    {
        std::cin >> a >> b;
        std::cout << suma[b] - suma[a-1] << "\n";
    }
}
