# Oana Miron Problem 1
class node:
    def __init__(self,item):
        self.head=item
        self.next=None

class stack:
    def __init__(self):
        self.top=0
        self.head=node(None)
    def push(self, item):
        var=self.head
        self.head=node(item)
        self.head.next=var
        self.top +=1
    def pop(self):
        val=self.head.head
        self.head=self.head.next
        self.top -=1
        return val
    def pop_all(self):
        while self.top!=0:
            l=self.pop()
            print(l)

s=stack()
s.push(5)
s.push(4)
s.push(2)
s.pop_all()
