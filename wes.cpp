#include <iostream>

int nwd(int a, int b)
{
    if (a > b)
        std::swap(b, a);
    if (a == 0)
        return b;
    return nwd(a, b%a);
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int z, n, d;
    std::cin >> z;
    while(z--)
    {
        std::cin >> n >> d;
        std::cout << n/nwd(n, d) << "\n";
    }
}
