#include <iostream>
#include <string>
int modulo, n;

int main()
{
	std::cin >> n >> modulo;
	std::string s;
	std::cin >> s;
	int * k = new int[n];
	k[0] = 1;
	for (int i = 1; i < n; i++)
	{
		k[i] = 0;
		if (s[i] == '1')
		{
			for (int y = 0; y<6; y++)
			{
				if (i - y - 1 < 0)
					break;
				k[i] += k[i - y - 1];
				k[i] %= modulo;
			}
		}
	}
	std::cout << k[n - 1];

}
