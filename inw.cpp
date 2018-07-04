#include <iostream>

int * A;
int * B;
long long licznik = 0;
void mergeSort(int p, int q)
{
    if(p==q)
        return;
    int h = (p+q)/2;
    mergeSort(p, h);
    mergeSort(h+1, q);
    int j = h+1, i = p;
    for(int k = p; k<=q; k++)
    {
        if((j>q) || (A[i]<A[j] && i<=h) )
        {
            B[k]=A[i];
            i++;
        }
        else
        {
            if(i<=h)
                licznik += h-i+1;
            B[k]=A[j];
            j++;
        }
    }
    for(int k = p; k<=q; k++)
        A[k]=B[k];
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    A = new int[n];
    B = new int[n];
    for(int i = 0; i<n; i++)
        std::cin >> A[i];
    mergeSort(0, n-1);
    for(int i = 0; i<n; i++)
        std::cout<<A[i] << " ";
    std::cout << "\n" <<licznik;
    delete[] A;
    delete[] B;
}
