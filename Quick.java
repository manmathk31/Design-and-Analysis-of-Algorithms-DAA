import java.util.*;

class Partiton {
    static int comparisons = 0;
    public static int partition(int[] a, int low, int high) {
        int pivote = a[high];
        int i = low;
        
        for (int j = low; j < high; j++) {
            comparisons++;
            if (a[j] < pivote) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
            }
        }

        int temp = a[i];
        a[i] = a[high];
        a[high] = temp;

        System.out.println("pivot = " + pivote);
        System.out.println("comparisons in this partition = " + (high - low));

        System.out.print("array: ");
        for (int x : a) {
            System.out.print(x + " ");
        }
        System.out.println();

        return i;


    }

    public static void quicksort(int[] a, int low, int high) {
        if (low < high) {
            int p = partition(a, low, high);

            quicksort(a, low, p - 1);
            quicksort(a, p + 1, high);
        }
    }
}

public class Quick {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("enter your array: ");

        int n = sc.nextInt();
        int arr[] = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int a = 0;
        int b = n - 1;

        Partiton.quicksort(arr, a, b);
        System.out.println("total comparisons = " + Partiton.comparisons);
        System.out.println("sorted array: ");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}