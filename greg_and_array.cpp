#include <bits/stdc++.h>
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define int long long
#define endl "\n"
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
    int n,m,k;
    cin >> n>>m>>k;
    vector<int> a(n);
    forp(i, 0, n)
    {
        cin >> a[i];
    }
    vector<vector<int>> v(m);
    forp(i,0,m){
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        t1--,t2--;
        v[i].push_back(t1);
        v[i].push_back(t2);
        v[i].push_back(t3);
    }
    int exec[m+1] = {0};
    while(k--){
        int x,y;
        cin>>x>>y;
        x--,y--;
        exec[x]++;
        exec[y+1]--;
    }
    int pref[m] = {0};
    pref[0] = exec[0];
    forp(i,1,m){
        pref[i] = pref[i-1] + exec[i];
    }
    int marks[n+1] = {0};
    forp(i,0,m){
        v[i][2] *= pref[i];
        marks[v[i][0]]+= v[i][2];
        marks[v[i][1] + 1] -= v[i][2];
    }
    int pr[n];
    pr[0] = marks[0];
    a[0]+=pr[0];
    forp(i,1,n){
        pr[i] = pr[i-1] + marks[i];
        a[i]+=pr[i];
    }
    forp(i,0,n){
        cout<<a[i]<<" ";
    }
}
void solve2(int in){
    int n,m,k;
    cin >>n>>m>>k;
    vector<int> a(n);
    forp(i, 0, n)
    {
        cin >> a[i];
    }
    vector<vector<int>> v(m);
    forp(i,0,m){
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        t1--,t2--;
        v[i].push_back(t1);
        v[i].push_back(t2);
        v[i].push_back(t3);
    }
    while(k--){
        int x,y;
        cin>>x>>y;
        x--,y--;
        forp(i,x,y+1){
            forp(j,v[i][0], v[i][1] + 1){
                a[j]+=v[i][2];
            }
        }   
    }
    forp(i,0,n){
        cout<<a[i]<<" ";
    }
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