// Oana Miron Pb 4

#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

class buffer{
private:
    int *arr;
    int beg;
    int siz;
public:
    buffer(int n);
    void enqueue(int item,int n);
    void dequeue(int n);
    int exist();

};

int buffer::exist()
{
    return siz;
}

buffer::buffer(int n)
{
    siz=0;
    arr=(int*)malloc(sizeof(int)*n);
    beg=0;
}

void buffer::enqueue(int item,int n)
{
    if(siz==n)
        cout<<"Buffer overflow of value "<<item<<endl;
    else
    {
        arr[(beg+siz)%n]=item;
        siz=siz+1;
    }
}

void buffer::dequeue(int n)
{
    if(siz==0)
        cout<<"Buffer underflow"<<endl;
    else
    {
        cout<<"We take out "<<arr[beg]<<endl;
        arr[beg]=0;
        beg=(beg+1)%n;
        siz=siz-1;
    }
}

int main()
{
    buffer *b=new buffer(4);
    b->enqueue(2,4);
    b->dequeue(4);
    b->dequeue(4);
    b->enqueue(2,4);
    b->enqueue(3,4);
    b->enqueue(4,4);
    b->enqueue(5,4);
    b->enqueue(6,4);
    while(b->exist()!=0)
    {
        b->dequeue(4);
    }
    return 0;
}
