#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void trySign(Bureaucrat& b, AForm& f) {
    std::cout << "\n[trySign] " << b.getName() << " tries to sign " << f.getName() << "\n";
    b.signForm(f);
    std::cout << f << "\n";
}

static void tryExec(Bureaucrat const& b, AForm const& f) {
    std::cout << "[tryExec] " << b.getName() << " tries to execute " << f.getName() << "\n";
    b.executeForm(f);
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::cout << "===== Setup =====\n";
    Bureaucrat lowSigner("LowSigner", 146);
    Bureaucrat okShrubSigner("OkShrubSigner", 145);
    Bureaucrat okShrubExec("OkShrubExec", 137);
    Bureaucrat badExec("BadExec", 138);
    Bureaucrat roboSigner("RoboSigner", 72);
    Bureaucrat roboExecOK("RoboExecOK", 45);
    Bureaucrat roboExecLow("RoboExecLow", 46);
    Bureaucrat prezSigner("PrezSigner", 25);
    Bureaucrat prezExecOK("PrezExecOK", 5);
    Bureaucrat prezExecLow("PrezExecLow", 6);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm   robo("Bender");
    PresidentialPardonForm prez("Ford Prefect");

    std::cout << shrub << "\n" << robo << "\n" << prez << "\n";

    std::cout << "\n===== 1) SHRUBBERY =====\n";
    // 1.a exécution NON-signée -> doit échouer (NotSigned)
    tryExec(okShrubExec, shrub);

    // 1.b signature par grade trop BAS -> KO
    trySign(lowSigner, shrub);

    // 1.c signature par grade suffisant -> OK
    trySign(okShrubSigner, shrub);

    // 1.d exécution par grade trop BAS -> KO
    tryExec(badExec, shrub);

    // 1.e exécution par grade suffisant -> OK (crée <home>_shrubbery)
    tryExec(okShrubExec, shrub);

    std::cout << "\n===== 2) ROBOTOMY =====\n";
    // 2.a signer OK
    trySign(roboSigner, robo);

    // 2.b exécuter avec grade insuffisant -> KO
    tryExec(roboExecLow, robo);

    // 2.c exécuter avec grade OK -> OK (50% succès)
    tryExec(roboExecOK, robo);

    std::cout << "\n===== 3) PRESIDENTIAL PARDON =====\n";
    // 3.a signer OK
    trySign(prezSigner, prez);

    // 3.b exécuter avec grade insuffisant -> KO
    tryExec(prezExecLow, prez);

    // 3.c exécuter avec grade OK -> OK (message pardon)
    tryExec(prezExecOK, prez);

    std::cout << "\n===== Done =====\n";
    return 0;
}
