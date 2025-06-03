#include <iostream>
using namespace std;
struct Node
{
public:
    int element;
    Node*next;
    Node*prev;
};


void insertfirst(Node**firstnode, int newelement)
{

    Node*newnode = new Node();
    newnode->element = newelement;
    newnode->next = (*firstnode);
    newnode->prev = NULL;
 if ((*firstnode) != NULL)
    {
    (*firstnode)->prev = newnode;
    (*firstnode) = newnode;
    }
}


void insertafter(Node*prevnode, int newelement)
{

    if (prevnode == NULL)
    {
     cout << "the given previous node cannot be NULL";
    }
    Node*newnode = new Node();
    newnode->element = newelement;
    newnode->next = prevnode->next;
    prevnode->next = newnode;
    newnode->prev = prevnode;
  if (newnode->next != NULL)
        {
        newnode->next->prev = newnode;
        }
}


void insertend(Node**firstnode, int newelement)
{

    Node*newnode = new Node();
    Node*last = *firstnode;
    newnode->element = newelement;
    newnode->next = NULL;
  if (*firstnode == NULL)
    {
    newnode->prev = NULL;
    *firstnode = newnode;
    }
while (last->next != NULL)
    {
    last = last->next;
    last->next = newnode;
    newnode->prev = last;
    }
}
/*void deletenode(Node**firstnode,Node*element)
{
  if (*firstnode== NULL || element == NULL)


    if (*firstnode== element)
        *firstnode= element->next;


    if (element->next != NULL)
        element->next->prev = element->prev;


    if (element->prev != NULL)
        element->prev->next = element->next;

}*/

void deletenode(struct Node** head, struct Node* del_node) {
  // if head or del is null, deletion is not possible
  if (*head == NULL || del_node == NULL)
    return;

  // if del_node is the head node, point the head pointer to the next of del_node
  if (*head == del_node)
    *head = del_node->next;

  // if del_node is not at the last node, point the prev of node next to del_node to the previous of del_node
  if (del_node->next != NULL)
    del_node->next->prev = del_node->prev;

  // if del_node is not the first node, point the next of the previous node to the next node of del_node
  if (del_node->prev != NULL)
    del_node->prev->next = del_node->next;

  // free the memory of del_node
  //free(del_node);
}

void printDLList(Node*node)
{
    Node*last;
    cout << "\nTraversal in forward direction \n";
    while (node != NULL) {
        cout << " " << node->element << " ";
        last = node;
        node = node->next;
    }

    cout << "\nTraversal in reverse direction \n";
    while (last != NULL)
    {
        cout << " " << last->element << " ";
        last = last->prev;
    }
}


int main()
{

    Node*firstnode = NULL;


    insertend(&firstnode, 6);

    insertfirst(&firstnode, 7);


    insertfirst(&firstnode, 1);


    insertend(&firstnode, 4);


    insertafter(firstnode->next, 8);

    cout << "Create a Doubly linked List is: "<<endl;
    printDLList(firstnode);
    deletenode(&firstnode, firstnode);
    deletenode(&firstnode, firstnode->next);
    deletenode(&firstnode, firstnode->next);
    cout << "\n Modified linked list is: "<<endl;
    printDLList(firstnode);


    return 0;
}
