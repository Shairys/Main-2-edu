#include <iostream>
#include <queue>


int main() {

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int z, m, n, x, y, _x, _y;
	std::cin >> z;
	while (z--) {
		std::queue<int> q;
		std::cin >> m >> n;
		char ** plansza = new char*[m];
		int ** graf = new int *[m];

		for (int i = 0; i < m; i++) {
			plansza[i] = new char[n];
			graf[i] = new int[n];
		}
		_x = -1;
		x = -1;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				std::cin >> plansza[i][j];
				if (plansza[i][j] == '@') {
					x = i; y = j;
				}
				else if (plansza[i][j] == '>') {
					_x = i; _y = j;
				}
				graf[i][j] = -1;
			}

		if (x == -1 || _x == -1) {
			std::cout << "NIE\n";

			for (int i = 0; i < m; i++) {
				delete[] plansza[i];
				delete[] graf[i];
			}
			delete[] plansza;
			delete[] graf;

			continue ;
		}

		q.push(x);
		q.push(y);
		graf[x][y] = 0;
		while (!q.empty()) {
			x = q.front();
			q.pop();
			y = q.front();
			q.pop();
			if (plansza[x][y] == '>')
				break;
			if (x > 0 && plansza[x - 1][y] != '#' && graf[x - 1][y] == -1) {
				q.push(x - 1); q.push(y);
				graf[x - 1][y] = graf[x][y] + 1;
			}
			if (y > 0 && plansza[x][y - 1] != '#' && graf[x][y - 1] == -1) {
				q.push(x); q.push(y - 1);
				graf[x][y - 1] = graf[x][y] + 1;
			}
			if (x < m - 1 && plansza[x + 1][y] != '#' && graf[x + 1][y] == -1) {
				q.push(x + 1); q.push(y);
				graf[x + 1][y] = graf[x][y] + 1;
			}
			if (y < n - 1 && plansza[x][y + 1] != '#' && graf[x][y + 1] == -1) {
				q.push(x); q.push(y + 1);
				graf[x][y + 1] = graf[x][y] + 1;
			}
		}
		if (0) {
			for (int i = 0; i < m; i++) {
				for (int k = 0; k < n; k++)
					std::cout << graf[i][k] << " ";
				std::cout << "\n";
			}
		}
		if (graf[_x][_y] == -1)
			std::cout << "NIE" << "\n";
		else
			std::cout << graf[_x][_y] << "\n";

		for (int i = 0; i < m; i++) {
			delete[] plansza[i];
			delete[] graf[i];
		}
		delete[] plansza;
		delete[] graf;
	}
}
