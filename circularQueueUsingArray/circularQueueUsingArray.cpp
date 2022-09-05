// circularQueueUsingArray.cpp 
//front and rear moving circularly for deletion and insertion till rear reach the loaction prior to the front


#include <iostream>

using namespace std;

struct queue
{
    int size;
    int front;
    int rear;
    int* arr;
};

void createQueue(struct queue* , int);
bool IsEmpty(struct queue* );
bool IsFull(struct queue* );
void enqueue(struct queue* , int );
void display(struct queue* );
void dequeue(struct queue*);




void dequeue(struct queue* q)
{
    if (IsEmpty(q))
    {
        cout << "Queue is empty ...deletion not possible ." << endl;
        return;
    }

    q->front = (q->front + 1) % q->size;
    cout << "The value -> " << q->arr[q->front] << " deleted from the queue .." << endl;

}


void display(struct queue* q)
{
    if (IsEmpty(q))
    {
        cout << "Queue is empty ." << endl;
        return;
    }

    int i = q->front;
    while (i != q->rear)
    {
        cout << q->arr[(++i) % q->size]<<" ";
    }
    cout << endl;

}


void enqueue(struct queue* q, int x)
{
    if (IsFull(q))
    {
        cout << "Queue is full ..Insertion of value -> "<<x<<" is not possible. " << endl;
        return;
    }

    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = x;
    cout << "the value -> " << x << " inserted into the queue . " << endl;

}


bool IsEmpty(struct queue* q)
{
    return (q->rear==q->front) ? 1 : 0;
}


bool IsFull(struct queue *q)
{
    return ((q->rear+1)%q->size==q->front) ? 1 : 0;

}


//Basic empty queue of expected size is created
void createQueue(struct queue* q,int qsize)
{
    q->size = qsize;
    q->front = q->rear = 0;
    q->arr = new int[q->size];
}



int main()
{

    struct queue q;
    createQueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    enqueue(&q, 70);
    enqueue(&q, 80);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q, 50);
    enqueue(&q, 60);
    enqueue(&q, 70);
    enqueue(&q, 80);

    //circular queue overcomes all the problems faced when reusing the array 
    //when choosing the array for queue implementation ...the circualr queue is the best choice.
}
