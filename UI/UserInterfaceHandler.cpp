#include "UserInterfaceHandler.hpp"
#include <iostream>
#include <string>
#include <vector>

#include "../Domain/Jobs/JobsHandler.hpp"
#include "../Domain/Resume/ResumeHandler.hpp"
#include "../Domain/UserAccount/UserAccountHandler.hpp"

using namespace Logical_View::Domain::Resume;
using namespace Logical_View::Domain::Jobs;
using namespace Logical_View::Domain::UserAccount;

namespace UserInterface
{
	ResumeHandler resume_handler;
	JobsHandler_ job;
	UserAccountHandler  user_account_handler;

	char loopMenu = 0;
		void UserInterface_::launch() {
			do {
			//step 1 authenticate user or Create Account
			std::string username;
			std::string password;
			int logInCreate = 0;

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
				//std::cin >> resume;
				user_account_handler.createProfile(name, dob, phoneNum, email, resume); // Manage Profile - SSD 4 
			}

			//step 2 user logged in enter Main Menu
			int menuSelection = 0;
			std::cout << "Welcome to the Seeker Main Menu Please enter a Number to Continue: \n";
			std::cout << "[1] - Search for Jobs\n";
			std::cout << "[2] - Review Resume \n";
			std::cout << "[3] - Review User Account \n";
			std::cin >> menuSelection;


			if (menuSelection == 1) {							//User Selects Search for Jobs Menu Option
				std::string search;
				char listSelect;
				std::cout << "Enter the Job Field You would Like to Search For: \n";
				std::cin >> search;
				job.searchBase(search);    //Lists Jobs - SSD 2
				std::cout << "Would you like to see the [1] - Priority List or [2] - Regular List of Job Listings?: \n";
				std::cin >> listSelect;
				if (listSelect == 1) {					// User Selects to see the Priority List of Jobs
					job.getPriorityList();		// Lists Jobs - SSD 3
				}
				else if (listSelect == 2) {				// User Selects to see the Regular Job Listings 
					job.getRegularList();		// Lists Jobs - SSD 4
				}

			}
			else if (menuSelection == 2) {						//User Selects Review Resume Menu Option
				std::string name;
				std::string workExp;
				std::string proSkill;
				std::string interests;
				std::string volunteerWork;
				std::string education;
				
				std::cout << "We will now take information for your Resume: \n";
				std::cout << "Please Enter Your Name: \n";
				std::cin >> name;
				std::cout << "Please Enter Your Work Experience: \n";
				std::cin >> workExp;
				std::cout << "Please Enter Your Professional Skills: \n";
				std::cin >> proSkill;
				std::cout << "Please Enter Your Interests: \n";
				std::cin >> interests;
				std::cout << "Please Enter Your Volunteer Work: \n";
				std::cin >> volunteerWork;
				std::cout << "Please Enter Your Education Level: \n";
				std::cin >> education;
				resume_handler.uploadResume(name, workExp, proSkill, interests, volunteerWork, education); // RateResume - SSD 2
				
				std::string ccNum;
				std::string ccName;
				std::string csv;
				std::string amount;
				std::cout << "Please Input Your Payment Information: \n";
				std::cout << "Please Input Your Credit Card Number: \n";
				std::cin >> ccNum;
				std::cout << "Please Input the Name of the Credit Card Holder: \n";
				std::cin >> ccName;
				std::cout << "Please Input the Card's CSV: \n";
				std::cin >> csv;
				std::cout << "Please Input the Amount Due for this Review: \n";
				std::cin >> amount;
				int paymentMenu;
				std::cout << "Would you like to Proceed with this payment? [1] - Yes / [2] - No \n";
				std::cin >> paymentMenu;
				if (paymentMenu == 1) {
					std:: cout << resume_handler.paymentInfoSubmitted(ccNum, ccName, csv, amount);
				}
				int sessionEnder;
				std::cout << "Would you like to end your current session? [1] - Yes / [2] - No \n";
				std::cin >> sessionEnder;
				if (sessionEnder == 1) {
					std::cout << "Thank You for Using Seeker, We hope to See you again \n";
					std::cout << "\n";
				}




			}

			else if (menuSelection == 3) {					//User Selects Review User Account Menu Option
				std::string jobInterests1;
				std::string jobInterests2;
				std::string jobInterests3;
				std::string jobInterests4;

				std::cout << "Please Enter your first Job Interests(input in this format: SoftwareEngineer): ";
				std::cin >> jobInterests1;

				std::cout << "Please Enter your second Job Interests: ";
				std::cin >> jobInterests2;

				std::cout << "Please Enter your third Job Interests: ";
				std::cin >> jobInterests3;

				std::cout << "Please Enter your fourth Job Interests: ";
				std::cin >> jobInterests4;

				std::cout << std::endl;

				std::vector<std::string> interests;
				interests.push_back(jobInterests1);
				interests.push_back(jobInterests2);
				interests.push_back(jobInterests3);
				interests.push_back(jobInterests4);
				job.fillInterests(interests);			//Manage Profile - SSD 2

				std::cout << "Your interests are: "
					<< interests[0] << ", " << interests[1] << ", " << interests[2] << ", " << interests[3] << std::endl;
				std::cout << std::endl;

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
					std::cout << std::endl;
				}
				std::vector<listings> jobs = job.getMatchingJobs();	// Manage Profile - SSD 5
				std::cout << "Matching Job List:" << std::endl;
				for (int i = 0; i < jobs.size(); i++) {

					std::cout << "Job name: " << jobs[i].listName << std::endl;
					std::cout << "Job location: " << jobs[i].listLocation << std::endl;
					std::cout << "Employer: " << jobs[i].listEmployer << std::endl << std::endl;
				}
				int sessionEnder = 0;
				std::cout << "Would you like to end your current session? [1] - Yes / [2] - No \n";
				std::cin >> sessionEnder;
				if (sessionEnder == 1) {
					std::cout << "Thank You for Using Seeker, We hope to See you again \n";
					std::cout << "\n";
				}
			}
		    } while (loopMenu == 0);
		}
	
}
