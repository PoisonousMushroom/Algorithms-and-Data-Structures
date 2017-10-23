// Oana Miron Problem 2

#include <iostream>

using namespace std;

struct node{
    int val;
    struct node *next;
};

class Queue{
private:
    node *last;
    node *first;
public:
    Queue();
    void enqueue(int item);
    void dequeue();
    int over();//checks if queue is empty

};

Queue::Queue()
{
    last=NULL;
    first=NULL;
}

int Queue::over()
{
    if(first==NULL)
        return 1;
    return 0;
}

void Queue::enqueue(int item)
{
    node *cur=new node;
    cur->val=item;
    cur->next=NULL;
    if(first==NULL)
    {
        first=cur;
    }
    else
        last->next=cur;
    last=cur;
}

void Queue::dequeue()
{
    node *cur=new node;
    if(first==NULL)
        cout<<"Queue is empty\n";
    else
    {
        cur=first;
        first=first->next;
        cout<<cur->val<<endl;
        delete cur;
    }
}

int main()
{
    Queue a;
    for(int i=0;i<5;i++)
        a.enqueue(i);
    while(a.over()!=1)
        a.dequeue();
    return 0;
}
