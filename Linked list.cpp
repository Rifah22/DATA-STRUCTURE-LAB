#include<iostream>
using namespace std;

struct linkedlistnode
{

public:

   int element;
   struct linkedlistnode*next;
   struct linkedlistnode *prev;

   linkedlistnode(int e)
   {
      element=e;
      struct linkedlistnode*head= NULL;
   }
};

bool search(linkedlistnode*head,int flag)
{
   if(head==NULL)
   {
      return false;
   }
   else if(head->element==flag)
   {
      return true;
   }
   else
   {
      return search(head->next,flag);
   }

}

void printsmallestlinkedlist(struct linkedlistnode* head)
{
   int min = 99999999;

   while (head != NULL)
    {
      if (min > head->element)
      {
        min = head->element;
      }
        head = head->next;
    }
 cout<<"Smallest element in the linked list is : "<<min<<endl;

}

void insertfirst(linkedlistnode*&head, int newelement)
{
   linkedlistnode*newnode= new linkedlistnode(newelement);
   newnode->element = newelement;
   newnode->prev = NULL;
   newnode->next= head;
   if(head != NULL)
   {
   head->prev = newnode ;
   head = newnode;
   }

}


    void insertlast(linkedlistnode*&head , int element)
    {
      linkedlistnode *newnode = new linkedlistnode(element);
      newnode->element = element;
      newnode->next = NULL;
      if(head == NULL)
      {
        head = newnode;
      }
      else
      {
        linkedlistnode* currentnode = head;
        while(currentnode->next != NULL)
          currentnode = currentnode->next;
          currentnode->next = newnode;
      }
    }


void deletefirst(linkedlistnode*&head)
{
   if(head==NULL)
    {
      return;
   }
   linkedlistnode*currentnode=head;
   head= head->next;
   delete(currentnode);
   return;
}

void deletelast(linkedlistnode*&head)
{
   linkedlistnode*previousnode= NULL;
   linkedlistnode*currentnode= head;
   while(currentnode->next!=NULL)
    {
      previousnode= currentnode;
      currentnode= currentnode->next;
   }
   delete currentnode;
   previousnode->next= NULL;
   return;
}


int countOfNodes(linkedlistnode*head)
{
    int count = 0;
    while (head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}

void deleteMid(linkedlistnode*&head)
{
    if (head == NULL)
    {
        return  ;
    }
    if (head->next == NULL)
    {
        delete head;
        return  ;
    }
    linkedlistnode*currentnode = head;

    int count = countOfNodes(head);

    int mid = count / 2;

    while (mid-->1)
    {
        head = head->next;
    }
    head->next = head->next->next;
    return ;
}

void printlinkedlistNode(linkedlistnode*head)
{
   struct linkedlistnode* ptr;
   ptr = head;
   while(ptr != NULL)
    {
      cout<< ptr->element <<" ";
      ptr = ptr->next;
   }
{
   while(head!=NULL)
   {
      cout<<head->element<<" ";
      head=head->next;
   }
   cout<<endl;
}
}
int main()
{

   linkedlistnode*head= NULL;
   insertfirst(head,3);
   insertfirst(head,1);
   insertfirst(head,7);
   insertfirst(head,2);
   insertfirst(head,9);
   cout<<"The doubly linked list is: ";
   printlinkedlistNode(head);
   printsmallestlinkedlist(head);
   insertfirst(head,11);
   insertfirst(head,21);
   insertfirst(head,12);
   printlinkedlistNode(head);
   insertlast(head,20);
   insertlast(head,18);
   printlinkedlistNode(head);
   /*insertmiddle(head,23);
   insertmiddle(head, 31);
   insertmiddle(head, 50);
   printlinkedlistNode(head);*/
   deletefirst(head);
   cout << "Linked List after deletion of first\n";
   printlinkedlistNode(head);
   deletelast(head);
   cout << "Linked List after deletion of last\n";
   printlinkedlistNode(head);
   deleteMid(head);
   cout << "Linked List after deletion of middle\n";
   printlinkedlistNode(head);
   if(search(head,30))
   {
      cout<<"FOUND"<<endl;
   }
   else
   {
      cout<<"NOT FOUND"<<endl;
   }
}
