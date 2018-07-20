#include <iostream>
#include <string>
const int max = 18;
bool znajomi[max][max];
bool sprawdzony[max];
int naj = 0;
bool * odp;
int n;


void szukaj(int osoba, bool * aktywniOryginal)
{
	bool * aktywni = new bool[n];
	for (int i = 0; i<n; i++)
		aktywni[i] = aktywniOryginal[i];

	int licznik = 0;
	for (int i = 0; i<n; i++)
	{
		if (znajomi[osoba][i] && aktywni[i])
			licznik++;
		else
			aktywni[i] = false;
	}
	sprawdzony[osoba] = true;
	bool ostatni = true;
	for (int i = 0; i<n; i++)
		if (aktywni[i] && !sprawdzony[i])
		{
			szukaj(i, aktywni);
			ostatni = false;
		}
	if (ostatni)
		if (licznik>naj)
			for (int i = 0; i<n; i++)
			{
				odp[i] = aktywni[i];
				naj = licznik;
			}
	delete[] aktywni;
	sprawdzony[osoba] = false;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> n;

	for (int i = 0; i<n; i++)
	{
		std::string tmp;
		std::cin >> tmp;
		for (int y = 0; y < n; y++)
		{
			if (tmp[y] == '1')
				znajomi[i][y] = false;
			else
				znajomi[i][y] = true;
		}
	}

	odp = new bool[n];
	bool * tmp = new bool[n];

	for (int i = 0; i < n; i++)
    {
		sprawdzony[i] = false;
		tmp[i] = true;
    }

	for (int i = 0; i<n; i++)
		szukaj(i, tmp);

	std::cout << naj << "\n";
	for (int i = 0; i<n; i++)
		if (odp[i])
			std::cout << i + 1 << " ";
}
