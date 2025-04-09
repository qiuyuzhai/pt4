from pt4 import *
def solve():
    task("Dynamic8")
    p1,p2=get2()
    while p1:##只要栈1里还有元素，都会飞给栈2
        p=p1
        p1=p1.Next##先把原来的p1用p飞走，原来的p1的next域的东西就是现在的p1//就是说你把p1搞走，首先要有容器p,然后要有接班人（p1的next域）
        p.Next=p2##游离的p接到p2前面
        p2=p##原来的顶针变成现如今新飞来的p
    put(p2)








start(solve)
