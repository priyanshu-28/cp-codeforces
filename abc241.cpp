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
    int h,w, n;
    cin>>h>>w >> n;
    int sx, sy, gx, gy;
    cin>>sx>>sy>>gx>>gy;
    vector<pair<int, int>> v(n);
    map<int, set<int>> rowf, colf;
    forp(i,0,n){
        cin>>v[i].first>>v[i].second;
        rowf[v[i].first].insert(v[i].second);
        colf[v[i].second].insert(v[i].first);
    }
    map<pair<int, int>, int> vis;
    queue<pair<int, int>> q;
    q.push({sx,sy});
    vis[{sx,sy}] = 0;
    while(q.size()){
        auto top = q.front();
        q.pop();
        int x = top.first, y = top.second;
        // right
        if(rowf[x].lower_bound(y) != rowf[x].end()){
            int ny = *rowf[x].lower_bound(y);
            if(vis.find({x,ny-1}) == vis.end()){
                vis[{x,ny-1}] = vis[{x,y}] + 1;
                q.push({x,ny-1});
            }
        }
        // left
        if(rowf[x].size() != 0){
            auto it = rowf[x].upper_bound(y);
            if(it!=rowf[x].begin()){
                it--;
                int ny = *it;
                if(vis.find({x,ny+1}) == vis.end()){
                    vis[{x,ny+1}] = vis[{x,y}] + 1;
                    q.push({x,ny+1});
                }
            }
        }
        // down
        if(colf[y].lower_bound(x) != colf[y].end()){
            int nx = *colf[y].lower_bound(x);
            if(vis.find({nx-1,y}) == vis.end()){
                vis[{nx-1,y}] = vis[{x,y}] + 1;
                q.push({nx-1,y});
            }
        }

        // up
        if(colf[y].size() != 0){
            auto it = colf[y].upper_bound(x);
            if(it!=colf[y].begin()){
                it--;
                int nx = *it;
                if(vis.find({nx+1,y}) == vis.end()){
                    vis[{nx+1,y}] = vis[{x,y}] + 1;
                    q.push({nx+1,y});
                }
            }
        }
    }
    if(vis.find({gx,gy}) == vis.end()){
        cout<<-1<<endl;
    }
    else{
        cout<<vis[{gx,gy}]<<endl;
    }

}

void solve2(int in){
    int q;
    cin>>q;
    map<int, int> m;
    set<pair<int, int>> s;
    while(q--){
        int n;
        cin>>n;
        if(n == 1){
            int x;
            cin>>x;
            m[x]++;
        }
        else{
            int x,k;
            cin>>x>>k;
            if(n == 2){
                auto it = m.lower_bound(x);
                if(it != m.end() && it->first == x){
                    k -= min(k, it->second);
                    if(k == 0){
                        cout<<x<<endl;
                        continue;
                    }
                }
                int flag = 0;
                while(k > 0){
                    if(it == m.begin()){
                        cout<<-1<<endl;
                        flag = 1;
                        break;
                    }
                    it--;
                    k -= it->second;
                }
                if(flag == 0)
                cout<<it->first<<endl;
            }
            else{
                auto it = m.lower_bound(x);
                while(k > 0){
                    if(it == m.end()){
                        cout<<-1<<endl;
                        break;
                    }
                    k -= it->second;
                    if(k <= 0){
                        cout<<it->first<<endl;
                        break;
                    }
                    it++;
                }
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
        solve2(i);
    }
    return 0;
}