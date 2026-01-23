listOfDicts = []

for i in range(3):
    name = input("Enter Student name: ")
    marks = float(input("Enter Marks: "))
    studentDict = {"name": name, "marks": marks}
    listOfDicts.append(studentDict)

print("\nStudent Records: ")

for student in listOfDicts:
    print(f"{student["name"]}: {student['marks']}")