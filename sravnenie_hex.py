f1 = open("1.hex", "rb")
f2 = open("2.hex","rb")
list_f1 = f1.readlines()
list_f2 = f2.readlines()
for  i in range(len(list_f1)):
    if list_f1[i] != list_f2[i]:
        print("Номер строки где отличаются hex файлы", end=" ")
        print(i+1)
        print(list_f1[i])
        print(list_f2[i])
