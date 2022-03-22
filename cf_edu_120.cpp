#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb push_back
// #define endl "\n"
#define int long long
typedef long long ll;
#define forp(i, x, t) for (int i = x; i < t; i++)
#define forn(i, x, t) for (int i = x; i > t; i--)
#define deb(x) cout << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 998244353;
const int N = 5001;
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
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<vector<int>> a;
    if(k== 0){
        cout<<1<<endl;
        return;
    }
    int ans = 1;
    for(int i=  0; i<n;){
        int cur = 0, lastone;
        if(s[i] == '1') cur++, lastone = i;
        int j = i+1;
        for(;j < n; j++){
            if(cur == k && s[j] == '1'){
                a.pb({i,j-1, lastone});
                break;
            }
            else if(cur < k && s[j] == '1'){
                cur++;
                lastone = j;
            }
        }
        if(j == n && cur == k) a.pb({i,n-1, lastone});
        while(s[i] != '1' && i < n) i++;
        i++;
    }
    if(a.size() >= 1){
        ans += nCr(a[0][1] - a[0][0] + 1, k) - 1;
        ans %= mod;
        if(ans < 0) ans += mod;
        forp(i,1,a.size()){
            ans += nCr(a[i][1] - a[i][0] + 1, k) - nCr(a[i][2] - a[i][0], k - 1);
            ans %= mod;
            if(ans < 0) ans += mod;

        }
    }
    cout<<ans<<endl;
    // forp(i,0,a.size()){
    //     ans += nCr(a[i].first, a[i].second);
    //     ans %= mod;
    // }
    // int temp = 0;
    // int len = 0;
    // for(int i = 0; i < n; i++){
    //     if(s[i] == '1'){
    //         temp++;
    //     }
    //     if(temp > k){
    //         break;
    //     }
    //     len++;
    // }
    // if(temp >= k){
    //     ans += nCr(len, k) - 1;
    // }
    // int start = 0;
    // while(s[start] != '1' && start < n){
    //     start++;
    // }
    // start++;
    // int prev = start;
    // int j = 1;
    // int lastone = -1;
    // for(int i=start;i<n;){
    //     int cur = 0;
    //     if(s[i] == '1'){
    //         cur = 1;
    //         lastone = max(i, lastone);
    //     }
    //     for(;j < n;){
    //         if(cur < k || cur == k && s[j] == '0'){
    //             cur += s[j] - '0';
    //             if(s[j] == '1')
    //                 lastone = max(j, lastone);
    //             j++;
    //         }
    //         else{
    //             j--;
    //             break;
    //         }
    //     }
    //     deb(j);
    //     deb(i);
    //     if(j == n) j--;
    //     if(cur == k) {
    //         deb(lastone);
    //         ans += nCr(j - i + 1, k) - nCr(lastone - i, k-1) - 1;
    //     }
    //     ans %= mod;
    //     deb(j);
    //     deb(i);
    //     deb(ans);
    //     while(i < n && s[i] != '1'){
    //         i++;
    //     }
    //     i++;
    // }
    // cout<<ans + 1<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    precompute();
    forp(i, 1, t + 1)
    {
        solve(i);
    }
    return 0;
}