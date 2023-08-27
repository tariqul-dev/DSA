class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

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


    def print_list(self):
        temp = self.head
        while temp:
            print(temp.data, end=' ')
            temp = temp.next

        print()

    def delete_at_position(self, position):
        count = 0
        temp = self.head
        if position == count:
            self.head = self.head.next
            return

        while temp.next:
            if count == position - 1:
                break
            temp = temp.next
            count += 1

        if temp.next.next:
            del_node = temp.next
            temp.next = temp.next.next
            del del_node
        else:
            del_node = temp.next
            del del_node
            temp.next = None

    def _print_reverse(self, node):
        if node:
            self._print_reverse(node.next)
            print(node.data, end=' ')

    def print_reverse(self):
        self._print_reverse(self.head)

    def _reverse_list(self, head):
        if not head or not head.next:
            return head

        new_head = self._reverse_list(head.next)
        head.next.next = head
        head.next = None

        return new_head

    def reverse_list(self):
        self.head = self._reverse_list(self.head)


if __name__ == '__main__':
    ls = LinkedList()
    ls.insert(3)
    ls.insert(5)
    ls.insert(7)
    ls.insert(1)
    ls.insert(2)

    ls.print_list()
    ls.delete_at_position(0)
    ls.print_list()

    ls.reverse_list()

    ls.print_list()
