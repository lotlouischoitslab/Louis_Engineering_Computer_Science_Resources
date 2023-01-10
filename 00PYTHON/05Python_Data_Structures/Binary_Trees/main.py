'''
Binary Search Tree
Author: Louis Sungwoo Cho
Date Created: 1/10/2023
'''
from src.utils import BinarySearchTree

def main():
    print('Binary Trees')
    numbers = [17, 4, 1, 20, 9, 23, 18, 34]

    numbers = [15,12,7,14,27,20,23,88 ]

    numbers_tree = BinarySearchTree.build_tree(numbers)
    print("Input numbers:",numbers)
    print("Min:",numbers_tree.min_val())
    print("Max:",numbers_tree.max_val())
    print("Sum:", numbers_tree.calculate_sum())
    # print("In order traversal:", numbers_tree.in_order_traversal())
    # print("Pre order traversal:", numbers_tree.pre_order_traversal())
    # print("Post order traversal:", numbers_tree.post_order_traversal())

if __name__ =='__main__':
    main()