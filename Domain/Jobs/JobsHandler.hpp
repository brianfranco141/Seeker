#ifndef JOBSHANDLER _H
#define JOBSHANDLER _H
#include <vector>
#include <iostream>

namespace Logical_View {
	namespace Domain {
		namespace Jobs {

			class listings {
				public:
					std::string listName;
					std::string listLocation;
					std::string listEmployer;
			};

			class JobsHandler_ {
				private:
					std::vector<std::string> applicantInterests;

				public:
					std::vector<listings> getMatchingJobs();

					std::vector<listings> getPriorityList();

					std::vector <listings> getRegularList();

					void fillInterests( std::vector<std::string> interests );

					void viewListing(int listingNumber);

					virtual std::vector<bool> searchBase(std::string filter);
			
			};
		}
	}
}

#endif
