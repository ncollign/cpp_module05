#include <ctime>
#include <cstdlib>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    // 1) Form connue
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    // 2) Form inconnue
    AForm* nope = someRandomIntern.makeForm("unknown thing", "Anyone");
    if (nope) delete nope;

    // 3) Une autre connue
    AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "home");
    if (shrub) {
        boss.signForm(*shrub);
        boss.executeForm(*shrub);
        delete shrub;
    }

    // 4) Pardon
    AForm* prez = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    if (prez) {
        boss.signForm(*prez);
        boss.executeForm(*prez);
        delete prez;
    }

    return 0;
}
