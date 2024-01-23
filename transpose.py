def display_matrix(matrix):
    for row in matrix:
        print(*row)


def transpose_matrix(matrix):
    transposed = [[matrix[j][i]
                   for j in range(len(matrix))] for i in range(len(matrix[0]))]
    return transposed


def fast_transpose(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    transpose = [[0 for _ in range(rows)] for _ in range(cols)]
    for i in range(rows):
        for j in range(cols):
            transpose[j][i] = matrix[i][j]
    return transpose


def add_matrices(matrix1, matrix2):
    if len(matrix1) != len(matrix2) or len(matrix1[0]) != len(matrix2[0]):
        return "Matrices have different dimensions and cannot be added."
    result = [[matrix1[i][j] + matrix2[i][j]
               for j in range(len(matrix1[0]))] for i in range(len(matrix1))]
    return result


def create_sparse_matrix():
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))
    sparse_matrix = []
    for i in range(rows):
        # most most most important....
        row = list(map(int, input(f"Enter values for row {i+1} separated by space: ").split()))
        sparse_matrix.append(row)
    return sparse_matrix


def main():
    print("Create Sparse Matrix 1:")
    sparse_matrix1 = create_sparse_matrix()
    sparse_matrix2 = []
    while True:
        print("\nMenu:")
        print("1. Display Sparse Matrix")
        print("2. Transpose of Sparse Matrix")
        print("3. Fast Transpose of Sparse Matrix")
        print("4. Add two Sparse Matrices")
        print("5. Create Sparse Matrix 2")
        print("6. Exit")
        choice = input("Enter your choice (1-6): ")
        if choice == '1':
            print("Sparse Matrix 1:")
            display_matrix(sparse_matrix1)
        elif choice == '2':
            transpose = transpose_matrix(sparse_matrix1)
            print("Transpose of Sparse Matrix 1:")
            display_matrix(transpose)
        elif choice == '3':
            fast_transposed = fast_transpose(sparse_matrix1)
            print("Fast Transpose of Sparse Matrix 1:")
            display_matrix(fast_transposed)
        elif choice == '4':
            if not sparse_matrix2:
                print("Please create Sparse Matrix 2 first.")
            else:
                result = add_matrices(sparse_matrix1, sparse_matrix2)
                if isinstance(result, str):
                    print(result)
                else:
                    print("Resultant Sparse Matrix after addition:")
                    display_matrix(result)
        elif choice == '5':
            print("Creating Sparse Matrix 2:")
            sparse_matrix2 = create_sparse_matrix()
        elif choice == '6':
            print("Exiting program...")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 6.")


if __name__ == "__main__":
    main()
