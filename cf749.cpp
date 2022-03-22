#include <bits/stdc++.h>
#define YES cout << "YES\n"
#define NO cout << "NO\n"
// #define endl "\n"
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
void solve2(int in){
    int n;
    cin>>n;
    vector<int> ans(n+1,0);
    int t = n+1;
    if(n%2) t++;
    //check if last number is 1
    cout<<"? ";
    forp(j,0,n-1) cout<<1<<" ";
    cout<<n<<endl;
    int temp;
    cin>>temp;
    if(temp != 0){
        ans[n] = 1;
        // if(temp!= 0){
        //     ans[n] = n;
        // }
        // else{
        //     ans[n] = 1;
        // }
    }
    else{
        //find last number
        forp(i,2,n){
            cout<<"? ";
            forp(j,0,n-1) cout<<1<<" ";
            cout<<n + 1 - i<<endl;
            cin>>temp;
            if(temp != 0){
                ans[n] = i;
                // ans[temp] = 1;
                break;
            }
        }
        if(ans[n] == 0) ans[n] = n;
    }
    // deb(ans[n]);
    //find all other numbers
    for(int i = 1; i<n+1;i++){
        if(i == ans[n]) continue;
        cout<<"? ";
        forp(j,0,n-1) cout<<n + 1 - i<<" ";
        cout<<n + 1 - ans[n]<<endl;
        cin>>temp;
        ans[temp] = i;
    }
    cout<<"! ";
    for(int i = 1; i<n+1;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    // for(int i = 1;i<=n;i+=2){
    //     cout<<"? ";
    //     int partner = i + 1;
    //     if(partner == n+1) partner = 1;
    //     forp(j,0,n-1) cout<<t - partner<<" ";
    //     cout<<t - i<<endl;
    //     int temp;
    //     cin>>temp;
    //     if(temp != 0){
    //         // last index is either i or partner
    //         cout<<"? ";
    //         forp(j,0,n-1) cout<<t - i<<" ";
    //         cout<<t - partner<<endl;
    //         cin>>temp;
    //         if(temp == 0){
    //             ans[n] = i;
    //         }
    //         else{
    //             ans[n] = partner;
    //         }
    //         break;
    //     }
    // }
    // int cnt = 0;
    // while(cnt < n){

    // }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    forp(i, 1, t + 1)
    {
        solve2(i);
    }
    return 0;
}