import random
n = int(input("Input Size"))
fp = open("random_"+str(n)+".txt","w") 
fp.write(str(n)+" ")
for i in range(1,n):
    x = random.random()
    fp.write(str(int(x*n))+" ")
x = random.random()
fp.write(str(int(x*n))+" ")
fp.close()
