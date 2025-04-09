from pt4 import *
#Given a string S that represents a correct expression of logical type, 
# output the value of this expression. 
# The expression is defined as follows ("T" means True, "F" means False):
#<expression>	::=	T | F | And(<expression> , <expression>) |
#	 	Or(<expression> , <expression>)
#从c那里转下语句抄过来的
s=""
k=0
def NextChar():
    global k
    k+=1
    return s[k]
def SkipChar(n):
    global k
    k += n
def Calc():
    global k
    c = NextChar()
    if c == 'T':
        return True
    if c == 'F':
        return False
    if c == 'O':
        SkipChar(2)
        a = Calc()
        SkipChar(1)
        b = Calc()
        SkipChar(1)
        return a or b
    SkipChar(3)
    a = Calc()
    SkipChar(1)
    b = Calc()
    SkipChar(1)
    return a and b

def solve():##
    global s,k
    task("Recur21")
    s = get()
    k = -1
    put(Calc())








start(solve)
