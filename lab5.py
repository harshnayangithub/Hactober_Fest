class Phonebook:
    def __init__(self):
        self.contacts = []

    def display_menu(self):
        print("Phonebook Menu:")
        print("1. Display Contacts")
        print("2. Search Contact (Binary Search - Recursive)")
        print("3. Search Contact (Binary Search - Non-Recursive)")
        print("4. Search Contact (Fibonacci Search)")
        print("5. Insert Contact")
        print("6. Exit")

    def display_contacts(self):
        if not self.contacts:
            print("Phonebook is empty.")
        else:
            print("Contacts:")
            for contact in self.contacts:
                print(contact)

    def binary_search_recursive(self, arr, target, low, high):
        if high >= low:
            mid = low + (high - low) // 2
            if arr[mid][0] == target:
                return mid
            elif arr[mid][0] > target:
                return self.binary_search_recursive(arr, target, low, mid - 1)
            else:
                return self.binary_search_recursive(arr, target, mid + 1, high)
        else:
            return -1

    def binary_search_iterative(self, arr, target):
        low = 0
        high = len(arr) - 1

        while low <= high:
            mid = low + (high - low) // 2
            if arr[mid][0] == target:
                return mid
            elif arr[mid][0] < target:
                low = mid + 1
            else:
                high = mid - 1
        return -1

    def fibonacci_search(self, arr, target):
        def find_fib(prev, curr, n):
            while curr < n:
                temp = curr
                curr = prev + curr
                prev = temp
            return prev

        n = len(arr)
        offset = -1
        prev = 0
        curr = 1

        while find_fib(prev, curr, n) > 1:
            index = min(offset + prev, n - 1)

            if arr[index][0] == target:
                return index
            elif arr[index][0] < target:
                prev = curr
                curr = prev + curr
                offset = index

            else:
                curr = prev
                prev = curr - prev

        if curr and arr[offset + 1][0] == target:
            return offset + 1
        return -1

    def search_contact(self, search_type):
        if not self.contacts:
            print("Phonebook is empty. Please add contacts first.")
            return

        name = input("Enter the name to search: ")
        sorted_contacts = sorted(self.contacts, key=lambda x: x[0])

        if search_type == 1:  # Binary Search - Recursive
            result = self.binary_search_recursive(sorted_contacts, name, 0, len(sorted_contacts) - 1)
        elif search_type == 2:  # Binary Search - Non-Recursive
            result = self.binary_search_iterative(sorted_contacts, name)
        else:  # Fibonacci Search
            result = self.fibonacci_search(sorted_contacts, name)

        if result != -1:
            print(f"Contact found: {sorted_contacts[result]}")
        else:
            print("Contact not found.")

    def insert_contact(self):
        name = input("Enter the name: ")
        number = input("Enter the mobile number: ")
        contact = (name, number)

        sorted_contacts = sorted(self.contacts, key=lambda x: x[0])

        if contact not in sorted_contacts:
            self.contacts.append(contact)
            self.contacts = sorted(self.contacts, key=lambda x: x[0])
            print("Contact inserted successfully.")
        else:
            print("Contact already exists in the phonebook.")

    def run_phonebook(self):
        while True:
            self.display_menu()
            choice = input("Enter your choice (1-6): ")

            if choice == '1':
                self.display_contacts()
            elif choice == '2':
                self.search_contact(1)
            elif choice == '3':
                self.search_contact(2)
            elif choice == '4':
                self.search_contact(3)
            elif choice == '5':
                self.insert_contact()
            elif choice == '6':
                print("Exiting phonebook.")
                break
            else:
                print("Invalid choice. Please enter a number between 1 and 6.")


if __name__ == "__main__":
    phonebook = Phonebook()
    phonebook.run_phonebook()
