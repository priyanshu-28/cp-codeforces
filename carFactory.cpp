#include<iostream>
#include<cmath>
using namespace std;
 
int main() {
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		long long int a,b;
		cin >> a >> b;
		cout << b+(a-1) <<"\n";
	}
	return 0;
}