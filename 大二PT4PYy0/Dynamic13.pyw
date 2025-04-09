from pt4 import *##齐心那个有12和14的，可以参考
# The top A1 of a stack is given. 
# Include two functions in the IntStack class (see Dynamic11): 
# a logical function IsEmpty returns true if the stack is empty, and false otherwise; 
# an integer function Peek returns the value of the top component of the stack. 
# The functions have no parameters. Using these functions and the Pop function from the task Dynamic12, 
# pop five components (or all stack components if their amount is less than five) off the given stack and output their values. 
# Also output the return value of the IsEmpty function for the resulting stack. 
# At last, in the case of the nonempty resulting stack, output the value of its top component and a reference to this component.
class IntStack:
    def IsEmpty(self):
        return self.top is None
    def Peek(self):
        if(self.top):
            return self.top.Data
    def __init__(self,top):
        self.top=top
    def push(self,data):
        node=Node(data)
        node.Next=self.top
        self.top=node
    def Pop(self):
        if(self.top):
            prev_top=self.top
            data=self.top.Data
            self.top=self.top.Next
            prev_top.dispose()
            return data
    
def solve():
    task("Dynamic13")
    a1=get()
    stack=IntStack(a1)
    for i in range(5):
        if not stack.IsEmpty():
            value=stack.Pop()
            put(value)
    put(stack.IsEmpty())
    if not stack.IsEmpty():
        top_value=stack.Peek()
        put(top_value)
        put(stack.top)




start(solve)
