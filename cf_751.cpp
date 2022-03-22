#include <bits/stdc++.h>
#define YES cout << "YES\n"
#define NO cout << "NO\n"
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
bool comp(vector<int> a, vector<int> b)
{
    forp(i,0,a.size()){
        if(a[i]!=b[i])
        return false;
    }
    return true;
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
    forp(i,0,n)
    {
        cin>>b[i];
    }
    // vector<int> as[n];
    // forp(i,0,n){
    //     int after_slip = i + b[i];
    //     if(after_slip>=n-1)
    //     {
    //         after_slip = n-1;
    //     }
    //     as[after_slip].push_back(i);
    // }
    // vector<int> dp[n];
    queue<pair<int, vector<int>>> q;
    q.push({n-1, {}});
    vector<int> vis(n,0);
    vector<int> answer;
    vis[n-1] = 1;
    int ans = -1;
    int depth = 1;
    set<int> s;
    forp(i,0,n-1){
        s.insert(i);
    }
    while(!q.empty())
    {   
        int cur = q.front().first;
        if(cur - a[cur] < 0){
            ans = q.front().second.size() + 1; 
            answer = q.front().second;
            answer.push_back(0);
            break;
        }
        auto low = lower_bound(all(s), cur - a[cur]);
        auto up = lower_bound(all(s), cur);
        // deb(*low);
        // deb(*up);
        vector<int> tt;
        while(low!=up && low != s.end()){
            auto temp = q.front().second;
            temp.push_back(*low + 1);
            if(vis[*low + b[*low]] == 0){
                q.push({min(n-1, *low + b[*low]), temp});
                vis[*low + b[*low]] = 1;
            }
            tt.push_back(*low);   
            low++;         
            // low = lower_bound(all(s), cur - a[cur]);
        }
        forp(i,0,tt.size()){
            s.erase(tt[i]);
        }
        // forp(i,cur-a[cur], cur){
        //     if(vis[i] == 0){

        //     }
        //     int pos = i + b[i];
        //     pos = min(pos, n-1);
        //     if(vis[pos]==0){
        //         auto temp = q.front().second;
        //         temp.push_back(i + 1);
        //         q.push({pos, temp});
        //         vis[pos] = 1;
        //     }
        // }
        q.pop();
    }
    cout<<ans<<endl;
    if(ans != -1){
        forp(i,0,ans){
            cout<<answer[i]<<" ";
        }
        cout<<endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    forp(i, 1, t + 1)
    {
        solve(i);
    }
    return 0;
}