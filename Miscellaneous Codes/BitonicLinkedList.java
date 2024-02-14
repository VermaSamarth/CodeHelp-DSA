import java.util.*;
public class BitonicLinkedList {
    static Node head;
    static class Node{
        int data;
        Node next;
        Node(int data){
            this.data = data;
            this.next = null;
        }
    }

    public static void push(int data){
        Node new_node = new Node(data);
        new_node.next = head;
        head = new_node;
    }

    public static void sorting(){
        BitonicLinkedList node = new BitonicLinkedList();
        ArrayList<Integer> list = new ArrayList<Integer>();
        Node temp = head;
        while(temp != null){
            list.add(temp.data);
            temp = temp.next;
        }
        Collections.sort(list);
        Collections.reverse(list);
        head = null;
        head.next = null;
        for(int it:list){
            node.push(it);
        }
    }

    public static void printList(){
        Node temp = head;
        while(temp != null){
            System.out.println(temp.data);
            temp = temp.next;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BitonicLinkedList node = new BitonicLinkedList();
        int n = sc.nextInt();
        int data;
        for(int i = 0; i < n; i++){
            data = sc.nextInt();
            node.push(data);
        }
        node.sorting();
        node.printList();
        sc.close();
    }
}
