def longest_word(s):
    words = s.split()
    return max(words, key=len)


def char_frequency(s, char):
    return s.count(char)


def is_palindrome(s):
    return s == s[::-1]


def first_appearance_index(s, substring):
    return s.find(substring)


def word_occurrences(s):
    words = s.split()
    word_count = {}
    for word in words:
        word_count[word] = word_count.get(word, 0) + 1
    return word_count


input_string = input("Enter a string: ")

while True:
    print("\n------ Menu ------")
    print("1. Display word with the longest length")
    print("2. Determine frequency of a particular character")
    print("3. Check whether the string is a palindrome")
    print("4. Display index of first appearance of substring")
    print("5. Count occurrences of each word")
    print("6. Exit")

    choice = int(input("Enter your choice (1-6): "))

    if choice == 1:
        result = longest_word(input_string)
        print("Word with the longest length: ", result)

    elif choice == 2:
        char_to_check = input("Enter a character to check its frequency: ")
        result = char_frequency(input_string, char_to_check)
        print("Frequency of", char_to_check, "in the string:", result)

    elif choice == 3:
        result = is_palindrome(input_string)
       # ans="NO"
        # if result==1:
      #      ans="YES"
        print("Is the string a palindrome?", result)

    elif choice == 4:
        substring_to_find = input("Enter a substring to find its index: ")
        result = first_appearance_index(input_string, substring_to_find)
        print("Index of the first appearance of ",
              substring_to_find, ":", result)

    elif choice == 5:
        result = word_occurrences(input_string)
        print("Occurrences of each word in the string:")
        print(result)

    elif choice == 6:
        print("Exiting the program. Goodbye!")
        break

    else:
        print("Invalid choice. Please enter a number between 1 and 6.")
