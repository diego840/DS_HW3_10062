#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *dynArr;

    // 指定空間大小
    int arrLen1 = 10;
    int arrLen2 = 5;

    // 取得記憶體空間
    dynArr = malloc(arrLen1 * arrLen2 * sizeof(int));

    if (dynArr == NULL)
    {
        fprintf(stderr, "Error: unable to allocate required memory\n");
        return 1;
    }

    // 使用動態取得的記憶體空間
    int i, j;
    for (i = 0; i < arrLen1; ++i)
    {
        for (j = 0; j < arrLen2; ++j)
        {
            int index = i * arrLen2 + j;
            printf("abc:%d\n", index);
            dynArr[index] = index;
            printf("%d ", dynArr[index]);
        }
    }

    // 釋放記憶體空間
    free(dynArr);

    return 0;
}