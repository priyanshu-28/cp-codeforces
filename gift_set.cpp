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
    int x,y,a,b;
    cin>>x>>y>>a>>b;
    if(y > x) swap(x,y);
    if(b > a) swap(a,b);
    int start = min(x/a, y/b);
    int curans = start + min((x-start*a)/b, (y-start*b)/a);
    int low = 0, high = start;
    // int mid = start/2;
    int prev = -1;
    // deb(start);
    // deb(curans);
    int maxi = curans;
    while(low<high){
        int mid = (high + low)/2;
        deb(mid);
        int midans = mid + min((x-mid*a)/b, (y-mid*b)/a);
        // deb(mid);
        // deb(midans);
        if(midans > curans){
            if(prev == -1){
                high = (high + mid)/2 == high ? high - 1 : (high + mid)/2;
            }
            else{
                low = (low + mid)/2 == low? low + 1: (low + mid)/2;
            }
        }
        else{
            if(prev == 1){
                high = (high + mid)/2 == high? high - 1 : (high + mid)/2;
                prev = -1;
            }
            else{
                low = (low + mid)/2 == low? low+1 : (low + mid)/2;
                prev = 1;
            }   
        }
        curans = midans;
        maxi = max(maxi,curans);
        deb(high);
        deb(low);
    
    }
    cout<<maxi<<endl;
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