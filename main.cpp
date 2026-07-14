#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int mid, int r) {
    vector<int> temp;

    int i = l;
    int j = mid + 1;

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);

    while (j <= r)
        temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[k] = temp[k];
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}

int main() {
    vector<int> arr = {5, 2, 4, 7, 1, 3, 2, 6};

    mergeSort(arr, 0, arr.size() - 1);

    for (int x : arr)
        cout << x << " ";

    return 0;
}