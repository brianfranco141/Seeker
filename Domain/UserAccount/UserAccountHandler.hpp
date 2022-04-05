#ifndef USERACCOUNTHANDLER_H
#define USERACCOUNTHANDLER_H
#include <iostream>

namespace Logical_View {
	namespace Domain {
		namespace UserAccount {
			class UserAccountHandler {
			private:
				std::string realName;
				std::string birthDate;
				std::string phoneNum;
				std::string emailAddress;
				std::string resumeFileName;

			public:
				void authenticate(std::string userName, std::string passPhrase);

				void createProfile(std::string name, std::string dateOfBirth, std::string phoneNumber, std::string email, std::string Resume);

				bool isProfileEmpty();
			};
		}
	}
}

#endif
