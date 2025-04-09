from pt4 import *
def solve():
    task("Recur24")
    f=get_str()
    result=wjr(f)
    put(result)
def wjr(S):
    if S=="T":
        return True
    elif S=="F":
        return False
    if S.startswith('And'):
        arguments=S[4:-1].split(",")
        result=True
        for arguments in arguments:
            result=result and wjr(arguments.strip())
        return result
    elif S.startswith("Or"):
        arguments=S[3:-1].split(",")
        result=False
        for arguments in arguments:
            result=result or wjr(arguments.strip())
        return result
    elif S.startswith("Not"):
        arguments=S[4:-1].strip()
        return not wjr(arguments)
start(solve)