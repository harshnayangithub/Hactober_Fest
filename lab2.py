def delete_duplicates(books):
    seen = set()
    unique_books = []
    for book in books:
        book_tuple = tuple(book)
        if book_tuple not in seen:
            unique_books.append(book)
            seen.add(book_tuple)
    return unique_books

def display_books_in_ascending_order(books):
    return sorted(books, key=lambda x: x[1])  # Sorting based on the cost of books (assuming format: [book_name, cost])

def count_books_cost_more_than_500(books):
    count = 0
    for book in books:
        if book[1] > 500:
            count += 1
    return count

def copy_books_cost_less_than_500(books):
    return [book for book in books if book[1] < 500]

def main():
    books = []

    n = int(input("Enter the number of books: "))
    for i in range(n):
        book_name = input(f"Enter the name of book {i + 1}: ")
        cost = float(input(f"Enter the cost of book {book_name}: "))
        books.append([book_name, cost])

    while True:
        print("\nMenu:")
        print("1. Delete duplicate entries")
        print("2. Display books in ascending order based on cost")
        print("3. Count number of books with cost more than 500")
        print("4. Copy books with cost less than 500 to a new list")
        print("5. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            books = delete_duplicates(books)
            print("Duplicate entries deleted.")
        elif choice == 2:
            sorted_books = display_books_in_ascending_order(books)
            print("Books in ascending order based on cost:")
            for book in sorted_books:
                print(f"{book[0]} - ${book[1]}")
        elif choice == 3:
            count = count_books_cost_more_than_500(books)
            print(f"Number of books with cost more than 500: {count}")
        elif choice == 4:
            less_than_500_books = copy_books_cost_less_than_500(books)
            print("Books with cost less than 500:")
            for book in less_than_500_books:
                print(f"{book[0]} - ${book[1]}")
        elif choice == 5:
            print("Exiting the program. Goodbye!")
            break
        else:
            print("Invalid choice. Please enter a valid option.")

if __name__ == "__main__":
    main()
