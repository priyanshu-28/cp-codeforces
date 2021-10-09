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
int sumPairs(int arr[],int n)
{ //GFG
    // final result
    int sum = 0;
    for (int i=n-1; i>=0; i--)
        sum += i*arr[i] - (n-1-i)*arr[i];
    return sum;
}
 
void solve(int in)
{
    double c,m,p,v;
    cin>>c>>m>>p>>v;
    double ans = 0;
    int prev = 2;
    int i = 2;
    ans += p;
    while (p < 1 && i < 6){
        p += (prev/2*(min(m/2,v/2)) + prev/2*(min(c/2,v/2)))/2;
        // deb(p);
        deb(p*c);
        deb(p*m);
        ans+= p*c*i + p*m*i;
        double oc = c;
        deb(c);
        c+= (-prev/2*(min(c,v)) + prev/2*(min(m/2,v/2)))/2;
        m+= (-prev/2*(min(m,v)) + prev/2*(min(oc/2,v/2)))/2;
        // c/=2;
        // m/=2;
        deb(p);
        deb(c);
        deb(m);
        prev *= 2;
        i++;
    }
    cout<<ans<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    forp(i, 1, t + 1)
    {
        solve(i);
    }
    return 0;
}