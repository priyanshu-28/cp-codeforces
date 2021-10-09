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
    forp(i,0,n){
        cin>>a[i];
    }
    sort(all(a));
    vector<int> ans;
    ans.push_back(a[0]);
    int mindif= INT_MAX;
    forp(i,1,n){
        if(a[i] - ans.back() >= a[i] && a[i] <= mindif){ 
            //ans.push_back(a[i]);
            mindif = min(a[i] - ans.back(),mindif);
            ans.push_back(a[i]);
        }
        else break;
    }
    cout<<ans.size()<<endl;




    // forp(i,0,n-1){
    //     v[i] = a[i+1] - a[i]; 
    // }
    // map<int,int> m;
    // map<int,int,greater<int>>cnt;
    // forp(i,0,n-1){
    //     m[abs(a[i] - a[i+1])]++;
    //     cnt[a[i]]++;
    // }
    // map<int,int> pref;
    // int prev = 0;
    // for(auto it:m){
    //     pref[it.first]+=it.second + prev;
    //     prev += it.second;
    // }

    // cnt[a[n-1]]++;
    // for(auto it:pref){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    // cout<<endl;
    // int ans = 0;
    // for(auto it:cnt){
    //     auto iter = m.lower_bound(it.first);
    //     if(iter == m.end()) iter--;
    //     deb(it.first);
    //     deb(iter->first);
    //     deb(iter->second);
    //     if(iter->first <= it.first){
    //         if(iter->second )
    //     }
    //     else{
    //         iter--;

    //     }
    // }


    // int mincons = INT_MAX;
    // forp(i,1,n){
    //     mincons = min(mincons, a[i] - a[i-1]);
    // }
    // if(n == 1){
    //     cout<<1<<endl;
    //     return;
    // }
    // int ans = n;
    // forn(i,n-1,0){
    //     if(a[i] - a[i-1] >= a.back());
    //     else{
    //         ans--;
    //         auto it = a.end();
    //         it--;
    //         if(i +1== a.size()) a.erase(it);
    //     }
    // }
    // cout<<ans<<endl;
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