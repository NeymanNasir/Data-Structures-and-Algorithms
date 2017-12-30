#include<iostream>
#include<cstdio>
using namespace std;

int arr[100];
int main()
{
    int n, i, j, num;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &num);
        arr[num]++;
    }

    printf("Sorted Array: ");
    for(i = 0; i <= 100; i++){
        if(arr[i]>0){
            for(j = 0; j < arr[i]; j++){
                printf("%d ", i);
            }
        }
    }
    return 0;
}
