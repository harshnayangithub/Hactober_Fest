def intersection(list1, list2):
    result = []
    for element in list1:
        if element in list2:
            result.append(element)
    return result

def difference(list1, list2):
    result = []
    for element in list1:
        if element not in list2:
            result.append(element)
    for element in list2:
        if element not in list1:
            result.append(element)
    return result

def students_playing_both_cricket_and_badminton(cricket_players, badminton_players):
    return intersection(cricket_players, badminton_players)

def students_playing_either_cricket_or_badminton_but_not_both(cricket_players, badminton_players):
    return difference(cricket_players, badminton_players)

def students_playing_neither_cricket_nor_badminton(total_students, cricket_players, badminton_players):
    cricket_or_badminton = cricket_players + badminton_players
    result = []
    for student in total_students:
        if student not in cricket_or_badminton:
            result.append(student)
    return result

def students_playing_cricket_and_football_but_not_badminton(cricket_players, football_players, badminton_players):
    cricket_and_football = []
    for student in cricket_players:
        if student in football_players and student not in badminton_players:
            cricket_and_football.append(student)
    return cricket_and_football

def main():
    total_students = []
    cricket_players = []
    badminton_players = []
    football_players = []

    total_count = int(input("Enter the total number of students: "))
    total_students = list(range(1, total_count + 1))

    print("Enter student numbers playing cricket (separated by space):")
    cricket_players = list(map(int, input().split()))

    print("Enter student numbers playing badminton (separated by space):")
    badminton_players = list(map(int, input().split()))

    print("Enter student numbers playing football (separated by space):")
    football_players = list(map(int, input().split()))

    while True:
        print("\nMenu:")
        print("1. List of students who play both cricket and badminton")
        print("2. List of students who play either cricket or badminton but not both")
        print("3. Number of students who play neither cricket nor badminton")
        print("4. Number of students who play cricket and football but not badminton")
        print("5. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            print("Students who play both cricket and badminton:", students_playing_both_cricket_and_badminton(cricket_players, badminton_players))
        elif choice == 2:
            print("Students who play either cricket or badminton but not both:", students_playing_either_cricket_or_badminton_but_not_both(cricket_players, badminton_players))
        elif choice == 3:
            print("Number of students who play neither cricket nor badminton:", len(students_playing_neither_cricket_nor_badminton(total_students, cricket_players, badminton_players)))
        elif choice == 4:
            print("Students who play cricket and football but not badminton:", students_playing_cricket_and_football_but_not_badminton(cricket_players, football_players, badminton_players))
        elif choice == 5:
            print("Exiting the program. Goodbye!")
            break
        else:
            print("Invalid choice. Please enter a valid option.")

if __name__ == "__main__":
    main()
