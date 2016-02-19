#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x1, y1, x2, y2, i, j;
    int** a;
    scanf("%d", &n);




    a = (int**)malloc((n + 1) * sizeof(int*));
    for (i = 1; i <= n; i++){
        a[i] = (int*)malloc((n + 1) * sizeof(int));
    }
    while (1){
            scanf("%d", &x1);
            if (x1 == 0){
                break;
            }
            scanf("%d %d %d", &y1, &x2, &y2);

        for (i = 1; i <= n; i++){
            for (j = 1; j <= n; j++){
                a[i][j] = i * j;
            }
        }
        for (i = y1; i <= y2; i++, printf("\n"))
            for (j = x1; j <= x2; j++)
                printf("%*d",7, a[i][j]);
    }
    for (i = 1; i <= n; i++){
        free(a[i]);
        a[i] = NULL;
    }
    free(a);
    a = NULL;
    return 0;
}
