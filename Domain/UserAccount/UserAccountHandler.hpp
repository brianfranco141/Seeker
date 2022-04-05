#ifndef USERACCOUNTHANDLER_H
#define USERACCOUNTHANDLER_H
#include <iostream>

namespace Logical_View {
	namespace Domain {
		namespace UserAccount {

			class Resume {
			public:
			};

			class UserAccountHandler {

			public:
				void authenticate(std::string userName, std::string passPhrase);

				void createProfile(std::string name, std::string dateOfBirth, std::string phoneNumber, std::string email, Resume Resume);

				bool isProfileEmpty();
			};
		}
	}
}

#endif
