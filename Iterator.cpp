#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    node *next;
};


class Iterator
{
private:
    bool hasNext;
    node *getNext;
};

class Set
{
public:
    virtual iterator Iterator() = 0;
    virtual void Delete(int x)= 0;
    virtual void Insert(int x) = 0;
    virtual bool contains(int x) = 0;
};


class ListSet: public Set
{
private:
    node *start;
public:
    class Iterator
    {
    private:
        bool hasNext;
        node getNext;
    public:
        Iterator(node* t)
        {
            if(t!=NULL)
                hasNext=true;
        }
    };
    ListSet()
    {
        start=NULL;
    }
    iterator Iterator()
    {
        iterator z=new ListIterator(this);
        return z;
    }
    void Delete(int x)
    {
        node *cur,*prev;
        cur=start;
        prev=NULL;
        while(cur!=NULL)
        {
            if(cur->data==x)
            {
                if(prev==NULL)
                {
                    start=cur->next;
                }
                else
                {
                    prev->next=cur->next;
                    delete cur;
                }
                break;
            }
            else
            {
                prev=cur;
                cur=cur->next;
            }
        }
    }
    void Insert(int x)
    {
        node *cur;
        node *prev;
        prev=NULL;
        cur=start;
        while(cur!=NULL)
        {
            if(cur->data==x)
                break;
            else
            {
                prev=cur;
                cur=cur->next;
            }
        }
        if(cur==NULL)
        {
            node *v;
            v->next=NULL;
            v->data=x;
            if(start==NULL)
            {
                start=v;
            }
            else
            {
                prev->next=v;
            }
        }
    }
    bool contains(int x)
    {
        node *cur;
        cur=start;
        while(cur!=NULL)
        {
            if(cur->data==x)
                return true;
            cur++;
        }
        return false;
    }

};

int main()
{
    cout << "Hello world!" << endl;
    ListSet a;
    a.Insert(2);
    a.Insert(3);
    a.Insert(2);
    a.Insert(4);
    int x;
    a.Iterator();
    return 0;
}
