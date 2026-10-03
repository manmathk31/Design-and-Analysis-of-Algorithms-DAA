//  Binary Search — found and not-found.
// Given the sorted array A = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]: (a) search for key 23 and list low, mid, high at every step; (b) search for key 40 and do the same. (c) Count comparisons in each case. (d) State the recurrence, time complexity, and space complexity for both the recursive and iterative versions.
// Expected: 23 found at index 5 (3 comparisons); 40 not found (~4 comparisons); T(n) = T(n/2) + 1 ⇒ O(log n); space O(1) iterative, O(log n) recursive.


import java.util.*;
public class Binary{

    public static void bsearch(int arr[],int x){
        int low = 0;
        int high = arr.length-1;
        int comp = 0;

        while(low <= high){
            
            int mid = (low+high)/2;
            comp++;
            System.out.println("low = "+ low + " high = "+ high+" mid = "+mid);
            if(arr[mid] == x){
                
                System.out.println(x + " found at index " + mid + " with comparisons = " + comp);
                return;
            }
            if(arr[mid] < x){
                
                low = mid+1;

            }else{
                
                high = mid -1;
            }
        }
        System.out.println(x+ " not found at any index in array \ntotal comparisons made = "+ comp);
    } 

    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter the element to enter :");
        int x = sc.nextInt();
        int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
       
        Binary.bsearch(arr,x);

    }
}
