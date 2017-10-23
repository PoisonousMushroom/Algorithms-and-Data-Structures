#include <iostream>

using namespace std;

typedef struct stack
{
    unsigned int count;
    int array[12]; //container
}stack;

//int push(int x,stack *s);
//void in(stack *s);
//int pop(stack *x);
//int isEmpty(stack *x);


int push(int v, stack *x)
{
    if(x->count<12)
    {
        x->count++;
        x->array[x->count-1]=v;
        return 1;
    }
    else
        return 0;
}

int pop(stack *x)
{
    int val;
    if(x->count==0)
        return 0;
    else
    {
        val=x->array[x->count-1];
        x->array[x->count-1]=0;
        x->count--;
        return val;
    }
}

int isEmpty(stack *x)
{
    if(x->count==0)
    {
        return 1;
    }
    return 0;
}

void in(stack *x)
{
    x->count=0;
}

int main()
{
    int b;
    stack x;
    in(&x);
    push(4,&x);
    push(5,&x);
    push(2,&x);
    while(isEmpty(&x)==0){
        b=pop(&x);
        cout<<"Popping "<<b<<endl;
    }
    return 0;
}
