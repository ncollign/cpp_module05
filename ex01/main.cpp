#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    Bureaucrat alice("Alice", 50);
    Form f1("Permit-A", 60, 30); // OK
    Form f2("Permit-B", 40, 30); // KO

    std::cout << f1 << "\n" << f2 << "\n";

    alice.signForm(f1); // attendu: "Alice signed Permit-A"
    alice.signForm(f2); // attendu: "Alice couldn’t sign Permit-B because Form: grade too low"

    std::cout << f1 << "\n" << f2 << "\n";
    return 0;
}
