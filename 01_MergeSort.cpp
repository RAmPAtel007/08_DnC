#include <iostream>
using namespace std; 

void merge(int* arr, int s, int e){
    int mid=(s+e)/2;

    int len1=mid-s+1;
    int len2=e-mid;

    int *left= new int[len1];
    int *right= new int[len2];

    //copy values 
    int k=s; //s is the starting index se left wale array ki values copy kr de 

    for(int i=0; i<len1 ;i++){
        left[i]= arr[k];
        k++;
    }
    k=mid+1; //mid+1 se end right wale array ki values copy kr de 
    for(int i=0; i<len2;i++){
        right[i]=arr[k];
        k++;
    }
    //merge logic 


    int leftIndex=0;
    int rightIndex=0;
    int mainArrayIndex = s;

    while(leftIndex<len1 && rightIndex <len2){

    if(left[leftIndex]<right[rightIndex]){
        arr[mainArrayIndex]= left[leftIndex];
        leftIndex++;
        mainArrayIndex++;
    }
    else{
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }
}
    //copy logic for left array 
    while(leftIndex < len1){
        arr[mainArrayIndex++] = left[leftIndex++];
    }
    //copy logic for right array
    while(rightIndex< len2){
        arr[mainArrayIndex++] = right[rightIndex++];
    }
    //TODO : delete left and right wla newly created array 
    delete[] left;
    delete[] right;

}

void mergeSort(int* arr, int s, int e){
    //base case 
    //s==e single element 
    //s>e invalid index
    if(s>=e){
        return;
    }

    int mid=(s+e)/2; //1.break
    //2.left past ko sort kro bhaiya 
    mergeSort(arr,s,mid);

    //3.right part ko sort kro bhaiya 
    mergeSort(arr,mid+1,e);

    merge(arr,s,e);//4.merge
}

int main(){
    int arr[]={12,10,18,7,9,6};
    int n=6;
    int s=0;
    int e=n-1;
    mergeSort(arr,s,e);

    //printing array after sorting
    for(int i=0; i<n ;i++){
        cout<<arr[i] <<" ";
    }
    cout<<endl;
    
     
}