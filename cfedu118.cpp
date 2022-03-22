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
    int x,y;
    forp(i,0,n)
    {
        forp(j,0,m)
        {
            cin>>a[i][j];
            if(a[i][j] == 'L'){
                x = i;
                y = j;
            }
        }
    }
    set<pair<int,int>> choices[n][m];
    forp(i,0,n)
    {
        forp(j,0,m)
        {
            if(i - 1 >= 0 && a[i-1][j] == '.') choices[i][j].insert({i-1,j});
            if(i + 1 < n && a[i+1][j] == '.') choices[i][j].insert({i+1,j});
            if(j - 1 >= 0 && a[i][j-1] == '.') choices[i][j].insert({i,j-1});
            if(j + 1 < m && a[i][j+1] == '.') choices[i][j].insert({i,j+1});
        }
    }
    queue<pair<int,int>> q;
    if(x + 1 < n && a[x+1][y] != '#' && choices[x+1][y].size() <= 1) q.push({x+1,y});
    if(x - 1 >= 0 && a[x-1][y] != '#' && choices[x-1][y].size() <= 1) q.push({x-1,y});
    if(y + 1 < m && a[x][y+1] != '#' && choices[x][y+1].size() <= 1) q.push({x,y+1});
    if(y - 1 >= 0 && a[x][y-1] != '#' && choices[x][y-1].size() <= 1) q.push({x,y-1});
    while(q.size()){
        pair<int,int> p = q.front();
        q.pop();
        int u = p.first;
        int v = p.second;
        a[u][v] = '+';
        if(u + 1 < n && a[u+1][v] == '.'){
            choices[u+1][v].erase({u,v});
            if(choices[u+1][v].size() <= 1) q.push({u+1,v});
        }
        if(u - 1 >= 0  && a[u-1][v] == '.'){
            choices[u-1][v].erase({u,v});
            if(choices[u-1][v].size() <= 1) q.push({u-1,v});
        }
        if(v + 1 < m && a[u][v+1] == '.'){
            choices[u][v+1].erase({u,v});
            if(choices[u][v+1].size() <= 1) q.push({u,v+1});
        }
        if(v - 1 >= 0 && a[u][v-1] == '.'){
            choices[u][v-1].erase({u,v});
            if(choices[u][v-1].size() <= 1) q.push({u,v-1});
        }
    }
    forp(i,0,n)
    {
        forp(j,0,m)
        {
            cout<<a[i][j];
        }
        cout<<endl;
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