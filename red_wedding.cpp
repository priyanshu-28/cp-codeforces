#include <bits/stdc++.h>
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define endl "\n"
#define int long long
typedef long long ll;
#define forp(i, x, t) for (int i = x; i < t; i++)
#define forn(i, x, t) for (int i = x; i > t; i--)
#define deb(x) cout << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7;

using namespace std;

int power(int x, int y)
{
    int res = 1;
    if (x == 0)
        return 0;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}
bool is_prime(ll n)
{
    if (n == 1)
    {
        return false;
    }
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            return false;
        }
        i += 1;
    }
    return true;
}
int nCr(int n, int r)
{
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;

            n--;
            r--;
        }
    }

    else
        p = 1;
    return p;
}
bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}
string toBinary(int n)
{
    string r;
    while (n != 0)
    {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r;
}

void solve(int in)
{
    int a,b;
    cin>>a>>b;
    int dif = b-a;
    int div = -1;
    forp(i,2,sqrt(b)+1){
        if(b%i == 0){
            div = i;
            break;
        }
    }
    if(dif < 0){
        cout<<"No"<<endl;
        return;
    }
    else if(dif == 0){
        cout<<"No"<<endl;
        return;
    }
    if(a%2 == 0 && b%2 == 0){
        cout<<"Yes";
        return;
    }
    if(b%2 == 0){
        forp(i,2,sqrt(a)+1){
            if(a%i == 0 && a+i<=b){
                cout<<"Yes";
                return;
            }
        }
        cout<<"No"<<endl;
        return;
    }
    if(a%2 && b%2){
        //deb(div);
        // if(div == -1){
        //     cout<<"No"<<endl;
        //     return;
        // }
        forp(i,2,sqrt(a)+1){
            if(a%i == 0){
                if(a + i <= b - div && div!=-1){
                    cout<<"Yes"<<endl;
                    return;
                }
                if(dif%i == 0){
                    cout<<"Yes"<<endl;
                    return;
                }
            }
        }
        cout<<"No"<<endl;
        return;
    }
    else
    {
        if(b - div >= a){
            cout<<"Yes"<<endl;
            return;
        }
        forp(i,2,sqrt(a)+1){
            if(a%i == 0){
                if(dif%i == 0){
                    cout<<"Yes"<<endl;
                    return;
                }
            }
        }
        cout<<"No"<<endl;
        return;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve(1);
    return 0;
}