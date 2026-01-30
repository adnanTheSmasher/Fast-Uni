class Employee:
    def __init__(self, name, emp_id):
        self.name = name
        self.emp_id = emp_id


class FullTimeEmployee(Employee):
    def __init__(self, name, emp_id, monthly_salary):
        super().__init__(name, emp_id)
        self.monthly_salary = monthly_salary

    def calculate_salary(self):
        return self.monthly_salary * 12

class PartTImeEmpoyee(Employee):
    def __init__(self, name, emp_id, hours_worked, hourly_rate):
        super().__init__(name, emp_id)
        self.hours_worked = hours_worked
        self.hourly_rate = hourly_rate

    def calculate_salary(self):
        return self.hours_worked * self.hourly_rate

fullTimeEmployee = FullTimeEmployee('Jhethlal', 1200, 45000)
partTimeEmployee = PartTImeEmpoyee('Tipendra', 1400, 48, 200)

fSalary = fullTimeEmployee.calculate_salary()
pSalary = partTimeEmployee.calculate_salary()

print(f"Total Salary of {fullTimeEmployee.name} is {fSalary}.....")
print(f"Total Salary of {partTimeEmployee.name} is {pSalary}.....")

