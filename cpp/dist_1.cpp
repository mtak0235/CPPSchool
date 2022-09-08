#include <iostream>
#include <cmath>
using namespace std;

void get_input(float *re) {
	for (int i = 0; i < 3; i++) {
		cin >> re[i];
	}
}

float get_distance(float* _from, float* _to) {
	float _dist = 0;
	for (int i = 0; i < 3; i++) {
		_dist += powf(_from[i] - _to[i], 2);
	}
	return  sqrt(_dist);
}

int main() {
	float _from[3];
	float _to[3];
	get_input(_from);
	get_input(_to);
	cout << get_distance(_from, _to);
}