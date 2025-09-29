#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a1("Alice", 42);
		std::cout << a1 << std::endl;
		Bureaucrat b1("Bob", 150);
		std::cout << b1 << std::endl;
		Bureaucrat c1("Charles", 1);
		std::cout << c1 << std::endl;

		a1.incrementGrade();
		std::cout << "After increment: " << a1 << std::endl;

		b1.decrementGrade();
		std::cout << "After decrement: " << b1 << std::endl;

		c1.incrementGrade();
		std::cout << "After increment: " << c1 << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
