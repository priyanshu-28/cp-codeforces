package main
import "fmt"

func main(){
	var tc int;
	fmt.Scanln(&tc);
	TestcaseBegin:
		var n, squareSum int;
		squareSum = 0;
		fmt.Scanln(&n);
		fmt.Println(n);
		InputBegin:
			var a int;
			fmt.Scanln(&a);
			if(a > 0){
				squareSum += a*a;
			}
			fmt.Println(squareSum);
			n--;
			if(n > 0){
				goto InputBegin;
			}
		fmt.Println(squareSum);
		tc--;
	if(tc > 0){
		goto TestcaseBegin;
	}
}