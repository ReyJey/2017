import cs50

def main():
    n = get_int() + 1
    for counter in range(n):
        space = n - counter
        for space in range(space, 0, -1):
            print(" ",end = "")
        for counter in range(counter, 0, -1):
            print("#",end = "")
        print("")
        
def get_int():
    while True:
        print("Height:")
        more = cs50.get_int()
        if more > 0 and more < 23:
            break
    return more
    
if __name__ == "__main__":
    main()