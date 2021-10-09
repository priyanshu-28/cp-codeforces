#include <iostream>
#include <bits/stdc++.h>
#include <set>
#include <stddef.h>
#include <stdlib.h>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <string>
#include <ctype.h>
#include <queue>
// #pragma GCC optimize "trapv"
typedef long long int ll;
using namespace std;

#define f(abcd, n) for (int abcd = 0; abcd < n; abcd++)
#define in(n) cin >> n;
#define print(n) cout << n;
#define out(n) cout << n << "\n";

 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    in(t)
    while(t--){
       
        ll n;
        in(n)
        
        char c;
        in(c)
        
        string s;
        in(s)
        int cnt=0;
        int z=0,f=0;
        f(i,n){
            if(s[i]!=c){
                cnt++;
            }
            else if(s[i]==c && i>=n/2){
                f=1;
                z=i;
            }
        }
        if(cnt==0){
            cout<<0<<"\n";
            continue;
        }
        if(n==1){
            cout<<1<<"\n";
            out(n)
            continue;
        }
        
        if(s[n-1]==c){
            cout<<1<<"\n";
            out(n);
        }
        else if(cnt==1){
            cout<<1<<"\n";
            out(n-1);
        }
        else if(s[n-2]==c){
            cout<<1<<"\n";
            out(n-1);
        }
        else if(f==1){
            cout<<1<<"\n";
            out(z+1);
        }
        else{
            cout<<2<<"\n";
            cout<<(n)<<" "<<(n-1)<<"\n";
        }
        
        
        
    }
    return 0;
}
