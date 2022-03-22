#include<iostream>
using namespace std;
 
int main() {
	long int a,b,x;
	cin >> a >> b;
	x=a*b;
	for(long int i=1;i<=x;i++){
		if(x%i==0 && i%a==0 && i%b==0){
			cout << i;
			break;
		}
	}
	return 0;
}