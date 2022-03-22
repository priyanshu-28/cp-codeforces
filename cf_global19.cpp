#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb push_back
#define endl "\n"
typedef long long ll;
#define int short
#define forp(i, x, t) for (int i = x; i < t; i++)
#define forn(i, x, t) for (int i = x; i > t; i--)
#define deb(x) cout << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7;

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

void solve(vector<int>&arr , int idx , int limit , int total , vector<int>&sums)
    {
        if(idx == limit)
        {
            sums.push_back(total) ; 
            return ; 
        }
        solve(arr , idx+1 , limit , total , sums) ; 
        solve(arr , idx+1 , limit , total + arr[idx] , sums) ;
    }
    
    void search(vector<int>&left , vector<int>&right , int &ans , int target)
    {
        int l = 0 ; 
        int r = right.size()-1 ; 
        while(l < left.size() && r >= 0)
        {
            int ss = left[l] + right[r] ; 
            ans = min(ans , abs(target - ss)) ; 
            if(ss < target) l++ ; 
            else if(ss > target) r-- ; 
            else break ; 
        }
    }
vector<int> pos;
void printknapSack(int W, vector<pair<int, int>> wt, int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
 
    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1].first <= w)
                K[i][w] = max(val[i - 1] +
                    K[i - 1][w - wt[i - 1].first], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
 
    // stores the result of Knapsack
    int res = K[n][W];
    // cout<< res << endl;
     
    w = W;
    for (i = n; i > 0 && res > 0; i--) {
        if (res == K[i - 1][w])
            continue;   
        else {
 
            // This item is included.
            pos.pb(wt[i - 1].second);
             
            // Since this weight is included its
            // value is deducted
            res = res - val[i - 1];
            w = w - wt[i - 1].first;
        }
    }
}
void solver(int in)
{
    pos.clear();
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int sum = 0;
    forp(i,0,n){
        cin>>a[i];
        sum += a[i];
    }
    vector<int> arr(n);
    forp(i,0,n){
        cin>>b[i];
        sum += b[i];
        if(b[i] < a[i]){
            swap(a[i],b[i]);
        }
        arr[i] = b[i] - a[i];
    }
    int ans = INT_MAX ; 
    int asum = 0;
    forp(i,0,n) asum += a[i];
    int target = sum/2 - asum;
    vector<int>left , right ; 
    solve(arr , 0 , n/2+1 , 0 , left) ; 
    solve(arr , n/2+1 , n , 0 , right) ; 
    
    for(int i = 0 ; i<left.size() ; i++)
    {
        ans = min(ans , abs(target - left[i])) ; 
    }
    for(int i = 0 ; i < right.size() ; i++)
    {
        ans = min(ans , abs(target - right[i])) ; 
    }
    
    sort(left.begin() , left.end()) ;
    sort(right.begin() , right.end()) ; 
    search(left , right , ans , target) ; 
    // cout<<ans<<endl;

    int reach = sum/2 - ans - asum;
    int val[n];
    forp(i,0,n) val[i] = 1;
    vector<pair<int, int>> wt(n);
    forp(i,0,n){
        wt[i].first = arr[i];
        wt[i].second = i;
    }
    printknapSack(reach , wt , val , n);
    forp(i,0,pos.size()) swap(a[pos[i]],b[pos[i]]);

    ans = 0;
    forp(i,0,n){
        forp(j,i + 1,n){
            ans += (a[i] + a[j]) * (a[i] + a[j]);
        }
    }
    forp(i,0,n){
        forp(j,i + 1,n){
            ans += (b[i] + b[j]) * (b[i] + b[j]);
        }
    }
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
        solver(i);
    }
    return 0;
}