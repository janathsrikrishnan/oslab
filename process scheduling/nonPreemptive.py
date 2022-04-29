def fcfs(queue):
    print("first in first serve")
    queue.sort(key = lambda x : x[1])
    complete = []
    wait = []
    tat = []
    time = queue[0][1]
    for process in queue:
    
        time+= process[2]
        complete.append(time)
        
    for i in range(len(queue)):
        tat.append(complete[i] - queue[i][1])
        wait.append(tat[i] - queue[i][2])
    print("process  arrival burst complete wait \t tat")
    for i in range(len(queue)):
        print(queue[i][0],'\t', queue[i][1],'\t', queue[i][2],'\t', complete[i],'\t', wait[i],'\t', tat[i])

    print("No of process is ", len(queue))
    print("average wait time is ", sum(wait)/len(wait))
    print("average tat is ", sum(tat)/len(tat))


def sjf(queue):
    print("short job first")
    queue.sort(key = lambda x : (x[1], x[2]))
    complete = []
    wait = []
    tat = []
    time = queue[0][1]
    final =[]
    while(queue):
        process = queue.pop(0)
        time+= process[2]
        complete.append(time)
        final.append(process)
        queue.sort(key = lambda x: (x[2],x[1]))
    for i in range(len(final)):
        tat.append(complete[i] - final[i][1])
        wait.append(tat[i] - final[i][2])
    print("process  arrival burst complete wait \t tat")
    for i in range(len(final)):
        print(final[i][0],'\t', final[i][1],'\t', final[i][2],'\t', complete[i],'\t', wait[i],'\t', tat[i])

    print("No of process is ", len(final))
    print("average wait time is ", sum(wait)/len(wait))
    print("average tat is ", sum(tat)/len(tat))

def priority(queue):
    print("priority scheduling")
    queue.sort(key = lambda x : (x[1], x[3]))
    complete = []
    wait = []
    tat = []
    time = queue[0][1]
    final =[]
    while(queue):
        process = queue.pop(0)
        time+= process[2]
        complete.append(time)
        final.append(process)
        queue.sort(key = lambda x: (x[3],x[1]))
    for i in range(len(final)):
        tat.append(complete[i] - final[i][1])
        wait.append(tat[i] - final[i][2])
    print("process  arrival burst priority complete wait \t tat")
    for i in range(len(final)):
        print(final[i][0],'\t', final[i][1],'\t', final[i][2],'\t', final[i][3],'\t', complete[i],'\t', wait[i],'\t', tat[i])

    print("No of process is ", len(final))
    print("average wait time is ", sum(wait)/len(wait))
    print("average tat is ", sum(tat)/len(tat))


fcfs([[1, 0, 15],[2,1,3], [3, 2,3]])
sjf([[1, 0, 15],[2,0,3], [3, 1,3]])
priority([[1, 0, 3, 0],[2, 0, 4, 2], [3, 1, 3, 1]])
