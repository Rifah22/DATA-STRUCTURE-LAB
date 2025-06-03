#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node*next;
};
class Stack
{
private:
    Node*top;
public:
    Stack()
    {
    top=NULL;
    }
    void push(int x);
    int pop();
    void print();
};
void Stack::push(int x)
{
 Node*n=new Node;
 if(n==NULL)
  {
  cout<<"Stack is Full\n";
  }
  else
  {
    n->data=x;
    n->next=top;
    top=n;
    cout<< x <<" is pushed "<<endl;
  }
}
int Stack::pop()
{
 int x=-1;
 if(top==NULL)
 {
 cout<<"Stack is Empty\n";
 }
 else
 {
  x=top->data;
  Node*n=top;
  top=top->next;
  delete n;
  }
return x;
}
void Stack::print()
{
 Node*p=top;
 while(p!=NULL)
 {
  cout<<p->data<<" ";
  p=p->next;
 }
 cout<<endl;
}
int main()
{
	Stack s;
    s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	cout<<"Print Push Stack is: "<<endl;
    s.print();
    cout<<s.pop()<<" is popped \n";
    cout<<s.pop()<<" is popped \n";
    cout<<"Print Pop Stack is: "<<endl;
    s.print();
return 0;
 }
