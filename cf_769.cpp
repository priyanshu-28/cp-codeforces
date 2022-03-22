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
    vector<int> adj[n+1];
    forp(i,0,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(q.size() > 0){
        int top = q.front();
        q.pop();
        for(auto x: adj[top]){
            if(dist[x] == -1){
                dist[x] = dist[top] + 1;
                q.push(x);
            }
        }
    }
    int maxdist = INT_MAX, maxnode = 1;
    forp(i,2,n + 1){
        queue<int> qu;
        auto tempdist = dist;
        qu.push(i);
        tempdist[i] = 1;
        while(qu.size() > 0){
            int top = qu.front();
            qu.pop();
            for(auto x: adj[top]){
                if(tempdist[x] > tempdist[top] + 1){
                    tempdist[x] = tempdist[top] + 1;
                    qu.push(x);
                }
            }
        }
        int curmax = 0;
        forp(j, 1, n + 1){
            curmax = max(curmax, tempdist[j]);
        }
        if(curmax < maxdist){
            maxdist = curmax;
            maxnode = i;
        }
    }
    maxdist = 0;
    forp(i,1, n + 1){
        if(dist[i] > maxdist){
            maxdist = dist[i];
        }
    }
    int prev = 0;
    forp(x,1,n+1){
        if(x < maxdist){
            top:
            auto tempdist = dist;
            queue<int> qu;
            qu.push(maxnode);
            tempdist[maxnode] = x;
            while(qu.size() > 0){
                int top = qu.front();
                qu.pop();
                for(auto y: adj[top]){
                    if(tempdist[y] > tempdist[top] + 1){
                        tempdist[y] = tempdist[top] + 1;
                        qu.push(y);
                    }
                }
            }
            int maxi = 0;
            forp(i,1,n+1){
                if(tempdist[i] > maxi){
                    maxi = tempdist[i];
                }
            }
            if(maxi > prev){
                // find maxnode again and maxi again
                int maxdist = INT_MAX, maxnode = 1;
                forp(i,2,n + 1){
                    queue<int> que;
                    tempdist = dist;
                    que.push(i);
                    tempdist[i] = x;
                    while(que.size() > 0){
                        int top = que.front();
                        que.pop();
                        for(auto x: adj[top]){
                            if(tempdist[x] > tempdist[top] + 1){
                                tempdist[x] = tempdist[top] + 1;
                                que.push(x);
                            }
                        }
                    }
                    int curmax = 0;
                    forp(j, 1, n + 1){
                        curmax = max(curmax, tempdist[j]);
                    }
                    if(curmax < maxdist){
                        maxdist = curmax;
                        maxnode = i;
                    }
                }
                maxdist = 0;
                forp(i,1, n + 1){
                    if(dist[i] > maxdist){
                        maxdist = dist[i];
                    }
                }
                prev = maxi;
                goto top;
            }
            cout<<maxi<<" ";
        }
        else cout<<maxdist<<" ";
    }
    cout<<endl;
}
void solve2(int in){
    int n;
    cin>>n;
    vector<int> a(n);
    forp(i,0,n){
        cin>>a[i];
        if(a[i] == 1){
            a[i] = -1;
        }
        else{
            int g = a[i];
            for(int j = i-1; j >= 0; j--){
                if(a[j] == -1) break;
                g = __gcd(g, a[j]);
                if(g == i - j + 1){
                    a[i] = -1;
                    break;
                }
            }
        }
    }
    int cur = 0;
    forp(i,0,n){
        if(a[i] == -1){
            cur++;
        }
        cout<<cur<<" ";
    }
    cout<<endl;
    
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    forp(i, 1, t + 1)
    {
        solve(i);
    }
    return 0;
}