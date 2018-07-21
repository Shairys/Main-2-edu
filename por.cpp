#include <iostream>
#include <queue>
#include <unordered_map>
/*
Raport ostatecznego sprawdzania
Test	Wynik	Czas	Wynik
1	OK	0.00s/1.00s	16/16
2	OK	0.10s/1.00s	16/16
3	Przekroczenie limitu czasu	1.02s/1.00s	0/17
4	OK	0.92s/6.00s	17/17
5	Przekroczenie limitu czasu	15.03s/15.00s	0/17
6	OK	0.80s/4.00s	17/17
*/


int grupy = 0;
int * v;
void bfs(std::vector<std::vector<int>> &znaj, int a){

    std::queue<int> q;
    grupy++;
    v[a] = 0;
    q.push(a);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto it = znaj[x].begin(); it!=znaj[x].end(); ++it){
            if(v[*it] == -1){
                q.push(*it);
                v[*it] = v[x] + 1;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int z, n, m, a, b, c;
    std::cin >> z;

    while(z--){
        grupy = 0;
        std::cin >> n >> m;
        std::vector<std::vector<int>> znaj(n+1, std::vector<int>() );
        for(int i = 0; i < m; i++){
            std::cin >> a >> b;
            znaj[a].push_back(b);
            znaj[b].push_back(a);
        }

        v = new int[n+1];
        for(int i = 0; i < n+1; i++)
            v[i] = -1;

        std::cin >> c;

        std::cout <<"Znajomi numeru "<<c<<":\n";
        bfs(znaj, c);
        for(int i = 1; i < n+1; i++){
            if(v[i] > 0)
                std::cout << i << ": " << v[i] <<"\n";
        }
        for(int i = 1; i < n+1; i++){
            if(v[i] == -1)
                bfs(znaj, i);
        }
        std::cout << "Grup znajomych jest " << grupy <<".\n";
        delete[] v;
    }
}
