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
int QueueSize(struct ArrayQueue *Q);
void PrintQueue(struct ArrayQueue *Q);

int main(void){
	int size = 5;
	struct ArrayQueue *Q;
	Q = CreateQueue(size);
	EnQueue(Q, 1);
	EnQueue(Q, 3);
	EnQueue(Q, 5);
	printf("Queuesize is %d\n", QueueSize(Q));
	PrintQueue(Q);
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

int QueueSize(struct ArrayQueue *Q){
	int queuesize = (Q->rear+1+Q->capacity-Q->front)%Q->capacity;
	if(queuesize==0){
		queuesize = queuesize + Q->capacity;
	}
	return queuesize;
}

void PrintQueue(struct ArrayQueue *Q){
	int i, current = Q->front;
	int queuesize = QueueSize(Q);
	for(i=0; i<queuesize; i++){
		if(current == Q->capacity){
			current = 0;
		}
		printf("%d\n", Q->array[current]);
		current++;
	}
}
