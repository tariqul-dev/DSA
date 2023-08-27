class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, data):
        node = Node(data)
        if not self.head:
            self.head = node
        else:
            self.tail.next = node

        self.tail = node

    def insert_using_head(self, data):
        node = Node(data)
        if self.head:
            temp = self.head

            while temp.next:
                temp = temp.next

            temp.next = node

        else:
            self.head = node

    def insert_node_at_head(self, data):
        node = Node(data)

        node.next = self.head
        self.head = node

    def insert_at_position(self, data, position):
        if self.head:
            p = position - 1
            count = 0
            node = Node(data)
            temp = self.head

            if p < 0:
                node.next = self.head
                self.head = node
                return

            while temp.next:
                if count == p:
                    break
                count += 1
                temp = temp.next

            node.next = temp.next
            temp.next = node

            #
            # prev_data = temp
            # temp = Node(data)
            # temp.next = prev_data
            # prev_data.next = temp

            # print(temp.data)
            # print(f'temp: {prev_data.data}')

    def print_head(self):
        if self.head:
            temp = self.head

            while temp:
                print(temp.data)
                temp = temp.next


ls = LinkedList()

# ls.insert(4)
# ls.insert(1)
# ls.insert(2)
# ls.insert(5)
#
# ls.print_head()

ls.insert_using_head(10)
ls.insert_using_head(11)
ls.insert_using_head(12)

ls.insert_node_at_head(5)
ls.insert_node_at_head(6)

ls.insert_at_position(99, 6)

ls.print_head()
