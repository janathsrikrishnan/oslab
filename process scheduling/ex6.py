def cal(queue, io, burst, time_quantum):
    for process in queue:
        process.append(process[2]*io)
        process.append(process[2]*burst)
        process.append(process[2]*io)
        process.append(process[4])
    queue.sort(key = lambda x:x[3])
    time = cpu_wait = queue[0][3]
    print(time)
    temp_queue = []
    while True:
        if queue:
            process = queue.pop(0)
            if process[6] <= time_quantum:
                time += process[6]
                process[6] = 0
                temp_queue.append(process)
            else:
                time += time_quantum
                process[6] -= time_quantum
                queue.append(process)
        elif temp_queue:
            wait = max(i[5] for i in temp_queue)
            
            time+=wait
            cpu_wait+=wait
            break
    print("totol time:", time)
    print("cpu_free time: ",cpu_wait)
    print("percentage of cpu free time ", cpu_wait/time * 100, "%")

cal([[1,0,10],[2,0,15],[3,0,20]], 0.2, 0.6, 5)
