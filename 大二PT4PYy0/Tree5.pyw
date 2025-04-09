from pt4 import *
#A pointer P1 to the root of a nonempty tree is given. 
# Output the amount of left child nodes (the tree root should not be counted).
def LChildCount(p,parent):
    if p==None:
        return 0
    res=0
    if parent!=None and parent.Left==p:#有父母且自身是父母的左孩子
      res=1
    return res+LChildCount(p.Left,p)+LChildCount(p.Right,p)

def solve():
    task("Tree5")
    put(LChildCount(get(),None))#一开始的根没有父母








start(solve)
