#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb push_back
// #define endl "\n"
// #define int long long
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
    int q;
    cin>>q;
    vector<vector<int>> a;
    int cnt = 0;
    forp(i,0,q)
    {
        vector<int> temp;
        int x;
        cin>>x;
        temp.pb(x);
        if(x == 1){
            cnt++;
            cin>>x;
            temp.pb(x);
        }
        else{
            cin>>x;
            temp.pb(x);
            cin>>x;
            temp.pb(x);
        }
        a.pb(temp);
    }
    vector<int> ans(cnt);
    cnt--;
    map<int, int> m;
    for(int i = q - 1; i >= 0;i--){
        if(a[i][0] == 2){
            
            m[a[i][1]] = a[i][2];
            if(m.find(m[a[i][1]]) != m.end() ){
                m[a[i][1]] = m[m[a[i][1]]];
            }
        }
        else{
            if(m.find(a[i][1]) == m.end()){
                ans[cnt] = a[i][1];
                cnt--;
            }
            else{
                ans[cnt] = m[a[i][1]];
                cnt--;
            }
        }
    }
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<endl;
}
void solve2(int in){
    int n,k,x;
    cin>>n>>k>>x;
    string s;
    cin>>s;
    vector<int> v;
    int cur = 0;
    string ans;
    forp(i,0,n){
        if(s[i] == '*'){
            cur += k;
            if(ans.size() == 0 || (ans.size() > 0 && ans.back() != '*')){
                ans.pb('*');
            }
        }
        else if(cur != 0){
            v.pb(cur + 1);
            cur = 0;
            ans += 'a';
        }
        else ans += 'a';
    }
    if(cur!= 0)
        v.pb(cur + 1);

    int pos;
    cur = 1;
    for(int i = v.size() - 1; i>=0;i--){
        int temp = cur*v[i];
        if(temp >= x){
            pos = i;
            break;
        }
        cur = temp;
    }

    int total = x/cur;
    if(x%cur != 0)
        total++;
    string ans2;
    int cnter = 0;
    forp(i,0,ans.size()){
        if(ans[i] == '*'){
            if(cnter == pos){
                forp(j,0,total){
                    ans2 += 'b';
                }
            }
            else if(cnter >= pos){
                forp(j,0,v[cnter]){
                    ans2 += 'b';
                }
            }
            cnter++;
        }
        else{
            ans2.pb(ans[i]);
        }
    }
    cout<<ans2<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    forp(i, 1, t + 1)
    {
        solve(i);
    }
    return 0;
}