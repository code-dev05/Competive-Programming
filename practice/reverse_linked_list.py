class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def print_list(head):
    temp = head
    while temp != None:
        print(temp.val, end=' ')
        temp = temp.next

head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)

def reverse_linked_list(head):
    cur = head
    prev = None
    while cur != None:
        tmp_next = cur.next
        cur.next = prev
        prev = cur
        cur = tmp_next
    return prev


print_list(reverse_linked_list(head))