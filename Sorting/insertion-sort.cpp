#include <iostream> 

int main(){

    int nums[100] = {
        57, 12, 98, 34, 76, 2, 45, 89, 15, 66,
        33, 5, 73, 88, 41, 17, 29, 100, 53, 7,
        86, 24, 67, 3, 50, 92, 18, 39, 81, 55,
        9, 27, 63, 14, 80, 4, 72, 32, 60, 10,
        95, 21, 54, 37, 68, 16, 74, 11, 90, 25,
        46, 31, 77, 43, 20, 8, 66, 35, 59, 97,
        28, 13, 84, 6, 53, 41, 90, 22, 88, 38,
        75, 57, 17, 4, 62, 91, 10, 33, 49, 80,
        26, 94, 1, 65, 82, 52, 48, 6, 99, 35,
        23, 47, 84, 16, 71, 5, 55, 98, 19, 50
    };

    int n = 100;

    //keep finding where the current element fits into the rest of the array
    for(int i = 1; i < n; i++){ //go up to n, we need to insert every element
        int key = nums[i];
        int k = i - 1; 
        while(k >= 0 && nums[k] > key){
            nums[k + 1] = nums[k];
            k -= 1; 
        }
        nums[k + 1] = key;
    }

    for(int i = 0; i < n; i++){
        std::cout << nums[i] << " ";
    }

    return 0; 
}