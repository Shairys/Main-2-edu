#include <iostream>

int power(int a, int b)
{
    if(b == 1)
        return a % 10000;
    if(b%2 == 0)
    {
        int s = power(a, b/2);
        return (s*s)%10000;
    }
    else
    {
        int s = power(a, b-1);
        return (a*s)%10000;
    }
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int n, a, b;
    std::cin >> n;
    while(n--)
    {
        std::cin >> a >> b;
        std::cout << power(a+1, b) << "\n";
    }
}
