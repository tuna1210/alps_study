#include <cstdio>
#include <cstdlib>

unsigned long long ans;

unsigned long long merge(int arr[], int tmp[], int left, int mid, int right)
{
    int i = left, j = mid+1, k = left;
    unsigned long long cnt = 0;
    
    while(i <= mid && j <= right)
    {
        if(arr[i] > arr[j])
        {
            tmp[k] = arr[j];
            j++;
            cnt += mid - i + 1;
        }
        else
        {
            tmp[k] = arr[i];
            i++;
        }
        k++;
    }

    if(i > mid)
    {
        for(int l = j; l <= right; l++)
        {
            tmp[k] = arr[l];
            k++;
        }
    }
    else
    {
        for(int l = i; l <= mid; l++)
        {
            tmp[k] = arr[l];
            k++;
        }
    }

    for(int l = left; l <= right; l++)
    {
        arr[l] = tmp[l];
    }

    return cnt;
}

void merge_sort(int arr[], int tmp[], int n, int left, int right)
{
    if(left>=right) return;
    int mid = (left + right) / 2;
    merge_sort(arr, tmp, n, left, mid);
    merge_sort(arr, tmp, n, mid+1, right);
    ans += merge(arr, tmp, left, mid, right);
}

int main()
{
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(sizeof(int)*n);
    int* tmp = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, tmp, n, 0, n - 1);

    printf("%llu\n", ans);

    return 0;
}