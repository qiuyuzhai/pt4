from pt4 import *
#A pointer P1 to the root of a nonempty tree and an integer N (> 0) are given. 
# The value of N is not greater than the amount of tree nodes. 
# Output the values of tree nodes whose order numbers are N or greater
#  (the tree nodes are numbered from 1 using postorder tree walk — see Tree14).
# 输出顺序编号为N或更大的树节点的值（树节点从1开始使用postorder tree walk编号-请参阅Tree14）。
def LRCNodeOutput(p,n):##从tree13改来的
    global res
    if p==None:
        return 
    LRCNodeOutput(p.Left,n)
    LRCNodeOutput(p.Right,n)
    res+=1
    if res>=n:
        put(p.Data)#一定要放到后面来操作
   
def solve():##
    global res
    task("Tree16")
    p, n = get2()
    res=0
    LRCNodeOutput(p,n)





start(solve)
