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
// int fact[N], invfact[N];
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
 
// void precompute()
// {
// 	fact[0]=fact[1]=1;
// 	for(int i=2;i<N;i++)
// 	{
// 		fact[i]=fact[i-1]*i;
// 		fact[i]%=mod;
// 	}
// 	invfact[N-1]=modinv(fact[N-1]);
// 	for(int i=N-2;i>=0;i--)
// 	{
// 		invfact[i]=invfact[i+1]*(i+1);
// 		invfact[i]%=mod;
// 	}
// }
 
// int nCr(int x, int y)
// {
// 	if(y>x)
// 		return 0;
// 	int num=fact[x];
// 	num*=invfact[y];
// 	num%=mod;
// 	num*=invfact[x-y];
// 	num%=mod;
// 	return num;
// }
 
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
set<pair<int, int>> glo;
void printSubsequences(int arr[], int index,
                       vector<int> subarr,int n)
{
    // Print the subsequence when reach
    // the leaf of recursion tree
    if (index == n)
    {
        int cur = 0, sum = 0;
         for (auto it:subarr){
             sum += it;
             cur++;
         }
       
        glo.insert(make_pair(cur, sum));
      return;
 
         
    }
    else
    {
       //pick the current index into the subsequence.
        subarr.push_back(arr[index]);
       
 
         printSubsequences(arr, index + 1, subarr,n);
 
         
        subarr.pop_back();
       
      //not picking the element into the subsequence.
        printSubsequences(arr, index + 1, subarr,n);
    }
    
}
 
vector<int> fact(15);
void solve(int in)
{
    int n;
    cin >> n;
    int ans = INT_MAX;
    for(auto it: glo){
        string s = toBinary( n- it.second);
        int f = 0;
        forp(i,0,s.size()) f += s[i] - '0';
        ans = min(ans, f + it.first);
    }
    cout<<ans<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[3] = 6;
    forp(i,4,15){
        fact[i] = fact[i-1]*i;
    }
    int arr[12];
    forp(i,3,15){
        arr[i-3] = fact[i];
    }
    vector<int> vec;
      
    printSubsequences(arr, 0, vec, 12);
    int t = 1;
    cin >> t;
    forp(i, 1, t + 1)
    {
        solve(i);
    }
    return 0;
}