def longest_word(string):
    words = string.split()
    longest = max(words, key=len)
    return longest

def char_frequency(string, char):
    return string.count(char)

def is_palindrome(string):
    return string == string[::-1]

def first_appearance(string, substring):
    return string.find(substring)

def word_occurrences(string):
    words = string.split()
    word_count = {}
    for word in words:
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1
    return word_count

def main():
    user_string = input("Enter a string: ")

    while True:
        print("\nMenu:")
        print("1. Display word with the longest length")
        print("2. Determine frequency of a particular character")
        print("3. Check if the string is a palindrome")
        print("4. Display index of first appearance of a substring")
        print("5. Count occurrences of each word")
        print("6. Exit")

        choice = input("Enter your choice (1-6): ")

        if choice == '1':
            longest = longest_word(user_string)
            print(f"The longest word in the string is: {longest}")
        elif choice == '2':
            char = input("Enter a character: ")
            frequency = char_frequency(user_string, char)
            print(f"The frequency of '{char}' in the string is: {frequency}")
        elif choice == '3':
            palindrome = is_palindrome(user_string)
            if palindrome:
                print("The string is a palindrome.")
            else:
                print("The string is not a palindrome.")
        elif choice == '4':
            substring = input("Enter a substring: ")
            index = first_appearance(user_string, substring)
            if index != -1:
                print(f"The substring '{substring}' first appears at index: {index}")
            else:
                print("Substring not found in the string.")
        elif choice == '5':
            word_counts = word_occurrences(user_string)
            print("Occurrences of each word:")
            for word, count in word_counts.items():
                print(f"'{word}': {count}")
        elif choice == '6':
            print("Exiting program...")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 6.")

if __name__ == "__main__":
    main()
