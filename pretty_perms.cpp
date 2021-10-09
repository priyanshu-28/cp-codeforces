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

void solve(int in)
{
    int n;
    cin >> n;
    vector<int> a(n);
    forp(i,0,n){
        cin>>a[i];
    }
    sort(all(a));
    if(n < 3) cout<<0<<endl;
    else{
        int temp = 0;
        int ans = 0;
        forp(i,2,n) {
            temp+=a[i-2];
            ans+=temp;
            ans-=a[i]*(i-1);
        }
        cout<<ans<<endl;
    }
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