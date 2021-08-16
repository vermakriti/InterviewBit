// What is the time complexity of the following code :

int j = 0;
for(int i = 0; i < n; ++i) {
    while(j < n && arr[i] < arr[j]) {
        j++;
    }
}

/*
for i=0 -  n times
    i=1 -  1 times
    i=2 -  1 times
    .
    .
    .
    .
    .
    i=n-1 - 1 times
    total TC = n+1+1+1+1......+n-1
             = n+n
             = 2*n
    time complexity = O(n)
*/
