#include <iostream>

int main()
{
    std::string A,B;
    std::cin>> A >> B;
    int _A = A.size()+1;
    int _B = B.size()+1;
    int **k = new int *[_A];

    for(int i=0; i<_A; i++)
    {
        k[i] = new int[_B];
        for(int j=0; j<_B; j++)
            {
                k[i][j]=0;
            }
    }

    for(int i=1; i<_A; i++)
        for(int j=1; j<_B; j++)
        {
            if(A[i-1]==B[j-1] )
            {
                k[i][j]=k[i-1][j-1]+1;

            }
            else
                k[i][j] = (k[i-1][j]>k[i][j-1]) ? k[i-1][j] : k[i][j-1];
        }

    std::cout<<k[_A-1][_B-1];

    for(int i=0; i<_A; i++)
        delete[] k[i];
    delete[] k;


}
