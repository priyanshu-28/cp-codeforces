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
#define  deb(x) cout << #x << " = " << x << endl
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
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool isPalindrome(string s){
    string t = s;
    reverse(all(t));
    return s == t;
}
bool checkPal(string s){
    if(s.size() < 5) return true;
    forp(i,0,s.size()){
        string cur;
        cur += s[i];
        forp(j,i+1,s.size()){
            cur += s[j];
            if(cur.size() > 4 && isPalindrome(cur)) return false;
            if(cur.size() >= 7) break;
        }
    }
    return true;
}
bool smallSolve(int n, string s)
{
    queue<string> q;
    q.push(s);
    vector<string> check;
    while(q.size()){
        auto top = q.front();
        q.pop();
        int flag = 0;
        forp(i,0,top.size()){
            if(top[i] == '?'){
                flag = 1;
                q.push(top.substr(0,i)+"0"+top.substr(i+1));
                q.push(top.substr(0,i)+"1"+top.substr(i+1));
                break;
            }
        }
        if(flag == 0){
            check.push_back(top);
        }
    }
    forp(i,0,check.size()){
        if(checkPal(check[i])){ // is there a palindrome substring having len 5 or 6
            return true;
        }
    }
    return false;
}
string t1 = "110010", t2= "001101",st1, st2;
void solver(int in){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string matcher;
    if(n <= 15){
        if(smallSolve(n, s)){
            cout<<"Case #"<<in<<": "<<"POSSIBLE"<<endl;
        }
        else{
            cout<<"Case #"<<in<<": "<<"IMPOSSIBLE"<<endl;
        }
        return;
    }
    forp(i,5,n-5){
        matcher += s[i];
    }
    forp(i,0,6){
        int matches = true;
        forp(j,0,matcher.size()){
            if(matcher[j] == '?' || matcher[j] == st1[j + i]){
                continue;
            }
            else{
                matches = false;
                break;
            }
        }
        if(matches){
            string first;
            forp(k,0,6) first += st1[k + i];
            string second;
            forp(k,0,6) 
                if(i + matcher.size() - k - 1 >= 0) 
                    second =  st1[i + matcher.size() - k - 1] + second;
            if(smallSolve(11, s.substr(0,5) + first) && smallSolve(11, second + s.substr(n-5,5))){
                cout<<"Case #"<<in<<": "<<"POSSIBLE"<<endl;
                return;
            }
        }
    }
    forp(i,0,6){
        int matches = true;
        forp(j,0,matcher.size()){
            if(matcher[j] == '?' || matcher[j] == st2[j + i]){
                continue;
            }
            else{
                matches = false;
                break;
            }
        }
        if(matches){
            string first;
            forp(k,0,6) first += st2[k + i];
            string second;
            forp(k,0,6) if(i + matcher.size() - k - 1 >= 0) second =  st2[i + matcher.size() - k - 1] + second;
            // deb(i);
            // deb(s.substr(0,5) + first);
                // deb(second + s.substr(n-5,5));
            if(smallSolve(11, s.substr(0,5) + first) && smallSolve(11, second + s.substr(n-5,5))){
                // deb(i);
                // deb(matcher);
                cout<<"Case #"<<in<<": "<<"POSSIBLE"<<endl;
                return;
            }
        }
    }
    cout<<"Case #"<<in<<": "<<"IMPOSSIBLE"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(st1.size() < 50010) st1 += t1;
    while(st2.size() < 50010) st2 += t2;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    forp(i, 1, t + 1)
    {
        solver(i);
    }
    return 0;
}