#include "Hourse.h"

Hourse::Hourse() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = '_';
		}
	}
}
void Hourse::Show() {
	char c = 'A';
	cout << "  ";
	for (int i = 0; i < 8; i++, c++) {
		cout << c << " ";
	}
	cout << endl;
	for (int i = 0; i < 8; i++) {
		cout << i + 1;
		for (int j = 0; j < 8; j++) {
			cout << "|" << board[i][j];
		}
		cout << "|" << endl;
	}
}
void Hourse::InitHourse() {
	cout << " уда поставить кон€ (например, ј3 или F1) -> ";
	char str[3]; cin >> str;
	i = str[0] - 65;
	j = atoi(&str[1]) - 1;
	board[j][i] = 'x';
}
void Hourse::Move() {
	int val = j * 10 + i; // получаем число дл€ поиска в массиве arr
	int k = 0; // индекс этого числа в массиве arr
	for (int i = 0; i < 64; i++) {
		if (val == arr[i]) {
			k = i;
			break;
		}
	}
	Recourse(k, k + 1);
}
void Hourse::Recourse(int k, int i) {
	if (i == k) return;
	if (i == 64)
		if (k != 0) i = 0;
		else return;
	board[arr[i] / 10][arr[i] % 10] = 'x';
	cout << endl;
	Show();
	Recourse(k, ++i);
}