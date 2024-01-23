def union(a,b):
    return a.union(b)#return set(a).union(b)
def intersection(a,b):
    return a.intersection(b)
def difference(a,b):
    return a.difference(b)
def count(a):
    return len(a)

cricket=[]
badi=[]
football=[]
 #bro you see nah where you made the mistake so fuck them don't do it in the practical where you need to be careful
cricket=set(input("Enter the student who play cricket(space separated): ").split())
badi=set(input("Enter the student who play badi(space separated): ").split())
football=set(input("Enter the student who play football(space separated): ").split())

while(True):
    print("------menu-------")
    print("1.List of students who play both cricket and badminton")
    print("2.List of students who play either cricket or badminton but not both")
    print("3.Number of students who play neither cricket nor badminton")
    print("4.Number of students who play cricket and football but not badminton")
    print("5.exit")
    choice=int(input("Enter your choice: "))

    if choice==1:
        print(f"List of students who play both cricket and badminton",union(cricket,badi))
    elif choice==2:
        print(f"List of students who play either cricket or badminton but not both",union(cricket,badi)-intersection(cricket,badi))
    elif choice==3:
         result=count(difference(football,union(cricket,badi)))
         print(f"Number of students who play neither cricket nor badminton",result)
    elif choice==4:  
        print(f"Number of students who play cricket and football but not badminton",count(intersection(cricket,football)-badi))
    elif choice==5:
        print("goodbye!")
        break
    else :
        print("Enter a valid choice")