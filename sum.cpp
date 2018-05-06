#include <iostream>
#include <vector>
const int rozmiar = 2000000;
const int pierwiastek = 1416;
bool czynniki[rozmiar];
long long suma[rozmiar];
void sito()
{
    czynniki[0] = false;
    czynniki[1] = false;

    for(int i = 2; i<=rozmiar; i++)
        czynniki[i]=true;

    for(int i = 2; i<=pierwiastek; i++)
        if(czynniki[i])
            for(int k = i*2; k<=rozmiar; k+=i)
                czynniki[k] = false;
}


int main()
{
    std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
    sito();
    int proby, a, b;
    suma[0]=0;
    for(int i = 1; i<rozmiar; i++)
    {
        if(czynniki[i])
            suma[i]=suma[i-1]+i;
        else
            suma[i]=suma[i-1];
    }
    std::cin >> proby;
    while(proby--)
    {
        std::cin>>a>>b;
        std::cout<<suma[b]-suma[a-1] <<"\n";
    }


    return 0;
}