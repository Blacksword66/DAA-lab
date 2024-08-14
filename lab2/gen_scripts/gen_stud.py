num = int(input("Enter the number of students"))

filename = f"/Users/yeyatiprasher/College_stuff/DAA/lab2/students{num}.txt"

with open(filename,"w") as f:
    for i in range(num):
        f.write(f"{i+1}\n")
