#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool mul_check(int a, int b, int n[32]);

int main(void){
	// int型の変数を配列で表現するために使う変数の用意
	int n[32];
	for(int i=0; i<32; i++){
		n[i] = 1 << i;
	}

	printf("start\n\n");
	// 入力値の保存
	int a, b; // a: 被乗数 b: 乗数

	for (a = -2147483648; a <= 2147483647; a++) {
        for (b = -2147483648; b <= 2147483647; b++) {
            if (!mul_check(a, b, n)) {
                printf("\nError:\n");
                printf("%d x %d\n", a, b);
                return 1;
            }
            // 進捗を表示
        	printf("\033[F");
        	printf("\033[K");
        	printf("\033[F");
        	printf("\033[K");

        	printf("a:%d\n", a);
        	printf("b:%d\n", b);
        }
        
        // printf("%d\n", a);
    }

	printf("\nDone.\n");

	return 0;
}

bool mul_check(int a, int b, int n[32]){
	// bool型のa, b
	bool bool_a[32], bool_b[32];

	// aを配列で表現
	for(int i=0; i < 32; i++){
		bool_a[i] = (a & n[i]) != 0;
	}
	
	// bを配列で表現
	for(int i=0; i < 32; i++){
		bool_b[i] = (b & n[i]) != 0;
	}
	
	// 乗算に関する変数
	int p=0, q, r; // p: 演算結果の保存 q: 各桁の合計 r: 各桁同士の演算結果の保存
	for(int i=0; i < 32; i++){
		q=0;
		for(int j=0; j < 32; j++){
			r = ((int)(bool_a[i] && bool_b[j])) << j;
			// 各桁の最後の値or
			if((j == 31 && i != 31) || (j != 31 && i == 31)){
				r = -r;
			}
			q += r;
		}
		q = q << i;
		p += q;
	}

	int x = a * b;

	if(x - p == 0){
		return true;
	}

	return false;
}