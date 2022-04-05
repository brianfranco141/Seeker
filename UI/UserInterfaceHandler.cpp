#include "UserInterfaceHandler.hpp"
#include <iostream>
#include <string>
#include <vector>

#include "Domain/Jobs/JobsHandler.hpp"
#include "Domain/Resume/ResumeHandler.hpp"
#include "Domain/UserAccount/UserAccountHandler.hpp"

using namespace Logical_View::Domain::Resume;
using namespace Logical_View::Domain::Jobs;
using namespace Logical_View::Domain::UserAccount;

namespace UserInterface
{	
	ResumeHandler resume_handler;
	JobsHandler_ job;
	UserAccountHandler  user_account_handler;

	void UserInterface::launch() {
		//step 1 authenticate user or Create Account
		std::string username;
		std::string password;
		char logInCreate = 0;

		std::cout << "Welcome to the Seeker Job System! Please Enter a Number to Continue \n";
		std::cout << "[1] - Log In\n";
		std::cout << "[2] - Create An Account \n";
		std::cin >> logInCreate;

		if (logInCreate == 1) {
			std::cout << "Please Enter your Username: \n";
			std::cin >> username;
			std::cout << "Please Enter your Password: \n";
			std::cin >> password;
			user_account_handler.authenticate(username, password);   //Manage Profile / List Jobs / Rate Resume - SSD 1
		}
		else if (logInCreate == 2) {
			std::string name;
			std::string dob;
			std::string phoneNum;
			std::string email;
			std::string resume;

			std::cout << "Please Enter Your Name: \n";
			std::cin >> name;
			std::cout << "Please Enter Your Date Of Birth: \n";
			std::cin >> dob;
			std::cout << "Please Enter Your Phone Number: \n";
			std::cin >> phoneNum;
			std::cout << "Please Enter Your Email: \n";
			std::cin >> email;
			std::cout << "Please Enter Your Resume File: \n";
			std::cin >> resume;
			user_account_handler.createProfile(name, dob, phoneNum, email, resume); // Manage Profile - SSD 4
		}

		//step 2 user logged in enter Main Menu
		char menuSelection = 0;
		std::cout << "Welcome to the Seeker Main Menu Please enter a Number to Continue: \n";
		std::cout << "[1] - Search for Jobs\n";
		std::cout << "[2] - Review Resume \n";
		std::cout << "[3] - Review User Account \n";
		std::cin >> menuSelection;
		
		
		if (menuSelection == 1){							//User Selects Search for Jobs Menu Option
			std::string search;
			char listSelect;
			std::cout << "Enter the Job Field You would Like to Search For: \n";
			std::cin >> search; 
			job.searchBase( search );    //Lists Jobs - SSD 2
			std::cout << "Would you like to see the [1] - Priority List or [2] - Regular List of Job Listings?: \n";
			std::cin >> listSelect;
			if (listSelect == 1) {					// User Selects to see the Priority List of Jobs
				job.getPriorityList();		// Lists Jobs - SSD 3
			}
			else if (listSelect == 2) {				// User Selects to see the Regular Job Listings 
				job.getRegularList();		// Lists Jobs - SSD 4
			}

		}
		else if (menuSelection == 2){						//User Selects Review Resume Menu Option
			std::string fileName;
			std::cout << "Please Enter the File Name of the Resume you Would like to Upload: \n";
			//std::cin >> fileName;
			resume_handler.uploadResume(fileName);		//RateResume - SSD 2

			char resumeReview;
			std::cout << "Would you like to Submit your Payment for this Resume Review?: Y/N \n"; 
			std::cout << "(This Will use the Payment Information On the Currently Signed In Account) \n";
			//std::cin >> resumeReview; 
			resume_handler.paymentInfoSubmitted( paymentDetails );    //RateResume - SSD 3
			resume_handler.reviewResume(resume);					//RateResume - SSD 4


		}
		else if (menuSelection == 3) {					//User Selects Review User Account Menu Option
			char jobInterests;
			std::cout << "Please Enter your Job Interests: "; 
			std::cin >> jobInterests;
			job.fillInterests(jobInterests);			//Manage Profile - SSD 2
			if (user_account_handler.isProfileEmpty()) {				//Manage Profile - SSD 3
				std::string name;
				std::string dob;
				std::string phoneNum;
				std::string email;
				std::string resume;

				std::cout << "Please Enter Your Name: \n";
				std::cin >> name;
				std::cout << "Please Enter Your Date Of Birth: \n";
				std::cin >> dob;
				std::cout << "Please Enter Your Phone Number: \n";
				std::cin >> phoneNum;
				std::cout << "Please Enter Your Email: \n";
				std::cin >> email;
				std::cout << "Please Enter Your Resume File: \n";
				std::cin >> resume;
				user_account_handler.createProfile(name, dob, phoneNum, email, resume); // Manage Profile - SSD 4 
			}
			job.getMatchingJobs();						// Manage Profile - SSD 5

		}

	}
}