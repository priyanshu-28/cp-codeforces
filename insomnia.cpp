#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb push_back
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
    int n;
    cin >> n;
    vector<int> a(n);
    forp(i, 0, n)
    {
        cin >> a[i];
    }
    int bits[31] = {0};
    forp(i,0,n){
        string s = toBinary(a[i]);
        reverse(all(s));
        forp(j,0,s.size()){
            bits[j] += (s[j]-'0');
        }
    }
    int cur = 32;
    forp(i,0,32){
        if(bits[i] == 0){
            cur = i;
            break;
        }
    }
    int flag = 0;
    forp(i,cur, 32){
        if(bits[i] > 0){
            flag = 1;
            break;
        }
    }
    if(flag ==0 ){
        cout<<n<<endl;
        return;
    }
    int left = 0, right = n-1;
    while(left <= right){
        int t = 0;
        forp(i,cur,32){
            t += bits[i];
        }
        if(t == 0) break;
        string s = toBinary(a[left]);
        reverse(all(s));
        int flag = 0;
        forp(i,cur,s.size()){
            if(s[i] == '1'){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            left++;
            forp(i,0,s.size()){
                if(s[i] == '1'){
                    bits[i]--;
                    if(bits[i] == 0){
                        cur = min(cur, i);
                    }
                }
            }
        }
        else{
            s = toBinary(a[right]);
            reverse(all(s));
            flag = 0;
            forp(i,cur + 1,s.size()){
                if(s[i] == '1'){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                right--;
                forp(i,0,s.size()){
                    if(s[i] == '1'){
                        bits[i]--;
                        if(bits[i] == 0){
                            cur = min(cur, i);
                        }
                    }
                }
            }
            else{
                break;
            }
        }
    }
    cout<<right-left+1<<endl;
}
int isgap(int bits[]){
    int pos;
    forp(i,0,32){
        if(bits[i] == 0){
            pos = i;
            break;
        }
    }
    int flag = 0;
    forp(i,pos, 32){
        if(bits[i] > 0){
            return i;
        }
    }
    // deb("HI");
    return -1;
}
void solve2(int in){
    int n;
    cin >> n;
    vector<int> a(n);
    forp(i, 0, n)
    {
        cin >> a[i];
    }
    int prefbits[n][32];
    forp(i,0,n) forp(j,0,32) prefbits[i][j] = 0;
    forp(i,0,n){
        if(i > 0){
            forp(j,0,32) prefbits[i][j] = prefbits[i-1][j];
        }
        string s = toBinary(a[i]);
        reverse(all(s));
        forp(j,0,s.size()){
            prefbits[i][j] += (s[j]-'0');
        }
    }
    int curbits[32] = {0};
    int lastpos[32] = {0};
    int ans = 0;
        // deb(1);
    forp(i,0,n){
        int maxlastpos = -1;
        forp(j,0,32){
            curbits[j] = prefbits[i][j];
        }
        string s = toBinary(a[i]);
        reverse(all(s));
        forp(j,0,s.size()){
            if(s[j] == '1'){
                lastpos[j] = i;
            }
        }
        // deb("EHRE");
        int temp = isgap(curbits);
        while(temp != -1){
            forp(j,0,32){
                maxlastpos = max(maxlastpos, lastpos[temp]);
                curbits[j] -= prefbits[lastpos[temp]][j];
            }
            temp = isgap(curbits);
        }
        ans = max(ans, i - maxlastpos);
    }
    cout<<ans<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    forp(i, 1, t + 1)
    {
        solve2(i);
    }
    return 0;
}