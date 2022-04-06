#include "JobsHandler.hpp"

std::vector<Logical_View::Domain::Jobs::listings> Logical_View::Domain::Jobs::JobsHandler_::getMatchingJobs() {
  std::vector<listings> jobs;
  listings softwareEngineer;
  softwareEngineer.listName = "Software Development";
  softwareEngineer.listEmployer = "Google";
  softwareEngineer.listLocation = "Los Angeles, CA";
  jobs.push_back( softwareEngineer );

  listings dataScience;
  dataScience.listName = "Data Scientist";
  dataScience.listEmployer = "NASA";
  dataScience.listLocation = "Washington, D.C.";
  jobs.push_back( dataScience );

  listings iT;
  iT.listName = "Information Techonology Specialist";
  iT.listEmployer = "CSUF";
  iT.listLocation = "Fullerton, CA";
  jobs.push_back( iT );

  listings customerService;
  customerService.listName = "Customer Service Representative";
  customerService.listEmployer = "UPS";
  customerService.listLocation = "Garden Grove, CA";
  jobs.push_back( customerService );

  return jobs;
}

std::vector<Logical_View::Domain::Jobs::listings> Logical_View::Domain::Jobs::JobsHandler_::getPriorityList() {
	// TODO - implement JobsHandler ::getPriorityList
	throw "Not yet implemented";
}

std::vector<Logical_View::Domain::Jobs::listings> Logical_View::Domain::Jobs::JobsHandler_::getRegularList() {
	// TODO - implement JobsHandler ::getRegularList
	throw "Not yet implemented";
}

void Logical_View::Domain::Jobs::JobsHandler_::fillInterests(std::vector<std::string>interests) {
	applicantInterests = interests;
}

void Logical_View::Domain::Jobs::JobsHandler_::viewListing(int listingNumber) {
	// TODO - implement JobsHandler ::viewListing
	throw "Not yet implemented";
}

std::vector<bool> Logical_View::Domain::Jobs::JobsHandler_::searchBase(std:: string filter) {
	// TODO - implement JobsHandler ::searchBase
	throw "Not yet implemented";
}
