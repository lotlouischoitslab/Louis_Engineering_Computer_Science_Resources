from src.utils import SinglyLinkedList
from src.utils import DoublyLinkedList

''' 
Linked Lists
Author: Louis Sungwoo Cho
Date Created: 1/10/2023
'''


def main():
    print('Singly Linked Lists')
    ll = SinglyLinkedList()
    ll.insert_values(["banana","mango","grapes","orange"])
    ll.print()
    ll.insert_after_value("mango","apple")
    ll.print()
    ll.remove_by_value("orange")
    ll.print()
    ll.remove_by_value("figs")
    ll.print()
    ll.remove_by_value("banana")
    ll.remove_by_value("mango")
    ll.remove_by_value("apple")
    ll.remove_by_value("grapes")
    ll.print()


    print('Doubly Linked Lists')
    l2 = DoublyLinkedList()
    l2.insert_values(["banana","mango","grapes","orange"])
    l2.print_forward()
    l2.print_backward()
    l2.insert_at_end("figs")
    l2.print_forward()
    l2.insert_at(0,"jackfruit")
    l2.print_forward()
    l2.insert_at(6,"dates")
    l2.print_forward()
    l2.insert_at(2,"kiwi")
    l2.print_forward()

if __name__ == '__main__':
    main()