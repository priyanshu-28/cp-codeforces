#include <bits/stdc++.h>
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define endl "\n"
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
int tab[101][100001];
 
// Check if possible subset with
// given sum is possible or not
int subsetSum(vector<int> a, int n, int sum)
{
     
    // If the sum is zero it means
    // we got our expected sum
    if (sum == 0)
        return 1;
         
    if (n <= 0)
        return 0;
    if (tab[n - 1][sum] != -1)
        return tab[n - 1][sum];
    if (a[n - 1] > sum)
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum);
    else
    {
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum) ||
                       subsetSum(a, n - 1, sum - a[n - 1]);
    }
}
 
void solve(int in)
{
    memset(tab, -1, sizeof(tab));
    int n;
    cin>>n;
    vector<int> a(n);
    int mini = INT_MAX;
    int minpos = 0;
    int sum = 0;
    forp(i,0,n){
        cin>>a[i];
        sum += a[i];
        if(mini > a[i]){
            mini = a[i];
            minpos = i;
        }
    }
    if(sum%2 == 0 && subsetSum(a, n, sum/2)){
        cout<<1<<endl;
        forp(i,0,n){
            if(a[i]%2 == 1){
                cout<<i+1<<endl;    
                return;
            }
        }
        vector<int> cur = a;
        forp(i,0,n){
            cur.erase(cur.begin() + i);
            if(!subsetSum(cur,n-1,(sum - a[i])/2)){
                cout<<i+1<<endl;
                return;
            }
            cur.insert(cur.begin() + i, a[i]);
        }
    }
    else{
        cout<<0<<endl;
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