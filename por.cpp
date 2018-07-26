#include <iostream>
#include <queue>
#include <unordered_map>

#define MAXM 500001
#define MAXN 200001

int grupy = 0;
int v[MAXN+1];
std::vector<int> znaj[MAXN];

void clear(int n) {
    for(int i = 0; i < n+1; i++)
        znaj[i].clear();
}
void bfs(std::vector<int> * znaj, int a){

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

void solve(){
    grupy = 0;
    int n, m;
    int a, b;
    std::cin >> n >> m;
    for(int i = 0; i < m; i++){
        std::cin >> a >> b;
        znaj[a].push_back(b);
        znaj[b].push_back(a);
    }
    for(int i = 0; i < n+1; i++)
        v[i] = -1;
    int c;
    std::cin >> c;
    std::cout << "Znajomi numeru " << c << ":\n";
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
    clear(n);
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int z, n, m, a, b, c;
    std::cin >> z;

    while(z--) solve();
}
