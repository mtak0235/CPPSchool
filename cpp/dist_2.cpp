#include <iostream>
#include <cmath>
using namespace std;

float *get_input() {
	float *re = new float[3];
	for (int i = 0; i < 3; i++) {
		cin >> re[i];
	}
	return re;
}

class Coordinate {
	private:
	float *coordinate;

	public:
	Coordinate(float *c): coordinate(c){};
	~Coordinate() {delete []coordinate;};
	float get_distance(Coordinate &target) {
		float _dist = 0;
		for (int i = 0; i < 3; i++) {
			_dist += powf(this->coordinate[i] - target.coordinate[i], 2);
	}
	return  sqrt(_dist);
	};
};


int main() {
	Coordinate f(::get_input());
	Coordinate t(::get_input());
	cout << f.get_distance(t) << endl;
}