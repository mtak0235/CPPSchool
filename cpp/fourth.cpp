#include <iostream>
#include <string>

using namespace std;

class Node {
	private:
	string name;
	int freq;
	public:
	Node():name(), freq(0){};
	Node(string name):name(name), freq(1){};
	void addFreq(){freq++;}
	string getName(){return name;};
	int getFreq(){return freq;};
};
class StringTable {
private:
int capacity;
int size;
Node **arr;
public:
StringTable(int capacity):capacity(capacity), size(0) {
	arr = new Node*[capacity];
	};
~StringTable(){
	delete []arr;
};
void insert() {
	cout << "저장할 문자열 " << capacity << "개를 입력하세요\n";
	for (int i = 0; i < capacity ; i++) {
		string target;
		cin >> target;
		Node *tmp = search(target);
		if (!tmp) {
			arr[size] = new Node(target);
			size++;
		}
		else
			tmp->addFreq();
	}
};
Node *search(string target) {
	for (int i = 0; i < size; i++) {
		if (target == arr[i]->getName()) {
			return arr[i];
		}
	}
	return NULL;
};
void printTable(){
	cout << "name | freq\n"; 
	for (int i = 0 ; i < size; i++) {
		cout << arr[i]->getName() << "|" << arr[i]->getFreq()<<  endl;
	}
};
};

int main() {
	cout << "테이블의 크기를 입력하세요\n";
	int size;
	cin >> size;
	StringTable st(size) ;
	st.insert();
	st.printTable();
}