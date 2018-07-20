#include <iostream>
#include <algorithm>
int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::string A,B;

    std::cin>> A >> B;

    int _A = A.size()+1;
    int _B = B.size()+1;
    int **p = new int *[_A];

    for(int i = 0; i < _A; i++)
        p[i] = new int[_B];

    for(int j = 0; j < _A; j++)
        p[j][0] = 0;
    for(int j = 0; j < _B; j++)
        p[0][j] = 0;

    for(int i = 1; i < _A; i++)
        for(int j = 1; j < _B; j++)
        {
            if(A[i-1] == B[j-1])
                p[i][j] = p[i-1][j-1]+1;
            else
                p[i][j] = std::max(p[i-1][j], p[i][j-1]);
        }
    std::cout << p[_A-1][_B-1];

    for(int i = 0; i < _A; i++)
        delete[] p[i];
    delete[] p;
}
