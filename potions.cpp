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
int dp[2000][2001];
int maxi = 0;
void rec(int a[], int health, int pos, int n,int curans){
    if(pos > n-1){
        return;
    }
    forp(i,pos,n){
        for(int j = curans+1;j<n;j++){
            if(dp[i][j] >= a[i] + health) return;
        }
        dp[i][curans+1] = a[i] + health;
        dp[i][curans] = max(dp[i][curans], health);
        if(a[i] >= 0){
            health+=a[i];
            curans++;
            dp[i][curans] = health;
        }
        else{
            if(health + a[i] >= 0){
                dp[i][curans+1] = a[i] + health;
                rec(a,health + a[i], i+1,n, curans+1);
            }
            else dp[i][curans] = max(dp[i][curans], health);
        }
    }
    maxi = max(maxi, curans);
}

void solve(int in)
{
   
    int n;
    cin >> n;
    forp(i,0,n)
        forp(j,0,n+1) 
            dp[i][j] = -1;
    int a[n];
    forp(i, 0, n)
    {
        cin >> a[i];
    }
    dp[0][0] = 0;
    if(a[0] >= 0) dp[0][1] = a[0];
    // forp(i,0,n){
    //     forp(j,0,n){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    forp(i,1,n){
        if(a[i] >= 0){
            forp(j,1,n+1){
                if(dp[i-1][j-1] >= 0){
                    dp[i][j] = dp[i-1][j-1] + a[i];
                }
            }
        }
        else{
            forp(j,0,n+1){
                dp[i][j] = dp[i-1][j];
            }
            forp(j,1,n+1){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i]);
            }   
        }
    //     forp(i,0,n){
    //     forp(j,0,n){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    }
    cout<<endl;
    forp(i,0,n){
        forp(j,0,n){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    //rec(a,0,0,n, 0);
    forn(i,n,-1){
        forp(j,0,n){
            if(dp[j][i] >= 0){
                cout<<i<<endl;
                return;
            }
        }
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