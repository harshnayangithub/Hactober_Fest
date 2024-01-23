def quick_sort(scores):
    def partition(arr, low, high):
        pivot = arr[high]
        i = low - 1
        for j in range(low, high):
            if arr[j] < pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1

    def sort(arr, low, high):
        if low < high:
            pi = partition(arr, low, high)
            sort(arr, low, pi - 1)
            sort(arr, pi + 1, high)

    sort(scores, 0, len(scores) - 1)

def shell_sort(scores):
    n = len(scores)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = scores[i]
            j = i
            while j >= gap and scores[j - gap] > temp:
                scores[j] = scores[j - gap]
                j -= gap
            scores[j] = temp
        gap //= 2

def display_top_scores(scores, n):
    top_scores = sorted(scores)[-n:]
    print(f"Top {n} scores:")
    print(top_scores)

def main():
    scores = []
    while True:
        print("\nMenu:")
        print("1. Add Student Percentage")
        print("2. Sort using Quick Sort & Display top 5 scores")
        print("3. Sort using Shell Sort & Display top 5 scores")
        print("4. Exit")

        choice = input("Enter your choice (1-4): ")

        if choice == '1':
            percentage = float(input("Enter the percentage: "))
            scores.append(percentage)
        elif choice == '2':
            quick_sort(scores)
            display_top_scores(scores, 5)
        elif choice == '3':
            shell_sort(scores)
            display_top_scores(scores, 5)
        elif choice == '4':
            print("Exiting program...")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 4.")

if __name__ == "__main__":
    main()
