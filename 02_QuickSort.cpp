 #include <iostream>
 #include <limits.h>
 using namespace std;

int partition(int arr[], int s , int e){
    //step 1 : pivot elment choose
    int pivotElemnt = arr[s];
    int pivotindex =s;
    //step 2 find thr right place for pivot element and place it there 
    int count=0;
    for(int i=s+1;i<=e;i++){//s+1 because s per toh pivot element hai
        if(arr[i]<=pivotElemnt){
            count++;
        }
    } 
    int rightIndex =s+count ;//jab mein loop k bhahr aa jaunga toh mere pass correct positio ka index ready hoga
    swap(arr[pivotindex],arr[rightIndex]);
    pivotindex = rightIndex;

    //step 3 left me chote and right mein bade 
    int i=s;
    int j=e;

    while(i<pivotindex && j>pivotindex){
        while(arr[i]<= pivotElemnt){
            i++;

        }
        while(arr[j]>pivotElemnt){
            j--;
        }
        //2 case 
    //A -> u found the element to swap 
    //B -> no need to swap
    if(i<pivotindex && j>pivotindex){
        swap(arr[i], arr[j]);
    }
    }
    
    return pivotindex;

   
 }
 void QuickSort(int arr[], int s, int e){
    //base case
    if(s>=e){
        return;
    }
    // partiton logic
    int p=partition(arr,s,e);

    //recusive call 
    //for left 
    QuickSort(arr,s,p-1);

    //for right
    QuickSort(arr,p+1,e);

 }

 int main(){
    int arr[]={8,2,3,45,75,12};
    int n= 6;
    int s=0;
    int e=n-1;

    QuickSort(arr,s,e);

    for(int i=0 ;i<n; i++){
        cout<<arr[i] <<" ";
    }
    cout<<endl;


 } 