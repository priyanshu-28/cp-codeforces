#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb push_back
#define endl "\n"
#define int long long
typedef long long ll;
#define forp(i, x, t) for (int i = x; i < t; i++)
#define forn(i, x, t) for (int i = x; i > t; i--)
#define deb(x) cout << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
const int MAXN = 10000001;
int spf[MAXN];
int fact[N], invfact[N];
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
/*

AUTHOR: 

$$$$$$$\            $$\                           
$$  __$$\           $$ |                          
$$ |  $$ | $$$$$$\  $$$$$$$\   $$$$$$\  $$$$$$$\  
$$$$$$$  |$$  __$$\ $$  __$$\  \____$$\ $$  __$$\ 
$$  __$$< $$ /  $$ |$$ |  $$ | $$$$$$$ |$$ |  $$ |
$$ |  $$ |$$ |  $$ |$$ |  $$ |$$  __$$ |$$ |  $$ |
$$ |  $$ |\$$$$$$  |$$ |  $$ |\$$$$$$$ |$$ |  $$ |
\__|  \__| \______/ \__|  \__| \_______|\__|  \__|
                                                  
                                                  
$$$$$$$\                     $$\ $$\       $$\       
$$  __$$\                    \__|$$ |      $$ |      
$$ |  $$ |$$$$$$\   $$$$$$\  $$\ $$ |  $$\ $$$$$$$\  
$$$$$$$  |\____$$\ $$  __$$\ $$ |$$ | $$  |$$  __$$\ 
$$  ____/ $$$$$$$ |$$ |  \__|$$ |$$$$$$  / $$ |  $$ |
$$ |     $$  __$$ |$$ |      $$ |$$  _$$<  $$ |  $$ |
$$ |     \$$$$$$$ |$$ |      $$ |$$ | \$$\ $$ |  $$ |
\__|      \_______|\__|      \__|\__|  \__|\__|  \__|
                                                     
*/
void printVec(vector<void *> v) {
  for (auto x : v) {
    cout << x << " ";
  }
    cout << endl;
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
 
int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}
 
int modinv(int k)
{
	return pow(k, mod-2, mod);
}
 
void precompute()
{
	fact[0]=fact[1]=1;
	for(int i=2;i<N;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=mod;
	}
	invfact[N-1]=modinv(fact[N-1]);
	for(int i=N-2;i>=0;i--)
	{
		invfact[i]=invfact[i+1]*(i+1);
		invfact[i]%=mod;
	}
}
 
int nCr(int x, int y)
{
	if(y>x)
		return 0;
	int num=fact[x];
	num*=invfact[y];
	num%=mod;
	num*=invfact[x-y];
	num%=mod;
	return num;
}
 
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
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

void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
int getFactorization(int x)
{
    int ret = 0;
    while (x != 1)
    {   
        ret++;
        x = x / spf[x];
    }
    return ret;
}

void solve(int in)
{
    int n;
    cin>>n;
    int m = 2*n;
    int a[m][m];
    forp(i,0,m){
        forp(j,0,m){
            cin>>a[i][j];
        }
    }
    int ans = 0;
    forp(i,n, m){
        forp(j, n, m){
            cout<<a[i][j]<<" ";
            ans += a[i][j];
            a[i][j] = 0;
        }
        cout<<endl;
    }
    deb(ans);
    int c[n][n];
    forp(i,0, n){
        forp(j, n, m){
            c[i][j-n] = a[i][j];
        }
    }
    int right[n][n], down[n][n];
    forp(i,0,n){
        right[i][0] = c[i][0];
    }
    forp(col, 1, n){
        forp(row, 0, n){
            right[row][col] = c[row][col] + right[row][col-1];
        }
    }
    forp(i,0,n){
        down[n-1][i] = c[n-1][i];
    }
    forn(row, n-2, -1){
        forp(col, 0, n){
            down[row][col] = c[row][col] + down[row+1][col];
        }
    }
    int cur = INT_MAX;
    forp(i,0,n){
        forp(j,0,n){
            if(cur > right[i][j] + down[i][j] - c[i][j]){
                cur = right[i][j] + down[i][j] - c[i][j];
            }
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = i+1; j < m; j++)
            swap(a[i][j], a[j][i]);
    forp(i,0, n){
        forp(j, n, m){
            c[i][j-n] = a[i][j];
        }
    }
    forp(i,0,n){
        right[i][0] = c[i][0];
    }
    forp(col, 1, n){
        forp(row, 0, n){
            right[row][col] = c[row][col] + right[row][col-1];
        }
    }
    forp(i,0,n){
        down[n-1][i] = c[n-1][i];
    }
    forn(row, n-2, -1){
        forp(col, 0, n){
            down[row][col] = c[row][col] + down[row+1][col];
        }
    }
    forp(i,0,n){
        forp(j,0,n){
            if(cur > right[i][j] + down[i][j] - c[i][j]){
                cur = right[i][j] + down[i][j] - c[i][j];
            }
        }
    }

    cout<<ans + cur<<endl;
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