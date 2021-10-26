#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a[10],b[10];
    cin >> n >> m;
    unordered_map < int,int > mp,mp2;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        mp[a[i]] = 1;
    }
    for(int i=0;i<m;i++)
    {
        cin >> b[i];
        mp2[b[i]] = 1;
    }
    sort(a,a+n);
    sort(b,b+m);
    for(int i=1;i<=9;i++)
    {
        if(mp[i]==1 && mp2[i]==1)
        {
            cout << i << endl;
            return 0;
        }
    }
    if(a[0]>b[0])
        swap(a[0],b[0]);
    cout << a[0] << b[0] << endl;
}
