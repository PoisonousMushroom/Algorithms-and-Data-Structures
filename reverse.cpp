//P2. Oana Miron
#include <iostream>
#include <string>
using namespace std;

template<class T>
class node
{
    public:
    node();
    node(T v)
    {
        next=NULL;
        val=v;
    }
    node* next;
    T val;
    T& Getval(){return val;}
};
template<class T>
class list
{
    public:
    node<T>* head;
    list(){head=NULL;};
    void add(T it)
    {
        if(head==NULL)
        {
            node<T>* t=new node<T>(it);
            head=t;
        }
        else
        {
            node<T>* cur;
            cur=head;
            while(cur->next!=NULL)cur=cur->next;
            node<T>* t=new node<T>(it);
            cur->next=t;
        }
    }
    ~list()
    {
        while(head!=NULL)
        {
            node<T>* cur = head;
            head = head->next;
            delete cur;
        }
    }
    void revers()
    {
        if(head==NULL)
            return;
        node<T> *prev=NULL,*cur,*next;
        cur=head;
        while(cur!=NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head=prev;
    }
    void append(list c)
    {
        if(head==NULL)
           head=c.head;
        else
        {
            node<T> *cur;
            cur=head;
            while(cur->next!=NULL)
                cur=cur->next;
            cur->next=c.head;
        }
    }
    void print()
    {
        node<T>* cur=head;
        while(cur!=NULL)
        {
            cout<<cur->val<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }
};

int main()
{

     list<int> a;
     a.add(3);
     a.add(4);
     a.add(5);
     a.print();
     list<int> b;
     b.add(22);
     b.add(33);
     b.add(44);
     b.print();
     a.append(b);
     a.print();
     a.revers();
     a.print();
    return 0;
}
