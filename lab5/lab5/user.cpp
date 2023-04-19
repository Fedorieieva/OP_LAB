#include "user.h"

void intro() {
	cout << "There will be created a class TBody that represents a spatial geometric figure" << endl;
	cout << "with methods for calculating its surface area and volume." << endl;
	cout << "Based on this classes, there will becreated derived classes TParallelepiped and TBall. " << endl;
	cout << "There will bw created a certain number of parallelepipeds and spheres so that their " << endl;
	cout << "total number equals the netered number." << endl;
	cout << "the task is to find the total volume for the spheres and" << endl;
	cout << "the sum of surface areas for the parallelepipeds." << endl << endl;
}

void user() {
	void input(TParallelepiped * p, int n);
	void input(TBall * b, int n);
	double parameter_sum(TParallelepiped * p, int n);
	double parameter_sum(TBall * b, int n);
	void output(TParallelepiped * p, int n);
	void output(TBall * b, int n);

	int num, n_p = 0, n_b = 0;
	char choice = 'n';

	cout << "Enter the total number of figures: ";
	cin >> num;
	cout << "Do you want a random number of parallelepipeds and balls between 1 and " << num << " [y/n]: ";
	cin >> choice;

	if (choice == 'y' || choice == 'Y') {
		srand(time(NULL));
		n_p = rand() % num + 1;
		n_b = num - n_p;
		cout << "There will be " << n_p << " parallelepipeds and " << n_b << " balls" << endl;
	}
	else {
		cout << endl << "Please enter the number of parallelepipeds: ";
		cin >> n_p;
		n_b = num - n_p;
		cout << "There will be " << n_b << " balls" << endl;
	}

	TParallelepiped* parallelepipeds = new TParallelepiped[n_p];
	TBall* balls = new TBall[n_b];

	input(parallelepipeds, n_p);
	input(balls, n_b);

	output(parallelepipeds, n_p);
	cout << endl << "Area sum of all parallelepipeds equals " << parameter_sum(parallelepipeds, n_p) << endl;

	output(balls, n_b);
	cout << endl << "Volume sum of all balls equals " << parameter_sum(balls, n_b) << endl;

	delete[] parallelepipeds;
	delete[] balls;
}

void input(TParallelepiped* p, int n) {
	double h = 0, l = 0, w = 0;
	for (int i = 0; i < n; i++) {
		cout << endl << "Please enter parameters for your parallelepiped number " << i + 1 << ":" << endl;
		cout << "height = ";
		cin >> h;
		cout << "lenght = ";
		cin >> l;
		cout << "width = ";
		cin >> w;
		new(&p[i]) TParallelepiped(h, l, w);
	}
}

void input(TBall* b, int n) {
	double r = 0;
	for (int i = 0; i < n; i++) {
		cout << endl << "Please enter radious for your ball number " << i + 1 << ":" << endl;
		cout << "radious = ";
		cin >> r;
		new(&b[i]) TBall(r);
	}
}

void output(TParallelepiped* p, int n) {
	cout << "-------------------------------------------------------------" << endl;
	cout << endl << "Here you can see your parallelepipeds and there area:";
	for (int i = 0; i < n; i++) {
		cout << endl << "Parallelepiped number " << i + 1 << ":" << endl;
		cout << p[i];
		cout << endl << "area = " << p[i].area() << endl;
	}
}

void output(TBall* b, int n) {
	cout << "-------------------------------------------------------------" << endl;
	cout << endl << "Here you can see your balls and there volume:";
	for (int i = 0; i < n; i++) {
		cout << endl << "Ball number " << i + 1 << ":" << endl;
		cout << b[i];
		cout << endl << "volume = " << b[i].volume() << endl;
	}
}

double parameter_sum(TParallelepiped* p, int n) {
	double res = 0;
	for (int i = 0; i < n; i++) {
		res += p[i].area();
	}
	return res;
}

double parameter_sum(TBall* b, int n) {
	double res = 0;
	for (int i = 0; i < n; i++) {
		res += b[i].volume();
	}
	return res;
}