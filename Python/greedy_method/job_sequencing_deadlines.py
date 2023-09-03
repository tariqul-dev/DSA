class Job:
    def __init__(self, title, profit, deadline):
        self.title = title
        self.profit = profit
        self.deadline = deadline

    def __str__(self):
        return f'{self.title}\t{self.profit}\t{self.deadline}'


if __name__ == '__main__':
    # jobs = [
    #     Job('j1', 35, 3),
    #     Job('j2', 30, 4),
    #     Job('j3', 25, 4),
    #     Job('j4', 20, 2),
    #     Job('j5', 15, 3),
    #     Job('j6', 12, 1),
    #     Job('j7', 5, 2),
    # ]
    jobs = [
        Job('j1', 20, 2),
        Job('j2', 15, 2),
        Job('j3', 10, 1),
        Job('j4', 5, 3),
        Job('j5', 1, 3),
    ]
    jobs = sorted(jobs, key=lambda job: job.profit, reverse=True)

    maxDeadline = -99

    for job in jobs:
        if job.deadline > maxDeadline:
            maxDeadline = job.deadline

    slots = []

    for i in range(maxDeadline):
        slots.append(-1)

    filledSlot = 0
    maxProfit = 0

    for job in jobs:

        if filledSlot > maxDeadline:
            break

        if slots[job.deadline - 1] == -1:
            slots[job.deadline - 1] = job
            maxProfit += job.profit
        else:
            for i in range(job.deadline - 1, -1, -1):
                if slots[i] == -1:
                    slots[i] = job
                    maxProfit += job.profit
                    break
        filledSlot += 1

    for slot in slots:
        print(slot)

    print(maxProfit)
