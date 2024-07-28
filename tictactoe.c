#include<stdio.h>
int main() {
    int n, m, x = 3, y, z = 0;
	char a[x][x];
	printf("For putting the x or o in your desired location you must enter the coordinates of the point. Select from the given below.\n");
	printf("(1 1) (1 2) (1 3) (2 1) (2 2) (2 3) (3 1) (3 2) (3 3)\n");
	for(int i = 0; i < x; i++) {
		for(int j = 0; j < x; j++) {
			a[i][j] = '_';
		}
	}
	printf("\n");
        for(int j = 0; j < x; j++) {
            for(int k = 0; k < x; k++) {
                printf("  %c",a[j][k]);
            }
            printf("\n");
        }
        printf("\n");
	y = x * x;
    for(int i = 1; i <= y; i++) {
        for(;;) {
            if(i % 2 != 0) {
                printf("Player 1 chance\n");
            } else {
                printf("Player 2 chance\n");
            }
            scanf("%d %d",&n,&m);
            if((n >= 1 && n <= x) && (m >= 1 && m <= x)) {
                if(a[n-1][m-1] == '_') {
                    break;
                }
            } 
            printf("Wrong input retry\n");
        }
        if(i % 2 != 0) {
            a[n-1][m-1] = 'x';
        } else {
            a[n-1][m-1] = 'o';
        }
        printf("\n");
        for(int j = 0; j < x; j++) {
            for(int k = 0; k < x; k++) {
                printf("%c  ",a[j][k]);
            }
            printf("\n");
        }
        printf("\n");
        for(int j = 0; j < x; j++) {
            for(int k = 0; k < x; k++) {
				if((a[j][k] == a[j][x-1]) && a[j][k] != '_') {
					if(k == (x - 1)) {
						if(a[j][j] == 'x'){
							printf("Player 1 has won");
						} else {
							printf("Player 2 has won");
						}
						return 0;
					}
				} else {
					break;
				}
			}
			for(int k = 0; k < x; k++) {
				if((a[k][j] == a[x-1][j]) && a[k][j] != '_') {
					if(k == (x - 1)) {
						if(a[j][j] == 'x'){
							printf("Player 1 has won");
						} else {
							printf("Player 2 has won");
						}
						return 0;
					}
				} else {
					break;
				}
			}
        }
		for(int j = 0; j < x; j++) {
			if((a[j][j] == a[x-1][x-1]) && a[j][j] != '_'){
				if(j == (x - 1)){
					if(a[j][j] == 'x'){
						printf("Player 1 has won");
					} else {
						printf("Player 2 has won");
					}
					return 0;
				}
			} else {
				break;
			}
		}
		for(int j = 0, k = x - 1; j < x; j++, k--) {
			if((a[(x-1)/2][(x-1)/2] == a[j][k]) && a[j][k] != '_'){
				if(j == (x - 1)){
					if(a[j][k] == 'x'){
						printf("Player 1 has won");
					} else {
						printf("Player 2 has won");
					}
					return 0;
				}
			}
		}
    }
    printf("Match is draw");
    return 0;
}
