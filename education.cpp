#include <bits/stdc++.h>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <queue>
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

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    forp(i, 0, n)
    {
        cin >> a[i];
    }
    vector<int> b(n - 1);
    forp(i, 0, n - 1)
    {
        cin >> b[i];
    }
    int cur = 0;
    int sum = 0;
    int ans = INT_MAX;
    int days = 0;
    ans = ceil(c*1./a[0]);
    forp(i, 1, n)
    {
        int d = ceil((b[i-1] - cur)*1./a[i-1]);
        cur += d*a[i-1] - b[i-1];
        days += d + 1;
        int temp = ceil((c - cur)*1./a[i]);
        ans = min(ans, days + temp);
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    forp(i, 1, t + 1)
    {
        solve();
    }
    return 0;
}