#include <bits/stdc++.h>
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define endl "\n"
// #define int long long
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
    int w,h;
    cin>>w>>h;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int w2,h2;
    cin>>w2>>h2;
    //w - (x2-x1) < h2 && h - (y2-y1) < w2 && 
    if(w - (x2-x1) < w2 && h - (y2-y1) < h2){
        cout<<-1<<endl;
        return;
    }
    int ans = INT_MAX;
    if(w - (x2-x1) >= w2){
        int t = w - x2, t2 = x1;
        ans = min(w2 - min(w2,t), w2 - min(w2,x1));
    }
    // deb(ans);
    if(h- (y2-y1) >= h2){
        int t = h - y2, t2 = y1;
        ans = min(ans,min(h2 - min(h2,t), h2 - min(h2,y1)));
    }
    cout<<ans<<endl;
}
void solve2(int in){
    int ans = INT_MAX;
    int m;
    cin>>m;
    int a[2][m];
    forp(i,0,2)
    {
        forp(j,0,m){
            cin>>a[i][j];
        }
    }
    int pref[m+1] = {0}, suf[m+1] = {0};
    forp(i,0,m){
        pref[i+1] = pref[i] + a[1][i];
    }
    forn(i,m-1,-1){
        suf[i] = suf[i+1] + a[0][i];
    }

    forp(i,0,m){
        ans = min(ans,max(suf[i+1], pref[i]));
    }
    cout<<ans<<endl;

}
void solve3(int in){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int pref[6][n+1];
    forp(i,0,6){
        forp(j,0,n+1){
            pref[i][j] = 0;
        }
    }
    string arr[6] = {"abc","acb", "bac", "bca", "cab", "cba"};
    forp(i,0,6){
        forp(j,0,n){
            pref[i][j+1] = pref[i][j] + (s[j] != arr[i][j%3]);
        }
    }
    forp(i,0,m){
        int x,y;
        cin>>x>>y;
        int ans = INT_MAX;
        forp(j,0,6){
            ans = min(ans,pref[j][y] - pref[j][x-1]);
        }
        cout<<ans<<endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    forp(i, 1, t + 1)
    {
        solve3(i);
    }
    return 0;
}