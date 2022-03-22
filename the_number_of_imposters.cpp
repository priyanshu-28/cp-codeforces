#include <bits/stdc++.h>
#define YES cout << "YES\n"
#define NO cout << "NO\n"
// #define endl "\n"
// #define int long long
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
int glo = 0;
void dfs(int x, map<int,int> &mp, vector<vector<int>> v, vector<int> &vis, vector<vector<int>> a, int ass){
    // if(vis[x] ==-1){
        // assume he is a crewmate
        mp[x] = ass;
        vis[x] = ass;
        deb("Hello");
    forp(i,0,a[x].size()){
        int j = a[x][i];
        deb(j);
        if(v[j][0] == x){
            if(vis[x] == 0){
                // x is v crewmate
                mp[v[j][1]] = v[j][2];
                // vis[v[j][1]] = v[j][2];
                if(vis[v[j][1]] == -1) dfs(v[j][1], mp, v, vis, v, v[j][2]);
                else if(vis[v[j][1]] != v[j][2]) glo = -1;
            }
            else{
                mp[v[j][1]] = 1 - v[j][2];
                // vis[v[j][1]] = 1 - v[j][2];
                if(vis[v[j][1]] == -1) dfs(v[j][1], mp, v, vis, v, 1 - v[j][2]);
                else if(vis[v[j][1]] != 1-v[j][2]) glo = -1;
            }
        }
        else{
            int val;
            if(vis[x] == 0){
                // x is v crewmate
                val = v[j][2] == 1? 1 : 0;
                mp[v[j][0]] = val;
                if(vis[v[j][0]] == -1) dfs(v[j][0], mp, v, vis, v, val);
                else if(vis[v[j][0]] != val) glo = -1;
            }
            else{
                val = 1 - val;
                mp[v[j][0]] = val;
                if(vis[v[j][0]] == -1) dfs(v[j][0], mp, v, vis, v, val);
                else if(vis[v[j][0]] != val) glo = -1;
            }
        }
    }
    
}
void solve(int in)
{
    glo = 0;
    string imp = "imposter", c = "crewmate";
    int n, m;
    cin >> n >> m;
    map<int,int> mp;
    vector<vector<int>> v(m), a(n);
    forp(i,0,m){
        int x,y;
        string s;
        cin>>x>>y;
        cin>>s;
        x--,y--;
        a[x].push_back(i);
        a[y].push_back(i);
        v[i].push_back(x);
        v[i].push_back(y);
        if(s==imp)v[i].push_back(1);
        else v[i].push_back(0);
    }
    vector<int> vis(n,-1);
    int ans = 0;
    forp(i,0,m){
        if(vis[i] == -1){
            dfs(i,mp,v,vis,a,0);
            if(glo == -1){
                cout<<-1<<endl;
                return;
            }
            int z = 0;
            for(auto it: mp){
                deb(it.first);
                deb(it.second);
                deb("");
                if(it.second == 0)z++;
            }
            ans += max((int)(mp.size() - z), z);
            mp.clear();
        }
    }
    forp(i,0,n){
        if(vis[i] == -1) ans++;
        deb(vis[i]);
    }
    cout<<ans<<endl;
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