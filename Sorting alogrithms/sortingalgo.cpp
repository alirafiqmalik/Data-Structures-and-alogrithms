#include <iostream>
using namespace std;
/*
Selection sort
Bubble sort
Insertion sort

*/



// Function to print array arr[]  
void printArray(int arr[], int arr_size)  
{  
    // Iterate and print every element  
    for (int i = 0; i < arr_size; i++)  
        cout << arr[i] << " ";  
  
}  


void swap(int *x,int *y){
    int tmp=*x;
    *x=*y;
    *y=tmp;
}

void selsort(int x[],int n){
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(x[j]<x[min]){
                min=j;
            }
        }
        swap(x[i],x[min]);
    }
    printArray(x,n);
}



int * bubblesort(int x[],int n){
    int ch=1;
    while (ch)
    {
        ch=0;
        for(int i=0;i<n-1;i++)
        if(x[i+1]<x[i]){
            swap(x[i],x[i+1]);
            ch=1;
        }
    }
    return x;
    //printArray(x,n);
}


/*
   int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }*/


void insertionSort(int x[], int n)
{
    int j,key;
    for(int i=1;i<n;i++){
        j=i-1;
        key=x[i];
        while(j>=0 && (key<x[j])){
            x[j+1]=x[j];
            j--;
        }
        x[j+1]=key;
    }
    
    printArray(x,n);
 
}


/*
// Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
*/





void shellSort(int arr[], int n)
{
    int j,key;
    int gap=n/2;
    
  //  for(int ext=n/2;ext>0;ext/=2.2){
while(gap>0){

    for(int i=gap;i<n;i++){
        key=arr[i];
        //int j=i;
        //while(j>=gap &&(key<arr[j-gap])){
       
        for(j=i;j>=gap  &&  (key<arr[j-1]);j-=gap){
            arr[j]=arr[j-gap];
            //j=j-gap;
        }
        arr[j]=key;
    }

  if(gap==2){
        gap=1;
    }
    else{
        gap/=2.2;
    }

    }


    printArray(arr,n);
}


void mergeA(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}


int* mergesort(int x,int start,int end){
    return NULL;

}






int main(){
    int n=6;
    int minval;
    int x[]={9,5,2,3,4,1};
    //int *y;
    
    cout<<endl;
    printArray(x,n);
    
    /*cout<<"\n";
    selsort(x,n);

    cout<<"\n";
    bubblesort(x,n);

    */
   //y=bubblesort(x,n);   
   
   //cout<<"\n";
   //printArray(y,n);
   //cout<<"\n";
   //cout<<"\n";
   //insertionSort(x,n);

   //cout<<"\n";
   //shellSort(x,n);
   //cout<<"\n";
   
   cout<<"\n";
   printArray(x,n);
   cout<<"\n";


    merge(x,0,(n/2),n-1);
    cout<<endl;
    printArray(x,n);


    return 0;
}