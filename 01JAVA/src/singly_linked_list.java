import java.util.*;
public class singly_linked_list {
	private ListNode head;
	private static class ListNode {
		private int data;
		private ListNode next;
		
		public ListNode(int data) {
			this.data = data;
			this.next = null;
		}
	}
	
	public void display() {
		ListNode current = head;
		while (current != null) {
			System.out.print(current.data + " --> " );
			current = current.next;
		}
		System.out.print("null");
	}
	
	public void display(ListNode head) {
		ListNode current = head;
		while (current != null) {
			System.out.print(current.data + " --> " );
			current = current.next;
		}
		System.out.print("null");
	}
	
	public int length(ListNode input) {
		if (input == null) {
			return 0;
		}
		return 1 + length(input.next);
	}
	
	public void insertfront(int value) {
		ListNode newNode = new ListNode(value);
		newNode.next = head;
		head = newNode;
	}
	
	public void insertend(int value) {
		ListNode newNode = new ListNode(value);
		ListNode current = head;
		while (current.next != null) {
			current = current.next;
		}
		current.next = newNode;
	}
	
	public void insert(int position,int value) {
		if (position == 0) {
			insertfront(value);
		} else{
			ListNode previous = head;
			int count = 1;
			
			while (count < position - 1) {
				previous = previous.next;
				count++;
			}
			ListNode node = new ListNode(value);
			ListNode current = previous.next;
			previous.next = node;
			node.next = current;
		}
	}
	
	public void deleteFirst() {
		if (head == null) {
			return;
		}
		ListNode current = head;
		head = current.next;
	}
	
	public void deleteLast() {
		if (head == null) {
			return;
		}
		ListNode current = head;
		while (current.next.next != null) {
			current = current.next;
		}
		
		current.next = null;
		
	}
	
	public void delete(int position) {
		if (position == 0) {
			deleteFirst();
		} else{
			ListNode previous = head;
			int count = 1;
			
			while (count < position - 1) {
				previous = previous.next;
				count++;
			}
			
			ListNode current = previous.next;
			previous.next = current.next;
			
		}
	}
	
	public boolean find(ListNode head, int key) {
		if (head == null) {
			return false;
		}
		ListNode current = head;
		while (current != null) {
			if (current.data == key) {
				return true;
			}
			current = current.next;
		}
		return false;
	}
	
	public ListNode reverse(ListNode head) {
		if (head == null) {
			return head;
		}
		ListNode current = head;
		ListNode previous = null;
		ListNode next = null;
		
		while (current != null) {
			next = current.next;
			current.next = previous;
			previous = current;
			current = next;
			
		}
		return previous;
		
	}
	
	public static void main(String[] args) {
		singly_linked_list sll = new singly_linked_list();
		sll.head = new ListNode(10);
		ListNode second = new ListNode(1);
		ListNode third = new ListNode(8);
		ListNode fourth = new ListNode(11);
		
		sll.head.next = second;
		second.next = third;
		third.next = fourth;
		
		System.out.println("My List");
		sll.display();
		System.out.println();
		System.out.println("Length of Linked List: " + sll.length(sll.head));
		
		//Insertion Algorithm for Linked Lists
		//Insert a node at the front
		System.out.println("Insert Front");
		sll.insertfront(5);
		sll.display();
		System.out.println();
		
		//Insert a node at the end
		System.out.println("Insert End");
		sll.insertend(20);
		sll.display();
		System.out.println();
		
		//Insert a node at a given position
		System.out.println("Insert");
		sll.insert(1,7);
		sll.display();
		System.out.println();
		////////////////////////////////////////////
		
		//Deletion Algorithm for Linked Lists
		//Delete first node
		System.out.println("Delete Front");
		sll.deleteFirst();
		sll.display();
		System.out.println();
		
		//Delete last node
		System.out.println("Delete Last");
		sll.deleteLast();
		sll.display();
		System.out.println();
		
		//Delete a node at a given position
		System.out.println("Delete");
		sll.delete(1);
		sll.display();
		System.out.println();
		
		//Find an element
		System.out.println("Find");
		boolean a = sll.find(sll.head,1);
		sll.display();
		System.out.println();
		
		//Reverse a linked list
		System.out.println("Reverse");
		ListNode reversehead = sll.reverse(sll.head);
		sll.display(reversehead);
		System.out.println();
		
		
		
	}
}
