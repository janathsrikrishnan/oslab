#banker algorithm

def bankerSafe(resourse, instances, queue):
    #need 
    for process in queue:
        need = []
        #allocated = [0]*resource
        for j in range(resourse):
            need.append(process[2][j] - process[1][j])
            instances[j]-=process[1][j]
        process.append(need)
    #print(instances)
    safe = []
    k = 0
    add = [False]*len(queue)
    while not all(add):
        if add[k]:
            k = (k+1)%len(queue)
        process = queue[k]
        if process[-1] <= instances:
            #print("process:", process[-1], "instances", instances)
            for res in range(resourse):
                instances[res] += process[1][res]
                add[k] = True
                #print(add)
            #print("instances", instances)
            safe.append(process)
        try:
            k = (k+1)%len(queue)
            #print(k)
        except:
            break
    for process in safe:
        print(process[0], end = " ")
    
    
#bankerSafe(3, [10, 5, 7], [['p0',[0,1,0],[7,5,3]], ['p1', [3,0,2],[3,2,2]], ['p2', [3,0,2],[9,0,2]], ['p3', [2,1,1],[2,2,2]], ['p4', [0,0,2], [4,3,3]]])

resourse = int(input("Enter the no of resource: "))
instance = list(map(int, input("Enter the instance of resourse: ").split(" ")))
pro = int(input("Enter the no of process: "))
process = []
for i in range(pro):
    a = input()
    b = list(map(int, input().split(" ")))
    c = list(map(int, input().split(" ")))
    process.append([a, b,c])
bankerSafe(resourse, instance, process)
