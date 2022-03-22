#include<bits/stdc++.h>
using namespace std;
    long long BIT[3][100000];
long long query(long long * b, long long idx) {
    long long res = 0;
    while (idx >= 0) {
        res += b[idx];
        idx = (idx&(idx+1))-1;
    }
    return res;
}
void update(long long* b, long long idx, long long val, long long n) {
    while (idx < n) {
        b[idx] += val;
        idx |= idx+1;
    }
}
long long goodTriplets(vector<long long>& a1, vector<long long>& a2) {
    long long n = a1.size();
    vector<long long> comp(n);
    map<long long, long long> m;
    for(long long i = 0; i < a2.size(); i++)
        m[a2[i]] = i;
    for(long long i = 0; i < n;i++){
        comp[i] = m[a1[i]];
    }
    for(long long i = 0; i < n; i++){
        long long x = comp[i];
        update(BIT[1] , x, 1, n);
        cout<<comp[i]<<endl;
        for (long long j = 2; j <= 3; j++) {
            update(BIT[j], x, query(BIT[j-1], x-1), n);
        }
    }
    return query(BIT[3], n);
}
int main(){
    vector<long long> a = {2,0,1,3}, b = {0,1,2,3};
    long long ans = goodTriplets(a, b);
    cout << ans << endl;
    return 0;
}