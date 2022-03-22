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
const int N = 2e5 + 5;
const int MAXN = 10000001;
int spf[MAXN];
int fact[N], invfact[N];
using namespace std;
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
    int n,m;
    cin>>n>>m;
    char a[n][m];
    forp(i,0,n){
        forp(j,0,m){
            cin>>a[i][j];
        }
    }
    vector<pair<int,int>> good, bad;
    forp(i,0,n){
        forp(j,0,m){
            if(a[i][j] == 'G') good.push_back({i,j});
            else if(a[i][j] == 'B'){
                bad.push_back({i,j});
                if(i - 1 >= 0 && a[i-1][j] == '.') a[i-1][j] = '#';
                if(i + 1 < n && a[i+1][j] == '.') a[i+1][j] = '#';
                if(j - 1 >= 0 && a[i][j-1] == '.') a[i][j-1] = '#';
                if(j + 1 < m && a[i][j+1] == '.') a[i][j+1] = '#';
            }
        }
    }
    if(a[n-1][m-1] == '#'){
        if(good.size() == 0){
            YES;
        }
        else NO;
        return;
    }
    else{
        int vis[n][m];
        memset(vis,0,sizeof(vis));        
        queue<pair<int,int>> q;
        q.push({n-1,m-1});
        while(q.size() > 0){
            auto top = q.front();
            q.pop();
            int i = top.first, j = top.second;
            if(i - 1 >= 0 && vis[i-1][j] == 0 && a[i-1][j] != '#'){
                vis[i-1][j] = 1;
                q.push({i-1,j});
            }
            if(j - 1 >= 0 && vis[i][j-1] == 0 && a[i][j-1] != '#'){
                vis[i][j-1] = 1;
                q.push({i,j-1});
            }
            if(i + 1 < n && vis[i+1][j] == 0 && a[i+1][j] != '#'){
                vis[i+1][j] = 1;
                q.push({i+1,j});
            }
            if(j + 1 < m && vis[i][j+1] == 0 && a[i][j+1] != '#'){
                vis[i][j+1] = 1;
                q.push({i,j+1});
            }
        }
        forp(i,0,good.size()){
            if(vis[good[i].first][good[i].second] == 0){
                NO;
                return;
            }
        }
        forp(i,0,bad.size()){
            if(vis[bad[i].first][bad[i].second] == 1){
                NO;
                return;
            }
        }
        YES;
    }
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