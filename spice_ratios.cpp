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

using namespace std;

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
const int MOD = 1e9 + 7;
 
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
	fact[0]=fact[1]=1;
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
 
bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
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

void solve(int in)
{
    int m,n,s,t;
    cin>>m>>n>>s>>t;
    int div = min(m/s, n/t);
    cout<<s*div<<" "<<t*div<<endl;
}
void solve2(int in){
    int l,w,h,v;
    cin>>l>>w>>h>>v;
    vector<int> vert(v+2), hori(h+2);
    vert[0] = 0;
    hori[0] = 0;
    forp(i,0,h){
        cin>>hori[i+1];
    }
    hori[h+1] = l;
    // forp(i,0,vert.size()) deb(vert[i]);
    // forp(i,0,hori.size())deb(hori[i]);
    forp(i,0,v){
        cin>>vert[i+1];
    }
    vert[v+1] = w;
    sort(all(vert));
    sort(all(hori));
    // forp(i,0,vert.size()) deb(vert[i]);
    // forp(i,0,hori.size())deb(hori[i]);
    int dif1 = 0, dif2 = 0;
    int a1,b1,a2,b2;
    forp(i,1,vert.size()){
        if(dif1 < vert[i] - vert[i-1]){
            dif1 = max(dif1, vert[i] - vert[i-1]);

            a1 = vert[i-1];
            b1 = vert[i];
        }
    }
    forp(i,1,hori.size()){
        if(dif2 < hori[i] - hori[i-1]){
            dif2 = max(dif2, hori[i] - hori[i-1]);
            a2 = hori[i-1];
            b2 = hori[i];
        }
    }
    cout<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    forp(i, 1, t + 1)
    {
        solve2(i);
    }
    return 0;
}