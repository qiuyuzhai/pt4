from pt4 import *
#给出一个整数N（>0）和N个整数序列。 
#创建具有N个节点的平衡树（即满足以下条件的二叉树：对于每个树节点，其左子树的深度与其右子树的深度至多相差1）并输出树根的地址。 
# 使用给定序列的元素作为节点值; 
# 通过以下递归算法创建树：创建根节点，然后重复该算法两次：
# 用于创建具有N/2个节点的左子树和用于创建具有N−1−N/2个节点的右子树（"/"表示整数除法
def CreatTree(n):
    if n==0:
        return None
    p=Node(get())
    p.Left=CreatTree(n//2)
    p.Right=CreatTree(n-1-n//2)
    return p
def solve():
    task("Tree32")
    put(CreatTree(get()))








start(solve)
