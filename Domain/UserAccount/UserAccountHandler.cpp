#include "UserAccountHandler.hpp"

void Logical_View::Domain::UserAccount::UserAccountHandler::authenticate(std::string userName, std::string passPhrase) {
	std::cout << "Successfully Logged In \n";
}

void Logical_View::Domain::UserAccount::UserAccountHandler::createProfile(std::string name, std::string dateOfBirth, std::string phoneNumber, std::string email, Resume Resume) {
	std::cout << "Profile Created \n";
}

bool Logical_View::Domain::UserAccount::UserAccountHandler::isProfileEmpty() {
	return true;
}
