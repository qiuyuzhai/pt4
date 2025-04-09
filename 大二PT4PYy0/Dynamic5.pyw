from pt4 import *
#The top A1 of a nonempty stack is given.
#Pop the top component off the stack and output its value D and a reference A2 to a new top of the stack. 
# If the stack will be empty after popping the component then A2 must be equal to null. 
# After popping the component release resources allocated for this component; 
# for this purpose call its Dispose method.
def solve():
    task("Dynamic5")
    p1=get()
    put(p1.Data,p1.Next)
    p1.dispose()
    








start(solve)
