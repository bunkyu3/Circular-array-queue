#include<stdio.h>
#include<stdlib.h>

struct ArrayQueue{
	int front, rear;
	int capacity;
	int *array;
};

struct ArrayQueue *CreateQueue(int);

int main(void){
	int size = 5;
	struct ArrayQueue *Q;
	Q = CreateQueue(size);
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
