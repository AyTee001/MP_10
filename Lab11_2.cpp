#include <iostream>
#include <stdlib.h>
using namespace std;

int find_first(int arr[], int l, int find) {
	for (int k = l; k < 15; k++) {
		if (arr[k] == find) {
			return k;
		}
	}
	return NULL;
}

void sort(float arr[], int marker, int arr_size) {
	if (marker == 0) {
		for (int j = 0; j < arr_size; j++) {
			for (int i = 0; i < arr_size; i++) {
				if (arr[i] < arr[i + 1]) {
					float c = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = c;
				}
			}
		}
	}
	else if (marker == 1) {
		for (int j = 0; j < arr_size; j++) {
			for (int i = 0; i < arr_size - 1; i++) {
				if (arr[i] < arr[i + 1]) {
					float c = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = c;
				}
			}
		}
	}
	else { cout << "Incorrect argument: enter asc or desc" << endl; }
}

void Ex_1_var_14_1() {
	int quant = 0;
	cout << "How many elements would you like to have in your array?: ";
	cin >> quant;
	float * arr = new float [quant];
	int mark = 0;
	cout << "Enter numbers" << endl;
	for (int i = 0; i < quant; i++) {
		float num = 0;
		cin >> num;
		arr[i] = num;
	}

	if (quant > 1) {
		sort(arr, mark, quant);
		cout << "The second lagrest number is: " << arr[1] << endl;
	}
	else {
		cout << "No second largest number";
	}
	delete[] arr;
}

void Ex_1_var_14_2() {
	int arr[15] = {
		0,1,1,
		0,2,2,
		1,2,1,
		1,0,0,
		0,2,2
	};

	for (int i = 0; i < 15; i++) {
		if (i % 3 == 0 && arr[i] != 0) {
			int temp = arr[i];
			int index = find_first(arr, i, 0);
			arr[i] = arr[index];
			arr[index] = temp;
		}
		else if (i % 3 == 1 && arr[i] != 1) {
			int temp = arr[i];
			int index = find_first(arr, i, 1);
			arr[i] = arr[index];
			arr[index] = temp;
		}
		else if (i % 3 == 2 && arr[i] != 2) {
			int temp = arr[i];
			int index = find_first(arr, i, 2);
			arr[i] = arr[index];
			arr[index] = temp;
		}
	}
	for (int i = 0; i < 15; i++) cout << arr[i] << endl;
}

void Ex_1_var_14_3() {
	int arr_size = 0;
	cout << "Enter array's size: " << endl;
	cin >> arr_size;
	float* arr = new float[arr_size];
	float max = 0;
	cout << "Enter your elements: " << endl;
	for (int i = 0; i < arr_size; i++) {
		cin >> arr[i];
		if (arr[i] > max) max = arr[i];
	}

	float sum = 0;
	
	for (int i = 0; i < arr_size; i++) {
		if (arr[i] >= 0) sum += arr[i];
		else if (arr[i] < 0 && i != 0) {
			sum -= arr[i - 1];
			break;
		}
		else {break;}
	}
	cout << "The sum of all elements before the last positive one is: " << sum << endl;

	float a_start = 0;
	float b_finish = 0;

	cout << "The max element is: " << max << endl;
	cout << "Enter a and b to delete values in range [a,b]: " << endl;
	cin >> a_start;
	cin >> b_finish;
	

	for (int i = 0; i < arr_size; i++) {
		float way = fabs(arr[i]);
		if (a_start <= way && way <= b_finish) {
			arr[i] = 0;
			for (int k = i; k < arr_size - 1; k++) {
				float temp = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = temp;
			}
			i--;
		}
	}
	for (int i = 0; i < arr_size; i++) {
		cout << arr[i] << "\t";
	}
	delete[] arr;
}

void Ex_1_var_14_4() {
	int arr_size = 0;
	cout << "Enter array's size: " << endl;
	cin >> arr_size;
	float* arr = new float[arr_size];
	cout << "Enter your elements: " << endl;
	for (int i = 0; i < arr_size; i++) {
		cin >> arr[i];
	}
	float min = arr[0];
	for (int i = 0; i < arr_size; i++) {
		if (arr[i] < min) min = arr[i];
	 }

	float sum = 0;

	int negatives = 0;

	for (int i = 0; i < arr_size; i++) {
		if (arr[i] < 0) {
			++negatives;
			for (int j = i + 1; j < arr_size; j++)
				if (arr[j] > 0)sum += arr[j];
				else { 
					++negatives;
					break; }
			break;
		}
	}

	if (negatives <= 1) {
		cout << "There are not 2 negative values, so the sum cannot be formed" << endl;
	}
	else {
		cout << "The sum of all elements between the first and the last negative ones is: " << sum << endl;
	}

	float a_start = 0;
	float b_finish = 0;

	cout << "The min element is: " << min << endl;


	for (int i = 0; i < arr_size; i++) {
		float way = fabs(arr[i]);
		if (way <= 1) {
			for (int k = i; k > 1; k--) {
				float temp = arr[k];
				arr[k] = arr[k - 1];
				arr[k - 1] = temp;
			}
		}
	}
	for (int i = 0; i < arr_size; i++) {
		cout << arr[i] << "\t";
	}
	delete[] arr;
}

void Ex_1_var_14_5() {
	int arr_size = 0;
	cout << "Enter array's size: " << endl;
	cin >> arr_size;
	float* arr = new float[arr_size];
	float mult = 1;
	float max = 0;
	float sum = 0;
	cout << "Enter your elements: " << endl;

	for (int i = 0; i < arr_size; i++){
		cin >> arr[i];
		if (arr[i] > max) max = arr[i];
	}
	int negatives = 0;

	for (int i = 0; i < arr_size; i++) {
		if (arr[i] < 0) {
			mult *= arr[i];
			++negatives;
		}
	}
	int positives = 0;
	for (int i = 0; i < arr_size; i++) {
		 if (arr[i] > 0) {
			 ++positives;
			if (arr[i] == max) break;
			else { sum += arr[i]; }
		}
	}
	if (negatives == 0) cout << "There were no negative values" << endl;
	else {
		cout << "Result of multiplication of all negative elements is: " << mult << endl;
	}
	if (positives == 0) cout << "There were no positive values" << endl;
	else {
		cout << "Result of adding all positive elements before the max one is: " << sum << endl;
	}

	sort(arr, 1, arr_size);
		for (int i = 0; i < arr_size; i++) {
			cout << arr[i] << "\t";
		}

	delete[] arr;
}

void Ex_1_var_14_6() {
	int arr_size = 0;
	cout << "Enter array's size: " << endl;
	cin >> arr_size;
	float* arr = new float[arr_size];

	int positive_counter = 0;
	int sum = 0;
	int has_zero = 0;
	cout << "Enter your elements:" << endl;
	for (int i = 0; i < arr_size; i++) {
		cin >> arr[i];
		if (arr[i] > 0) ++positive_counter;
		else if (arr[i] == 0) has_zero = 1;
	}

	cout << "There are " << positive_counter << " positive elements in your array" << endl;

	if (has_zero){
		for (int j = arr_size - 1; j >= 0; j--) {
			if (arr[j] == 0) break;
			sum += arr[j];
		}
		cout << "The sum of all positive elements after the last zero element is: " << sum << endl;
	}
	else { cout << "There were no zeros in your array" << endl; }

	for (int i = 0; i < arr_size; i++) {
		int way = int(fabs(arr[i]));
		if (way <= 1) {
			for (int k = i; k > 0; k--) {
				float temp = arr[k];
				arr[k] = arr[k - 1];
				arr[k - 1] = temp;
			}
		}
	}

	for (int i = 0; i < arr_size; i++) {
		cout << arr[i] << "\t";
	}

	delete[] arr;
}

void Ex_2_var_9() {
	int arr[200];
	int first_ind = 0;
	int last_ind = 0;
	int max_sum = 0;
	for (int i = 0; i < 200; i++) arr[i] = rand() % 101;
	for (int i = 0; i < 190; i++) {
		int new_sum = 0;
		for (int j = i; j < i + 9; j++) {
			new_sum += arr[j];
		}
		if (new_sum > max_sum) {
			first_ind = i;
			last_ind = i + 9;
			max_sum = new_sum;
		}
	}
	for (int i = first_ind; i <= last_ind; i++) {
		cout << arr[i] << "\t";
	}
}

int main()
{
	int ex;
	int task;
	cout << "Enter the number of an ecercise you would like to look at: " << endl;
	cin >> ex;

	switch (ex) {
	case 1:
		cout << "Enter the number of a particular task (1 - 6):" << endl;
		cin >> task;
		switch (task) {
		case 1:
			Ex_1_var_14_1();
			break;
		case 2:
			Ex_1_var_14_2();
			break;
		case 3:
			Ex_1_var_14_3();
			break;
		case 4:
			Ex_1_var_14_4();
			break;
		case 5:
			Ex_1_var_14_5();
			break;
		case 6:
			Ex_1_var_14_6();
			break;
		default:
			cout << "No task with this number" << endl;
			break;
		}
		break;
	case 2:
		Ex_2_var_9();
		break;
	default:
		cout << "There is no exercise with such number" << endl;
		break;
	}

	return 0;
}

