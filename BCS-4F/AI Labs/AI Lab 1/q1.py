name = input("Enter Student Name: ")
marks = float(input("Enter Marks: "))

print("Student Name: " + name)
print("Marks: " + str(marks))

if 85 <= marks <= 100:
    print("Grade: A")
elif 70 <= marks <= 85:
    print("Grade: B")
elif 50 <= marks <= 70:
    print("Grade: C")
elif 0 <= marks <= 50:
    print("Grade: Fail")
else:
    print("Invalid Input")

