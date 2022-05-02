def cal(exe_time, start_quantum, increment):
    interrupt = 0
    queue = 1
    while exe_time:
        if exe_time > start_quantum:
            exe_time -= start_quantum
            start_quantum += increment
            interrupt += 1
            queue += 1
        else:
            exe_time = 0

    print("No of time interrupted is ", interrupt)
    print("process terminate at ", queue)

cal(40, 2, 5)


