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
bool isPalindrome(string S)
{
    for (int i = 0; i < S.length() / 2; i++) {
        if (S[i] != S[S.length() - i - 1]) {
            return false;
        }
    }
    return true;
}
int lcm(int a, int b){
    return (a*b)/__gcd(a,b);
}
void solve(int in)
{
    int n;
    cin>>n;
    vector<int> a(n);
    forp(i,0,n)
    {
        cin>>a[i];
    }
    vector<int> b(n);
    if(n%2){    
        for(int i = 1; i < n; i+=2)
        {
            b[i] = a[i+1];
            b[i+1] = a[i];
            if(a[i] * b[i] + a[i+1] * b[i+1] != 0)
                b[i] = -1*b[i];
            
            int g = __gcd(abs(a[i]),(a[i+1]));
            b[i] /= g;
            b[i+1] /= g;
        }
        int x,y;
        int t1;
        int sum = INT_MAX;
        for(int i = 1; i < n; i+=2)
        {
            if(a[i] + a[i + 1] < sum){
                sum = a[i] + a[i + 1];
                t1 = i;
            }
        }
        int l = lcm(abs(a[0]), abs(a[2]));
        int i = 0;
        b[i] = a[i+1];
        b[i+1] = a[i];
        if(a[i] * b[i] + a[i+1] * b[i+1] != 0)
            b[i+1] = -1*b[i+1];
        
        int g = __gcd(abs(a[i]),(a[i+1]));
        b[i] /= g;
        b[i+1] /= g;
        deb(b[0]);
        deb(b[1]);
        deb(b[2]);
        if(a[2] < 0){
            b[0] += l/a[2];
            b[2] = -1*l/a[2];
        } 
        b[0] += l/a[2];
        b[2] = l/a[0];
        // if(abs(a[0]) > abs(a[t1])) swap(a[0],a[t1]);
        // if(abs(a[t1]) > abs(a[t1+1])) swap(a[t1],a[t1+1]);
        // x = a[t1];
        // y = a[t1+1];
        // if(x + y != 0){
        //     b[t1] = a[0];
        //     b[t1+1] = a[0];
        //     b[0] = x + y;
        //     int g = __gcd(abs(b[0]),abs(b[t1]));
        //     g = __gcd(g,abs(b[t1+1]));
        //     b[0] /= g;
        //     b[t1] /= g;
        //     b[t1+1] /= g;
        // }
        // else{
        //     int temp = x < 0 ? t1 + 1 : t1;
        //     int t2 = x < 0 ? t1 : t1 + 1;
        //     b[0] = a[temp];
        //     b[temp] = a[0];

        //     int g = __gcd(abs(b[0]),abs(b[temp]));
        //     // g = __gcd(g,abs(b[t1+1]));
        //     b[0] /= g;
        //     b[temp] /= g;
        //     b[temp] += 1;
        //     b[t2] = 1;
        // }
        // // deb(b[0]);
        // // deb(b[t1]);
        // // deb(b[t1+1]);
        // if(a[0]*b[0] ==  a[t1]*b[t1] + a[t1+1]*b[t1+1])
        //     b[0] = -1*b[0];
           
    }
    else{
        for(int i = 0; i < n; i+=2)
        {
            b[i] = a[i+1];
            b[i+1] = a[i];
            if(a[i] * b[i] + a[i+1] * b[i+1] != 0)
                b[i] = -1*b[i];
            
            int g = __gcd(abs(a[i]),(a[i+1]));
            b[i] /= g;
            b[i+1] /= g;
        }
    }
    forp(i,0,n)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
}
void solve2(int in){
    int n;
    cin>>n;
    vector<int> a(n);
    forp(i,0,n)
    {
        cin>>a[i];
    }
    set<int> ans;
    ans.insert(0);
    // vector<vector<vector<int>>> cnt(n , vector<int>(501, vector<int>()));
    vector<int> p[501];
    forp(i,0,n)
    {
        p[a[i]].push_back(i);
    }
    forp(i,0,n){
        set<vector<int>> s;
        s.insert({a[i],a[i],i}); //number, should be greater than, position should be greater than
        forp(j,a[i] + 1,501){
            auto iter = lower_bound(all(p[j]), i);
            if(iter != p[j].end()){
                for(auto x:s){
                    if(j > x[1]){
                        iter = lower_bound(all(p[j]), x[2]);
                        if(iter != p[j].end()){
                            s.insert({j ^ x[0], j, *iter});
                        }
                    }
                }
            }
        }
        for(auto x:s){
            ans.insert(x[0]);
        }
    }
    cout<<ans.size()<<endl;
    for(auto x : ans){
        cout<<x<<" ";
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