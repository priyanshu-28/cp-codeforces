#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb push_back
#define endl "\n"
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

bool customSortProject(pair<string, pair<vector<int>, vector<pair<string, int>>>> &a, 
                pair<string, pair<vector<int>, vector<pair<string, int>>>> &b
)
{
    return a.second.first[2] > b.second.first[2];
}
bool customSortSkill(pair<string, int> &a, pair<string, int> &b)
{
    return a.second < b.second;
}
void solve(int in)
{
    int total_c, total_p;
    cin>>total_c>>total_p;
    map<string, vector<pair<string, int>>> contri;
    map<string, vector<pair<string, int>>> skills;
    for(int i = 0; i < total_c; i++){
        string s;
        cin>>s;
        int n;
        cin>>n;
        while(n--){
            string skill;
            cin >> skill;
            int x;
            cin>>x;
            contri[s].pb({skill, x});
            skills[skill].pb({s, x});
        }
    }
    for(auto it:skills){
        sort(it.second.begin(), it.second.end(), customSortSkill);
    }
    // map<string, pair<vector<int>, vector<int>>> proj; // map<project_name, {days, score, best before, roles}
    vector<pair<string, pair<vector<int>, vector<pair<string, int>>>>> proj;
    for(int i = 0; i < total_p; i++){
        string p;
        cin>>p;
        int d, s, b, r;
        cin>>d>>s>>b>>r;
        vector<pair<string, int>> temp(r);
        for(int j = 0; j < r; j++){
            cin>>temp[j].first>>temp[j].second;
        }
        proj.pb({p, {{d,s,b,r}, temp}});
    }
    sort(proj.begin(), proj.end(), customSortProject);
    // for(int i = 0; i < proj.size(); i++){
    //     cout<<proj[i].first<<" ";
    //     // for(int j = 0; j < proj[i].second.first[3]; j++){
    //     //     cout<<proj[i].second.second[j]<<" ";
    //     // }
    //     // cout<<endl;
    // }
    for(int i = 0; i < proj.size(); i++){
        string projName = proj[i].first;
        cout<<projName<<endl;
        int req_contri = proj[i].second.second.size();
        auto curRoles = proj[i].second.second;
        sort(curRoles.begin(), curRoles.end(), customSortSkill);
        for(auto role:curRoles){
            string cur_skill = role.first;
            int cur_level = role.second;
            auto skilled = skills[cur_skill];
            // deb(cur_skill);
            for(auto sk:skilled){
                // deb(sk.first)
                if(cur_level <= sk.second){
                    cout<<sk.first<<" ";
                    break;
                }
            }
            // auto it = lower_bound(skilled.begin(), skilled.end(), {"a", cur_level});
            // cout<<(*it).first<<endl;
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