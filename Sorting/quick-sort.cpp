#include <iostream> 

//keep picking a pivot and sort by pivot 

void quickSort(int nums[], int start, int end){

    if(end <= start){ //ensure we always have at least 1 element
        return;
    }

    int pivot = nums[end];
    int lo = start; 
    int hi = end - 1; 

    while(lo <= hi){
        while(lo <= hi && nums[lo] <= pivot){
            lo += 1; 
        }

        while(lo <= hi && nums[hi] >= pivot){
            hi -= 1; 
        }

        if(lo < hi){
            int temp = nums[hi];
            nums[hi] = nums[lo];
            nums[lo] = temp; 
        }
    }

    int temp = nums[lo];
    nums[lo] = pivot;
    nums[end] = temp;

    quickSort(nums, start, lo - 1);
    quickSort(nums, lo + 1, end); 
}

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

    quickSort(nums, 0, n - 1); 

    for(int i = 0; i < n; i++){
        std::cout << nums[i] << " ";
    }

    return 0; 
}

