class Node:
    def __init__(self, number, next = None):
        self.number = number
        self.next = next


class LinkedList:
    def __init__(self):
        self.head = None
    
    def append(self, number):
        if self.head == None:
            self.head = Node(number)
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        
        temp.next = Node(number)

    def __iter__(self):
        current = self.head
        while current:
            yield current.number
            current = current.next

    def __len__(self):
        count = 0
        current = self.head

        while current:
            count += 1
            current = current.next

        return count 

    def __getitem__(self, key):
        if isinstance(key, slice):
            print(key.indices(len(self)))
            start, stop, step = key.indices(len(self))
            result = []

            for index, value in enumerate(self):
                 if index >= start and index < stop and (index - start) % step == 0:
                     result.append(value)
            return result

        if isinstance(key, int):
            if key < 0:
                key += len(self)
            
            for index, value in enumerate(self):
                if index == key:
                    return value
            
            raise IndexError("Index out of range")
        
        raise TypeError("Invalid argument")


    def __repr__(self):
        return f"[{', '.join(str(x) for x in self)}]"
    
    def __contains__(self, value):
        return any(item == value for item in self)


ls = LinkedList()

for x in range(10):
    ls.append(x)

print(ls[1:6:2])

rt = reversed(ls)
for x in rt:
    print(x)

print()
print(ls)
print(tuple(ls))