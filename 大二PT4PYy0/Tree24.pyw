from pt4 import *
# A pointer P1 to the root of a nonempty tree is given.
#  Using inorder tree walk find the last node with the maximal odd value and output its address P2.
#  If the tree does not contain nodes with odd values then output nil.
# 给出指向非空树的根的指针P1。 使用inorder tree找到最大奇数值的最后一个节点并输出其地址P2。 
# 如果树不包含具有奇数值的节点，则输出nil。
def CNodeOutput(p):#直接把13题的拿来改一下就用了
    global pmax,dmax
    if p==None:
        return
    CNodeOutput(p.Left)
    if p.Data%2!=0 and p.Data>=dmax:#等于号是保证输出的是最后的那个
        dmax=p.Data
        pmax=p
    CNodeOutput(p.Right)
def solve():
    global pmax,dmax
    task("Tree24")
    pmax=None
    dmax=-1
    CNodeOutput(get())
    put(pmax)
    









start(solve)
