#include <iostream>
#include <stdlib.h>

using namespace std;
/* Queue ADT
A list or collection with the restriction that insertion can be performed at one
end (rear) and deletion can be performed at the other end (front)

Operations: All constant time O(1)
(1) EnQueue(x)
(2) DeQueue()
(3) front()
(4) IsEmpty()
*/

/*Array Implementation*/

class Queue {
    public:
        int A[10] = {0,0,0,0,0,0,0,0,0,0};
        int front;
        int rear;
        bool IsEmpty();
        void EnQueue(int x);
        void DeQueue();
        void print();
};

bool Queue::IsEmpty() {
    if(front == -1 && rear == -1) return true;
    else return false;
}

void Queue::EnQueue(int x) {
    if (rear == 9) {
        cout << "Queue is full" << endl;
        return;
    } else if (IsEmpty()) {
        front = rear = 0;
        A[rear] = x;
    } else {
        rear++;
    }
    A[rear] = x;
} 

void Queue::DeQueue() {
    if (IsEmpty()) return; //check if queue is empty
    else if (front == rear) front = rear = -1; //if there is one element
    else {
      A[front] = 0;
      front++;
    }
}

void Queue::print() {
    for(size_t i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
}

int main() {
    Queue q ;
    q.front = -1;
    q.rear = -1;
    cout << q.IsEmpty() << endl;

    q.EnQueue(1);
    q.EnQueue(3);
    q.EnQueue(5);
    q.EnQueue(7);
    q.EnQueue(9);
    q.EnQueue(11);
    q.EnQueue(13);
    q.EnQueue(15);
    q.EnQueue(17);
    q.EnQueue(20);

    q.DeQueue();
    q.print();
    
    cout << endl;
    q.DeQueue();
    q.print();

}