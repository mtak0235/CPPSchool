#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
class Graph {
    public:
    map<int, vector<int>> root;
    map<int, vector<int>>::iterator search(int key) {
        return root.find(key);
    };
    void insert(int from, int to) {
        map<int, vector<int>>::iterator f = search(from);
        map<int, vector<int>>::iterator t = search(to);
        if (f == root.end() || t == root.end()) {
            vector<int> value;
            value.push_back(to);
            root.insert({from, value});
            vector<int> value2;
            value2.push_back(from);
            root.insert({to, value2});
            return ;
        } 
        if (find(f->second.begin(), f->second.end(), to) == f->second.end()) f->second.push_back(to);
        if (find(t->second.begin(), t->second.end(), from) == t->second.end()) t->second.push_back(from);
    };
    void print() {
        for (auto itr = root.begin(); itr != root.end(); itr++) {
            cout << "[" << itr->first << "] : ";
            for (auto itrr = itr->second.begin(); itrr != itr->second.end(); itrr++)
                cout << *itrr << " ";
            cout << "\n";
        }
    };
};

int main(int ag, char **av) {
    Graph graph;
    if (ag != 2) {
        cout << "write the file name when you execute program\n";
        exit(1);
    }
    fstream edgeFile;
    edgeFile.open(av[1], ios::in);
    if (!edgeFile) {
        cout << "No such file\n";
        exit(1);
    }
    for (string line; getline(edgeFile, line);) {
        stringstream stream;
        stream.str(line);
        int set[2];
        int cnt = 0;
        for (string val; getline(stream, val, ';');)
            set[cnt++] = stoi(val);
        graph.insert(set[0], set[1]);
    }
    graph.print();
    edgeFile.close();
}