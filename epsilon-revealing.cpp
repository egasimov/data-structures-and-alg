#include <iostream>
#include <conio.h>
using namespace std;

int main(){
	float epsilon=1;
	
	while(1){
		if(1+epsilon<=1){
			break;
		}
		epsilon=epsilon/2;
	}
	cout<<epsilon*2<<endl;
	getch();
}
