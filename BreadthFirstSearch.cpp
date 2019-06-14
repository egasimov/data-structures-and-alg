#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5
void breadthFirstSearch();

struct Vertex {
   char label;
   bool visited;
};

struct Vertex* listVertices[MAX];
int vertexCount=0; //list`deki vertixlere access ucun
int adjMatrix[MAX][MAX];

//graph funtions
//adding vertex into list
void addVertex(char isim){
	struct Vertex *yeni_vertex=(struct Vertex*)malloc(sizeof(struct Vertex));
	yeni_vertex->label =isim;
	yeni_vertex->visited =false;
	listVertices[vertexCount++]=yeni_vertex;
}
//add an edge between two vertices
void addEdge(int start, int end){
	adjMatrix[start][end]=1;
	adjMatrix[end][start]=1;
	
}

void displayVertex(int v){
	printf("%c",listVertices[v]->label);
}

int getAdjUnvisitedVertex(int vertexIndex){	
	for(int i=0 ; i<MAX ; i++){
		if(adjMatrix[vertexIndex][i]==1 && listVertices[i]->visited==false){
			return i;
		}
	}
	
	return -1;
}

//queue variables

int queue[MAX];
int rear = -1;
int front = 0;
int queueItemCount = 0;

//queueu functions

void insert(int data) {
   queue[++rear] = data;
   queueItemCount++;
}

int removeData() {
   queueItemCount--;
   return queue[front++]; 
}

bool isQueueEmpty() {
   return queueItemCount == 0;
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
   
	breadthFirstSearch();	
			
	return 0;
}
void breadthFirstSearch(){
	//make first node ad visited
	listVertices[0]->visited=true;
	//insert into queue
	insert(0);
	//display vertex
	displayVertex(0);
	
	int unvisitedVertex ;
	
	while(!isQueueEmpty()){
      //get the unvisited vertex of vertex which is at front of the queue		
		int temp_vertex=removeData();
	//	unvisitedVertex=getAdjUnvisitedVertex(temp_vertex);

		while((unvisitedVertex = getAdjUnvisitedVertex(temp_vertex)) != -1) {
			
			listVertices[unvisitedVertex]->visited=true;
			insert(unvisitedVertex);
			displayVertex(unvisitedVertex);
			//unvisitedVertex=getAdjUnvisitedVertex(temp_vertex);
		}
		
	}
	
	//queue is empty, search is complete, reset the visited flag        
   for(int i = 0;i<vertexCount;i++) {
      listVertices[i]->visited = false;
   } 
}
