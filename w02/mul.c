#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void){
	// 入力値の保存
	int a, b;
	printf("被乗数と乗数を入力して下さい\n");
	printf("被乗数:");
	scanf("%d", &a);
	printf("乗数:");
	scanf("%d", &b);

	// int型の変数を配列で表現するために使う変数の用意
	int n[32];
	for(int i=0; i<32; i++){
		n[i] = 1 << i;
		// printf("%b\n", n[i]);
	}

	// bool型のa, b
	bool bool_a[32], bool_b[32];
	// aを配列で表現
	for(int i=0; i < 32; i++){
		bool_a[i] = (a & n[i]) != 0;
	}

	// printf("\n");
	
	// bを配列で表現
	for(int i=0; i < 32; i++){
		bool_b[i] = (b & n[i]) != 0;
	}
	
	int p=0, q, r;
	for(int i=0; i < 32; i++){
		q=0;
		for(int j=0; j < 32; j++){
			r = ((int)(bool_a[i] && bool_b[j])) << j;
			if(j == 31 && i != 31){
				r = -r;
			} else if(i == 31) {
				r = -r;
			}
			q += r;
			// q = (j == 31 &&)
		}
		q = q << i;
		p += q;
	}

	// 乗算結果の出力
	printf("%d\n", p);
	printf("\nDone.\n");

	return 0;
}
