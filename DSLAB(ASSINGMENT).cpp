#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node*next;
  struct Node*prev;
};

void insertfirst(struct Node**firstNode, int data)
{
  struct Node*newNode = new Node;
  newNode->data=data;
  newNode->next=(*firstNode);
  newNode->prev=NULL;
  if ((*firstNode)!=NULL)
  {
   (*firstNode)->prev=newNode;
  }
  (*firstNode)=newNode;
}

void insertafter(struct Node*prevnode, int data)
{
  if (prevnode==NULL)
  {
    cout << "previous node cannot be null";
    return;
  }
  struct Node*newNode=new Node;
  newNode->data=data;
  newNode->next=prevnode->next;
  prevnode->next=newNode;
  newNode->prev = prevnode;
 if (newNode->next != NULL)
 {
  newNode->next->prev = newNode;
 }
}

void insertend(struct Node**firstNode, int data)
{
  struct Node*newNode = new Node();
  newNode->data = data;
  newNode->next = NULL;
  struct Node*temp =*firstNode;
 if (*firstNode== NULL)
    {
    newNode->prev=NULL;
    *firstNode=newNode;
    return;
  }
 while (temp->next!=NULL)
 {
  temp = temp->next;
 }
  temp->next = newNode;
  newNode->prev = temp;
}

void deletenode(struct Node**firstNode, struct Node*deletenode)
{
 if (*firstNode==NULL || deletenode==NULL)
 return;
 if (*firstNode==deletenode)
 *firstNode= deletenode->next;
 if (deletenode->next!=NULL)
    deletenode->next->prev=deletenode->prev;
 if (deletenode->prev!= NULL)
    deletenode->prev->next = deletenode->next;
}

void printDLList(struct Node*node)
{
    struct Node*last;

    while (node != NULL)
    {
        cout << " " << node->data << " ";
        last = node;
        node = node->next;
    }
    cout<<endl;

    while (last != NULL)
    {
        cout << " " << last->data << " ";
        last = last->prev;
    }
    cout<<endl;
}

int main()
{
Node*firstnode = NULL;

insertfirst(&firstnode,2);
insertfirst(&firstnode,3);
insertafter(firstnode->next,5);
insertend(&firstnode,1);
cout<<"Create a Double linked List is:"<<endl;
printDLList(firstnode);
deletenode(&firstnode,firstnode);
cout<<"Deleting 3 a Double linked list is:"<<endl;
printDLList(firstnode);
insertend(&firstnode,6);
cout<<"Inserting 6 a Double linked list is:"<<endl;
printDLList(firstnode);
deletenode(&firstnode,firstnode->next);
cout<<"Deleting 5 a Double linked list is:"<<endl;
printDLList(firstnode);
return 0;
}
