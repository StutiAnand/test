//queue implemented using ll
#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* next;
};

typedef struct 
{
    struct node* front;
    struct node* rear;
} QUEUE;

int insert(QUEUE* q, int val) 
{
    struct node* curr;
    curr = (struct node*)malloc(sizeof(struct node));
    if (curr == NULL) 
    {
        return 1;
    }
    curr->data = val;
    curr->next = NULL;
    if (q->front == NULL) 
    {
        q->front = q->rear = curr;
    } 
    else 
    {
        q->rear->next = curr;
        q->rear = curr;
    }
    return 0;
}

int delete (QUEUE* q, int* del) 
{
    if (q->front == NULL) 
    {
        return 1;
    }
    *del = q->front->data;
    if (q->front == q->rear) 
    {
        free(q->front);
        q->front = q->rear = NULL;
    } 
    else 
    {
        struct node* prev = q->front;
        q->front = q->front->next;
        free(prev);
    }
    return 0;
}

int main() 
{
    QUEUE q;
    q.front = q.rear = NULL;
    int val = rand() % 10;
    if (insert(&q, val) != 0) 
    {
        printf("QUEUE Overflow\n");
    } 
    else 
    {
        printf("%d inserted successfully\n", val);
    }

    int del;
    if (delete (&q, &del) != 0) 
    {
        printf("QUEUE Underflow\n");
    } 
    else 
    {
        printf("%d deleted successfully\n", del);
    }
    return 0;
}