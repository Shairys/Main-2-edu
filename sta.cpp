#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

int tree[524289]; //2^19 +1
int bajt = 0;
int leaf_count;

void load()
{
    for(int i = leaf_count; i < leaf_count+bajt; i++)
        std::cin >> tree[i];
    int current = leaf_count/2;
    int tmp = leaf_count;
    while(tmp > 1){
        while(current < leaf_count){
            tree[current] = std::max(tree[current*2], tree[current*2+1]);
            current++;
        }
        tmp /= 2;
        current = tmp/2;
    }
}

void update(int k, int x)
{
    int current = leaf_count+k;
    tree[current] = x;
    current /= 2;
    while(current >= 1){
        tree[current] = std::max(tree[current*2], tree[current*2+1]);
        current /= 2;
    }
}

int max(int L, int R, int v = 1, int a = 0, int b = leaf_count - 1){
	if (L == a && R == b) {
		return tree[v];
	}
	int mid = (a + b - 1) / 2;
	if (R <= mid) {
		return max(L, R, 2 * v, a, mid);
	}
	else if (L > mid) {
		return max(L, R, 2 * v + 1, mid + 1, b);
	}
	 else {
	    return std::max(
		max(L, mid, 2 * v, a, mid),
		max(mid + 1, R, 2 * v + 1, mid + 1, b)
		);
	}
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int m, k, x;
    std::string s;
    std::cin >> bajt >> m;
    int log = std::ceil(std::log2(bajt));
    leaf_count = std::pow(2, log);
    load();

    while(m--)
    {
        std::cin >> s;
        if(s == "MAX"){
            std::cin >> k >> x;
            std::cout << max(k - 1, x - 1) << "\n"; // Bo wnioski numerujemy od 1
        }
        else{
            std::cin >> k >> x;
            update(k - 1, x);
        }
    }
}
