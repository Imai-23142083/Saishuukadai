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
	cout << "新しいタスクを入力してください:";
	string title;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, title);
	tasks.push_back(Task(title));
	cout << "タスクを追加しました" << endl;
}

void viewTasks(const vector<Task>& tasks) {
	if (tasks.empty()) {
		cout << "タスクはありません" << endl;
		return;
	}

	cout << "タスクリスト" << endl;
	int index = 1;
	for (auto it = tasks.begin(); it != tasks.end(); ++it) {
		cout << index << ". ";
		if (it->isCompleted()) {
			cout << "[完了]";
		}
		else {
			cout << "[未完了]";
		}
		cout << it->getTitle() << endl;
		index++;
	}
}

	void completeTask(vector<Task>& tasks) {
		if (tasks.empty()) {
			cout << "タスクはありません" << endl;
			return;
		}

		viewTasks(tasks);
		cout << "完了するタスクの番号を入力してください";
		int taskIndex;
		cin >> taskIndex;

		if (taskIndex > 0 && taskIndex <= tasks.size()) {
			tasks[taskIndex - 1].markAsCompleted();
		}else {
			cout << "無効な番号です" << endl;
		}
	}

	void deleteTask(vector<Task>& tasks){
		if (tasks.empty()) {
			cout << "タスクがありません" << endl;
			return;
		}

		viewTasks(tasks);
		cout << "削除するタスクの番号を入力してください";
		int taskIndex;
		cin >> taskIndex;

		if (taskIndex > 0 && taskIndex <= tasks.size()) {
			auto it = tasks.begin() + (taskIndex - 1);
			tasks.erase(it);
			cout << "タスクを削除しました" << endl;
		}else {
			cout << "無効な番号です" << endl;
		}
	}

	int main() {
		vector<Task> tasks;
		int choice;

		while (true) {
			cout << "メニュー" << endl;
			cout << "1. タスクを追加" << endl;
			cout << "2. タスクを表示" << endl;
			cout << "3. タスクを完了" << endl;
			cout << "4. タスクを削除" << endl;
			cout << "5. 終了" << endl;
			cout << "選択" << endl;
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
				cout << "アプリケーションを終了します" << endl;
				return 0;
			default:
				cout << "無効な選択です。もう一度入力してください" << endl;
				break;
			}
		}
		return 0;
	}


