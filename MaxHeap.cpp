//Oana Miron Pb 7.1
#include <iostream>

using namespace std;

class Node{
private:
    int item;
public:
    Node(){item=0;};
    Node(int val){item=val;};
    ~Node(){};
    int getNode(){return item;}
};

class MaxHeap{
private:
    int length;//size of array
    int nb;//elements in heap
    Node *vals;
public:
    MaxHeap();
    MaxHeap(int dim);
    ~MaxHeap();
    void ReheapUp(int root, int last);
    void ReheapDown(int root, int last);
    int Insert(int v);
    Node Extract();
    int NbElements(){return nb;};
    int Find(){return vals[0].getNode();};
};

MaxHeap::MaxHeap(int dim)
{
    nb=0;
    vals=new Node(dim);
    length=dim;
}

MaxHeap::MaxHeap()
{
    nb=0;
    vals=new Node[100];
    length=100;
}

MaxHeap::~MaxHeap()
{
    for(int i=0;i<length;i++)
        vals[i].~Node();
}

void MaxHeap::ReheapDown(int root, int last)
{
    int maxim, right=root*2+2,left=root*2+1;
    Node temp;
    if(left<=last){
        if(left==last)
            maxim=left;
        else{
            if(vals[left].getNode()<=vals[right].getNode())
                maxim=right;
            else
                maxim=left;}
        if(vals[root].getNode()<vals[maxim].getNode())
        {
            temp=vals[root];
            vals[root]=vals[maxim];
            vals[maxim]=temp;
            ReheapDown(maxim,last);
        }
    }
}

void MaxHeap::ReheapUp(int root, int last)
{
    int parent;
    Node temp;
    if(last>root)
    {
        parent=(last-1)/2;
        if(vals[parent].getNode()<vals[last].getNode())
        {
            temp=vals[parent];
            vals[parent]=vals[last];
            vals[last]=temp;
            ReheapUp(root,parent);
        }
    }
}

int MaxHeap::Insert(int v)
{
    if(nb<length)
    {
        Node temp(v);
        vals[nb]=temp;
        ReheapUp(0,nb);
        nb++;
        temp.~Node();
        return 1;
    }
    return 0;
}

Node MaxHeap::Extract()
{
    Node temp(vals[0].getNode());
    nb--;
    vals[0]=vals[nb];
    ReheapDown(0,nb-1);
    return temp;
}

class IntPriorityQueue
{
private:
    MaxHeap elements;
public:
    IntPriorityQueue(){MaxHeap elements;};
    IntPriorityQueue(int dim){MaxHeap elements(dim);};
    ~IntPriorityQueue(){elements.~MaxHeap();};
    int enqueue(int v)
    {
        int a=elements.Insert(v);
        return a;
    }
    void dequeue()
    {

        if(elements.NbElements()==0)
            cout<<"There are no more elements in the Priority Queue"<<endl;
        else
        {
            Node temp=elements.Extract();
            cout<<"We dequeue "<<temp.getNode()<<endl;
            temp.~Node();
        }
    }
    void printall()
    {
        while(elements.NbElements()!=0)
            this->dequeue();
    }
};

int main()
{
    IntPriorityQueue x(20);
    x.enqueue(2);
    x.dequeue();
    x.dequeue();
    x.enqueue(5);
    x.enqueue(6);
    x.enqueue(4);
    x.enqueue(7);
    x.enqueue(20);
    x.enqueue(2);
    x.printall();
    return 0;
}
