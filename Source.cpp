#include <iostream>

using namespace std;

template <typename T>
void printWithTab(T toPrint)
{
	cout << toPrint << '\t';
}


struct Pupil
{
	int age;
	char name[50];
	char surname[60];
	char grade[60];
	float avgMark;

	void fillTheFields()
	{
		cout << endl;
		cout << "Age - ";
		cin >> age;
		cout << "Name is ";
		cin >> name;
		cout << "Surname is ";
		cin >> surname;
		cout << "Grade: ";
		cin >> grade;
		cout << "Average mark = ";
		cin >> avgMark;
		cout << endl;
	};

	Pupil *next; 
};

class List
{
private:
	Pupil *head;

public:

	List() { head = NULL; };
	~List()
	{
		while (head != NULL)
		{
			Pupil *temp = head->next;
			delete head;
			head = temp;
		}
	};

	void add(Pupil &pupil)
	{
		Pupil *temp = new Pupil;
		temp->next = head;

		temp->age = pupil.age;
		strcpy(temp->name, pupil.name);
		strcpy(temp->surname, pupil.surname);
		strcpy(temp->grade, pupil.grade);
		temp->avgMark = pupil.avgMark;

		head = temp;
	};
	

	void printAllFields()
	{
		Pupil *temp = head;

		while (temp != NULL)
		{
			printWithTab(temp->age);
			printWithTab(temp->name);
			printWithTab(temp->surname);
			printWithTab(temp->grade);
			printWithTab(temp->avgMark);
			cout << endl;
			
			temp = temp->next;
		}
		cout << endl;
	};
};


int main()
{
	Pupil pupil;
	int quantity;  
	List lst;

	cout << "Quantity = ";
	cin >> quantity;

	for (int i = 0; i < quantity; i++)
	{
		pupil.fillTheFields();
		lst.add(pupil);
	}

	cout << endl;
	lst.printAllFields();
	getchar();
}