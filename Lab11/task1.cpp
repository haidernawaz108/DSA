#include <iostream>
using namespace std;
void insertionSort(int arr[], int n){
	for(int i =1; i< n; i++){
		int key = arr[i];
		int j = i-1;
		
		while(j>=0 && arr[j]> key){
			arr[j+1] = arr[j];
			j = j - 1;
		}
		arr[j+1] = key;
	}
}
void printArray(int arr[], int n){
	for(int i = 0; i< n; i++){
		cout<<arr[i]<< " "<<endl;
	}
	cout<< endl;
}
int main(){
	int arr[] = {11, 15, 4, 5, 8, 2, 18, 13};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<" ORIGINAL ARRAY IS: "<<endl;
	printArray(arr, n);
	insertionSort(arr, n);
	cout<<" SORTED ARRAY IS: "<<endl;
	printArray(arr, n);
	system("pause");
}
