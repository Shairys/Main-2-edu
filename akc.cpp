#include <iostream>

int searchDown(int * tab, int s, int n)
{
    int p = 0;
    int q = n-1;
    while(p < q)
    {
        int h = (p+q)/2;
        if (tab[h] >= s)
            q = h;
        else
            p = h+1;
    }
    if(tab[p] != s)
        return -1;
    else
        return p;
}

int searchUp(int * tab, int s, int n)
{
    int p = 0;
    int q = n-1;
    while(p < q)
    {
        int h = (p+q+1)/2;
        if (tab[h] <= s)
            p = h;
        else
            q = h-1;
    }
    if(tab[p] != s)
        return -1;
    else
        return p;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n, q, s;
    std::cin >> n;
    int * tab = new int[n];

    for(int i = 0; i < n; i++)
        std::cin >> tab[i];

    std::cin >> q;

    while(q--)
    {
        std::cin >> s;
        int p = searchDown(tab, s, n);
        int q = searchUp(tab, s, n);
        if (p == -1)
            std::cout<<0 << "\n";
        else
            std::cout<< q - p + 1 << "\n";
    }
}
