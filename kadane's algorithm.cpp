int kadaneAlgo(int a[], int n) {
  int maxSum = a[0], currSum = a[0];
  for(int i=1 ; i<n ; i++){
    currSum += a[i];
    if(currSum < a[i])
      currSum = a[i];
    maxSum = max(maxSum, currSum);
  }
  return maxSum;
}