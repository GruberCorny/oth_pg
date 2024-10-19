zahl = 120
array = [True] * zahl
for i in range(2, zahl):
    if array[i] == True:
        for j in range(i+i, zahl, i):
            array[j] = False

for i in range(1,zahl):
    if array[i] == True:
        print(i)