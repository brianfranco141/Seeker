#include "UserAccountHandler.hpp"

void Logical_View::Domain::UserAccount::UserAccountHandler::authenticate(std::string userName, std::string passPhrase) {
	if (userName == "khoinguyen123" && passPhrase == "462isawesome!"){
		std::cout << "Successfully Logged In \n";
	}
	else if (userName == "student" && passPhrase == "462isawesome!") {
		std::cout << "Successfully Logged In \n";
	}
	else if (userName == "student1" && passPhrase == "462isawesome!") {
		std::cout << "Successfully Logged In \n";
	}
	else {
		std::cout << "Logged In failed \n";
	}
}

void Logical_View::Domain::UserAccount::UserAccountHandler::createProfile(std::string name, std::string dateOfBirth, std::string phoneNumber, std::string email, std::string Resume) {
	realName = name;
	birthDate = dateOfBirth;
	phoneNum = phoneNumber;
	emailAddress = email;
	resumeFileName = Resume;
	std::cout << "Profile Created \n";
}

bool Logical_View::Domain::UserAccount::UserAccountHandler::isProfileEmpty() {
	return true;
}
