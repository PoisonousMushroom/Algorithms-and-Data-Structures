# Oana Miron Problem 1

class node:
    def __init__(self,val):
        self.val=val
        self.to={}

    def addEdge(self,to,weight=0):
        self.to[to]=weight
        a=0

    def out(self):
        return self.getEdges()

    def getWeight(self,to):
        return self.to[to]

    def getEdges(self):
        return sorted(self.to.keys())
    
    def inc(self,i):
        if i in self.getEdges():
            return self.val


class Graph:
    def __init__(self):
        self.numNodes=0
        self.NodeList={}

    def addNode(self,nod):
        self.numNodes+=1
        newNode=node(nod)
        self.NodeList[nod]=newNode
        return newNode

    def addEdge(self,fro,to,weight =0):
        if fro not in self.NodeList:
            nou=self.addNode(fro)
        if to not in self.NodeList:
            nou2=self.addNode(to)
        self.NodeList[fro].addEdge(to,weight)
        self.NodeList[to].addEdge(fro,weight)

    def outgoing(self,i):
        q=[]
        l=self.NodeList[i].out()
        for x in l:
            q.append([i,x])
        return q
    
    def incoming(self,i):
        l=[]
        for x in self.NodeList:
            v=self.NodeList[x].inc(i)
            if v!=None:
                l.append([v,i])
        return l

    def getEdge(self,i,j):
        v=self.NodeList[i].inc(j)
        if v!=None:
            return self.NodeList[i].getWeight(j)
        else:
            return None    

g=Graph()
for i in range(6):
    g.addNode(i)
g.addEdge(10,0,8)
g.addEdge(3,6,14)
g.addEdge(4,5,1)
g.addEdge(4,6,3)
g.addEdge(6,4,6)
g.addEdge(8,12,2)
g.addEdge(9,1,4)
g.addEdge(9,2,7)
g.addEdge(9,7,2)
g.addEdge(9,8,3)
g.addEdge(9,10,1)
g.addEdge(10,1,4)
g.addEdge(10,12,1)
g.addEdge(11,9,14)
g.addEdge(12,11,4)
g.addEdge(3,4,2)
g.addEdge(1,2,5)
g.addEdge(8,7,11)
g.addEdge(9,3,5)
print('Edges going in node 9')
print(g.incoming(9))
print('Edges starting from node 9')
print(g.outgoing(9))
print('The edge [1,2] has the weight ')
print(g.getEdge(1,2))
print('The edge [2,1] has the weight ')
print(g.getEdge(2,1))
print('Edges starting from node 0')
print(g.outgoing(0))
print('Edges starting from node 1')
print(g.outgoing(1))
print('Edges starting from node 2')
print(g.outgoing(2))
print('Edges starting from node 3')
print(g.outgoing(3))
print('Edges starting from node 4')
print(g.outgoing(4))
print('Edges starting from node 5')
print(g.outgoing(5))
print('Edges starting from node 6')
print(g.outgoing(6))