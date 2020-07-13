#include<bits/stdc++.h>
using namespace std;


int BITree[100];
int pref[100];


int getSum(int index) { 
    int sum = 0; // Initialize result 
  
    // Traverse ancestors of BITree[index] 
    while (index>0) { 
        // Add current element of BITree to sum 
        sum += BITree[index]; 
  
        // Move index to parent node in getSum View 
        index -= index & (-index); 
    } 
    return sum; 
} 


// Updates a node in Binary Index Tree (BITree) at given index 
// in BITree. The given value 'val' is added to BITree[i] and  
// all of its ancestors in tree. 
void updateBIT(int BITree[], int n, int index, int val){
    // Traverse all ancestors and add 'val' 
    while (index <= n) { 
    	// Add 'val' to current node of BI Tree 
    	BITree[index] += val; 
    	// Update index to that of parent in update View 
    	index += index & (-index); 
    } 
} 
  
  

void constructBITree(int arr[], int n) 
{ 
    // Initialize BITree[] as 0 
    for (int i=1; i<=n; i++) {
        BITree[i] = 0; 
    }
    
    // Store the actual values in BITree[] using update() 
    for (int i=1; i<=n; i++){ 
        updateBIT(BITree, n, i, arr[i]); 
    }
    // Uncomment below lines to see contents of BITree[] 
    for (int i=1; i<=n; i++) 
        cout << BITree[i] << " "; 
  
}

void solveBIT(int a[], int n){
	constructBITree(a, n);
}


int getPrefSum(int l, int r){
	return pref[r]-pref[l-1];
}

void solvePref(int a[], int n){
	for(int i=0 ; i<=n ; i++){
		pref[i] = pref[i-1]+a[i];
	}
}



int main(){
	
	int n = 11;
	int arr[n+1];
	for(int i=1 ; i<=n ; i++){
		cin>>arr[i];
	}
	
	for(int i=1 ; i<=n ; i++){
		cout<<arr[i]<<' ';
	}
	
	solveBIT(arr, n);
	solvePref(arr, n);
	
	for(int i=1 ; i<=n ; i++){
		int sumPref = getPrefSum(1,i);
		int sumBIT = getSum(i);
		cout<<"1 to "<<i<<" : "<<sumPref<<' '<<sumBIT<<endl;
	}
	
	cout<<endl;

	return 0;	
}