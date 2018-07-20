#include <iostream>
#include <string>
#include <algorithm>
#include <deque>


int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;
    int * tab = new int[n];
    int * max = new int[k];

    for(int i = 0; i < n; i++)
       std::cin >> tab[i];
    for(int i = 0; i < k; i++)
        max[i] = 0;
    int profit = 0;
    for(int y = 0; y < k; y++)
    {
        int it = 0;
        int _max = 0;
        for(int i = 0; i < n; i++)
        {
            if(tab[i] > _max)
            {
                it = i;
                _max = tab[i];
            }
        }
        profit += tab[it];
        tab[it] = -1;
    }
    int c = 0;
    int d = 0;
    std::cout << profit << "\n";

    for(int i = 0; i < n; i++)
    {
        c++;
            if(tab[i] == -1)
            {
                d++;
                if(d == k)
                    std::cout << c + (n-i-1);
                else
                    std::cout << c << " ";
                c = 0;
            }
    }



}

