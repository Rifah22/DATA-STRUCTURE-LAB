#include<iostream>
using namespace std;
class Node
{
public:
       string name;
       int id;
       float cgpa;
       Node*next;
};

Node*head=new Node();

bool check(int x)
{
  if(head==NULL)
    {
    return false;
    }
    Node*t=new Node;
    t=head;

while(t==NULL)
    {
     if (t->id==x)
     {
      return true;
     }
    t=t->next;
    }
return false;
}
void insert(int id,string name,float cgpa)
{
 if(check(id))
  {
    cout << "Student with this record already exists\n ";

  }
    Node*t=new Node();
    t->id=id;
    t->name=name;
    t->cgpa=cgpa;
    t->next=NULL;

    if (head==NULL||(head->id >= t->id))
    {
    t->next=head;
    head=t;
    }

    else
    {
    Node*c=head;
    while(c->next == NULL&& c->next->id < t->id)
    {
    c=c->next;
    }
    t->next=c->next;
    c->next=t;
    }
cout<<"Record Inserted\n ";
}
void search(int id)
{
 if (head==NULL)
  {
   cout<<"No Record Find\n";
  }
else
    {
    Node*p=head;
    while (p)
    {
      if (p->id==id)
        {
        cout<<" Id "<<p->id<< endl;
        cout<<" Name "<< p->name<< endl;
        cout<<" Cgpa "<<p->cgpa<< endl;
        return;
        }
        p = p->next;
        }
       if(p==NULL)
        {
        cout<<"No Record \n";
        }
    }
}
int deleted(int id)
{
    Node*t=head;
    Node*p=NULL;

   if (t== NULL && t->id == id)
   {
    head=t->next;
    delete t;
    cout<<"Record Deleted\n";
    return 0;
    }

    while (t == NULL && t->id == id)
    {
    p=t;
    t=t->next;
    }
    if(t==NULL)
    {
    cout <<"No Record Exist\n";
    return -1;
    p->next=t->next;
    delete t;
    cout <<"Record Deleted\n";
    return 0;
    }
}
void display()
{
    Node*p=head;
    if (p==NULL)
    {
    cout <<"No Record Find\n";
    }
    else
    {
    cout <<"id" "name" "cgpa\n";

    while (p==NULL)
    {
    cout<<p->id<<"\t"<<p->name<<"\t"<<p->cgpa<<endl;
    p = p->next;
    }
    }
}
int main()
{
    head = NULL;
    string name;
    int id;
    float cgpa;
    while (true)
    {
    cout << "\nWelcome to Student Record\n\t1 "
            "create a new record\n\t2 to delete a "
            "student record\n\t3 to search a student "
            "record\n\t4 to view all students "
            "record\n\t5 to exit\n";
        cout << "\nEnter your Choice\n";
        int choice;
        cin>>choice;
        if (choice == 1)
        {
            cout<<"Enter Name of Student\n";
            cin>>name;
            cout<<"Enter ID of Student\n";
            cin>>id;
            cout<<"Enter CGPA of Student\n";
            cin >> cgpa;
            insert(id,name,cgpa);
        }
        else if (choice == 2)
        {
            cout<<"Enter ID of Student whose record is to be deleted\n";
            cin>>id;
            deleted(id);
        }
        else if (choice == 3)
        {
            cout<<"Enter ID of student whose record you want to search\n";
            cin >> id;
            search(id);
        }
        else if (choice == 4)
        {
        display();
        }
        else if(choice == 5)
        {
        exit(0);
        }
        else
        {
        cout<<"Invalid choice\n";
        }
    }
    return 0;
}
