def calculate_average(listOfMarks):
    sumMarks = 0
    for mark in listOfMarks:
        sumMarks += mark
    print(f"Average marks: {sumMarks / len(listOfMarks)}")

def main():
    listOfMarks = [70, 80, 90]
    calculate_average(listOfMarks)


main()