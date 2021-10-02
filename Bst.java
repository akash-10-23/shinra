
/*
 *  Binary Search Tree
 */

import java.util.*;
import java.util.Random;

public class Bst
{
    class Node 
    { 
        int key; 
        Node left, right; 
  
        public Node(int item) 
        { 
            key = item; 
            left = right = null; 
        } 
    } 

    Node root; 

    Bst() 
    {  
        root = null;  
    } 
 
    /* INSERTION */
    void insert(int key) 
    { 
       root = insertRec(root, key); 
    } 
   
    Node insertRec(Node root, int key) 
    { 
  
        if (root == null) 
        { 
            root = new Node(key); 
            return root; 
        } 
  
        if (key < root.key) 
            root.left = insertRec(root.left, key); 
        else if (key > root.key) 
            root.right = insertRec(root.right, key); 
 
        return root; 
    } 
    
    /* DELETION */
    
    void deleteKey(int key) 
    { 
        root = deleteRec(root, key); 
    } 
  
    Node deleteRec(Node root, int key) 
    { 
        if (root == null)  
            return root; 
  
        if (key < root.key) 
            root.left = deleteRec(root.left, key); 
        else if (key > root.key) 
            root.right = deleteRec(root.right, key); 
  
        else
        { 
            if (root.left == null) 
                return root.right; 
            else if (root.right == null) 
                return root.left; 
  
            root.key = minValue(root.right); 
            root.right = deleteRec(root.right, root.key); 
        } 
  
        return root; 
    } 
  
    int minValue(Node root) 
    { 
        int minv = root.key; 
        while (root.left != null) 
        { 
            minv = root.left.key; 
            root = root.left; 
        } 
        return minv; 
    } 
  
    public static void main(String[] args) 
    {
        System.out.println('\f');
        Scanner sc= new Scanner(System.in);
        Bst tree = new Bst(); 
        int a[]= new int[10000];         //for the inputs of the BST
        
        int t=10500;
        System.out.println("Array b[] ");
        for(int i=0; i<a.length;i++)    //Array a[] with elements in decending order
        {    
           a[i]= t;
           t--;
        }
        System.out.println("First element: "+a[0]);
        System.out.println("Last element: "+a[a.length-1]);
        
        System.out.println();
        System.out.println("Binary Search Tree Insertion ");
        long start= System.nanoTime();
        start= start/1000;
        for(int i=0; i< a.length ;i++)
            tree.insert(a[i]);
        long end= System.nanoTime();
        end=end/1000;
        
        System.out.println("All elements are inserted in Binary Search Tree.");
        System.out.println("Time taken by Binary Search Tree insertion function: "+(end-start) +" ms.");
        
        System.out.println();
        System.out.println("Binary Search Tree Deletion ");
        System.out.print("Enter element to be deleted: ");
        int del=sc.nextInt();
        
        start= System.nanoTime();
        start= start/1000;
        tree.deleteKey(del);
        end= System.nanoTime();
        end=end/1000;
        
        System.out.println("The entered element is deleted from the Binary Search Tree.");
        System.out.println("Time taken by Binary Search Tree deletion function: "+(end-start) +" ms.");
    } 
}
