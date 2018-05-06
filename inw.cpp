#include <iostream>
#include <vector>

long long inwersje = 0;

using namespace std;
void mergeSort(int p, int q, int *A)
{
	if (p == q)
		return;
	int s = (p + q) / 2;
	mergeSort(p, s, A);
	mergeSort(s + 1, q, A);
	int i = p;
	int j = s + 1;
	int * B = new int[q+1];
	for (int k = p; k <= q; k++)
		if (j>q || (i <= s && A[i] <= A[j]))
		{
			B[k] = A[i];
			i++;
		}
		else
		{
			if (i <= s && A[i] > A[j])
				inwersje += s + 1 - i;
			B[k] = A[j];
			j++;
		}

	for (int k = p; k <= q; k++)
		A[k] = B[k];
	delete[] B;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int * liczby = new int[n];
	for (int i = 0; i < n; i++)
		cin >> liczby[i];
	mergeSort(0, n - 1, liczby);
	for (int i = 0; i < n; i++)
		cout << liczby[i] << " ";
	cout <<"\n" << inwersje << "\n";
	delete[] liczby;
}
