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


vector<int> si;
int primeFactors(int n)
{
    int ans = 0;
    for (int i = 0; i < si.size();i++)
    {
        // While i divides n, print i and divide n
        while (n % si[i] == 0)
        {
            ans++;            
            n = n/si[i];
        }
    }

    if (n > 2)
    ans++;
    return ans;
}
void SieveOfEratosthenes(int n)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            si.push_back(p);
}
void solve(int in)
{
    int a,b,k;
    cin>>a>>b>>k;
    // if(a==b){

    //     YES;
    //     return;
    // }
    int g = __gcd(a,b);
    // deb(g);
    // if(a == g || b == g){
    //     YES;
    //     return;
    // }
    int n1 = primeFactors(a/g);
    int n2 = primeFactors(b/g);
    int pf = primeFactors(g);
    // deb(n1);
    // deb(n2);
    if(k == 1){
        if((a == g || b == g) && a!=b){
            YES;
        }
        else NO;
    }
    else{
        if(k%2 == 0){
            int hand = min(k-2, 2*pf);
            int pl = 2*pf - hand;
            if(a == b && b == g) hand = min(k,2*pf);
            int rem = k - hand;
            if(n1 + n2 + pl>= rem){
                YES;
            }
            else NO;
        }
        else{
            int hand = min(k-3, 2*pf);
            int pl = 2*pf - hand;
            // if(a == b && b == g) hand = min(k-1,2*pf);
            int rem = k - hand;
            if(n1 + n2 + pl >= rem){
                YES;
            }
            else NO;
        }
        // if(k<=n1+n2 + pf){
        //     YES;
        // }
        // else NO;
    }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    SieveOfEratosthenes(31623);
    cin >> t;
    forp(i, 1, t + 1)
    {
        solve(i);
    }
    return 0;
}