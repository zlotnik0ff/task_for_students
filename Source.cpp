
#include <iostream>



struct Pupil {
	int age;
	int grade;
	char name[20];
	char *surname;
	float avg_mark;
};




void InitMas(int *mas, int n) {
	for (int i = 0; i < n; ++i) {
		mas[i] = rand() % 101 - 50;
	}
}

void PrintMas(int *mas, int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << mas[i]<< '\t';
	}
	std::cout << std::endl;
}

void DeleteNegatives(int *&mas, int &n) {
	int nNegative = 0;
	for (int i = 0; i < n; ++i) {
		if (mas[i] < 0) {
			++nNegative;
		}
	}
	n -= nNegative;
	int *aNewMas = new int[n];
	int step = 0;
	for (int i = 0; i < n + nNegative; ++i) {
		if (mas[i] < 0) {
			++step;
			continue;
		}
		aNewMas[i - step] = mas[i];
	}
	delete[]mas;
	mas = aNewMas;
	PrintMas(mas, n);
}



void DeleteByCondition(int *&mas, int &n, bool(*pred)(int)) {
	int nNegative = 0;
	for (int i = 0; i < n; ++i) {
		if (pred(mas[i])) {
			++nNegative;
		}
	}
	n -= nNegative;
	int *aNewMas = new int[n];
	int step = 0;
	for (int i = 0; i < n + nNegative; ++i) {
		if (pred(mas[i])) {
			++step;
			continue;
		}
		aNewMas[i - step] = mas[i];
	}
	delete[]mas;
	mas = aNewMas;
	PrintMas(mas, n);
}


bool IsPositive(int item) {
	return item > 0;
}

bool IsNegative(int item) {
	return item < 0;
}

bool IsOdd(int item) {
	return item % 2;
}

void PrintPupilInfo(Pupil pup) {
	std::cout << "Name:=" << pup.name << "Age:" << pup.age << std::endl;
}


int main()
{
	Pupil me;
	me.age = 18;
	me.grade = 99;
	strcpy(me.name, "Karl");
	me.avg_mark = 99.5f;
	PrintPupilInfo(me);

	void(*some_f_pointer)(int *, int) = InitMas;
	const int* a;
	int const* b;
	int* const p=NULL;

	int n;
	std::cin >> n;
	int *mas = new int[n];

	some_f_pointer(mas, n);
	PrintMas(mas, n);

	DeleteByCondition(mas, n, [](int a) -> bool { return a % 2; });
	
	PrintMas(mas, n);
	delete[] mas;

	system("pause");
	return 0;
}