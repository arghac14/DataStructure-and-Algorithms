#include<iostream>

using namespace std; 

#define MAX_size 10     // Maximum size of array or Dequeue

   

// Deque class

class Deque

{
int  array[MAX_size];

int  front;

int  rear;

int  size;

public :

Deque(int size) {

front = -1;

rear = 0;
this->size = size;

    }

   

    // Operations on Deque:

void  insertfront(int key);

void  insertrear(int key);
void  deletefront();

void  deleterear();

int  getFront();
int  getRear();

     

    // Check if Deque is full

bool  isFull(){

return ((front == 0 && rear == size-1)||front == rear+1);   


    }

    // Check if Deque is empty

bool  isEmpty(){

return (front == -1); 

    }

};

   

// Insert an element at front of the deque

void Deque::insertfront(int key)
{

if (isFull())  {

cout << "Overflow!!\n" << endl;

return;
    }

   

if (front == -1)  {

front = 0;

rear = 0;

    }

else if (front == 0)              // front is first position of queue

front = size - 1 ;

else // decrement front 1 position

front = front-1;

   

array[front] = key ;            // insert current element into Deque
}

   

// insert element at the rear end of deque

void Deque ::insertrear(int key)

{

if (isFull()) {

cout << " Overflow!!\n " << endl;

return;

    }

   

    //  If queue is initially empty,set front=rear=0; start of deque

if (front == -1) {

front = 0;

rear = 0;

    }
else if (rear == size-1)               // rear is at last position of queue

rear = 0;

else                            // increment rear by 1 position

rear = rear+1;

   

array[rear] = key ;         // insert current element into Deque

}

   

// Delete element at front of Deque

void Deque ::deletefront()

{

if (isEmpty())

   {

cout << "Queue Underflow!!\n" << endl;

return ;
    }

   

    // Deque has only one element

 if (front == rear)
    {

front = -1;

rear = -1;

    }

else

        // back to initial position

if (front == size -1)

front = 0;

   

else // remove current front value from Deque;increment front by 1

front = front+1;

}

   

// Delete element at rear end of Deque

void Deque::deleterear()

{

if (isEmpty())

    {

cout << " Underflow!!\n" << endl ;

return ;

    }
    // Deque has only one element

if (front == rear)

    {
front = -1;

rear = -1;

    }

else if (rear == 0)

rear = size-1;

else

rear = rear-1;

}

int Deque::getFront()

{

if (isEmpty())   {

cout << " Underflow!!\n" << endl;

return -1 ;

    }

return array[front];

}


int Deque::getRear()

{

if(isEmpty() || rear < 0)  {

cout << " Underflow!!\n" << endl;

return -1 ;

    }

return array[rear];

}


int main()

{

    Deque dq(5);

cout << "Insert element 1 at rear end \n";

dq.insertrear(1);

cout << "insert element 3 at rear end \n";

dq.insertrear(3);

cout << "rear element of deque " << " " << dq.getRear() << endl;

dq.deleterear();

cout << "After deleterear, rear = " << dq.getRear() << endl;

cout << "inserting element 5 at front end \n";
dq.insertfront(5);

cout << "front element of deque " << " "
<< dq.getFront() << endl;

dq.deletefront();

cout << "After deletefront, front = " << dq.getFront() << endl;

return 0;
}
