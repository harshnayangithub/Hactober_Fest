def generate_magic_square(n):
    magic_square = [[0] * n for _ in range(n)]

    i, j = 0, n // 2
    current_number = 1

    while current_number <= n**2:
        magic_square[i][j] = current_number
        current_number += 1
        i -= 1
        j += 1

        if i < 0 and j >= n:
            i += 2
            j -= 1
        elif i < 0:
            i = n - 1
        elif j >= n:
            j = 0

        if magic_square[i][j] != 0:
            i += 2
            j -= 1

    return magic_square

def print_magic_square(square):
    for row in square:
       print(row)

def print_sums(square):
    n = len(square)
    main_diag_sum = sum(square[i][i] for i in range(n))

   
    print(f"Main Diagonal Sum: {main_diag_sum}")

while True:
    print("\n------ Menu ------")
    print("1. Generate Magic Square")
    print("2. Exit")

    choice = input("Enter your choice (1-2): ")

    if choice == '1':
        # Input for n from the user
        n = int(input("Enter the value of n: "))
        if n % 2 == 0:
            print("Please enter an odd value for n.")
        else:
            magic_square_n = generate_magic_square(n)
            print(f"\nMagic Square for n={n}:")
            print_magic_square(magic_square_n)
            print_sums(magic_square_n)
    elif choice == '2':
        print("Exiting the program. Goodbye!")
        break
    else:
        print("Invalid choice. Please enter a number between 1 and 2.")
1