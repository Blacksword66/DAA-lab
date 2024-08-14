import random

def generate_employee_data(num_employees):
    employees = []
    start = 1001
    sal = 1200000.0
    for i in range(num_employees):
        # Generate random employee ID and salary
        employee_id = start+i
        salary = sal - i
        employees.append((employee_id, salary))
    return employees

def write_to_file(filename, employees):
    with open(filename, 'w') as file:
        for emp in employees:
            file.write(f"{emp[0]} {emp[1]}\n")

def main():
    order = "desc"
    num_employees = int(input("Enter the number of employees"))    
    filename = f"/Users/yeyatiprasher/College_stuff/DAA/lab2/{order}_employees{num_employees}.txt"

    employees = generate_employee_data(num_employees)
    write_to_file(filename, employees)

    print(f"{filename} created with {num_employees} employees.")

if __name__ == "__main__":
    main()
