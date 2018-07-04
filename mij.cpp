#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n, s, licznik = 0;
    long long odp = 0;
    std::cin >> n;
    while(n--)
    {
        std::cin >> s;
        if(s == 0)
            licznik ++;
        else
            odp += licznik;
    }
    std::cout << odp;
}
