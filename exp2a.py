def duplicate(books):
    return list({tuple(book.items()) for book in books})
def sort_books(books):
    return sorted(books,key=lambda x: x["cost"])
def expensive(books):
    count=0
    for book in books:
        if(book["cost"]>500.0):
            count=count+1
    return count
def copy(books):
    result=[]
    for book in books:
        if(book["cost"]<=500):
            result.append(book)
    return result

N=int(input("Enter the number of books:"))
list=[]

title=input("Enetr the title:")
cost=float(input("Enetr the cost:"))
list.append({"title":title,"cost":cost})
#always remember python always take input as string if you are getting some error then check it, must be some sort of technical error there