'''
Binary Search Tree
Author: Louis Sungwoo Cho
Date Created: 1/10/2023
'''
from src.utils import BinarySearchTree

def main():
    print('Binary Trees')
    numbers = [17, 4, 1, 20, 9, 23, 18, 34]

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

if __name__ =='__main__':
    main()