#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a[10], b[10], t[10], w[10], g[10], i;
    float att = 0, awt = 0;

    // Initialize arrays
    for(i = 0; i < 10; i++) {
        a[i] = 0;
        b[i] = 0;
        w[i] = 0;
        g[i] = 0;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the burst times: ");
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);
    
    printf("\nEnter the arrival times: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    g[0] = 0;
    for(i = 0; i < n; i++)
        g[i+1] = g[i] + b[i];

    for(i = 0; i < n; i++) {
        w[i] = g[i] - a[i];
        t[i] = g[i+1] - a[i];
        awt += w[i];
        att += t[i];
    }

    awt /= n;
    att /= n;

    printf("\n\tProcess\tWaiting Time\tTurn Around Time\n");
    for(i = 0; i < n; i++) {
        printf("\tp%d\t\t%d\t\t%d\n", i+1, w[i], t[i]);
    }

    printf("The average waiting time is %f\n", awt);
    printf("The average turn around time is %f\n", att);

    return 0;
}