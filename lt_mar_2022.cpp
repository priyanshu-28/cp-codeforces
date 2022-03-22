#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define YES cout << "YES"<<endl
#define NO cout << "NO"<<endl
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
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void solve(int in)
{
    int n, q;
    cin>>n>>q;
    vector<set<int>> adj(n + 1);
    forp(i,0,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }   
    auto cp = adj;
    int ans = 0;
    queue<int> qu;
    forp(i,1,n+1){
        if(adj[i].size()==1){
            qu.push(i);
        }
    }  
    while(qu.size()){
        int top = qu.front();
        qu.pop();
        // deb(top);
        if(adj[top].size()){
            int connectedTo = *adj[top].begin();
            ans += adj[top].size() * adj[connectedTo].size();
            adj[top].clear();
            adj[connectedTo].erase(top);
            if(adj[connectedTo].size()==1){
                qu.push(connectedTo);
            }
        }
    }
    cout<<ans<<endl;
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int temp = ans - (1 + cp[a].size() - 1 + cp[b].size() - 1);
        // deb(temp);
        cp[a].erase(b);
        cp[b].erase(a);
        // deb(cp[c].size());
        // deb(cp[d].size());
        temp += cp[c].size() + cp[d].size() + 1;
        cp[a].insert(b);
        cp[b].insert(a);
        cout<<temp<<endl;   
    }
}
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
void solve2(int in){
    int n, q;
    cin>>n>>q;
    vector<int> v(n);
    forp(i,0,n){ cin >> v[i]; }
    set<int> s[n], all;
    map<int, int> pref[n];
    forp(i,0,n){
        if(i != 0){
            pref[i] = pref[i-1];
        }
        int tt = v[i];
        map<int, int> tempmap;
        while(tt % 2 == 0){
            tempmap[2]++;
            tt /= 2;
        }
        for(int j = 3; j <= sqrt(tt); j += 2){
            while(tt % j == 0){
                tempmap[j]++;
                tt /= j;
            }
        }
        if(tt > 1){
            tempmap[tt]++;
        }
        for(auto it = tempmap.begin(); it != tempmap.end(); it++){
            pref[i][it->first] = max(it->second, pref[i][it->first]);
        }
    }
    forp(i,0,n){
        deb(i);
        for(auto it: pref[i]){
            cout<<it.first<<" "<<it.second<<endl;
        }

    }
    while(q--){
        int x , y;
        cin>>x>>y;
        x-=2, y--;
        int ans = 1;
        for(auto it = pref[y].rbegin(); it != pref[y].rend(); it++){
            int temp = 0;
            // deb(x);
            if(x >= 0 && pref[x].find(it->first) != pref[x].end()){
                deb("hi");
                temp = pref[x][it->first];
            }
            deb(it -> first);
            deb(it -> second );
            deb(temp);
            ans *= binpow(it->first, it->second - temp);
        }
        cout<<ans<<endl;
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
        solve2(i);
    }
    return 0;
}