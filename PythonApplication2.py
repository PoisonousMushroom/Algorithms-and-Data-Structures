jgr
# Oana Miron Pb 3

class node:
    def __init__(self,item):
        self.head=item
        self.next=None

class queue:
    def __init__(self):
        self.first=node(None)
        self.last=node(None)
    def enqueue(self,item):
        x=node(item)
        if self.first==None:
            self.first=x
            self.last=x
        else:
            self.last.next=x
            self.last=x
    def dequeue(self):
        x=node(None);
        if self.first==None:
            print("Queue is empty")
        else:
            x=self.first
            self.first=self.first.next
            print(x.head)
    