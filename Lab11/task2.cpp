#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n){
	for(int i =0; i< n-1; i++){
		for( int j=0; j< n -i - 1; j++){
			if(arr[j]> arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j+1] = temp;
			}
		}
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
	bubbleSort(arr, n);
	cout<<" SORTED ARRAY IS: "<<endl;
	printArray(arr, n);
	system("pause");
}
