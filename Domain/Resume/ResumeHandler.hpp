#ifndef RESUMEHANDLER_H
#define RESUMEHANDLER_H
#include <iostream>

namespace Logical_View {
	namespace Domain {
		namespace Resume {

			class Resume {
				public:
			};

			class payment {
				public:
			};

			class ResumeHandler {


			public:
				std::string uploadResume(Resume resume);

				void reviewResume(Resume resume);

				std::string paymentInfoSubmitted(payment paymentDetails);
			};
		}
	}
}

#endif
