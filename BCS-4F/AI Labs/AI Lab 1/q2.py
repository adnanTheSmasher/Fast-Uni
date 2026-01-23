num = int(input("Enter a number: "))

start = 1
end = num + 1
count = 0

print("Even Numbers: ", end="")

for i in range(start, end):
    if i%2 == 0:
        print(i, end=" ")
        count += 1
print()
print("Total even Numbers: " + str(count))