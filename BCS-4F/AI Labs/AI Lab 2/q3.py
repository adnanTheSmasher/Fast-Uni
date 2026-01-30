class Student:
    def __init__(self, name, marks):
        self.name = name
        self.__marks = marks

    def set_marks(self, marks):
        self.__marks = marks

    def get_marks(self):
        return self.__marks

    def calculate_grade(self):
        if 85 <= self.__marks <= 100:
            return "A"
        elif 70 <= self.__marks < 85:
            return "B"
        elif 50 <= self.__marks < 70:
            return "C"
        elif 0 <= self.__marks < 50:
            return "Fail"

s1 = Student("Jhethalal", 100)
s2 = Student("Tipendra", 49)

grade1 = s1.calculate_grade()
grade2 = s2.calculate_grade()

print(f"Grade of {s1.name}: {grade1}")
print(f"Grade of {s2.name}: {grade2}")
