def selection_sort(scores):
    n = len(scores)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if scores[j] < scores[min_index]:
                min_index = j
        scores[i], scores[min_index] = scores[min_index], scores[i]

def bubble_sort(scores):
    n = len(scores)
    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if scores[j] > scores[j + 1]:
                scores[j], scores[j + 1] = scores[j + 1], scores[j]

def insertion_sort(scores):
    n = len(scores)
    for i in range(1, n):
        key = scores[i]
        j = i - 1
        while j >= 0 and key < scores[j]:
            scores[j + 1] = scores[j]
            j -= 1
        scores[j + 1] = key

def display_top_scores(scores, n):
    top_scores = sorted(scores)[-n:]
    print(f"Top {n} scores:")
    print(top_scores)

def main():
    scores = []
    while True:
        print("\nMenu:")
        print("1. Add Student Percentage")
        print("2. Sort using Selection Sort & Display top 5 scores")
        print("3. Sort using Bubble Sort & Display top 5 scores")
        print("4. Sort using Insertion Sort & Display top 5 scores")
        print("5. Exit")

        choice = input("Enter your choice (1-5): ")

        if choice == '1':
            percentage = float(input("Enter the percentage: "))
            scores.append(percentage)
        elif choice == '2':
            selection_sort(scores)
            display_top_scores(scores, 5)
        elif choice == '3':
            bubble_sort(scores)
            display_top_scores(scores, 5)
        elif choice == '4':
            insertion_sort(scores)
            display_top_scores(scores, 5)
        elif choice == '5':
            print("Exiting program...")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 5.")

if __name__ == "__main__":
    main()
