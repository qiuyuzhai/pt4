from pt4 import *
def solve():
    task("Dynamic15")
    class myQueue:

        def __init__(self, bottom, top):
            self.bottom = bottom
            self.top = top

        def Put(self):
            print(self.top)
            print(self.bottom)
            put(self.top, self.bottom)

        def Push(self, d):
            temp = Node()
            temp.Data = d
            temp.Next = None
            self.bottom.Next = temp
            self.bottom = temp


    pd1, pd2 = Node(), Node()
    pd1.Data, pd2.Data, pd1.Next, pd2.Next = get(), get(), None, None
    q1, q2 = myQueue(pd1, pd1), myQueue(pd2, pd2)
    for i in range(4):
        d1, d2 = get2()
        q1.Push(d1)
        q2.Push(d2)

    
    q1.Put()
    q2.Put()    

start(solve)