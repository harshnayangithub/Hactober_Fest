def deposit(balance, amount):
    return balance + amount


def withdraw(balance, amount):
    if balance >= amount:
        return balance - amount
    else:
        print("Withdrawal not allowed. Insufficient balance.")
        return balance


# def main():
balance = 0

while True:
    print("\n------ Menu ------")
    print("1. Deposit")
    print("2. Withdraw")
    print("3. View Balance")
    print("4. Exit")

    choice = int(input("Enter your choice (1-4): "))

    if choice == 1:
        amount = float(input("Enter the deposit amount: "))
        # this is important you are always updating the balance
        balance = deposit(balance, amount)
        print(f"Deposit of {amount} successful. Updated balance: {balance}")

    elif choice == 2:
        amount = float(input("Enter the withdrawal amount: "))
        # this is important you are always updating the balance
        balance = withdraw(balance, amount)
        print(f"Withdrawal of {amount}. Updated balance: {balance}")

    elif choice == 3:
        print("Current Balance: ", balance)

    elif choice == 4:
        print("Exiting the program. Goodbye!")
        break

    else:
        print("Invalid choice. Please enter a number between 1 and 4.")

# if __name__ == "__main__":
   # main()
