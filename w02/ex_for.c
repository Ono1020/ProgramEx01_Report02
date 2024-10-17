#include <stdio.h>

int main(void){
	int a, b; // 整数型の変数a, bを宣言
	printf("被乗数と乗数を入力して下さい\n");
	printf("被乗数:");
	scanf("%d", &a);
	printf("乗数:");
	scanf("%d", &b);

	int ans=0; // 積を保持する変数

	// b回繰り返し実行するという意味
	for(int i=0; i < b; i++){
		ans+=a; // ansにaの値を加算する
	}

	// 乗算した結果の出力
	printf("%d x %d = %d\n", a, b, ans);

	return 0;
}