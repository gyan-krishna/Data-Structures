/**********************************************************************************
* FILENAME  : Linked Lists/1. singly linked list/SinglyLinkedListTest.java
* REPO LINK : https://github.com/gyan-krishna/Data-Structures
* 
* DESCRIPTION :
*       Singly Linked List Demo
*
* PUBLIC FUNCTIONS SinglyLinkedList:
* 
*       public void append(int data)            : Append a new node to the end of the LL.
*       public void traverse()                  : Traverse and display the LL.
*       public int search(int s)                : Search for s in LL
*       public void insert_start(int data)      : Insert node at the start of the LL.
*       public void insert(int data, int pos)   : Insert node at position pos in the LL.
*       public void merge(SinglyLinkedList L2)  : Merge two linked lists.
*       
* NOTES :
*       
* TODO :
*       1. Add menu in main method.
*
* AUTHOR : Gyan Krishna Sreekar                     DATE : 12/6/2021
* 
***********************************************************************************/
public class SinglyLinkedListTest
{
    public static void main(String args[])
    {
        SinglyLinkedList ll1 = new SinglyLinkedList("LL1");
        SinglyLinkedList ll2 = new SinglyLinkedList("LL2");
        
        ll1.insert_start(0);
        ll1.append(10);
        ll1.append(20);
        
        ll1.insert(12, 3);
        ll1.update(99, 1);
        /*ll2.append(30);
        ll2.append(40);
        ll2.append(50);
        
        ll1.traverse();
        ll2.traverse();
        ll1.merge(ll2);*/
        
        ll1.traverse();
        //System.out.println("position = "+ll.search(32) );
    }
}
class SinglyLinkedList
{
    private Node head;
    private String name;
    
    public SinglyLinkedList(String n)
    {
        head = null;
        name = n;
    }
   
    public SinglyLinkedList()
    {
        head = null;
        name = "LL1";
    }    
    
    public void append(int data)
    {
        Node new_node = new Node(data);
        //if list is empty, head = new node
        if(head == null)
            head = new_node;
        else
        {
            Node ptr = head;
            // traversing to the end of the linked list
            while(ptr.next != null)
                ptr = ptr.next;
            // adding new node to the end of the list
            ptr.next = new_node;
        }
    }
    
    public void insert_start(int data)
    {
        Node new_node = new Node(data);
        //if list is empty, head = new node
        if(head == null)
            head = new_node;
        else
        {
            new_node.next = head;
            head = new_node;
        }
    }
    public void insert(int data, int pos)
    {
        int counter;
        Node prev,ptr;
        Node new_node = new Node(data);
        if(this.head == null) //if LL is empty, insert new node at start
        {
            new_node.next = null;
            this.head = new_node;
        }
        else if(pos == 0)
            insert_start(data);
        else
        {
            counter = 0;
            // traversing through the LL till we reach needed position
            // or the end of the LL.
            prev = ptr = this.head;
            while(ptr.next != null && pos != counter)
            {
                prev = ptr;
                ptr = ptr.next;
                counter++;
            }
            
            if(counter == pos)// adding new node in middle of the linked list.
            {
                new_node.next = ptr;
                prev.next = new_node;
            }
            else// adding new node on end.
                append(data);  
        }
    }
    public void merge(SinglyLinkedList L2)
    {
        Node ptr = this.head;
        if(ptr != null)// checking if first linked list is not empty
        {
            while(ptr.next != null)
                ptr = ptr.next;
            ptr.next = L2.head;
        }
        else // if first linked list is empty
            this.head = L2.head;
    }
    public void traverse()
    {
        Node ptr = head;
        System.out.print("Contents of "+name+" :");
        while(ptr != null)
        {
            System.out.print(ptr.data+" ");
            ptr = ptr.next;
        }
        System.out.println();
    }
    
    /*
     * Searches for an element in the linked list,
     * if found returns the position of the element in the list,
     * if not found returns -1.
     */
    public int search(int s)
    {
        Node ptr = head;
        int loc = 0;
        while(ptr.next != null)
        {
            if(ptr.data == s)
                return loc;
            ptr = ptr.next;
            loc += 1;
        }
        return -1;
    }
    
    public void update(int new_val, int pos)
    {
        Node ptr = head;
        int counter = 0;
        
        if(head == null)
            return;
        
        while(ptr.next != null && counter != pos)
        {
            ptr = ptr.next;
            counter++;
        }
        if(counter == pos)
            ptr.data = new_val;
    }
}
class Node
{
    int data;
    Node next;
    
    Node(int d)
    {
        data = d;
        next = null;
    }
    
    Node()
    {
        data = 0;
        next = null;
    }
}