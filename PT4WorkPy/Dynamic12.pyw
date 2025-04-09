from asyncio.windows_events import NULL
from pt4 import *

class IntStack:
    def __init__(self, t):
        self.Top = t

    def Pop(self):
        put(self.Top.Data)
        tmp = self.Top
        self.Top = self.Top.Next
        tmp.dispose()

def solve():
    task("Dynamic12")
    node = get()
    stack = IntStack(node)
    for m in range(5):
        stack.Pop()
    put(stack.Top)

start(solve)
