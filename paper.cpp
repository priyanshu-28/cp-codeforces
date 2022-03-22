#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,cnt=0;
    cin >> a >> b;
    if(b==1)
    {
        cout << a << endl;
        return 0;
    }
    while(a>0 && b>0)
    {
        if(a>b)
            cnt += a/b , a = a%b;
        else
            cnt += b/a , b = b%a;
    }
    cout << cnt << endl;
