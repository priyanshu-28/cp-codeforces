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
const int mod = 998244353;

using namespace std;

int power(int x, int y)
{
    int res = 1;
    if (x == 0)
        return 0;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
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

const int N = 2e5 + 5;
const int MOD = mod;
 
int fact[N], invfact[N];
 
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
	return pow(k, MOD-2, MOD);
}
 
void precompute()
{
	fact[0]=1;fact[1]=1;
	for(int i=2;i<N;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	invfact[N-1]=modinv(fact[N-1]);
	for(int i=N-2;i>=0;i--)
	{
		invfact[i]=invfact[i+1]*(i+1);
		invfact[i]%=MOD;
	}
}
 
int nCr(int x, int y)
{
	if(y>x)
		return 0;
	int num=fact[x];
	num*=invfact[y];
	num%=MOD;
	num*=invfact[x-y];
	num%=MOD;
	return num;
}
 
void solve(int in)
{
    int n;
    cin >> n;
    vector<int> a(n);
    int maxi = 0;
    forp(i, 0, n)
    {
        cin >> a[i];
        maxi = max(maxi, a[i]);
    }
    int cntm = 0, cntmin1 = 0;
    // deb(n);
    forp(i, 0, n)
    {
        if (a[i] == maxi)
            cntm++;
        else if (a[i] == maxi - 1)  
            cntmin1++;
    }
    // deb(n);
    int useless = n - cntmin1 - 1;

    if(cntm > 1){
        cout<<fact[n]<<endl;
    }
    else if(cntmin1 >= 1){
        int ans = fact[n];
        forp(i,0,useless+1){
            int back = n-1-i;
            int ncr;
            ncr = nCr(useless,i);
            ncr = ncr%mod;
            int net = fact[back] * ncr;
            net = net%mod;
            net *= fact[i];
            net = net%mod;
            ans -= net;
            if(ans < 0) ans += mod;
        }
        cout<<ans<<endl;
    }
    else cout<<0<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("output.txt", "r", stdin);
    int t = 1;
    cin >> t;
    precompute();
    forp(i, 1, t + 1)
    {
        solve(i);
    }
    return 0;
}