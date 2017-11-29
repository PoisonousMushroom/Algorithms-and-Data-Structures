#include <iostream>

using namespace std;


struct node
{
   int element;
   node* next;
};


class Set
{
    public:
        virtual bool contains(int x)=0;
        virtual void insert(int x)=0;
        virtual void Delete(int x)=0;
        class Iterator
        {
            private:
                node *Node;
            public:
            Iterator(node *p){Node = p;}
            ~Iterator() {}
            Iterator& operator=(const Iterator& other)
            {
                Node = other.Node;
                return(*this);
            }
            bool operator==(const Iterator& other)
            {
                return(Node == other.Node);
            }
            bool operator!=(const Iterator& other)
            {
                return(Node != other.Node);
            }
            Iterator& operator++()
            {
                if (Node != NULL)
                {
                    Node = Node->next;
                }
                return(*this);
            }
            Iterator& operator++(int)
            {
                Iterator tmp(*this);
                ++(*this);
                return(tmp);
            }
            int& operator*()
            {
                return(Node->element);
            }
            bool print()
            {
                if(Node==NULL)
                    return false;
                cout<<Node->element<<endl;
                return true;
            }
        };
    virtual Iterator iterator()=0;
};


class ListSet : public Set
{
  public:
    ListSet(){
    first=NULL;
    index=0;
    pos=0;};
    ~ListSet(){};
    Iterator begin(){
        return(Iterator(first));
    }
    Iterator end(){
        return(Iterator(NULL));
    }
    bool contains(int x)
    {
        for(ListSet::Iterator it=begin();it!=end();++it){
            if(*it==x)
                return true;
        }
        return false;
    }
    void insert(int x)
    {
        int ok=1;
        for(ListSet::Iterator it=begin();it!=end();++it)
        {
            if(*it==x)
            {
                ok=0;
                break;
            }
        }
        if(ok==1)
        {
            node *t=new node();
            t->element=x;
            t->next=NULL;
            if(first==NULL)
                first=t,index++,pos++;
            else
            {
                node *par;
                par=first;
                for(int i=0;i<index-1;i++)
                {
                    par=par->next;
                }
                par->next=t;
                index++;
                pos++;
            }
        }
    }
    void Delete(int x)
    {
        node *t;
        node *prev;
        t=first;
        prev=NULL;
        while(t!=NULL)
        {
            ListSet::Iterator b=Iterator(t);
            if(*b==x)
            {
                if(prev==NULL)
                {
                    first=t->next;
                }
                else
                {
                    prev->next=t->next;
                    delete t;
                }
                break;
            }
            prev=t;
            t=t->next;
        }
    }
    Iterator iterator()
    {
        if(pos==-1){pos=index;}
        ListSet::Iterator it=begin();
        int i=0;
        while(i!=index-pos)it++,i++;
        pos--;
        return it;
    }
protected:
    node *first;
    int index;
    int pos;
};


int main()
{

    ListSet test;
    test.insert(4);
    test.insert(2);
    test.insert(4);
    while(test.iterator().print());
    test.~ListSet();
    return 0;
}
