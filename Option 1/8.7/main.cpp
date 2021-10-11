#include "class_8.7.h"

const int MAX_SIZE = 65000;

int main(void)
{

	cout << "Enter the number of graph's elements:" << endl;
	cout << "N = ";
	int n = 0;
	enter(cin, n);
	if (n > MAX_SIZE)
	{
		cout << "Too many graphs!" << endl;
		return 0;
	}
	cout << endl;

	Graf<int> graf;

	cout << "Enter elements of the graf:" << endl;
	graf.input(n);
	cout << endl;
	cout << "Elements of the graf:" << endl;
	graf.output();
	cout << endl;
	int x = 0;
	cout << "Enter vertex of the graf: ";
	enter(cin, x);
	cout << "Inaccessible vertex: ";
	vector<int> arr = graf.function(x, n);
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
	return 0;
}