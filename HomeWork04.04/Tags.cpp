#include "Tags.h"

Tags::Tags() {
	// אכדמנטעל Ôטרונא-Éועסא
	for (int i = 0; i < size; i++) {
		int j = rand() % (i + 1);
		nums[i] = nums[j];
		nums[j] = i;
	}

	InitZero();
}
void Tags::Show() {
	for (int i = 0, j = 0; i < size / 4; i++) {
		for (int k = 0; k < size / 4; k++, j++) {
			cout << "| " << setw(3)
				<< nums[j] << " | ";
		}
		cout << endl;
	}
}
void Tags::InitZero() {
	for (int i = 0; i < size; i++) {
		if (nums[i] == 0) {
			index_zero = i;
			break;
		}
	}
}
void Tags::Move() {
	while (!IsWin()) {
		_getch();
		int k = _getch();
		switch (k)
		{
		case LEFT:
			if ((index_zero + 1) % 4 != 0)
				swap(nums[index_zero], nums[index_zero + 1]);
			break;
		case RIGHT:
			if (index_zero % 4 != 0)
				swap(nums[index_zero], nums[index_zero - 1]);
			break;
		case UP:
			if (index_zero < 12)
				swap(nums[index_zero], nums[index_zero + 4]);
			break;
		case DOWN:
			if (index_zero > 3)
				swap(nums[index_zero], nums[index_zero - 4]);
			break;
		default:
			break;
		}
		system("cls");
		Show();
		InitZero();
	}
}
bool Tags::IsWin() {
	bool flag = true;
	for (int i = 1; i <= size - 1; i++) {
		if (nums[i - 1] != i) flag = false;
	}
	return flag;
}