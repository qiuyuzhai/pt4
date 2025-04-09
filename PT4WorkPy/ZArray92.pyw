from pt4 import *
def even(e):
    return e%2==0
def solve():
    task("ZArray92")
    a=get_list()
    list(filter(even,a))
    put (len (a),a)



start(solve)
