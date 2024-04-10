#include "src/funcs/Myfraction.hpp"
#include "src/funcs/MyMatrix.hpp"
#include "src/funcs/LinkedList.hpp"

int main()
{
try {
	srand(time(NULL));
	std::cout << ".............FRACTION..............\n";

	MyFraction fraction1;
	std::cout << fraction1 << '\n';
	MyFraction fraction2(3, -15);
	MyFraction fraction3(fraction2);

	std::cout << fraction3 << '\n';

	std::cout << fraction1.getNum() << " " << fraction2.getNum() << " " << fraction3.getNum() << '\n';
	std::cout << fraction1.getDen() << " " << fraction2.getDen() << " " << fraction3.getDen() << '\n';

	fraction1.setNum(14);
	fraction2.setNum(4);
	fraction3.setNum(-62);
	std::cout << fraction1 << " " << fraction2 << " " << fraction3 << '\n';

	std::cout << "...........MATRIX........\n";
	Matrix matrix1(1, 1);
	std::cout << matrix1;
	matrix1.setElement(0, 0, 41);
	std::cout << matrix1 << '\n';
	std::cout << matrix1 * 3;
}
catch (std::invalid_argument& e) {
	std::cerr << e.what() << '\n';
}
catch (std::out_of_range& e) {
	std::cerr << e.what() << '\n';
}
catch (std::runtime_error& e) {
	std::cerr << e.what() << '\n';
}
return 0;
}