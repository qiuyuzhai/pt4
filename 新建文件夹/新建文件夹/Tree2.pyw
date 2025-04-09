from pt4 import *
#An address P1 of a record of TNode type (a tree root) is given. 
#This record is linked by its Left and Right fields with records of the same type (child nodes);
#they, in turn, are linked with their own child nodes and so on, until records whose Left and Right fields are equal to nil.
#Some of the nodes may have one field (Left or Right) equals nil. Output the amount of tree nodes.
def NodeCount(p):
    if p==None:
        return 0
    return 1+NodeCount(p.Left)+NodeCount(p.Right)
def solve():
    task("Tree2")
    put(NodeCount(get()))
    








start(solve)
