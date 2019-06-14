/*
add to the  tail(end of) of  the queue  ,  remove from head;

*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int item;
	struct node* next;
};

struct node*root=NULL;
struct node*tail=NULL;

int dequeue(){
	if(root==NULL){
		printf(" ( WARNING ) : There is no element");
		return -1;
	}
	
	int return_value=root->item;
	struct node * temp=root;
	
	root=root->next;
	free(temp);
	
	return return_value;
		
}

void enqueue(int item){
	if(root==NULL){
		root=(struct node*)malloc(sizeof(struct node));
		root->item=item;
		
		tail=root;
		tail->next=NULL;
		return;
	}
	
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->item=item;
	temp->next=NULL;
	
	tail->next=temp; 
	tail=temp;
		
}

int main(){
	//list is empty
	for(int i=10 ; i<15 ;i++){
		enqueue(i);
	}
	// list : 10 11 12 13 14
	
	for(int i=0 ; i <3;i++){
	dequeue();
	}
	//list 13 14
	
	int e;
	for(; (e=dequeue())!=-1;){
		printf("\n ELEMENT : %d \n",e);
	}
	printf("\n P R O G R A M  C O M P L E T E D");
}
