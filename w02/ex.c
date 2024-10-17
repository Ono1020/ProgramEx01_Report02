#include <stdio.h>

int main(void){
	int a, b; // 整数型の変数a, bを宣言
	printf("被乗数と乗数を入力して下さい\n");
	printf("被乗数:");
	scanf("%d", &a); // aに入力された値を代入
	printf("乗数:");
	scanf("%d", &b); // bに入力された値を代入

	// 乗算した結果の出力
	printf("%d x %d = %d\n", a, b, a*b);

	return 0;
}