#include <iostream>
#include <algorithm>

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t, w, h;
    std::cin >> t;

    while(t--){
        std::cin >> w >> h;
        int ** tab = new int*[h];
        for(int i = 0; i < h; i++)
            tab[i] = new int[w];

        for(int i = 0; i < h; i++)
            for(int y = 0; y < w; y++){
                std::cin >> tab[i][y];
                tab[i][y] += std::max(
                    y == 0 ? 0 : tab[i][y-1],
                    i == 0 ? 0 : tab[i-1][y]
                    );
            }
        std::cout << tab[h-1][w-1] << "\n";
        for(int i = 0; i < h; i++)
            delete[] tab[i];
        delete[] tab;
    }
}
