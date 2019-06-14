/*
add to the  head of queue  ,  remove from tail;

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
		printf("There is no element");
		return -1;
	}
	if(root->next==NULL){
		int val=root->item;
		free(root);
		root=tail=NULL;
		return val;
	}
	
	struct node* prev_tail=root;
	
	while(prev_tail->next!=NULL){
		if(prev_tail->next->next==NULL){
		break;
		}
		prev_tail=prev_tail->next;
	}

//
//	while(prev_tail->next!=tail){
//		prev_tail=prev_tail->next;
//	}
	
			
	int value=tail->item;
	struct node* p=tail;
	tail=prev_tail;
	free(p);
	
	tail->next=NULL;
	return value;
}

void enqueue(int item){
	if(root==NULL){
		root=(struct node*)malloc(sizeof(struct node));
		root->item=item;
		root->next=NULL;
		
		tail=root;
		return;
	}	
	
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->item=item;
	
	temp->next=root;
	root=temp;
	
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
