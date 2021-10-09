#include <bits/stdc++.h>
#define YES cout << "YES\n"
#define NO cout << "NO\n"
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
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    forp(i,0,n){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(all(v),sortbysec);
    int bought = 0;
    int ans = 0;
    int f = 0, l = n-1;
    while(f<=l){
        if(f == l){
            int dif = max((int)0,v[f].second - bought);
            ans += min(v[f].first, dif)*2;
            v[f].first -= min(v[f].first,dif);
            ans+=v[f].first;
            f++;
        }
        else{
            if(bought >= v[f].second){
                ans+=v[f].first;
                bought+=v[f].first;
                f++;
                continue;
            }
            else{
                int need = v[f].second - bought;
                if(need < v[l].first) {
                    v[l].first -= need;
                    bought+=need;
                    ans+=need*2;
                }
                else {
                    bought += v[l].first;
                    ans+=v[l].first*2;
                    v[l].first = 0;
                    l--;
                }
            }
        }
    }
    cout<<ans<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    forp(i, 1, t + 1)
    {
        solve(i);
    }
    return 0;
}