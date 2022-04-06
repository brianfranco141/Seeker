#include "ResumeHandler.hpp"

void Logical_View::Domain::Resume::ResumeHandler::uploadResume(std::string name, std::string workExperience, std::string professionalSkills, std::string interests, std::string volunteerWork, std::string education) {
	applicantName = name;
	applicantWorkExp = workExperience;
	applicantProfSkills = professionalSkills;
	applicantInterests = interests;
	applicantVolWork = volunteerWork;
	applicantEdu = education;
	std::cout << "Resume Review Response \n";
}

void Logical_View::Domain::Resume::ResumeHandler::reviewResume(std::string name, std::string workExperience, std::string education, std::string professionalSkill, std::string interests, std::string volunteerWork) {
	applicantName = name;
	applicantWorkExp = workExperience;
	applicantProfSkills = professionalSkill;
	applicantInterests = interests;
	applicantVolWork = volunteerWork;
	applicantEdu = education;
	std::cout << "Resume Review Response \n";
}

void Logical_View::Domain::Resume::ResumeHandler::paymentInfoSubmitted(std::string creditCardNumber, std::string cardHolderName, std::string csv, std::string amount) {
	applicantCreNum = creditCardNumber;
	applicantCreName = cardHolderName;
	applicantCreCsv = csv;
	applicantAmount = amount;
	std::cout << "Payment Successful \n";
}

void Logical_View::Domain::Resume::ResumeHandler::endSession() {
	std::cout << "You Have Been Logged Out \n";
}
