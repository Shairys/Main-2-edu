#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;

	bool * rodz = new bool[m + 1];
	for (int i = 0; i <= m; i++)
		rodz[i] = false;
	int * cuk = new int[n];

	for (int i = 0; i<n; i++)
		std::cin >> cuk[i];

	int licznik = 0;
	long long odp = 0;
	int pocz = 0;
	for (int i = 0; i<n; i++)
	{
		if (rodz[cuk[i]] == false)
		{
			rodz[cuk[i]] = true;
			licznik++;
			odp += licznik;
		}
		else
		{
			while (rodz[cuk[i]] != false)
			{
				rodz[cuk[pocz]] = false;
				licznik--;
				pocz++;
			}
			rodz[cuk[i]] = true;
			licznik++;
			odp += licznik;
		}
	}
	std::cout << odp << "\n";
	delete[] rodz;
	delete[] cuk;
}
