import copy

# need to complete 
def round_robin(queue, time_quantum):
    queue.sort(key=lambda x:x[1])
    time = queue[0][1]
    wait = []
    tat = []
    complete = []
    temp_queue = []
    finished = []
    for process in queue: process.append(process[2])
    temp_queue.append(queue.pop(0))
    while queue or temp_queue:
        #print("time", time)
        #print("queue", queue)
        #print("temp", temp_queue)
        if temp_queue:
            process = temp_queue.pop(0)
            #print("get from temp queue ", process[0])
        else:
            process = queue.pop(0)
        if time_quantum >= process[3]:
            time += process[3]
            process[3] = 0
            finished.append(process)
            complete.append(time)
        else:
            time += time_quantum
            process[3] -= time_quantum
            while queue:
                if queue[0][1] <= time:
                    temp_queue.append(queue.pop(0))
                else: break
            temp_queue.append(process)
        """if queue == []:
            queue = copy.deepcopy(temp_queue)
            temp_queue = []"""
        """while queue:
            if queue[0][1] == time:
                temp_queue.append(queue.pop(0))
                
            else: break"""
    for i in range(len(finished)):
        tat.append(complete[i] - finished[i][1])
        wait.append(tat[i] - finished[i][2])
        
    print("process arrival burst complete wait \ttat")
    for i in range(len(finished)):
        print(finished[i][0], '\t', finished[i][1], '\t', finished[i][2],
              '\t', complete[i], '\t', wait[i], '\t', tat[i])
    

    print("No of process is ", len(finished))
    print("average wati time is ", sum(wait)/len(wait))
    print("average tat is ", sum(tat)/len(tat))


#round_robin([[1,0,4],[2,1,5],[3,2,2],[4,3,1],[5,4,6],[6,6,3]], 2)
n = int(input("Enter the no of process: "))
time_quantum = int(input("Enter the time quentum: "))
process = []
print("enter in order: processNo  arrivalTime BurstTime")
for i in range(n):
    a = list(map(int, input().split(' ')))
    process.append(a)
round_robin(process, time_quantum)
    
