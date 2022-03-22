#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb push_back
#define endl "\n"
// #define int long long
typedef long long ll;
#define forp(i, x, t) for (int i = x; i < t; i++)
#define forn(i, x, t) for (int i = x; i > t; i--)
#define deb(x) cout << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 998244353;
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
int gcdExtended(int a, int b, int *x, int *y);
 
// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't
int modInverse(int b, int m)
{
    int x, y; // used in extended GCD algorithm
    int g = gcdExtended(b, m, &x, &y);
 
    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;
 
    // m is added to handle negative x
    return (x%m + m) % m;
}
 
 
// C function for extended Euclidean Algorithm (used to
// find modular inverse.
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
vector<int> primes;
map<int, int> getPrimeFactors(int n){
    map<int, int> mp;
    for(int i=0;i<primes.size() && primes[i] <= sqrt(n);i++){
        if(n%primes[i]==0){
            mp[primes[i]]++;
            n/=primes[i];
            i--;
        }
    }
    if(n!=1)
        mp[n]++;
    return mp;
}
void solve(int in)
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    int props[n + 1][n + 1];
    map<pair<int, int>, pair<int, int>> m;
    forp(i, 0, n - 1)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        adj[a].push_back(b);
        adj[b].push_back(a);
        int g = __gcd(c, d);
        c /= g;
        d /= g;
        m[{a, b}] = {c, d};
        m[{b, a}] = {d, c};
    }
    // fix value of node 1
    vector<int> numden(n + 1);
    int vis[n + 1] = {0};
    queue<pair<int, pair<map<int, int>, map<int, int>>>> q;
    map<int, int> temp;
    temp[1] = 1;
    q.push({1, {temp, temp}});
    numden[1] = 1;
    map<int, int> lcm;
    while (!q.empty())
    {
        int top = q.front().first;
        auto numd = q.front().second;
        q.pop();
        forp(i, 0, adj[top].size())
        {
            int nxt = adj[top][i];
            if (vis[nxt] == 0)
            {
                vis[nxt] = 1;
                auto m1 = getPrimeFactors(m[{nxt, top}].first);
                auto tempest = getPrimeFactors(numden[top]);
                for(auto it: tempest) {
                    m1[it.first] += it.second;
                }
                auto m2 = getPrimeFactors(m[{nxt, top}].second);
                for(auto it: numd.second) {
                    m2[it.first] += it.second;
                }
                map<int, int> subber;
                for(auto it: m1) {
                    if(m2.find(it.first) != m2.end() && it.first != 1) {
                        int sub = min(it.second, m2[it.first]);
                        subber[it.first] += sub;
                    }
                }
                for(auto it:subber){
                    m1[it.first] -= it.second;
                    m2[it.first] -= it.second;
                    if(m1[it.first] == 0)
                        m1.erase(it.first);
                    if(m2[it.first] == 0)
                        m2.erase(it.first);
                }
                int num = 1;
                for(auto it: m1) {
                    num *= pow(it.first, it.second, mod);
                    num %= mod;
                }
                for(auto it:m2){
                    lcm[it.first] = max(lcm[it.first], it.second);
                }
                numden[nxt] = num;
                q.push({nxt, m2});
            }
        }
    }
    ll ans = 0;
    forp(i,1,n+1){
        ll cur2 = 1;
        for(auto it: lcm){
            cur2 *= pow(it.first, it.second - min(it.second, numden[i].second[it.first]), mod);
            cur2 %= mod;
        }
        // deb(cur2);
        ans += numden[i].first * cur2;
        ans %= mod;
    }
    cout << ans << endl;
}
void SieveOfEratosthenes(int n)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.pb(p);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    SieveOfEratosthenes(200001);
    int t = 1;
    cin >> t;
    forp(i, 1, t + 1)
    {
        solve(i);
    }
    return 0;
}