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
    string s;
    cin>>s;
    int last_len = 1;
    int ans = 0;
    int qlen = 0;
    if(s[0] == '?') qlen++;
    vector<int> v;
    int minus =0;
    forp(i,1,s.size()){
        if(s[i] == '0'){
            if(s[i-1] == '1')
                last_len++;
            else if(s[i-1] == '?'){
                if(i - qlen  > 0){
                    if(qlen%2){
                        if(s[i-1-qlen] == '0'){
                            last_len++;
                        }
                        else{
                            ans+= (last_len*(last_len + 1))/2 - (minus*(minus+1))/2;
                            last_len = qlen+1;
                            minus = qlen;
                        }
                    }
                    else{
                        if(s[i-1-qlen] == '1'){
                            last_len++;
                        }
                        else{
                            ans+= (last_len*(last_len + 1))/2 - (minus*(minus+1))/2;
                            last_len = qlen+1;
                            minus = qlen;

                        }
                    }
                }
                else{
                    last_len++;
                }
            }
            else{
                ans+= (last_len*(last_len + 1))/2 - (minus*(minus+1))/2;
                last_len = 1;
                minus = 0;
            }
            qlen = 0;
        }
        else if(s[i] == '1'){
            if(s[i-1] == '0')
                last_len++;
            else if(s[i-1] == '?'){
                if(i - qlen  > 0){
                    if(qlen%2){
                        if(s[i-1-qlen] == '1'){
                            last_len++;
                        }
                        else{
                            ans+= (last_len*(last_len + 1))/2 - (minus*(minus+1))/2;
                            last_len = qlen+1;
                            minus = qlen;
                        }
                    }
                    else{
                        if(s[i-1-qlen] == '0'){
                            last_len++;
                        }
                        else{
                            ans+= (last_len*(last_len + 1))/2 - (minus*(minus+1))/2;
                            last_len = qlen+1;
                            minus = qlen;
                        }
                    }
                }
                else{
                    last_len++;
                }
            }
            else{
                ans+= (last_len*(last_len + 1))/2 - (minus*(minus+1))/2;
                last_len = 1;
                minus = 0;
            }
            qlen = 0;
        }
        else{
            last_len++;
            qlen++;
        }
        //deb(last_len);
        // deb(i);
        // deb(ans);

        // else if(s[i] == '1' && (s[i-1] == '?' || s[i-1] == '0')){
        //     last_len++;
        // }
        // else if(s[i] == '?'){
        //     qlen++;
        //     last_len++;
        // }
        // else{
        //     ans+= (last_len*(last_len + 1))/2;
        //     last_len = 0;
        // }
    }
    ans+= (last_len*(last_len + 1))/2 - (minus*(minus+1))/2;
    cout<<ans<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    forp(i, 1, t + 1)
    {
        solve(i);
    }
    return 0;
}