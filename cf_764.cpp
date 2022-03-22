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
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    forp(i,0,n)
    {
        cin>>v[i];
    }
    string s;
    cin>>s;
    map<string, vector<int> > mp;
    forp(i,0,n){
        forp(j,0,m-1){
            string temp;
            temp += v[i][j];
            temp += v[i][j+1];
            mp[temp] = {j, j+1, i};
            if(j + 2 < m){
                temp += v[i][j+2];
                mp[temp] = {j, j+2, i};
            }
        }   
    }
    vector<vector<int>> dp(m);
    dp[m-1] = {-1};
    vector<int> parent(m, -1);
    for(int i = m-2; i>=0;i--){
        string two;
        two += s[i];
        two += s[i+1];
        if(i == m-2){
            parent[i] = -1;
            auto temp = two;
            if(mp.find(temp) != mp.end()){
                dp[i] = mp[temp];
            }
            else{
                dp[i] = {-1};
            }
        }
        else if(i==m-3){
            parent[i] = -1;
            auto temp = two;
            temp += s[i+2];
            if(mp.find(temp) != mp.end()){
                dp[i] = mp[temp];
            }
            else{
                dp[i] = {-1};
            }
        }
        else if(i == m-4){
            if(dp[i+2][0] == -1){
                dp[i] = {-1};
            }
            else{
                parent[i] = i+2;
                auto temp = two;
                if(mp.find(temp) != mp.end()){
                    dp[i] = mp[temp];
                }
                else{
                    dp[i] = {-1};
                }
            }
        }
        else{
            if(dp[i+2][0] == -1){
                dp[i] = {-1};
            }
            else{
                auto temp = two;
                if(mp.find(temp) != mp.end()){
                    dp[i] = mp[temp];
                    parent[i] = i+2;
                }
                else{
                    dp[i] = {-1};
                }
            }
            if(dp[i][0] == -1){
                two += s[i+2];
                if(mp.find(two) != mp.end()){
                    dp[i] = mp[two];
                    parent[i] = i+3;
                }
                else{
                    dp[i] = {-1};
                }
            }
        }
    }
    int start = parent[0];
    if(dp[0][0] == -1){
        cout<<-1<<endl;
    }
    else{
        vector<vector<int>> ans;
        start = 0;
        while(1){
            ans.pb(dp[start]);
            start = parent[start];
            if(start == -1) break;
        }
        cout<<ans.size()<<endl;
            for(auto x : ans){
                cout<<x[0]+1<<" "<<x[1]+1<<" "<<x[2]+1<<endl;
            }
    }
}
void solve2(int in){
    int n;
    cin>>n;
    int left = 1, right = n;
    int prev = 0;
    while(left <= right){
        int mid = (left + right) / 2 + 1;
        int reqovf = n - mid%n;
        cout<<"+ "<<reqovf<<endl;
        int temp;
        cin>>temp;
        if(temp > prev){
            //overflow
            left = mid;
        }
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