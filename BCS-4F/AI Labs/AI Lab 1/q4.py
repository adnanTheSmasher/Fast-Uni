print("1. Add two Numbers")
print("2. Subtract two Numbers")
print("3. Exit")

loopOn = True
while loopOn:
    choice = input("Enter your choice: ")
    if choice == "1":
        num1 = int(input("Enter first number: "))
        num2 = int(input("Enter second number: "))
        print(f"Result: {num1 + num2}")
    elif choice == "2":
        num1 = int(input("Enter first number: "))
        num2 = int(input("Enter second number: "))
        print(f"Result: {num1 - num2}")
    else:
        loopOn = False
