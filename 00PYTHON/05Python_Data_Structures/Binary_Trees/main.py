'''
Binary Search Trees (BST)
Author: Louis Sungwoo Cho
Date Created: 1/10/2023
'''
from src.utils import BinarySearchTree

def main():
    print('Binary Search Trees')

    numbers = [15,12,7,14,27,20,23,88]
    
    louis_tree = BinarySearchTree()
    louis_tree = louis_tree.build_tree(numbers)
    print("Input numbers:",numbers)
    print('Height:',louis_tree.height(louis_tree))
    print("Max:",louis_tree.max_val())
    print("Min:",louis_tree.min_val())
    print("Sum:", louis_tree.total())
    print("Level order traversal:", louis_tree.level_order_bfs())
    print("Pre-order traversal:", louis_tree.pre_order_dfs())
    print("In-order traversal:", louis_tree.in_order_dfs())
    print("Post order traversal:", louis_tree.post_order_dfs())



    #Delete Function Testing
    numbers_tree = BinarySearchTree()
    numbers_tree = numbers_tree.build_tree([17, 4, 1, 20, 9, 23, 18, 34])
    numbers_tree.delete_child(20)
    print("After deleting 20 ",numbers_tree.in_order_dfs()) # this should print [1, 4, 9, 17, 18, 23, 34]

    numbers_tree = numbers_tree.build_tree([17, 4, 1, 20, 9, 23, 18, 34])
    numbers_tree.delete_child(9)
    print("After deleting 9 ",numbers_tree.in_order_dfs())  # this should print [1, 4, 17, 18, 20, 23, 34]

    numbers_tree = numbers_tree.build_tree([17, 4, 1, 20, 9, 23, 18, 34])
    numbers_tree.delete_child(17)
    print("After deleting 17 ",numbers_tree.in_order_dfs())  # this should print [1, 4, 9, 18, 20, 23, 34]

if __name__ =='__main__':
    main()