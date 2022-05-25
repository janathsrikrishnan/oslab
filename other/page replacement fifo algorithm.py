#generate the random page reference
import random
import matplotlib.pyplot as plt
#d
n = int(input("Enter the size of page reference: "))
page_reference = []
for i in range(n):
    page_reference.append(random.randint(1,1000))


#print("random page reference are: ", *page_reference)

page_1 = [-1]
page_2 = [-1]*2
page_3 = [-1]*3
page_4 = [-1]*4
page_5 = [-1]*5

page_fault = [0]*5

for i in page_reference:
    if i not in page_1:
        page_fault[0]+=1
        page_1[0] = i

j = 0
for i in page_reference:
    if i not in page_2:
        page_fault[1]+=1
        page_2[j] = i
        j = (j+1)%2

j = 0
for i in page_reference:
    if i not in page_3:
        page_fault[2]+=1
        page_3[j] = i        
        j = (j+1)%3

j = 0
for i in page_reference:
    if i not in page_4:
        page_fault[3]+=1
        page_4[j] = i
        j = (j+1)%4

j = 0
for i in page_reference:
    if i not in page_5:
        page_fault[4]+=1
        page_5[j] = i
        j = (j+1)%5
        
print("page fault :", *page_fault)
x = [1,2,3,4,5]
plt.plot(x, page_fault)
plt.xlabel('no of frame')
plt.ylabel('no of page fault')
plt.show()
        
