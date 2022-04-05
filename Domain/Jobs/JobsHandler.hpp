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


			public:
				std::vector<listings> getMatchingJobs();

				std::vector<listings> getPriorityList();

				std::vector <listings> getRegularList();

				void fillInterests(int jobType);

				void viewListing(int listingNumber);

				virtual std::vector<bool> searchBase(std::string filter);
			
			};
		}
	}
}

#endif
