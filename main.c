#include<stdio.h>
#include<stdlib.h>

struct ArrayQueue{
	int front, rear;
	int capacity;
	int *array;
};

struct ArrayQueue *CreateQueue(int data);
void EnQueue(struct ArrayQueue *Q, int data);
int DeQueue(struct ArrayQueue *Q);
int IsFullQueue(struct ArrayQueue *Q);
int IsEmptyQueue(struct ArrayQueue *Q);
int QueueSize(struct ArrayQueue *Q);
void PrintQueue(struct ArrayQueue *Q);

int main(void){
	int size = 5;
	struct ArrayQueue *Q;
	Q = CreateQueue(size);
	EnQueue(Q, 1);
	EnQueue(Q, 3);
	EnQueue(Q, 5);
	EnQueue(Q, 7);
	EnQueue(Q, 9);
	DeQueue(Q);
	DeQueue(Q);
	DeQueue(Q);
	EnQueue(Q, 11);
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

int DeQueue(struct ArrayQueue *Q){
	int data;
	if(IsEmptyQueue(Q)){
		printf("Queue is Empty\n");
		return 0;
	}else{
		data = Q->array[Q->front];
		if(Q->front == Q->rear){
			Q->front = Q->rear = -1;
		}else{
			Q->front = (Q->front+1)%Q->capacity;
			return data;
		}
	}
}

int IsFullQueue(struct ArrayQueue *Q){
	return ((Q->rear+1)%Q->capacity == Q->front); 
}

int IsEmptyQueue(struct ArrayQueue *Q){
	return (Q->front==-1); 
}

int QueueSize(struct ArrayQueue *Q){
	int queuesize;
	if(Q->front==-1){
		queuesize = 0;
	}else{
		queuesize = (Q->rear+1+Q->capacity-Q->front)%Q->capacity;
		if(queuesize==0){
			queuesize = queuesize + Q->capacity;
		}
	}
	return queuesize;
}

void PrintQueue(struct ArrayQueue *Q){
	int i, current = Q->front;
	int queuesize = QueueSize(Q);
	if(queuesize == 0){
		printf("Queue is Empty\n");
	}else{
		for(i=0; i<queuesize; i++){
			if(current == Q->capacity){
				current = 0;
			}
			printf("%d\n", Q->array[current]);
			current++;
		}
	}
}
