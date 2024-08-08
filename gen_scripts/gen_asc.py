n = int(input("Input size"))
fp = open("ascending_"+str(n)+".txt","w")

#fp.write(str(n)+" ")
for i in range(1,n): # 1 to n-1
#ascending_60000.txt
    fp.write(str(i)+" ") # 1 2 3 4 ... 10 11 12 
fp.write(str(n))
fp.close()
