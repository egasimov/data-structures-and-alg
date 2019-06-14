/*
Queue data yapisinin array implementaion`u .
**Dynamic array kullanildi.(Eger array size if overflow , 
	enlarged it in twice )
**sirabasi , sirasonu degiskenler pointer gibi dusunuler bilir
**cleanArr() , eger array-de bosh yerler siranin evvelinde varsa
		surusdurme baslayacaq(accord to25% condition)

*/


#include <stdio.h>
#include <stdlib.h>
int *array=NULL;
int sirabasi=0;
int sirasonu=0; //( next available )bosh yeri gosterir
int uzunluk=2;
void cleanArr();
void enqueue(int item){
	if(array==NULL){
		array=(int*)malloc(sizeof(int)*uzunluk);
		array[sirasonu++]=item;
		return;
	}
	
	if((sirasonu-sirabasi)>=uzunluk){
		//expanding array
		uzunluk*=2;
		int *new_array=(int*)malloc(sizeof(int)*uzunluk);
		
		for(int i =0 ; i <(sirasonu-sirabasi );i++){
			new_array[i]=array[sirabasi+i];
		}
		
		int *old_arr=array;
		free(old_arr);
		
		array=new_array;
		sirasonu=sirasonu-sirabasi;
		sirabasi=0;

	}
	array[sirasonu++]=item;
}

int dequeue(){
	if(sirabasi==sirasonu){
		printf("THERE IS NO ELEMENT");
		return -1;
	}
	
	return array[sirabasi++];
	
}

void cleanArr(){
	if(sirabasi>=uzunluk/4){
		//surusdurme emeliyyati
		for(int i =0  ; i<(sirasonu-sirabasi);i++){
			array[i]=array[sirabasi+i];
			
		}
		sirasonu-=sirabasi;
		sirabasi=0;
		printf("\nCleaning operated :\n ");
	}
}

int main(){
	for(int i = 1 ; i <11 ; i++ ){
		enqueue(i*10);
	}
	
	for(int i=0 ; i <8 ; i++){
		dequeue();
	}
	int e;
	cleanArr();	
	for(; (e=dequeue())!=-1;){
		printf("element %d \n ",e);
	}
	
	printf("\n\nP R O G R A M  C O M P L E T E D . . .");
	return 0 ;
}
