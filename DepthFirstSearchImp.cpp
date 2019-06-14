#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5
void depthFirstSearch();
int vertexCount=0; //listdeki verticler e access ucun
struct Vertex* listVertices[MAX]; //vertices saxlamaq ucn
int adjMatrix[MAX][MAX]; // qonsuluq relations ucun

struct Vertex{
	char label;
	bool visited;
};

//adding vertex to vertex List
void addVertex(char isim){
	//dinamik vertix yaradilmasi , adlandirilmasi ve liste  add edilmesi
 	struct Vertex* yeni_vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
	yeni_vertex->label =isim;
	yeni_vertex->visited=false;
	listVertices[vertexCount++]=yeni_vertex;
}
// if Vi and Vj are adjecent , corresponding term is 1
void addEdge(int start,int end){
	// iki qonsu vertex arasinda edge yaratmaq
	adjMatrix[start][end]=1;
	adjMatrix[end][start]=1;	
}

//get the adjacent unvisited vertex
int getAdjUnvisitedVertex(int vertexIndex) {
	//verilen 'vertexIndex' e qonsu vertix lerin tapilmasi,eks halda -1;
   for(int i = 0; i < vertexCount; i++) {
      if(adjMatrix[vertexIndex][i] == 1 && listVertices[i]->visited == false) {
         return i;
      }
   }

   return -1;
}

void displayVertex(int vertexIndex) {
	//vertex`in adinin ekrana yazilmasi
   printf("%c ",listVertices[vertexIndex]->label);
} 


//stack variables
int stack[MAX];
int top=-1;
//stack functions
void push(int item){
	stack[++top]=item;
}
int pop(){
	return stack[top--];
}

int peek(){
	return stack[top];
}

bool isStackEmpty(){
	//stack is empty
	return top==-1;
}

int main(){
	for(int i=0 ; i <MAX ; i++){
		for(int j=0 ; j<MAX ;j++){
			adjMatrix[i][j]=0;
		}
	}
	
   addVertex('S');   // 0
   addVertex('A');   // 1
   addVertex('B');   // 2
   addVertex('C');   // 3
   addVertex('D');   // 4
   
   addEdge(0, 1);    // S - A
   addEdge(0, 2);    // S - B
   addEdge(0, 3);    // S - C
   addEdge(1, 4);    // A - D
   addEdge(2, 4);    // B - D
   addEdge(3, 4);    // C - D
   
	depthFirstSearch();	
			
	return 0;
}

void depthFirstSearch(){
	//mark first node as visited
	listVertices[0]->visited=true;
	displayVertex(0);
	//add to stack
	push(0);
	
	while(!isStackEmpty()){
    //get the unvisited vertex of vertex which is at top of the stack 
	int unvisitedVertex = getAdjUnvisitedVertex(peek());
        
     //no adjaceny found
     if(unvisitedVertex==-1){
     	//-1 yeni , qonsu unvisited vertex yoxdur
     	pop();
	 }
	 else
	 {
	 	//unvisited vertex olan hal
	 	listVertices[unvisitedVertex]->visited=true;
	 	push(unvisitedVertex);
	 	displayVertex(unvisitedVertex);
	 }
     
	}
}


