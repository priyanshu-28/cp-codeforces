#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
bool isReachable(int num, vector<int> a, int n, int k){
    int ans = 0;
    forn(i,n-1,-1){
        int temp = num/a[i];
        num -= temp*a[i];
        ans += temp;
    }
    if(ans > k) return false;
    return true;
}
void solve(int in)
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    int ans = k + 1;
    vector<int> req(10, 0);
    req[0] = 1;

    forp(i,0,n)
    {
        cin>>a[i];
        req[a[i]] = 1;
        a[i] = pow(10, a[i]);
    }
    forp(i,1,10){
        if(req[i] == 0){
            req[i] = req[i-1] * 10;
        }
    }
    forp(i,0,10){
        deb(req[i]);
    }
    if(n == 1){
        cout<<k + 1<<endl;
    }
    else{
        k++;
        int cnt = 0;
        int ans = 0;
        while(k > 0){
            if(k - 9*req[cnt] >= 0){
                k -= 9*req[cnt];
                ans += 9*a[cnt];
                cnt++;
            }
            else if(k >= req[cnt]){
                int temp = k/req[cnt];
                k -= temp*req[cnt];
                ans += temp*a[cnt];
            }
            else{
                cnt--;
            }
            deb(k);
        }
        cout<<ans<<endl;
    }
    
}
void solve2(int in){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    forp(i,0,n)
    {
        cin>>a[i];
    }
    int ans = 0;
    k++;
    forp(i,0,n-1){
        int dif = a[i+1] - a[i];
        int sub = pow(10,dif) - 1;
        // deb(i);deb(sub);
        if(k - sub > 0){
            k -= sub;
            ans += pow(10,a[i])*sub;
        }
        else{
            ans += k*pow(10,a[i]);
            k = 0;
            break;
        }
        // deb(ans);
        // deb(k);
    }
    // cout<<(int)(k*pow(10,a[n-1]))<<endl;
    if(k > 0){
        ans += (int)(k*pow(10,a[n-1]));
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
        solve2(i);
    }
    return 0;
}