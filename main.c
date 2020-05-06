#include<stdio.h>
#include<stdlib.h>

struct ArrayQueue{
	int front, rear;
	int capacity;
	int *array;
};

struct ArrayQueue *CreateQueue(int data);
void EnQueue(struct ArrayQueue *Q, int data);
int IsFullQueue(struct ArrayQueue *Q);

int main(void){
	int size = 5;
	struct ArrayQueue *Q;
	Q = CreateQueue(size);
	EnQueue(Q, 1);
	EnQueue(Q, 3);
	EnQueue(Q, 5);
	EnQueue(Q, 7);
	EnQueue(Q, 9);
	printf("%d\n", IsFullQueue(Q));
	return 0;
}

struct ArrayQueue *CreateQueue(int size){
	struct ArrayQueue *Q = malloc(sizeof(struct ArrayQueue));
	if(!Q){
		return NULL;
	}
	Q->front = -1;
	Q->rear = -1;
	Q->capacity = size;
	Q->array = malloc(sizeof(int) * size);
	if(!Q->array){
		return NULL;
	}
	return Q;
};

void EnQueue(struct ArrayQueue *Q, int data){
	if(IsFullQueue(Q)){
		printf("Queue Overflow\n");
	}else{
		Q->rear = (Q->rear+1)%Q->capacity;
		Q->array[Q->rear] = data;
		if(Q->front==-1){
			Q->front = Q->rear;
		}
	}
}

int IsFullQueue(struct ArrayQueue *Q){
	return ((Q->rear+1)%Q->capacity == Q->front); 
}
