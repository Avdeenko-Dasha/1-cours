#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int Lx = 0, Ly = 0, Fx = 0, Fy = 0;
	cin >> Lx >> Ly >> Fx >> Fy;
	if (Lx == Fx || Ly == Fy)
		cout << "The figures beat each other";
	else if (abs(Fx - Lx) == abs(Fy - Ly))
		cout << "The queen beats the rook";
	else cout << "Figures don't hit each other. A move is possible for example: " << Fx << " " << Ly;
	return 0;
}