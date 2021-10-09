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

using namespace std;

int power(int x, int y)
{
    int res = 1;
    if (x == 0)
        return 0;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
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
int nCr(int n, int r)
{
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;

            n--;
            r--;
        }
    }

    else
        p = 1;
    return p;
}
bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
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

void solve(int in)
{
    int n;
    cin >> n;
    vector<pair<char,int>> vp;
    vector<int> ans(n);
    stack<int> pos;
    int check = 0,flag = 0,cnter = -1, prevpos = -1, previns;
    forp(i,0,2*n){
        char c;
        cin>>c;
        if(c == '-'){
            check--;
            int x;
            cin>>x;
            vp.push_back({c,x});
            if(pos.size() > 0){
                int temp = pos.top();
                pos.pop();
                if(prevpos == -1){
                    ans[temp] = x;
                    prevpos = temp, previns = x;
                }
                else{
                    if(temp > prevpos || x > previns){
                        ans[temp] = x;
                        prevpos = temp;
                        previns = x;
                    }
                    else flag = 1;
                }
            }
            else flag = 1;
        }
        else{
            vp.push_back({c,-1});
            check++;
            cnter++;
            pos.push(cnter);
        }
        if(check < 0){
            flag = 1;
        }
    }
    if(flag){
        NO;
    }
    else{
        set<int> s;
        int t = 0;
        forp(i,0,2*n){
            if(vp[i].first == '+')
            {
                s.insert(ans[t]);
                t++;
            }
            else{
                if(*s.begin() == vp[i].second){
                    s.erase(s.begin());
                }
                else{
                    NO;
                    return;
                }
                // if(s.find(vp[i].second) == s.end()){
                //     NO;
                //     return;
                // }
                // else{
                //     s.erase(s.find(vp[i].second));
                // }
            }
        }
        YES;
        forp(i,0,n){
            cout<<ans[i]<<" ";
        }
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