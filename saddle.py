def find_saddle_point(matrix):
    rows, cols = len(matrix), len(matrix[0])

    for i in range(rows):
        for j in range(cols):
            # Check if a[i][j] is the smallest value in row i
            if matrix[i][j] == min(matrix[i]):
                # Check if a[i][j] is the largest value in column j
                if matrix[i][j] == max(matrix[k][j] for k in range(rows)):
                    return i, j

    return None


def print_matrix(matrix):
    for row in matrix:
        print(row)


# Example usage:
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

while True:
    print("\n------ Menu ------")
    print("1. Enter a matrix")
    print("2. Find saddle point")
    print("3. Display matrix")
    print("4. Exit")

    choice = int(input("Enter your choice (1-4): "))

    if choice == 1:
        rows = int(input("Enter the number of rows: "))
        cols = int(input("Enter the number of columns: "))
        matrix = []
        for i in range(rows):
            row = list(
                map(int, input(f"Enter values for row {i+1} separated by space: ").split()))
            matrix.append(row)
    elif choice == 2:
        saddle_point = find_saddle_point(matrix)
        if saddle_point:
            print(f"Saddle point found at position: {saddle_point}")
        else:
            print("No saddle point found.")
    elif choice == 3:
        print("Matrix:")
        print_matrix(matrix)
    elif choice == 4:
        print("Exiting the program. Goodbye!")
        break
    else:
        print("Invalid choice. Please enter a number between 1 and 4.")
