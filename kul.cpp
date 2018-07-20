#include <iostream>
#include <sstream>
#include <string>


/**
Do dokończenia kiedyś
OBECNIE NIE DZIALA
*/


const int rozmiar = 8;
const int maxRuchy = 8;
int rozwiazanie = 0;
std::string _rozwiazanie = "";
char _pole[rozmiar][rozmiar];
char pola[maxRuchy+1][rozmiar][rozmiar]; //Dla każdego powiomu indywidualne pole

void wypiszPlansze(int p)
{
	std::cout << "\n\n\n";
	for (int i = 0; i < rozmiar; i++)
	{
		for (int y = 0; y < rozmiar; y++)
			std::cout << pola[p][i][y];
		std::cout << "\n";
	}
}

bool pusta(int p)
{
    for(int i = 0; i<rozmiar-1; i++)
        if(pole[p][rozmiar-1][i] != '.')
            return false;
    return true;
}

bool opadniecie(int p, int kolumna = 0, bool opadlo = false)
{
    if(kolumna >= rozmiar)
        return opadlo;

	int dol = rozmiar;
	for (int i = dol-1; i >= 0; i--)
	{
		if (pole[i][kolumna] != '.')
			dol = i;
		else
			break;
	}
	for (int i = dol - 2; i >= 0; i--)
	{
		if (pole[p][i][kolumna] != '.')
		{
			std::swap(pole[i][kolumna], pole[dol - 1][kolumna]);
			dol--;
			opadlo = true;
		}
	}
	return opadniecie(pole, kolumna+1, opadlo);
}

bool znikniecie(int ** pole)
{
	bool kasacja[rozmiar][rozmiar];
	bool ruch = false;
	for (int i = 0; i < rozmiar; i++)
		for (int y = 0; y < rozmiar; y++)
			kasacja[i][y] = false;
    //przeszukanie wierszy
	for (int i = 0; i < rozmiar; i++)
		for (int y = 0; y < rozmiar-1; y++)
		{
			if (pole[i][y] == pole[i][y+1] && pole[i][y] != '.')
			{
				int licznik = 2;
				for (int u = y + 1; u<rozmiar-1; u++)
				{
					if (pole[i][u] == pole[i][u+1])
						licznik++;
					else
						break;
				}
				if (licznik >= 3)
				{
					for (int u = y; u < y+licznik; u++)
					{
						kasacja[i][u] = true;
						ruch = true;
					}
					y += licznik-1;
				}
			}
		}
    //przeszukanie kolumn
    for (int y = 0; y < rozmiar; y++)
		for (int i = 0; i < rozmiar-1; i++)
		{
			if (pole[i+1][y] == pole[i][y] && pole[i][y] != '.')
			{
				int licznik = 2;
				for (int u = i+1; u<rozmiar-1; u++)
				{
					if (pole[u][y] == pole[u+1][y])
						licznik++;
					else
						break;
				}
				if (licznik >= 3)
				{
					for (int u = i; u < i+licznik; u++)
					{
						kasacja[u][y] = true;
					}
					i += licznik-1;
				}
			}
		}
	for (int i = 0; i < rozmiar; i++)
		for (int y = 0; y < rozmiar; y++)
			if (kasacja[i][y])
				pole[i][y] = '.';

    if(opadniecie(pole) );
        znikniecie(pole);
    return ruch;
}

void ruch(int i, int y, int _i, int _y, int ruchy, std::string wynik, char **p)
{


    if(pole[i][y] == '.' || pole[_i][_y] == '.' || pole[i][y] == pole[_i][_y])
        return;

    std::swap(pole[i][y], pole[_i][_y]);
        if(znikniecie())
        {
            if(pusta())
                if(rozwiazanie == 0 || ruchy<rozwiazanie)
                {
                    rozwiazanie = ruchy;
                    _rozwiazanie = wynik;
                }
            wynik += i + ' ' + y + ' ' + _i + ' ' + _y;
            for(int x = 0; x<rozmiar; x++)
                for(int z = 0; z<rozmiar-1; z++)
                    ruch(x, z, x, z+1, ruchy+1, wynik);

            for(int x = 0; x<rozmiar; x++)
                for(int z = 0; z<rozmiar-1; z++)
                    ruch(z, x, z+1, x, ruchy+1, wynik);
        }
        else
        {
            std::swap(pole[i][y], pole[_i][_y]);
            return;
        }



}


int main()
{


	for (int i = 0; i < rozmiar; i++)
		for (int y = 0; y < rozmiar; y++)
			std::cin >> _pole[i][y];

	wypiszPlansze();

    for(int x = 0; x<rozmiar; x++)
        for(int z = 0; z<rozmiar-1; z++)
            ruch(x, z, x, z+1, 0, " ");

    for(int x = 0; x<rozmiar; x++)
        for(int z = 0; z<rozmiar-1; z++)
            ruch(z, x, z+1, x, 0, " ");

    std::cout << rozwiazanie <<"\n" << _rozwiazanie;
	wypiszPlansze();


}
