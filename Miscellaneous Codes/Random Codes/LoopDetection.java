import java.util.*;
public class LoopDetection{
    static class Node{
        int data;
        Node next;
        Node(int data){
            this.data = data;
            this.next = null;
        }
    }
    
    static Node head;
    public static void push(int new_data){
        Node new_node = new Node(new_data);
        new_node.next = head;
        head = new_node;
    }

    public static void detectLoop(){
        Node slow = head;
        Node fast = head;
        while(slow != null && fast != null && fast.next != null){
            fast = fast.next;
            if(fast.next != null){
                slow = slow.next;
                fast = fast.next;
            }
            if(slow == fast){
                System.out.println("Loop is found.");
                return;
            }
        }
        System.out.println("Loop is not found.");
    }

    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        LoopDetection list = new LoopDetection();
        int num = scan.nextInt();
        int data;
        for(int i = 0; i < num; i++){
            data = scan.nextInt();
            list.push(data);
        }
        scan.close();
        list.detectLoop();
    }
}