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
    int n;
    cin >> n;
    vector<int> a(n);
    forp(i, 0, n)
    {
        cin >> a[i];
    }
    if(!is_sorted(all(a))){
        NO;
        return;
    }
    vector<int> ans(n, -1);
    vector<int> pos;
    int prev = a[0];
    vector<int> req;
    forp(i,0,a.back()+1){
        req.push_back(1);
    }
    forp(i,1,n){
        if(a[i] != a[i-1]){
            ans[i] = a[i-1];
            pos.push_back(i);
            req[a[i-1]] = 0;
        }
    }
    forp(i,pos.back() + 1,n){
        ans[i] = a[pos.back()];
    }
    set<int,greater<int>> s;
    int cur = a[pos.back()]-1;
    forn(i,pos.size() - 1, 0){
        int mini = a[pos[i] - 1];
        forn(j,pos[i] - 1, pos[i-1]){
            if(cur == mini){
                ans[j] = mini;
                req[mini] = 0;
            }
            else{
                ans[j] = cur;
                req[cur] = 0;
                cur--;
            }
        }
    }
    int cnter = pos[0] -1;
    if(a[0] == 1){
        req[0] = 0;
        ans[0] = 0;
        int t;
        while
    }
    forn(i,pos[0]-1,-1){
        if(a[0] == 1){
            ans[i] = 0; 
        }
        else ans[i] = 1;
    }
    forp(i,0,n){
        cout<<ans[i]<<" ";
    }
    // unordered_set<int> req;
    // forn(i,a.back() - 1, -1){
    //     req.insert(i);
    // }
    // forn(i,n-1,-1){

    // }
    // forp(i,0,st.size()){
    //     cout<<st[i].first<<" "<<st[i].second<<endl;
    // }
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