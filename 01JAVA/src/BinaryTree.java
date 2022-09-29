import java.util.*;

public class BinaryTree {
	private TreeNode root;
	
	private class TreeNode {
		private TreeNode left;
		private TreeNode right;
		private int data;
		
		public TreeNode(int data) {
			this.data = data;
		}
	}
	
	public void createBinaryTree() {
		TreeNode first = new TreeNode(1);
		TreeNode second = new TreeNode(2);
		TreeNode third = new TreeNode(3);
		TreeNode fourth = new TreeNode(4);
		TreeNode fifth = new TreeNode(5);
		
		root = first;
		first.left = second;
		first.right = third;
		
		second.left = fourth;
		second.right = fifth;
	}
	
	public void preOrder(TreeNode root) {
		if (root == null) {
			return;
		}
		System.out.print(root.data + " ");
		preOrder(root.left);
		preOrder(root.right);
	}
	
	public void inOrder(TreeNode root) {
		if (root == null) {
			return;
		}
		
		preOrder(root.left);
		System.out.print(root.data + " ");
		preOrder(root.right);
	}
	
	public void postOrder(TreeNode root) {
		if (root == null) {
			return;
		}
		
		preOrder(root.left);
		preOrder(root.right);
		System.out.print(root.data + " ");
	}
	
	public void levelOrder() {
		if (root == null) {
			return;
		}
		Queue<TreeNode> queue = new LinkedList<>();
		queue.offer(root);
		while (!queue.isEmpty()) {
			TreeNode temp = queue.poll();
			System.out.println(temp.data + " ");
			if (temp.left != null) {
				queue.offer(temp.left);
			}
			if (temp.right != null) {
				queue.offer(temp.right);
			}
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BinaryTree Louis = new BinaryTree();
		Louis.createBinaryTree();
		Louis.preOrder(Louis.root);
		System.out.println();
		Louis.inOrder(Louis.root);
		System.out.println();
		Louis.postOrder(Louis.root);
		System.out.println();
		Louis.inOrder(Louis.root);
		System.out.println();
	}

}
