def merge_lists(list_a, list_b):
    merged_list = sorted(list_a + list_b, key=lambda x: (x[2], x[1]))
    return merged_list


def display_list(student_list):

    print("PRN\tDOB")
    for student in student_list:
        print(f"{student[0]}\t{student[1]}/{student[2]}")


# def main():
list_se_comp_a = []  # List for SE Computer Division A
list_se_comp_b = []  # List for SE Computer Division B

while True:
    print("\n------ Menu ------")
    print("1. Add student to Division A")
    print("2. Add student to Division B")
    print("3. Merge and Display Lists")
    print("4. Exit")

    choice = input("Enter your choice (1-4): ")

    if choice == '1':
        prn = input("Enter PRN: ")
        dob_date = int(input("Enter Date of Birth (1-31): "))
        dob_month = int(input("Enter Month of Birth (1-12): "))

        if 1 <= dob_date <= 31 and 1 <= dob_month <= 12:
            # list can store any number of elements in it
            list_se_comp_a.append((prn, dob_date, dob_month))
            print("Student added to Division A.")
        else:
            print("Invalid date or month. Please enter valid values.")

    elif choice == '2':
        prn = input("Enter PRN: ")
        dob_date = int(input("Enter Date of Birth (1-31): "))
        dob_month = int(input("Enter Month of Birth (1-12): "))

        if 1 <= dob_date <= 31 and 1 <= dob_month <= 12:
            list_se_comp_b.append((prn, dob_date, dob_month))
            print("Student added to Division B.")
        else:
            print("Invalid date or month. Please enter valid values.")

    elif choice == '3':
        merged_list = merge_lists(list_se_comp_a, list_se_comp_b)
        print("Merged List:")
        display_list(merged_list)

    elif choice == '4':
        print("Exiting the program. Goodbye!")
        break

    else:
        print("Invalid choice. Please enter a number between 1 and 4.")

# if __name__ == "__main__":
 #   main()
