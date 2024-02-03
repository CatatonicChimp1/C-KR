#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
//Task3
//void F_Massiv(int* arr, int size) {
//    for (int i = 0; i < size; ++i) {
//        arr[i] = rand() % 50 + 1;
//}
//}
//void F_Vivod(int* arr, int size) {
//    std::cout << "Massiv:";
//    for (int i = 0; i < size; ++i) {
//        std::cout << arr[i] << " ";
//    }
//   std::cout << std::endl;
//}
//void F_Raznost(int* arr, int size, int zad_ch) {
//    std::cout << "Pars elements with raznost" << zad_ch << ": ";
//    for (int i = 0; i < size - 1; ++i) {
//        for (int j = i + 1; j < size; ++j) {
//            if (abs(arr[i] - arr[j]) == zad_ch) {
//                std::cout << "(" << arr[i] << ", " << arr[j] << ") ";
//            }
//        }
//    }
//    std::cout << std::endl;
//}
//int main()
//{
//    srand(time(0));
//    int size;
//    std::cout << "Size: ";
//    std::cin >> size;
//    int* dynamicArray = new int[size];
//    F_Massiv(dynamicArray, size);
//    F_Vivod(dynamicArray, size);
//    int zad_ch;
//    std::cout << "Vedite chislo dlya raznosti: ";
//    std::cin >> zad_ch;
//    F_Raznost(dynamicArray, size,zad_ch);
//    delete[] dynamicArray;
//    return 0;
//}

//Task4
struct POP_task{
	std::string title;
	std::string description;
};
typedef void (*TaskFunction)(POP_task*, int&);

void del_POP(POP_task* tasks, int& POP_Cnt) {
	if (POP_Cnt == 0) {
		std::cout << "Spisok zadach pystoy" << std::endl;
		return;
	}
	int index;
	std::cout << "Enter numder of task for delete: ";
	std::cin >> index;

	if (index >= 0 && index < POP_Cnt) {
		for (int i = index; i < POP_Cnt - 1; ++i) {
			tasks[i] = tasks[i + 1];
		}
		--POP_Cnt;
		std::cout << "Task delete." << std::endl;
	}
	else {
		std::cout << "Wrong number of task." << std::endl;
	}
}
void add_POP(POP_task* tasks, int& POP_Cnt) {
	POP_task newTask;
	std::cout << "Enter numder of task: ";
	std::cin.ignore();
	std::getline(std::cin, newTask.title);
	std::cout << "Enter opicanie task: ";
	std::getline(std::cin, newTask.description);
	tasks[POP_Cnt++] = newTask;
	std::cout << "Task add." << std::endl;
}

void update_POP(POP_task* tasks, int& POP_Cnt) {
	if (POP_Cnt == 0) {
		std::cout << "Task list is empty." << std::endl;
		return;
	}
	int index;
	std::cout << "Enter numder of task for update: ";
	std::cin >> index;

	if (index >= 0 && index < POP_Cnt) {
		POP_task& task = tasks[index];
		std::cout << "Enter new opicanie task: ";
		std::cin.ignore();
		std::getline(std::cin, task.description);
		std::cout << "Task update." << std::endl;
	}
	else {
		std::cout << "Wrong number of task." << std::endl;
	}
}

	void display_POP(POP_task * tasks, int& POP_Cnt){
		if (POP_Cnt == 0) {
			std::cout << "Task list = 0." << std::endl;
			return;
		}
		std::cout << "TAsk list:" << std::endl;
		for (int i = 0; i < POP_Cnt; ++i) {
			std::cout << i << ". " << tasks[i].title << ": " << tasks[i].description << std::endl;
		}
	}
int main() {
	const int maxTasks = 100;
	POP_task tasks[maxTasks];
	int taskCount = 0;
	TaskFunction taskFunctions[] = { add_POP, del_POP, update_POP, display_POP};
	while (true) {
		std::cout << "Enter task:" << std::endl;
		std::cout << "1. Enter task" << std::endl;
		std::cout << "2. Delete task" << std::endl;
		std::cout << "3. Update task" << std::endl;
		std::cout << "4.Task list" << std::endl;
		std::cout << "0. Exit" << std::endl;

		int choice;
		std::cin >> choice;

		if (choice < 0 || choice > 4) {
			std::cout << "Wrong.Try again" << std::endl;
			continue;
		}

		if (choice == 0) {
			std::cout << "Exit." << std::endl;
			break;
		}

		taskFunctions[choice - 1](tasks, taskCount);
	}

	return 0;
}