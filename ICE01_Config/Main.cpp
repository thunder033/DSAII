#include "Main.h"
using namespace std;

int length(char* string) {
	int len = 0;
	while ((*(string + len)) != '\0') {
		len++;
	}
	return len;
}

class Point
{
public:
	string a;
	Point() {
		a = "stuff";
		this->a = "more stuff";
	}
};


void main(void) {
	int j = 0;
	int* i = &j;

	const int k = 1;
	//i = 2;

	int * const l = &j;
	//l = &j;
	*l = 3;
	cout << (*l);

	int const * const m = &j;
	//m = &k;
	//*m = 3;
	cout << (*m) << endl;

	int* numbers = new int[5];
	*(numbers + sizeof(int) * 3) = 4;
	int arr[4] = { 1, 2, 3, 4 };

	int a;
	cin >> a;
	int b;
	cin >> b;
	int** numbers2 = new int*[a];
	for (size_t i = 0; i < b; i++)
	{
		numbers2[i] = new int[b];
	}

	Point aa;

	char myStr[6] = { 'h','e','l','l','o', '\0'};
	cout << length(myStr);

	cout << "Hello Word" << endl;
	cout << "Press Enter to continue...";
	getchar();
}