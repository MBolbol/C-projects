#include <stdio.h>
#include <stdlib.h>




void MultiplyArrayByTen(int *param) {
    for (int i = 0; i < 5; i++) {
        param[i] *= 10;  // Multiply each element by 10
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    //int size = 6 ;

    MultiplyArrayByTen(arr);  // Pass the array and its size

    // Print the modified array
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

