import java.util.*;
public class SegregateOddEven {
    static Node head;
    static class Node{
        int data;
        Node next;
        Node(int data){
            this.data = data;
            this.next = null;
        }
    }
    public static void push(int new_data){
        Node new_node = new Node(new_data);
        new_node.next = head;
        head = new_node;
    }

    public static void segregateList(){
        if(head == null){
            System.out.println("Linked list is empty.");
            return;
        }
        Node evenHead = null, evenTail = null;
        Node oddHead = null, oddTail = null;
        Node temp = head;
        while(temp != null){
            if(temp.data % 2 == 0){
                if(evenHead == null){
                    evenHead = evenTail = temp;
                }
                else{
                    evenTail.next = temp;
                    evenTail = temp; // Update evenTail
                }
            }
            else{
                if(oddHead == null){
                    oddHead = oddTail = temp;
                }
                else{
                    oddTail.next = temp;
                    oddTail = temp; // Update oddTail
                }
            }
            temp = temp.next; // Move to the next node
        }
        if(evenHead != null){
            evenTail.next = oddHead;
        }
        if(oddHead != null){
            oddTail.next = null;
        }
        head = evenHead != null ? evenHead : oddHead;
    }
    
    public static void printList(){
        Node temp = head;
        while(temp != null){
            System.out.println(temp.data);
            temp = temp.next;
        }
    }

    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        SegregateOddEven list = new SegregateOddEven();
        int num = scan.nextInt();
        int data;
        for(int i = 0; i < num; i++){
            data = scan.nextInt();
            list.push(data);
        }
        scan.close();
        list.segregateList();
        list.printList();
    }
}
