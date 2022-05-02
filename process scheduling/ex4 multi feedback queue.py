#multi feedback queue

def MultiFeedBack(queue, _time):
    print("Multi Feedback scheduling algorithm")
    time_quantum1, time_quantum2 = _time

    queue.sort(key = lambda x: x[1])

    time = queue[0][1]
    wait = []
    complete = []
    queue_1 = []  # round robin 1
    queue_2 = []  # round robin 2
    queue_3 = []  # fcfs
    tat = []
    finished = []
    
    for process in queue: process.append(process[2])
    #queue_1.append(queue.pop(0))
    while True:
        if queue and time >= queue[0][1]:
            process = queue.pop(0)
            if time_quantum1 >= process[3]:
                time += process[2]
                finished.append(process[:3])
                complete.append(time)
            else:
                time += time_quantum1
                process[3] -= time_quantum1
                queue_2.append(process)

        elif queue_2:
            process = queue_2.pop(0)
            if time_quantum2 >= process[3]:
                time += process[3]
                finished.append(process[:3])
                complete.append(time)
            else:
                time += time_quantum2
                process[3] -= time_quantum2
                queue_3.append(process)

        elif queue_3:
            process = queue_3.pop(0)
            time += process[3]
            finished.append(process)
            complete.append(time)

        else: break
    
    for i in range(len(finished)):
        tat.append(complete[i] - finished[i][1])
        wait.append(tat[i] - finished[i][2])

    print("process arrival burst complete wait \ttat")
    for i in range(len(finished)):
        print(finished[i][0], '\t', finished[i][1], '\t', finished[i][2],
              '\t', complete[i], '\t', wait[i], '\t', tat[i])

    print("No of process ", len(finished))
    print("Average wait time ", sum(wait)/len(wait))
    print("average tat is ", sum(tat)/len(tat))


#MultiFeedBack([[1,0,12],[2,5,45],[3,24,3],[4,30, 22],[5,33,32],[6,40,15]], [8,12])

n = int(input("Enter the no of process: "))
time = list(map(int, input("Enter the time quantume for queue 1 and 2: ").split(' ')))
process = []
print("Enter in order: processNO arrival burst")
for i in range(n):
    a = list(map(int, input().split(' ')))
    process.append(a)
MultiFeedBack(process, time)
