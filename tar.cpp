#include <iostream>
#include <math.h>
typedef long long ll;

void tar(ll p, ll q)
{
    ll a = 0;
    ll b = pow(q, 1/3.0 );
    while (a < b)
    {
        ll x = (a+b)/2;
        if(x*x*x+p*x >= q)
            b = x;
        else
            a = x+1;
    }
    if(a*a*a+p*a == q)
        std::cout << a << "\n";
    else
        std::cout << "NIE" << "\n";
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int z;
    ll p, q;
    std::cin >> z;
    while(z--)
    {
        std::cin >> p >> q;
        tar(p, q);
    }

}
