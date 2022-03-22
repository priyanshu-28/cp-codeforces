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
    int n, k;
    cin>>n >> k;
    vector<int> a(n);
    forp(i,0,n)
    {
        cin>>a[i];
    }
    sort(all(a));
    int ans = 0;
    forp(i,0, n - 2*k) ans += a[i];
    if(k == 0){
        cout<<ans<<endl;
        return;
    }
    map<int,int> m;
    forp(i, n - 2*k, n)
    {
        m[a[i]] ++;
    }
    // deb("HI");
    // deb(ans);
    vector<pair<int,int>> vv;
        for(auto x : m)
        {
            vv.push_back(make_pair(x.first, x.second));
        }
        sort(all(vv), sortbysec);
    while(1){
        // deb("HI");
        // forp(i,0,vv.size()){
        //     deb(vv[i].first);
        //     deb(vv[i].second);
        // }
        sort(all(vv), sortbysec);
        int temp = vv.size();
        if(temp == 1 || (temp!= 1 && vv[temp - 2].second == 0)){
            ans += vv[temp - 1].second / 2;
            break;
        }
        vv[temp - 1].second--;
        vv[temp - 2].second--;
    }
    cout<<ans<<endl;
}
bool is_substring(string s1, string s2)
{
    return (s2.find(s1) != string::npos);
}
void solve2(int in){
    int n, k;
    cin>>n>>k;
    string x = toBinary(n);
    string y = toBinary(k);
    // deb(x);
    // deb(y);
    // if(x.size() > y.size()){
    //     NO; 
    //     return;// cout<<"0"<<endl;
    //     // return;
    // }
    int pos = 0;
    bool temp = is_substring(x,y);
    if(temp){
        forp(i,0,y.size() - x.size() + 1){
            if(y.substr(i, x.size()) == x){
                pos = i;
                break;
            }
        }
        int ans = 0;
        if(x.back() == '0' && pos > 0){
            ans++;
        }
        if(ans == 1 && pos + x.size() < y.size() && y[pos + x.size()] == '1') ans--;
        forp(i,0,pos){
            if(y[i] == '0') ans++;
        }
        forp(i,pos + x.size(), y.size()){
            if(y[i] == '0') ans++;
        }
        if(ans == 0){
            YES;
            return;
        }
    }
    reverse(all(y));
    temp = is_substring(x,y);
    if(temp && y[0] == '1'){
        forp(i,0,y.size() - x.size() + 1){
            if(y.substr(i, x.size()) == x){
                pos = i;
                break;
            }
        }
        int ans = 0;
        if(x.back() == '0' && pos > 0 ){
            ans++;
        }
        if(ans == 1 && pos + x.size() < y.size() && y[pos + x.size()] == '1') ans--;

        forp(i,0,pos){
            if(y[i] == '0') ans++;
        }
        forp(i,pos + x.size(), y.size()){
            if(y[i] == '0') ans++;
        }
        if(ans == 0){
            YES;
            return;
        }
    }
    // else {
    reverse(all(x));
    string tt;
    forp(i,0,x.size()){
        if(x[i] == '1'){
            pos = i;
            break;
        }
    }
    tt = x.substr(pos, x.size() - pos);
    x = tt;
    temp = is_substring(x,y);
    if(temp && y[0] == '1'){
        forp(i,0,y.size() - x.size() + 1){
            if(y.substr(i, x.size()) == x){
                pos = i;
                break;
            }
        }
        int ans = 0;
        
        forp(i,0,pos){
            if(y[i] == '0') ans++;
        }
        forp(i,pos + x.size(), y.size()){
            if(y[i] == '0') ans++;
        }
        if(ans == 0){
            YES;
            return;
        }
    }
    reverse(all(y));
    temp = is_substring(x,y);
    if(temp){
        forp(i,0,y.size() - x.size() + 1){
            if(y.substr(i, x.size()) == x){
                pos = i;
                break;
            }
        }
        
        int ans = 0;
        
        forp(i,0,pos){
            if(y[i] == '0') ans++;
        }
        forp(i,pos + x.size(), y.size()){
            if(y[i] == '0') ans++;
        }
        if(ans == 0){
            YES;
            return;
        }
        else NO;
    }
    else NO;
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