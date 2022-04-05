#ifndef RESUMEHANDLER_H
#define RESUMEHANDLER_H
#include <iostream>

namespace Logical_View {
	namespace Domain {
		namespace Resume {
			class ResumeHandler {


			public:
				void uploadResume(std::string name, std::string workExperience, std::string professionalSkills, std::string interests, std::string volunteerWork, std::string education);

				void reviewResume(std::string name, std::string workExperience, std::string education, std::string professionalSkill, std::string interests, std::string volunteerWork);

				std::string paymentInfoSubmitted(std::string creditCardNumber, std::string cardHolderName, std::string csv, std::string amount);

				void endSession();
			};
		}
	}
}

#endif

