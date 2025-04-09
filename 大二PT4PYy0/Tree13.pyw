from pt4 import *
# A pointer P1 to the root of a nonempty tree is given. 
# Using the recursive algorithm named preorder tree walk output the values of all tree nodes as follows:
# output the root node, then output the left subtree (using preorder tree walk),
#  then output the right subtree (using preorder tree walk too).
#输出根节点，然后输出左子树（使用preorder tree walk），然后输出右子树
def CNodeOutput(p):
    if p==None:
        return
    put(p.Data)
    CNodeOutput(p.Left)
    CNodeOutput(p.Right)
def solve():
    task("Tree13")
    CNodeOutput(get())








start(solve)
