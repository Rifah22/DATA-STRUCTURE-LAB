#include <iostream>
using namespace std;
class Node
{
public:
      int data;
      Node*next;
};
Node*swap(Node*p1,Node*p2)
{
    Node*x=p2->next;
    p2->next=p1;
    p1->next=x;
}
int bubblesort(Node**head,int data)
{
 Node**h;
 int i,j,soa;
 for (i=0;i<data;i++)
 {
  h=head;
  data=0;
   for (j=0;j<data-i-1;j++)
    {
     Node*p1=*h;
     Node*p2=p1->next;
    if (p1->data>p2->data)
    {
     *h=swap(p1,p2);
    }
    h=&(*h)->next;
    }
 }
}
void insertfirst(Node**first,int data)
{
    Node*d1=new Node;
    d1->data=data;
    d1->next=*first;
    *first=d1;
}
void print(Node*n,int size)
{
 while(n!=NULL)
  {

   cout<<n->data<<"  ";
   n=n->next;
  }
}
int main()
{
 int arr[]={65,-3,0,98,37,5};
 int size,i;
 Node*head=NULL;
 size=sizeof(arr)/sizeof(arr[10]);
 for (i=0;i<size;i++)
 insertfirst(&head,arr[i]);
 bubblesort(&head,size);
 cout <<"Sorting Linked List : "<<endl;
 print(head,size);
 return 0;
}
