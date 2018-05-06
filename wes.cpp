#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
a+=b;
b=a-b;
a-=b;
}
int nwd(int a, int b)
{
if (a<b)
    swap(a, b);
if(b==0)
    return a;
else
    return nwd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tmp, n, d;
    cin>>tmp;
    while(tmp--)
    {
        cin>>n>>d;
        cout<<n/nwd(n, d)<<"\n";
    }

}
