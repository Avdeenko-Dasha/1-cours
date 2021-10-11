#include <iostream>
#include "Human.h"
#include "Car.h"
#include "Bag.h"
#include "Bicycles.h"

using namespace std;

int main()
{
	Bicycles bicycles(19, 23, 55.7, 43.9, 1, 0, 1, 0, "red");
	bicycles.Print();
}