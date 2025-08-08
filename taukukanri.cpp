#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Task {
private:
	string title;
	bool completed;

public:
	Task(const string&title) : title(title), completed(false) {}
	string getTitle() const { return title; }
	bool isCompleted() const { return completed; }
	void markAsCompleted() { completed = true; }
};

void addTask(vector<Task>& tasks) {
	cout << "�V�����^�X�N����͂��Ă�������:";
	string title;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, title);
	tasks.push_back(Task(title));
	cout << "�^�X�N��ǉ����܂���" << endl;
}

void viewTasks(const vector<Task>& tasks) {
	if (tasks.empty()) {
		cout << "�^�X�N�͂���܂���" << endl;
		return;
	}

	cout << "�^�X�N���X�g" << endl;
	int index = 1;
	for (auto it = tasks.begin(); it != tasks.end(); ++it) {
		cout << index << ". ";
		if (it->isCompleted()) {
			cout << "[����]";
		}
		else {
			cout << "[������]";
		}
		cout << it->getTitle() << endl;
		index++;
	}
}

	void completeTask(vector<Task>& tasks) {
		if (tasks.empty()) {
			cout << "�^�X�N�͂���܂���" << endl;
			return;
		}

		viewTasks(tasks);
		cout << "��������^�X�N�̔ԍ�����͂��Ă�������";
		int taskIndex;
		cin >> taskIndex;

		if (taskIndex > 0 && taskIndex <= tasks.size()) {
			tasks[taskIndex - 1].markAsCompleted();
		}else {
			cout << "�����Ȕԍ��ł�" << endl;
		}
	}

	void deleteTask(vector<Task>& tasks){
		if (tasks.empty()) {
			cout << "�^�X�N������܂���" << endl;
			return;
		}

		viewTasks(tasks);
		cout << "�폜����^�X�N�̔ԍ�����͂��Ă�������";
		int taskIndex;
		cin >> taskIndex;

		if (taskIndex > 0 && taskIndex <= tasks.size()) {
			auto it = tasks.begin() + (taskIndex - 1);
			tasks.erase(it);
			cout << "�^�X�N���폜���܂���" << endl;
		}else {
			cout << "�����Ȕԍ��ł�" << endl;
		}
	}

	int main() {
		vector<Task> tasks;
		int choice;

		while (true) {
			cout << "���j���[" << endl;
			cout << "1. �^�X�N��ǉ�" << endl;
			cout << "2. �^�X�N��\��" << endl;
			cout << "3. �^�X�N������" << endl;
			cout << "4. �^�X�N���폜" << endl;
			cout << "5. �I��" << endl;
			cout << "�I��" << endl;
			cin >> choice;

			switch (choice) {
			case 1:
				addTask(tasks);
				break;
			case 2:
				viewTasks(tasks);
				break;
			case 3:
				completeTask(tasks);
				break;
			case 4:
				deleteTask(tasks);
				break;
			case 5:
				cout << "�A�v���P�[�V�������I�����܂�" << endl;
				return 0;
			default:
				cout << "�����ȑI���ł��B������x���͂��Ă�������" << endl;
				break;
			}
		}
		return 0;
	}


