// matrix mul
#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    int i, j, k;
	int sum = 0;
    printf("enter r1 and c1: ");
    scanf("%d %d", &r1, &c1);
    printf("enter r2 and c2: ");
    scanf("%d %d", &r2, &c2);
    if(c2 == r1){
        int mat1[r1][c1], mat2[r2][c2];
		int mat3[r1][c2];
		printf("\nEnter data for first matrix\n");
		for(i=0; i<r1; i++){
            for(j=0; j<c1; j++){
				scanf("%d", &mat1[i][j]);
            }
        }
		printf("Enter data for second matrix\n");
		for(i=0; i<r2; i++){
            for(j=0; j<c2; j++){
				scanf("%d", &mat2[i][j]);
            }
        }

		printf("\n\n");

		for(i=0; i<r1; i++){
			for(j=0; j<c1; j++){
				printf("%d ", mat1[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		for(i=0; i<r2; i++){
			for(j=0; j<c2; j++){
				printf("%d ", mat2[i][j]);
			}
			printf("\n");
		}

		for(i=0; i<r1; i++){
			for(j=0; j<c2; j++){
				for(k=0; k<c1; k++){
					sum+= mat1[i][k] * mat2[k][j];
				}
				// resetting sum after getting each ele in result mat 
				mat3[i][j] = sum;
				sum = 0;
			}
		}

		printf("\n\n");
		
		printf("mat1 * mat2 : \n\n");

		for(i=0; i<r1; i++){
			for(j=0; j<c2; j++){
				printf("%d ", mat3[i][j]);
			}
			printf("\n");
		}
    }
    else{
        printf("col of mat1 != row of mat2");
		}
    return 0;
}