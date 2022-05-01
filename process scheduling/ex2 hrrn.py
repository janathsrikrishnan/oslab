def sort_process(time, x):
    if  time > x[1]:
        return ((-(abs(time - x[1]) + x[2])/x[2],x[1]))
    else:
        return (x[1], -(abs(time - x[1]) + x[2])/x[2])


def hrrn(queue):
    
    print("Highest response ratio Next scheduling")
    wait = []
    time = queue[0][1]
    queue.sort(key=lambda x:(x[1], -(abs(time - x[1]) + x[2])/x[2]))
    complete = []
    tat = []
    finished = []
    idle = [0]*len(queue)
    j = 0
    while queue:
        process = queue.pop(0)
        if time < process[1]:
            idle[j] = 1
            time = process[1]
        time += process[2]
        complete.append(time)
        finished.append(process)
        #for p in queue: p.append(time)
        #queue.sort(key=lambda x:(x[1],-(abs(time - x[1]) + x[2])/x[2]))
        queue.sort(key=lambda x: sort_process(time, x))
        j+=1

    for i in range(len(finished)):
        tat.append(complete[i] - finished[i][1])
        wait.append(tat[i] - finished[i][2])

        
    print("process arrival burst complete\t wait \t tat")
    for i in range(len(finished)):
        if (idle[i]): print("idle")
        print(finished[i][0],'\t', finished[i][1],'\t', finished[i][2],
              '\t', complete[i], '\t', wait[i], '\t', tat[i])

    print("No of process is ", len(wait))
    print("average wait time is ", sum(wait)/len(wait))
    print("average tat is ", sum(tat)/len(tat))

#hrrn([[1,0,3],[2,1,6],[3,4,4],[4,6,5],[5,8,2], [6, 21, 5]])

n = int(input("Enter the no of process: "))
process = []
print("Enter in order: process No, arrival time, burst time with space")
for i in range(n):
    a = list(map(int ,input().split(' ')))
    process.append(a)
hrrn(process)

