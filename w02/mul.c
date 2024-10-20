#include <stdio.h>
#include <stdbool.h>

int main(void){
	// int型の変数を配列で表現するために使う変数の用意
	int n[32];
	for(int i=0; i<32; i++){
		n[i] = 1 << i;
	}


	// 入力値の保存
	int a, b; // a: 被乗数 b: 乗数
	printf("被乗数と乗数を入力して下さい\n");
	printf("被乗数:");
	scanf("%d", &a);
	printf("乗数:");
	scanf("%d", &b);


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
			// 各桁の最後の値or最後のbの最後のa以外を負の数にする
			if((j == 31 && i != 31) || (j != 31 && i == 31)){
				r = -r;
			}
			q += r;
		}
		q = q << i;
		p += q;
	}

	// 乗算結果の出力
	printf("%d x %d = %d\n", a, b, p);
	printf("\nDone!\n");

	return 0;
}
