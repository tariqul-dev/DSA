def jobSequencing(jobs):
    jobs = sorted(jobs, key=lambda job: job[2], reverse=True)

    maxDeadline = 0
    for job in jobs:
        if job[1] > maxDeadline:
            maxDeadline = job[1]

    slots = []
    filledSlot = 0
    profit = 0

    for i in range(maxDeadline):
        slots.append(-1)

    for job in jobs:

        if filledSlot > maxDeadline:
            break

        if slots[job[1] - 1] == -1:
            slots[job[1] - 1] = job
            profit += job[2]
            filledSlot += 1

        else:
            for i in range(job[1] - 1, -1, -1):
                if slots[i] == -1:
                    slots[i] = job
                    profit += job[2]
                    filledSlot += 1
                    break

    return filledSlot, profit


if __name__ == '__main__':
    jobs = [
        (1, 2, 100), (2, 1, 19), (3, 2, 27),
        (4, 1, 25), (5, 1, 15)
    ]

    slottedJob, profit = jobSequencing(jobs)

    print(f'{slottedJob} {profit}')

# (3, 1, 40)
# (4, 1, 30)
# (1, 4, 20)
# (2, 1, 10)
