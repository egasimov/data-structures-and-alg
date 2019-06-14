#include <stdio.h>
//Counting Sort

int getMax(int arr[],int n){
	int mx=arr[0];
	for(int i=1; i <n;i++){
		if(arr[i]>mx){
			mx=arr[i];
		}
	}
	return mx;
}

void countSort(int arr[] , int n ){
	int clen=getMax(arr,n)+1;
	int count[clen]={0};
	int output[n];
	for(int i=0;i<n;i++){
		count[arr[i]]++;
	}
	
	//accumulating process , in order to find correct positon
	
	for(int i=1; i < clen ; i++){
		count[i]+=count[i-1];
	}
	
	for(int i=n-1; i>=0;i--){
		output[ count[arr[i]] -1]=arr[i];
		count[arr[i]]--;
	}


	for(int i=0 ; i < n ; i++){
		arr[i]=output[i];
	}
}


int main(){
	int arr[]={1,3,4,7,8,4};
	int size=sizeof(arr)/sizeof(arr[0]);
	countSort(arr,size);
	
	for(int i=0 ; i < size ; i++){
		printf("%d ",arr[i]);
	}
	
}
