#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;


///////////////////////Heaps/////////////////////////////////
void max_heapify(int arr[], int i, int n) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;
    if(left <= n && arr[left] > arr[i]) {
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        max_heapify(arr, largest, n);
    }
}
void build_maxheap(int arr[], int n) {
    for(int i = n / 2 ; i >= 1 ; i--) {
        max_heapify(arr, i, n);
    }
}
void min_heapify(int arr[], int i, int n) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;
    if(left <= n && arr[left] < arr[i]) {
        largest = left;
    }
    if(right <= n && arr[right] < arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        min_heapify(arr, largest, n);
    }
}
void build_minheap(int arr[], int n) {
    for(int i = n / 2 ; i >= 1 ; i--) {
        min_heapify(arr, i, n);
    }
}
void heap_sort(int arr[], int n) {
    int heap_size = n;
    build_maxheap(arr, n);
    for(int i = n ; i >= 1 ; i--) {
        swap(arr[1], arr[i]);
        heap_size--;
        max_heapify(arr, 1, heap_size);
    }
}
/////////////////////////////////////////////////////////////


/////////////////Priority-Queues/////////////////////////////


int pq[10] = {0};
int length = 0;
int maximum(int arr[]) {
    return arr[1];
}

int extract_maximum(int arr[]) {
    if(length == 0) {
        cout<<"Queue is empty ";
        return -1;
    }
    int maxm = arr[1];
    arr[1] = arr[length];
    arr[length] = -1;
    length--;
    max_heapify(arr, 1, length);
    return maxm;
}

void insert_pq(int arr[], int val) {
    length++;
    arr[length] = val;
    int i = length;
    while( i > 1 && arr[ i / 2 ] < arr[ i ]) {
        swap(arr[ i / 2 ], arr[ i ]);
        i = i / 2;
    }
}

void build_priorityQueue(int arr[], int n) {

    for(int i = 1 ; i <= n ; i++) {
        insert_pq(pq, arr[i]);
        for(int j = 1 ; j <= n ; j++) {
            cout << pq[j] << ' ';
        }
        cout << endl;
    }
}

void extracting_maximum() {
    cout << extract_maximum(pq) << endl;
    for(int i = 1 ; i <= length ; i++) {
        cout << pq[i] << ' ';
    }
    cout << endl;
}


/////////////////////////////////////////////////////////////




void solve() {
    ll n;
    cin >> n;
    int arr[n + 1];
    for(int i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }
    cout << "Before max_heapify: ";
    for(int i = 1 ; i <= n ; i++) {
        cout << arr[i] << ' ';
    }
    // build_maxheap(arr, n);
    // cout << endl;
    // for(int i = 1 ; i <= n ; i++) {
    //     cout << arr[i] << ' ';
    // }
    cout << endl;

    build_priorityQueue(arr, n);
    extracting_maximum();


}


int main() {
    freopen("input.txt", "r", stdin);
    solve();
    cout << endl;
}