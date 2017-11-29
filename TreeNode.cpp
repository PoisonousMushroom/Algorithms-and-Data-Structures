//Oana Miron Pb 7.2
//BFG line 211-228
//DFG line 233-260
#include <iostream>
#include <vector>

using namespace std;

class treeNode{
private:
    vector<treeNode> children;
    treeNode *parent;
    int item;
public:
    treeNode(treeNode *parent,int val);
    ~treeNode();
    void getItem();
    void addChild(int val);
    void removeChild(int pos);
    treeNode* getChild(int pos);
    treeNode* getParent();
    int getnbC();
    treeNode* getNode(int pos,int &cur);
};

//tree Node functions

treeNode::treeNode(treeNode* parent,int val)
{
    this->parent=parent;
    item=val;
    children.clear();
}

treeNode::~treeNode()
{
    item=0;
    children.erase(children.begin(),children.end());
}

void treeNode::getItem()
{
    cout<<this->item<<endl;
}

void treeNode::addChild(int val)
{
    treeNode temp(this,val);
    children.push_back(temp);
    temp.~treeNode();
}

void treeNode::removeChild(int pos)
{
    children.erase(children.begin()+pos);
}

treeNode* treeNode::getChild(int pos)
{
    return &children[pos];
}

treeNode* treeNode::getParent()
{
    return parent;
}

int treeNode::getnbC()
{
    return children.size();
}

treeNode* treeNode::getNode(int pos, int &cur)
{
    if(this==NULL||cur==pos)
    {
        return this;
    }
    cur++;
    int i;
    for(i=0;i<this->getnbC()-1;i++)
    {
        treeNode *temp=this->getChild(i)->getNode(pos,cur);
        if(temp!=NULL)
        {
            return temp;
        }
    }
    return this->getChild(i)->getNode(pos,cur);
}





class Tree{
private:
    treeNode* root;
    int el;
public:
    ~Tree();
    Tree(int val);
    void addC(treeNode* parent, int val);
    int isRoot();
    treeNode* getRoot();
    treeNode* getNodeX(int pos);
};

//Tree functions
Tree::Tree(int val)
{
    root=new treeNode(NULL,val);
    el=1;
}

void Tree::addC(treeNode* parent, int val)
{
    if(parent==NULL)
        cout<<"You cannot add another root."<<endl;
    else
    {
        parent->addChild(val);
        el++;
    }
}

int Tree::isRoot()
{
    if(root==NULL)
        return 1;
    return 0;
}

treeNode* Tree::getRoot()
{
    return this->root;
}

treeNode* Tree::getNodeX(int pos)
{
    int cur=0;
    if(pos>el)
    {
        cout<<"The position "<<pos<<" is bigger than the number of elements "<<el<<"."<<endl;
        cout<<"The item will be added as the child of the last element."<<endl;
        return root->getNode(el-1,cur);
    }
    return root->getNode(pos-1,cur);
}

struct node
{
    treeNode *vari;
    node *next;
};

class Queue{
private:
    node *last;
    node *first;
public:
    Queue();
    void enqueue(treeNode *vari);
    treeNode* dequeue();
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
        return 0;
    return 1;
}

void Queue::enqueue(treeNode *item)
{
    node *cur=new node;
    cur->vari=item;
    cur->next=NULL;
    if(first==NULL)
    {
        first=cur;
    }
    else
        last->next=cur;
    last=cur;
}

treeNode* Queue::dequeue()
{
    node w;
    if(first==NULL){
        cout<<"Queue is empty\n";
        return NULL;
    }
    else
    {
        w=*first;
        first=first->next;
        return w.vari;
    }
}

/*BFS*/

void TreeBFS(Tree *x)
{
    Queue *q=new Queue();
    treeNode *pas;
    if(x->isRoot())
    {
        return;
    }
    q->enqueue(x->getRoot());
    while(q->over())
    {
        pas=q->dequeue();
        pas->getItem();
        int t=pas->getnbC();
        for(int i=0;i<t;i++)
            q->enqueue(pas->getChild(i));
    }
}

/*DFS*/
void DFS(Queue q)
{
    treeNode *pas;
    treeNode *trash;
    if(q.over())
    {
        pas=q.dequeue();
        pas->getItem();
        for(int i=0;i<pas->getnbC();i++)
        {
            q.enqueue(pas->getChild(i));
            DFS(q);
            while(q.over())
                trash=q.dequeue();
        }
    }
}

void TreeDFS(Tree *x)
{
    Queue q;
    if(x->isRoot())
    {
        return;
    }
    q.enqueue(x->getRoot());
    DFS(q);
}

int main()//the nodes are numbered from left to right
{
    Tree *x=new Tree(4);
    x->addC(x->getRoot(),6);
    x->addC(x->getRoot(),7);
    x->addC(x->getRoot()->getChild(0),3);
    x->addC(x->getNodeX(3),5);
    x->addC(x->getNodeX(14),17);
    x->addC(x->getNodeX(1),9);
    cout<<"The tree BFS is"<<endl;
    TreeBFS(x);
    cout<<"The tree DFS is"<<endl;
    TreeDFS(x);
    return 0;

}

/*
                 4
               / | \
              6  7  9
             /  /
            3  17
           /
          5
*/
