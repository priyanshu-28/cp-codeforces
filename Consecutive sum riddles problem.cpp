#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    long long input_array[t];
    for(int i=0; i<t; i++)
    {
        cin>>input_array[i];
    }

    for(int j=0; j<t; j++)
    {
        cout<<-1*(input_array[j]-1)<<" "<<input_array[j]<<"\n";
    }
}

/* 
1 = 0 1
2 = -1 0 1 2
3 = -2 -1 0 1 2 3
4 = -3 -2 -1 0 1 2 3 4
.
.
.
.
n = -(n-1) -(n-2) ... 0 1 2 ... (n-1) n   (Everything cancels out leaving n)
*/
