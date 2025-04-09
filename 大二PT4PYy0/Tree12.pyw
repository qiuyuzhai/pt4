from pt4 import *
#A pointer P1 to the root of a nonempty tree is given.
# Using the recursive algorithm named inorder tree walk output the values of all tree nodes as follows: 
#output the left subtree (using inorder tree walk), then output the root node, 
#then output the right subtree (using inorder tree walk too).
# 给出指向非空树的根的指针P1。 使用名为inorder tree walk的递归算法输出所有树节点的值，
# 如下所示：输出左子树（使用inorder tree walk），然后输出根节点，然后输出右子树（也使用inorder tree walk）。
#我发现定义这类函数，都是那些命令，但好像和命令的排序相关
def LNodeOutput(p):
    if p==None:
        return 
    LNodeOutput(p.Left)
    put(p.Data)
    LNodeOutput(p.Right)
    
    
def solve():
    task("Tree12")
    LNodeOutput(get())








start(solve)
