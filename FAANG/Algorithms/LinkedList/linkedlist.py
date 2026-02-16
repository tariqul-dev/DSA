class Node:
    def __init__(self, value, next = None):
        self.value = value
        self.next = next

class LinkedList:
    def __init__(self):
        self._head = None
    
    def __iter__(self):
        head = self._head
        while head:
            yield head.value
            head = head.next
    
    def __len__(self):
        count = 0
        head = self._head
        while head:
            count += 1
            head = head.next
        return count
    
    def __getitem__(self, key):
        if isinstance(key, slice):
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
                if key == index:
                    return value
            raise IndexError("Index out of range")
        
        raise TypeError("Invalid argument")


    def __contains(self, value):
        return any(item == value for item in self)

    def __repr__(self):
        # return f"[{', '.join(map(str, self))}]"
        return f"[{', '.join(str(x) for x in self)}]"
    


    def append(self, value):
        if not self._head:
            self._head = Node(value)
            return
        temp = self._head

        while temp.next:
            temp = temp.next
        
        temp.next = Node(value)

    def insert(self, index, value):
        if index < 0:
            raise IndexError("Negative index is not allowed")
        
        newNode = Node(value)
        
        if index == 0:
            newNode.next = self._head
            self._head = newNode
            return

        count = 0
        current = self._head

        while count < index - 1 and current:
            count += 1
            current = current.next
        
        if current is None:
            raise IndexError("Index out of range")

        newNode.next = current.next
        current.next = newNode

    def middleValue(self):
        head = self._head
        if not head:
            return
        
        slow = head
        fast = slow.next

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        return slow.value

    
ls = LinkedList()

for x in range(10):
    ls.append(x)

print(ls)

ls.insert(1, 100)
print(ls)

