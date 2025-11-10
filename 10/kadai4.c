#include <stdio.h>

#define MAX 5

// 問題１　正しくキューを構造体定義する

struct Que {
	int que[MAX]; // キュー本体
	int front, rear; // 先頭要素，末尾要素の位置
	int num; // 現在のデータ数
	// 来週もう少しマニアな実装を追加します（試験範囲外）
};

// 問題２-1　（Javaになると不要な技術ですが）C言語で複数のオブジェクト（もの、この場合はキュー）を扱う仕掛けに慣れておこう
int Enque(struct Que *q, int x) {
	// 問題２-2 構造体ポインタ q のメンバとして、numやqueを扱う
	if (q->num >= MAX) {
		return -1;
	}
	q->que[q->rear++] = x;
	if (q->rear == MAX)
		q->rear = 0;
	q->num++;

	return x;
}

int Deque(struct Que *q) {
	// 問題２-2 構造体ポインタ q のメンバとして、numやqueを扱う
	if (q->num <= 0) {
		return -1;
	}
	int tmp = q->que[q->front];
	q->que[q->front++] = 0;
	if (q->front == MAX)
		q->front = 0;
	q->num--;
	return tmp;
}
// 修正不要
void Display(struct Que *q) {
	for (int i = 0; i < MAX; i++) {
		if (i == q->front)
			printf(" front->");
		else
			printf("        ");
		printf("%6d: %6d", i, q->que[i]);
		if (i == q->rear)
			printf("  <-rear\n");
		else
			printf("        \n");
	}
}
// 修正不要
void Initialize(struct Que *q) {
	q->front = q->rear = q->num = 0;
	for (int i=0; i<MAX; i++)
		q->que[i] = 0;
}

int main() {
	struct Que que1, que2;
    // 問題３-0　設問はなくても、それぞれの関数呼び出しの仕掛けを理解しよう
	Initialize(&que1);
	Initialize(&que2);

	int count = 0;
	int x;

	while(1) {
		printf("?Enque x = ");
		scanf("%d", &x);
		if (x == 0)           //問題３-1　ループを抜け出る
			break;
		count += 1;
		if (count % 2 == 1) { //問題３-2　奇数のとき
			x = Enque(&que1, x);
			if (x == -1)
				printf("que1 full\n");
		} else {              //問題３-3　偶数のとき
			x = Enque(&que2, x);
			if (x == -1)
				printf("que2 full\n");
		}
		printf("que1\n");
		Display(&que1);
		printf("que2\n");
		Display(&que2);
	}

	int total = 0;
	// while (input_number != -1) {
	//問題３-4　que1にデータがある間、繰り返す
	while (que1.num != 0) {
		x = Deque(&que1);
		if (x != -1) {
			printf("%d\n", x);
			total += x;
		}
	}
	x = 0;
	while (x != -1) {     // que1の場合と同じ条件でもOK
	    //問題３-5　que2からデータを取り出す（デキュー）
		x = Deque(&que2);
		if (x != -1) {
			printf("%d\n", x);
			total += x;
		}
	}
	printf("Total: %d\n", total);

	printf("que1\n");
	Display(&que1);
	printf("que2\n");
	Display(&que2);

	return 0;
}
