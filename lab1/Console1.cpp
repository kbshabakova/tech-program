#include <iostream>
#include <string>

class Student {
public:
	int id = 0;
	std::string name = "";
	double AvgPoints = 0;
	static int count; 
	Student* next = nullptr;
public:
	Student(int id = 0, std::string name = "", double AvgPoints = 60) :name(name) {
		this->id = id;
		this->AvgPoints = AvgPoints;
		count++;
	}
	~Student() {
		count--;
	}
};

int Student::count = 0;

class Decanat {
public:
	Student* list = nullptr; // Указатель на начало списка 
public:
	void AddFront(Student* stud) {
		stud->next = list; // Новый студент указывает на текущий список
		list = stud;       // Новый студент становится началом списка 
	}

	void AddBack(Student* stud) {
		if (list == nullptr) {
			list = stud; 
		}
		else {
			Student* temp = list;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = stud; // Добавляем в конец
		}
	}

	void AddAfter(Student* stud, int afterId) {
		Student* temp = list;
		while (temp != nullptr) {
			if (temp->id == afterId) {      //добавляет новый Student(студент) после студента в списке, чей id совпадает с afterId.
				stud->next = temp->next;
				temp->next = stud;
				return;
			}
			temp = temp->next; 
		}
		std::cout << "Студент с id " << afterId << " не найден." << std::endl;
	}

	void AddBefore(Student* stud, int beforeId) {
		if (list == nullptr) {
			std::cout << "Список пуст, нельзя добавить перед." << std::endl;
			return;
		}

		if (list->id == beforeId) {         //добавляет новый Student (stud) передStudent в списке, id которого совпадает с beforeId.
			stud->next = list;
			list = stud;
			return;
		}

		Student* temp = list;
		while (temp->next != nullptr) {
			if (temp->next->id == beforeId) {  //перед существующим Student в списке, id которого равен beforeId.
				stud->next = temp->next;
				temp->next = stud;
				return;
			}
			temp = temp->next;
		}
		std::cout << "Студент с id " << beforeId << " не найден." << std::endl;
	}

	void Remove(int id) {    //Эта функция удаляет Student из связанного списка на основе их id.
		if (list == nullptr) return;

		if (list->id == id) {
			Student* tmp = list;
			list = list->next;
			delete tmp;
			return;
		}

		Student* temp = list;
		while (temp->next != nullptr) {
			if (temp->next->id == id) {
				Student* tmp = temp->next;
				temp->next = temp->next->next;
				delete tmp;
				return;
			}
			temp = temp->next;
		}
	}

	void PrintList() {       //Эта функция выводит содержимое связанного списка на консоль.
		Student* temp = list;
		while (temp != nullptr) {
			std::cout << "id:" << temp->id << " name:" << temp->name << " avg point:" << temp->AvgPoints << std::endl;
			temp = temp->next;
		}
	}
};

int main() {
	Decanat decanat;

	
	for (int i = 0; i < 6; i++) {
		Student* tmp = new Student(i, "Student" + std::to_string(i), i * 10 + 50);
		decanat.AddBack(tmp); 
	}

	
	std::cout << "Первоначальный список(PrintList):" << std::endl;
	decanat.PrintList();
	std::cout << std::endl;

	
	Student* newFront = new Student(100, "NewFront", 95);
	decanat.AddFront(newFront);
	std::cout << "Список после добавления(AddFront) на передний план:" << std::endl;
	decanat.PrintList();
	std::cout << std::endl;

	
	Student* newAfter = new Student(200, "NewAfter", 80);
	decanat.AddAfter(newAfter, 2);
	std::cout << "Список после добавления(AddAfter) после идентификатора 2:" << std::endl;
	decanat.PrintList();
	std::cout << std::endl;

	
	Student* newBefore = new Student(300, "NewBefore", 70);
	decanat.AddBefore(newBefore, 4);
	std::cout << "Список после добавления(AddBefore) перед идентификатором 4:" << std::endl;
	decanat.PrintList();
	std::cout << std::endl;

	
	decanat.Remove(3);
	std::cout << "Список после удаления(Remove) студента с идентификатором 3:" << std::endl;
	decanat.PrintList();
	std::cout << std::endl;

	
	Student* current = decanat.list;
	while (current != nullptr) {
		Student* next = current->next;
		delete current;
		current = next;
	}

	return 0;
}

