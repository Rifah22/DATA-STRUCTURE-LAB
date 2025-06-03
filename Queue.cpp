#include<iostream>
#define maxsize 5
using namespace std;
class Queue
{
private:
int queue[maxsize];
int front,rear;
public:
Queue()
{
front = rear = -1;
}
bool isEmpty()
 {
 if ((front==-1) and (rear==-1))
 {
 return true;
 }
 else
    return false;
}

bool isFull(){
 if (front == 0 && rear==(maxsize-1))
    {
   return true;
    }
 else
  return false;
}
void enQueue(int e)
{
if(isFull())
 {
  cout << endl<< "Queue is full!!";
 }
else
 {
if(front == -1) front = 0;
rear++;
queue[rear] = e;
cout << e << " ";
 }
}
int deQueue()
{
int d;
if(isEmpty())
 {
cout << "Queue is empty!!" << endl;
return(-1);
 }
else
{
d= queue[front];
 if(front >= rear)
 {
 front = -1;
 rear = -1;
 }
else {
front++;
            }
cout << endl << "Deleted => " << d << " from queue";
return(d);
        }
    }
void showQueue()
{
int i;
if(isEmpty())
 {
cout << endl << "Queue is Empty!!" << endl;
 }
else
 {
cout << endl << "Front = " << front;
cout << endl << "Queue elements : ";
 for(i=front; i<=rear; i++)
 {
 cout << queue[i] << "\t";
 cout << endl << "Rear = " << rear << endl;
 }
 }
 }
};
int main()
{
Queue q;
q.deQueue();
cout<<"Queue created:"<<endl;
q.enQueue(10);
q.enQueue(20);
q.enQueue(30);
q.enQueue(40);
q.enQueue(50);
q.enQueue(60);
q.showQueue();
q.deQueue();
q.showQueue();

return 0;
}

