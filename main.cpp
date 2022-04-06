#include <iostream>
#include "UI/UserInterfaceHandler.hpp"

using namespace UserInterface;

int main()
{
	int num = 0;
	do {
		UserInterface_ user_;
		user_.launch();
        num++;
	} while( num < 3 );

	return 0;
}
