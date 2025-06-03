#include<iostream>
#define maxSize 5
using namespace std;

class Stack
{
 public:
     int top=0,maxsize,size;
     int* stk = new int[size];

    bool isEmpty()
    {
        if(top==0)
        {
            return true;
        }
        else
            return false;
    }
    bool isFull()
    {
        if(top==maxSize)
        {
            return true;
        }
            else
            {
                return false;
        }
    }
    void push(int x)
    {
        if(isFull())
        {

            cout<<"stack is full\n";
        }
        else
        {

        top++;
        cout<<x<<" is pushed into the stack\n";
        }
    }
    void pop()
    {
        if(isEmpty())

        {
            cout<<"Stack is empty\n";
        }
        else
        {

        cout<<stk[top-1]<<"is popped from the stack\n";
        top--;
        }
    }
   void resize()
{
   int * resize = new int[size + 1];
   for(int i = 0; i < size; i++)
        resize[i] = stk[i];

   size++;
   stk = resize;
   delete[] resize;
}

    int getTopElement()
    {
        cout<<"Top element is:"<<stk[top-1]<<endl;
        return stk[top-1];
    }
    void print()
    {
        if(isEmpty())
        {
            cout<<"Nothing to show\n";
            cout<<endl;
        }
        else
        {


        for(int i=top-1;i>=0;i--)

        {
            cout<<stk[i]<<endl;
        }
        }
    }


/*void resize()
{
   int* resize_stk = new int[resize + 1];
   for(int i = 0; i < resize; i++)
    {
        resize_stk[i] = stk[i];
    }
   resize++;
   stk = resize_stk;
   delete[] resize_stk;*/




};
int main()
{
    Stack s;
   s.print();
   s.push(2);
   s.push(6);
   s.push(8);
   s.push(9);
      s.push(1);
       s.push(5);
       s.print();
}
