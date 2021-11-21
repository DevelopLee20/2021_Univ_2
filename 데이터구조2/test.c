void selection_sort(int list[], int n) {
    int i, j, least, temp;
    for (i = 0; i < n - 1; i++) {
        printf("STEP %d", i + 1);
        least = i;
        for (j = i + 1; j < n; j++) {
            if (list[j] < list[least])   least = j;
            SWAP(list[i], list[least], temp);
            printf("%d ", list[least]);
        }
    }
}
void insertion_sort(int list[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        printf("STEP %d", i);
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--) {
            list[j + 1] = list[j];
            printf("%d ", list[j + 1]);
        }
        list[j + 1] = key;
    }
}

void bubble_sort(int list[], int n)
{
    int i, j, temp;
    for (i = n - 1; i > 0; i--) {
        printf("STEP %d", n);
        for (j = 0; j < i; j++)
            /* 앞뒤의 레코드를 비교한 후 교체 */
            if (list[j] > list[j + 1]) {
                SWAP(list[j], list[j + 1], temp);
                printf("%d", list[j+1]);
            }
    }
}
inc_insertion_sort(int list[], int first, int last, int gap) {
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap) {
        key = list[i];
        for (j = i - gap; j >= first && key < list[j]; j = j - gap)
            list[j + gap] = list[j];
        list[j + gap] = key;
    }
}
void sell_sort(int list[], int n) {
    int i, gap;
    for (gap = n / 2; gap > 0; gap = gap / 2) {
        if ((gap % 2 == 0)) gap++;
        for (i = 0; i < gap; i++) {
            printf("STEP %d", i + 1);
            inc_insertion_sort(list, i, n - 1, gap);
        }
    }
}