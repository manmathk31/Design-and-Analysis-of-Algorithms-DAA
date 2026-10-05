#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

// ============================================================================
// Approach 1: Merge Method (Linear Time - O(m + n))
// ============================================================================
// Uses two pointers to simulate merging the two sorted standard arrays.
// Because m = n, total elements = 2n.
// The median is the average of elements at index (n - 1) and index n
// in the merged sequence.
//
// Time Complexity:  O(n) which is O(m + n) since m = n
// Space Complexity: O(1) auxiliary space
// ============================================================================


double findMedianByMerge(const int A[], const int B[], int n) {
    int i = 0; // Pointer for array A
    int j = 0; // Pointer for array B
    
    int m1 = -1; // Stores element at index (n - 1)
    int m2 = -1; // Stores element at index n
    
    // We advance n + 1 times to find elements at rank n and n + 1
    for (int count = 0; count <= n; ++count) {
        // Shift previous element
        m1 = m2;
        
        if (i < n && j < n) {
            if (A[i] <= B[j]) {
                m2 = A[i++];
            } else {
                m2 = B[j++];
            }
        } else if (i < n) {
            m2 = A[i++];
        } else {
            m2 = B[j++];
        }
    }
    
    return (m1 + m2) / 2.0;
}

// Helper function to find the median of a single sorted standard array
double getArrayMedian(const int arr[], int n) {
    if (n % 2 == 0) {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
    return arr[n / 2];
}

// ============================================================================
// Approach 2: Divide and Conquer Method (Logarithmic Time - O(log n))
// ============================================================================
// Recursively compares the medians m1 and m2 of subarrays of A and B:
// 1. If m1 == m2, return m1.
// 2. If m1 < m2, median lies in A[m1...end] and B[start...m2].
// 3. If m1 > m2, median lies in A[start...m1] and B[m2...end].
//
// Time Complexity:  O(log n)
// Space Complexity: O(log n) due to recursive call stack
// ============================================================================
double findMedianDivideAndConquer(const int A[], const int B[], int n) {
    // Base Case 1: Subarrays of size 1
    if (n == 1) {
        return (A[0] + B[0]) / 2.0;
    }
    
    // Base Case 2: Subarrays of size 2
    // For 4 sorted numbers {A[0], A[1], B[0], B[1]}, the two middle values are:
    // max(A[0], B[0]) and min(A[1], B[1])
    if (n == 2) {
        return (max(A[0], B[0]) + min(A[1], B[1])) / 2.0;
    }
    
    double m1 = getArrayMedian(A, n);
    double m2 = getArrayMedian(B, n);
    
    // If medians are equal, return immediately
    if (m1 == m2) {
        return m1;
    }
    
    // If m1 < m2, the median must lie in A[m1...] and B[...m2]
    if (m1 < m2) {
        if (n % 2 == 0) {
            // For even n, include the elements contributing to the median
            return findMedianDivideAndConquer(A + n / 2 - 1, B, n - n / 2 + 1);
        }
        return findMedianDivideAndConquer(A + n / 2, B, n - n / 2);
    } 
    // If m1 > m2, the median must lie in A[...m1] and B[m2...]
    else {
        if (n % 2 == 0) {
            return findMedianDivideAndConquer(B + n / 2 - 1, A, n - n / 2 + 1);
        }
        return findMedianDivideAndConquer(B + n / 2, A, n - n / 2);
    }
}

int main() {
    // Standard normal C-style arrays
    int A[] = {1, 3, 8, 9, 15};
    int B[] = {7, 11, 18, 19, 21};
    int n = sizeof(A) / sizeof(A[0]);
    
    cout << "==========================================================" << "\n";
    cout << "  Median of Two Sorted Arrays of Equal Size (n = " << n << ")" << "\n";
    cout << "==========================================================" << "\n";
    
    cout << "Array A: ";
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << "\n";
    
    cout << "Array B: ";
    for (int i = 0; i < n; ++i) {
        cout << B[i] << " ";
    }
    cout << "\n\n";
    
    cout << fixed << setprecision(2);
    
    // (a) Solution 1: Merging approach O(m + n)
    double medianMerge = findMedianByMerge(A, B, n);
    cout << "Approach 1 (Merging - O(m + n)):            " << medianMerge << "\n";
    
    // (a) Solution 2: Divide and Conquer approach O(log n)
    double medianDivideConquer = findMedianDivideAndConquer(A, B, n);
    cout << "Approach 2 (Divide & Conquer - O(log n)): " << medianDivideConquer << "\n";
    
    cout << "==========================================================" << "\n";
    
    return 0;
}
