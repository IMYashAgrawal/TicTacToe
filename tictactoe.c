#include<stdio.h>
void display(char a[3][3]) {
	printf("\n");
	for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
    	    printf("%c  ",a[i][j]);
        }
        printf("\n");
    }
	printf("\n");
}
int checkResult(char a[3][3]) {
	char ch = '_';
	if(a[0][0] != '_' && a[0][0] == a[1][1] && a[1][1] == a[2][2]) {
		ch = a[0][0];
	} else if(a[0][2] != '_' && a[0][2] == a[1][1] && a[1][1] == a[2][0]) {
		ch = a[0][2];
	} else {
		for (int i = 0; i < 3; i++) {
			if (a[i][0] != '_' && a[i][0] == a[i][1] && a[i][1] == a[i][2]) {
				ch = a[i][0];
				break;
			} else if (a[0][i] != '_' && a[0][i] == a[1][i] && a[1][i] == a[2][i]) {
				ch = a[0][i];
				break;
			}
		}
	}
	if(ch == 'x') {
		printf("Player 1 has won\n\n");
		return 1;
	} else if(ch == 'o') {
		printf("Player 2 has won\n\n");
		return 1;
	} else {
		return 0;
	}
}
int input(char a[3][3], int i) {
	int n,m;
	while(1) {
		if(i % 2 != 0) {
			printf("Player 1 chance: ");
		} else {
			printf("Player 2 chance: ");
		}
		scanf("%d %d",&n,&m);
		if((n >= 1 && n <= 3) && (m >= 1 && m <= 3)) {
			if(a[n-1][m-1] == '_') {
				break;
			}
		} 
		printf("Wrong Input Retry\n\n");
	}
	if(i % 2 != 0) {
		a[n-1][m-1] = 'x';
	} else {
		a[n-1][m-1] = 'o';
	}
	display(a);
	return checkResult(a);
}
int main() {
	char a[3][3];
	printf("For putting the x or o in your desired location you must enter the coordinates of the point. Select from the given below.\n");
	printf("(1 1) (1 2) (1 3) (2 1) (2 2) (2 3) (3 1) (3 2) (3 3)\n");
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			a[i][j] = '_';
		}
	}
	printf("\n");
	display(a);
    printf("\n");
    for(int i = 1; i <= 9; i++) {
        if(input(a,i))
			return 0;
    }
    printf("Match is draw\n\n");
    return 0;
}