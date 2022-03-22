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

// void solve(int in)
// {
//     int mean = 0;
//     int n;
//     cin>>n;
//     map<int,int> m;
//     vector<int> a(n);
//     forp(i,0,n){
//         cin>>a[i];
//         mean += a[i];
//     }
//     if((mean*2) % n != 0){
//         cout<<0<<endl;
//     }
//     else{
//         // mean /= n;
//         double mm = mean*1./n;
//         int sum = 2*mm;
//         sort(all(a));
//         int ans = 0;
//         forp(i,0,n){
//             int temp = upper_bound(all(a),sum - a[i]) - lower_bound(all(a), sum - a[i]);
//             if(a[i] == sum - a[i]) temp--;
//             ans += temp;
//         }
//         cout<<ans/2<<endl;
//     }

// }
void solve2(int in){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    int ca[n+1] = {0}, cb[n+1] = {0};
    int pra = 1, prb = 1;

    forp(i,0,n){
        cin>>v[i].first >> v[i].second;
        ca[v[i].first]++;
        cb[v[i].second]++;
    }
    // sort(all(v));
    map<int, vector<int>> m;
    forp(i,0,n){
        m[v[i].first].push_back(v[i].second);
    }
    forp(i,1,n+1){
        if(ca[i]!=0)pra *= ca[i];
    }
    int ans = 0;
    forp(i,0,n){
        ans += pra/ca[v[i].first];
    }
    // ans /= 3;
    deb(ans);
    int add = 0;
    forp(i,1,n+1){
        if(ca[i]!=0) add += (ca[i]*(ca[i]-1))/2;
    }
    int nn = 0;
    int minus[n+1] = {0};
    forp(i,0,v.size()){
        if(ca[v[i].first] > 1) minus[v[i].second] += ca[v[i].first]-1;
    }
    deb(add);
    forp(i,0,n){
        nn = 0;
        nn += add;
        nn -= ((ca[v[i].first])*(ca[v[i].first] - 1))/2;
        // nn += ca[v[i].first];
        nn -= minus[v[i].second];
        if(ca[v[i].first] > 1) nn += ca[v[i].first];
        ans += nn;
    }
    ans/=3;
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