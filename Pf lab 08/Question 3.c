#include <stdio.h>

int main() {
    int n;
    int i,j;
    scanf("%d",&n);
    for (i = n; i >= 1; i--) {
    	for(j=n;j>=i;j--){
			printf(" ");
		}
        for ( j = i; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
    
    for ( i = 2; i <= n; i++) {
    	for(j=n;j>=i;j--){
			printf(" ");
		}
        for ( j = i; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

