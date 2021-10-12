#include<iostream>
#include<cstring>
using namespace std;
 
int main() {
	char a[1000];
	cin >> a;
	int c=0;
	for(int i=0;i<strlen(a);i++){
		if(a[i]>=65 && a[i]<=90)
			c++;
	}
	if(c>strlen(a)-c){
		for(int i=0;i<strlen(a);i++){
			if(a[i]>=97 && a[i]<=122)
				a[i]=a[i]-32;
		}
	}else{
		for(int i=0;i<strlen(a);i++){
			if(a[i]>=65 && a[i]<=90)
				a[i]=a[i]+32;
		}
	}
	cout << a;
	return 0;
}