n=int(input("Input size"))
fp = open("descending_"+str(n)+".txt","w") 
fp.write(str(n)+" ")
# descending_10000.txt
for i in range(n,1,-1): # n = 10000, 9999, 9998, ---- 1 
    fp.write(str(i)+" ")
fp.write(str(1))
fp.close()
