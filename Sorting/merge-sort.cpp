#include <iostream> 

//idea: have a mergeSort and merge function that repeatedly splits up the array until it is size 2

void merge(int temp[], int nums[], int a, int b, int end){

	int end2 = b - 1; 
	int n = (end - a) + 1; //ending index of temp
	int i = 0; 
	int aOG = a; 

	while(a <= end2 && b <= end){
		if(nums[a] <= nums[b]){
			temp[i] = nums[a];
			a += 1; 
		} else {
			temp[i] = nums[b];
			b += 1; 
		}
		i += 1; 
	}

	if(a > end2){
		while(b <= end){
			temp[i] = nums[b];
			b += 1; 
			i += 1; 
		}
	}

	if(b > end){
		while(a <= end2){
			temp[i] = nums[a];
			a += 1; 
			i += 1; 
		}
	}

	for(int i = 0; i < n; i++){
		nums[aOG + i] = temp[i];
	}

}

void mergeSort(int temp[], int nums[], int start, int end){

	if(start < end){ //ensures we have at least an array of size 2
		int mid = (start + end)/2; 
		mergeSort(temp, nums, start, mid); 
		mergeSort(temp, nums, mid + 1, end); 
		merge(temp, nums, start, mid + 1, end); 
	}

}

/* sizeA/B is the number of elements in array A/B */
void merge(int * a, int * b, int sizeA, int sizeB){
	int indexA = sizeA - 1;
	int indexB = sizeB - 1; 
	int mergeIndex = sizeA + sizeB - 1;

	while(indexA >= 0 && indexB >= 0){
		if(a[indexA] > a[indexB]){
			a[mergeIndex] = a[indexA];
			indexA -= 1;
		} else {
			a[mergeIndex] = b[indexB];
			indexB -= 1; 
		}
		mergeIndex -= 1; 
	}

	while(indexB >= 0){
		a[mergeIndex] = b[indexB];
		indexB -= 1;
		mergeIndex -= 1;
	}
}

int main(){

    int n = 100;

    int* nums = new int[n]{
        57, 12, 98, 34, 76, 2, 45, 89, 15, 66,
        33, 5, 73, 88, 41, 17, 29, 100, 53, 7,
        86, 24, 67, 3, 50, 92, 18, 39, 81, 55,
        9, 27, 63, 14, 80, 4, 72, 32, 60, 10,
        95, 21, 54, 37, 68, 16, 74, 11, 90, 25,
        46, 31, 77, 43, 20, 8, 66, 35, 59, 97,
        28, 13, 84, 6, 53, 41, 90, 22, 88, 38,
        75, 57, 17, 4, 62, 91, 10, 33, 49, 80,
        26, 94, 1, 65, 82, 52, 48, 6, 99, 35,
        23, 47, 84, 16, 71, 5, 55, 98, 19, 50, 
    };

    int* temp = new int[n];

    mergeSort(temp, nums, 0, n - 1);

    for(int i = 0; i < n; i++){
        std::cout << nums[i] << " ";
    }

    return 0; 
}