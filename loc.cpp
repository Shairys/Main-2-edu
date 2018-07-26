#include <iostream>
#include <queue>
#include <deque>

#define MAXM 1000
#define MAXN 1000

std::deque<int> queue;
char plansza[MAXM][MAXN];
int graf[MAXM][MAXN];
int m, n; //liczba wierszy i liczba kolumn


inline bool isEmpty() {
  return queue.empty();
}

inline void enqueue(int v) {
  queue.push_back(v);
}

inline int dequeue() {
  int v = queue.front();
  queue.pop_front();
  return v;
}

inline void init() {
  queue.clear();
}

void findHero(int &x, int &y){
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(plansza[i][j] == '@'){
                x = i; y = j;
                return;
            }
}

void solve()
{
    init();
    int  x = -1, y = -1; //polozenie bohatera
    std::cin >> m >> n;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            std::cin >> plansza[i][j];
            graf[i][j] = -1;
        }
    findHero(x, y);
        if (x == -1 || y == -1) {
			std::cout << "NIE\n";
			return;
        }
    graf[x][y] = 0;
    enqueue(x);
    enqueue(y);
    while(!isEmpty() ){
        x = dequeue();
        y = dequeue();
        if(plansza[x][y] == '>'){
            std::cout << graf[x][y] <<"\n";
            return;
        }
        if (x > 0 && plansza[x - 1][y] != '#' && graf[x - 1][y] == -1) {
            enqueue(x - 1); enqueue(y);
            graf[x - 1][y] = graf[x][y] + 1;
        }
        if (y > 0 && plansza[x][y - 1] != '#' && graf[x][y - 1] == -1) {
            enqueue(x); enqueue(y - 1);
            graf[x][y - 1] = graf[x][y] + 1;
        }
        if (x < m - 1 && plansza[x + 1][y] != '#' && graf[x + 1][y] == -1) {
            enqueue(x + 1); enqueue(y);
            graf[x + 1][y] = graf[x][y] + 1;
        }
        if (y < n - 1 && plansza[x][y + 1] != '#' && graf[x][y + 1] == -1) {
            enqueue(x); enqueue(y + 1);
            graf[x][y + 1] = graf[x][y] + 1;
        }
    }
    std::cout <<"NIE\n";


}

int main() {

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int z;
	std::cin >> z;
	while (z--) solve();


}
