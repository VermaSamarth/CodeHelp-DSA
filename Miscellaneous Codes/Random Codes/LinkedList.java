import java.util.*;
public class LinkedList {
    Node head;
    static class Node{
        int data;
        Node next;
        Node(int data){
            this.data = data;
            this.next = null;
        }
    }

    public static LinkedList insertNode(int data, LinkedList list){
        Node newNode = new Node(data);
        if(list.head == null){
            list.head = newNode;
        }
        else{
            Node last = list.head;
            while(last.next != null){
                last = last.next;
            }
            last.next = newNode;
        }
        return list;
    }

    public static void main(){
        LinkedList list = new LinkedList();
        list = insertNode(0, list);
        list = insertNode(1, list);
        list = insertNode(2, list);
        list = insertNode(3, list);
    }
}
