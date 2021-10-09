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
    unordered_map<int,int> m;
    vector<int> v(2*n+1);
    forp(i,0,2*n) v[i] = -1;
    int maxi = 0;
    forp(i, 0, n)
    {
        cin >> a[i];
        // m[a[i]] = i;
        v[a[i]] = i;
        // maxi = max(maxi, a[i]);
    }
    int ans =0;
    forp(i,0,2*n){
        int temp = i+1;
        for(int j = 1;j<=sqrt(temp);j++){
            if(temp%j == 0){
                if(v[j]!=-1 && v[temp/j] != -1 && v[j] + v[temp/j] + 2 == temp && j!=temp/j) {ans++;}
            }
        }
    }
    cout<<ans<<endl;

    // set<pair<int,int>> used;
    // for(auto it:m){
    //     int start = it.first;
    //     int need = it.first - (it.second+1)%it.first;
    //     while(start <= maxi){
    //         int pos = start - it.second - 1 + need;
    //         if(pos!= it.second){
    //         if(a[pos]* a[it.second] == pos + it.second + 2){
    //             // deb(pos);
    //             // deb(it.second);
    //             if(pos > it.second){
    //                 if(used.find({it.second,pos}) == used.end()){
    //                     used.insert({it.second,pos});
    //                     ans++;
    //                 }
    //             }
    //             else{
    //                 if(used.find({pos,it.second}) == used.end()){
    //                     used.insert({pos,it.second});
    //                     ans++;
    //                 }
    //             }
    //         }
    //         }
    //         start+=it.first;
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