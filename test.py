import subprocess
import random

def test():
    inlist = ""
    checklist = []
    tmp = 0
    for i in range(random.randint(10, 30)):
        tmp = random.randint(0, 100)
        checklist.append(tmp)
        inlist += ' ' + str(tmp)
    process = subprocess.run("./a.out" + inlist, shell=True, capture_output=True)
    outlist = process.stdout.decode().split()
    outlist = [ int(x) for x in outlist ]
    print(sorted(checklist))
    print(outlist)
    return sorted(checklist) == outlist

if __name__ == "__main__":
    for i in range(10):
        print(test())
