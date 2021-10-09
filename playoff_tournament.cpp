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
int ans = 0;

void solve(int in)
{
    int k;
    cin>>k;
    string s;
    cin>>s;
    reverse(all(s));
    int dp[s.size()];
    forn(i,s.size(),0){
        if(i*2 + 1 <= s.size()){
            if(s[i-1] == '?') dp[i-1] = dp[2*i-1] + dp[2*i];
            else if(s[i-1] == '1') dp[i-1] = dp[2*i-1];
            else dp[i-1] = dp[2*i];
        }
        else{
            if(s[i-1] == '?') dp[i-1] = 2;
            else dp[i-1] = 1; 
        }
    }
    int q;
    cin>>q;
    while(q--){
        int p;
        char x;
        cin>>p>>x;
        p = s.size() - p + 1;
        if(s[p-1]!=x){
            int dev = 0;
            if(p*2 + 1 <= s.size()){
                if(x == '?'){
                    dev = dp[p*2-1] + dp[p*2] - dp[p-1];
                }
                else if(x == '1'){
                    dev = dp[p*2-1] - dp[p-1];
                }
                else{
                    dev = dp[p*2] - dp[p-1];
                }
            }
            else{
                if(x == '?') dev = 1;
                else if(s[p-1] == '?') dev = -1;
            }
            int temp = p;
            dp[temp-1] +=dev;
            temp/=2;
            int prev = p;
            while(temp>=1){
                if(prev%2 && s[temp-1] == '1') break;
                else if(prev%2 == 0 && s[temp-1] == '0') break;
                dp[temp-1]+=dev;
                temp/=2;
                prev/=2;
            }
            s[p-1] = x;
        }
        cout<<dp[0]<<endl;
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