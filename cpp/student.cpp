#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
	private:
		string name;
		int studentId;
		static int key;
	public:
		Student(string name) : name(name), studentId(++key) {};
		string getName(){return name;};
		int getStudentId() {return studentId;};
		void setName(string name) { this->name = name;};
		Student *clone() const {
			return (new Student(*this));
		}
};
int Student::key = 220000;

class StudentTable {
	public:
		vector<Student *> studentList;
	public:
		~StudentTable(){
			vector<Student*>::iterator ite = this->studentList.end();
			for (vector<Student*>::iterator it = this->studentList.begin(); it != ite; ++it)
				delete *it;
			this->studentList.clear();
		};
		void insert(Student *student){
			if (student) {
				vector<Student*>::iterator ite = this->studentList.end();
				for (vector<Student*>::iterator it = this->studentList.begin(); it != ite; ++it)
					if ((*it)->getStudentId() == student->getStudentId())
						return ;
				this->studentList.push_back(student->clone());
			}
		};
		Student *search(int studentId){
			vector<Student*>::iterator ite = this->studentList.end();
			for (vector<Student*>::iterator it = this->studentList.begin(); it != ite; ++it) {
				if ((*it)->getStudentId() == studentId)
					return (*it);
			}
			return nullptr;
		};
		void print(){
			vector<Student*>::iterator ite = this->studentList.end();
			for (vector<Student*>::iterator it = this->studentList.begin(); it != ite; ++it) {
				cout <<"\033[34m" << (*it)->getName() << "\033[35m\t" << (*it)->getStudentId() << "\033[37m"<<endl;
			}
		};
};

int main() {
	StudentTable students;
	string candidates[] = {"mtak", "taeskim", "seonkim", "jinchoi", "hailey"};
	cout << "\033[36m" << "========="<< "insert()" << "=========" << "\033[37m" << endl;
	for (int i = 0; i < sizeof(candidates)/sizeof(*candidates) ; i++) {
		Student *student = new Student(candidates[i]);
		students.insert(student);
	}
	students.print();
	cout << "\033[36m" << "========="<< "search()" << "=========" << "\033[37m" << endl;
	Student *searchingStudent = students.search(220000);
	cout << "Does studentId 220000 exist?" << endl;
	if (searchingStudent)
		cout << "\033[34m" << searchingStudent->getName() << "\033[35m\t" << searchingStudent->getStudentId() << "\033[37m"<< endl;
	else
		cout << "Doesn't exist" << endl;
	cout << "Does studentId 220001 exist?" << endl;
	searchingStudent = students.search(220001);
	if (searchingStudent)
		cout << "\033[34m" << searchingStudent->getName() << "\033[35m\t" << searchingStudent->getStudentId() << "\033[37m"<< endl;
	else
		cout << "Doesn't exist" << endl;
		
	

}

