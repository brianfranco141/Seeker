#include "UserInterfaceHandler.hpp"
#include <iostream>
#include <vector>

#include "Domain/Jobs/JobsHandler.hpp"
#include "Domain/Resume/ResumeHandler.hpp"
#include "Domain/UserAccount/UserAccountHandler.hpp"

namespace UserInterface
{
	void UserInterface::launch() {
		//step 1 authenticate user or Create Account
		char username;
		char password;
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
			UserAccount_.authenticate(username, password);   //Manage Profile / List Jobs / Rate Resume - SSD 1
		}
		else if (logInCreate == 2) {
			char name;
			char dob;
			char phoneNum;
			char email;
			char resume;

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
			UserAccount_.createProfile(name, dob, phoneNum, email, resume); // Manage Profile - SSD 4 
		}

		//step 2 user logged in enter Main Menu
		char menuSelection = 0;
		std::cout << "Welcome to the Seeker Main Menu Please enter a Number to Continue: \n";
		std::cout << "[1] - Search for Jobs\n";
		std::cout << "[2] - Review Resume \n";
		std::cout << "[3] - Review User Account \n";
		std::cin >> menuSelection;
		
		
		if (menuSelection == 1){							//User Selects Search for Jobs Menu Option
			char search;
			char listSelect;
			std::cout << "Enter the Job Field You would Like to Search For: \n";
			std::cin >> search; 
			listings.searchBase(search);			//Lists Jobs - SSD 2
			std::cout << "Would you like to see the [1] - Priority List or [2] - Regular List of Job Listings?: \n";
			std::cin >> listSelect;
			if (listSelect == 1) {					// User Selects to see the Priority List of Jobs
				listings.getPriorityList();		// Lists Jobs - SSD 3
			}
			else if (listSelect == 2) {				// User Selects to see the Regular Job Listings 
				listings.getRegularList();		// Lists Jobs - SSD 4
			}

		}
		else if (menuSelection == 2){						//User Selects Review Resume Menu Option
			char fileName;
			std::cout << "Please Enter the File Name of the Resume you Would like to Upload: \n";
			std::cin >> fileName;
			resumeHandler.uploadResume(fileName);		//RateResume - SSD 2

			char resumeReview;
			std::cout << "Would you like to Submit your Payment for this Resume Review?: Y/N \n"; 
			std::cout << "(This Will use the Payment Information On the Currently Signed In Account) \n";
			std::cin >> resumeReview; 
			resumeHandler.paymentInfoSubmitted(paymentDetails);		//RateResume - SSD 3
			resumeHandler.reviewResume(resume);					//RateResume - SSD 4


		}
		else if (menuSelection == 3) {					//User Selects Review User Account Menu Option
			char jobInterests;
			std::cout << "Please Enter your Job Interests: "; 
			std::cin >> jobInterests;
			jobsHandler.fillInterests(jobInterests);			//Manage Profile - SSD 2
			if (jobsHandler.isProfileEmpty()) {				//Manage Profile - SSD 3
				char name;
				char dob;
				char phoneNum;
				char email;
				char resume;

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
				UserAccount_.createProfile(name, dob, phoneNum, email, resume); // Manage Profile - SSD 4 
			}
			jobsHandler.getMatchingJobs();						// Manage Profile - SSD 5

		}

	}
}