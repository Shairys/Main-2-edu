#include <iostream>
#include <vector>
const int pierwiastek = 31624; //sqrt(10^9);

bool czynniki[pierwiastek];

void sito()
{
    czynniki[0] = false;
    czynniki[1] = false;

    for(int i = 2; i<=pierwiastek; i++)
        czynniki[i]=true;

    for(int i = 2; i*i<=pierwiastek; i++)
        if(czynniki[i])
            for(int k = i*2; k<=pierwiastek; k+=i)
                czynniki[k] = false;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
    sito();
    std::vector<int> pierwsze;
    for(int i = 2; i <= pierwiastek; i++)
        if(czynniki[i])
            pierwsze.push_back(i);
    int proby, liczba;
    std::cin >> proby;
    while(proby--)
    {
        std::cin>>liczba;
        std::cout<< liczba <<" = ";
        int p = 0;
        int dzielnik = pierwsze[p];
        int wykladnik = 0;
        while(liczba != 1 || wykladnik != 0)
        {
            if(liczba%dzielnik == 0)
            {
                liczba/=dzielnik;
                ++wykladnik;
            }
            else
            {
                if(wykladnik > 0)
                {
                    std::cout<<dzielnik;
                    if(wykladnik > 1)
                        std::cout<<"^"<<wykladnik;
                    if(liczba != 1)
                        std::cout<<"*";
                }
                wykladnik = 0;
                p++;
                if(p+1>pierwsze.size())
                {
                    std::cout<<liczba;
                    liczba=1;
                }
                dzielnik = pierwsze[p];
            }
        }
        std::cout<<"\n";
    }


    return 0;
}
