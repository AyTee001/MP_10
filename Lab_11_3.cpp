#include <iostream>


using namespace std;

void Ex_1_var_9() {
	int left = 4;
	int right = 4;
	int top = 4;
	int bottom = 4;
	int index = 1;
	int arr[9][9];

	while (1) {
		// print right
		for (int i = top; i <= bottom; i++) {
			arr[i][right] = index++;
		}
		bottom++;
		//
		if (bottom > 8)
		break;
		// print bottom
		for (int i = right; i >= left; i--) {
			arr[bottom][i] = index++;
		}
		left--;
		//
		if (left < 0)
			break;
		// print left
		for (int i = bottom; i >= top; i--) {
			arr[i][left] = index++;
		}
		top--;
		//
		if (top < 0)
			break;
		// print top
		for (int i = left; i <= right; i++) {
			arr[top][i] = index++;
		}
		right++;
		//
		if (right>8)
			break;
	}

		
	for (int i = 0; i < 9; i++) {
		for (int k = 0; k < 9; k++) {
			cout << arr[i][k] << "  ";
		}
		cout << "\n";
	}
}


void Fill_array(int** arr, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int k = 0; k < columns; k++) {
			arr[i][k] = rand() % 100;
		}
	}
}

int Mid_min_max(int** arr, int rows, int columns) {
	int min = 0;
	int max = 0;
	for (int i = 0; i < rows; i++) {
		for (int k = 0; k < columns; k++) {
			if (arr[i][k] > max) max = arr[i][k];
			else if (arr[i][k] < min) min = arr[i][k];
		}
	}
	int mid = (min + max) / 2;
	return mid;
}

void Change_array_row(int** arr, int columns, int row_to_change, int value_to_change) {
	for (int k = 0; k < columns; k++) {
			arr[row_to_change - 1][k] = value_to_change;
		}
}

void Print_array(int** arr, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int k = 0; k < columns; k++) {
			cout << arr[i][k] << " ";
		}
		cout << "\n";
	}
}

void Ex_2_var_14_1() {
	int rows = 0;
	int columns = 0;
	cout << "Enter the number of rows and columns in your array" << endl;
	cin >> rows >> columns;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[columns];
	}
	for (int i = 0; i < rows; i++) {
		cout << "Enter the " << i + 1 << " row: " << endl;
		for (int k = 0; k < columns; k++) {
			cin >> arr[i][k];
		}
	}
	int counter = 0;
	for (int i = 0; i < rows; i++) {
		cout << "In the row " << i + 1 << " the number of positive values equals to ";
		for (int k = 0; k < columns; k++) {
			if (arr[i][k] > 0) {
				++counter;
			}
		}
		cout << counter << endl;
		counter = 0;
	}
}

void Ex_2_var_14_2() {
	int rows = 0;
	int columns = 0;
	cout << "Enter the number of rows and columns in your array" << endl;
	cin >> rows >> columns;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[columns];
	}
	for (int i = 0; i < rows; i++) {
		cout << "Enter the " << i + 1 << " row: " << endl;
		for (int k = 0; k < columns; k++) {
			cin >> arr[i][k];
		}
	}
	int max_absolute = 0;
	int max = 0;
	for (int i = 0; i < rows; i++) {
		for (int k = 0; k < columns; k++) {
			if (abs(arr[i][k]) > max_absolute) {
				max_absolute = abs(arr[i][k]);
				max = arr[i][k];
			}
		}
	}
	cout << "The element with the biggest absolute value is " << max << endl;
}

void Ex_2_var_14_3() {
	int rows = 0;
	int columns = 0;
	cout << "Enter the number of rows and columns in your array" << endl;
	cin >> rows >> columns;
	int** arr = new int*[rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[columns];
	}
	Fill_array(arr, rows, columns);
	Print_array(arr, rows, columns);
	cout << "\n";
	int new_val = Mid_min_max(arr, rows, columns);
	int sub_row = 0;
	cout << "Enter the number of a row you would like to substitute (default -- row 1): ";
	cin >> sub_row;
	Change_array_row(arr, columns, sub_row, new_val);
	Print_array(arr, rows, columns);

	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = NULL;
}


int main()
{
	int ex;
	int task;
	cout << "Enter the number of an exercise you would like to look at: ";
	cin >> ex;
	switch (ex) {
	case 1:
		Ex_1_var_9();
		break;
	case 2:
		cout << "Enter the number of a particular task (1 - 3): ";
		cin >> task;
		switch (task) {
		case 1:
			Ex_2_var_14_1();
			break;
		case 2:
			Ex_2_var_14_2();
			break;
		case 3:
			Ex_2_var_14_3();
			break;
		default:
			cout << "No task with this number" << endl;
			break;
		}
		break;
	default:
		cout << "There is no exercise with this number" << endl;
		break;
	}
	return 0;
}