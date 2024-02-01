// main.cpp
#include "application.hpp"
#include <iostream>
#include <stdexcept>
 
//throw exception when resoucres can't load correctly, unless you have some way to deal with a fallback behavior
// make interface so you can stop breaking the law of demeter 
	//background should render itself
	///collision detection against wall::brick should probably be handled by wall::checkCollision(player::rect)
	//or give wall a begin() and end() so you can do for(auto brick : wall) { rectRect(player, brick); }
//give your objects constructors, don't perform two-step init
//	//you should not need restart() or setup() functions. (with the exception for application::restart possible)


//not necessary, but strongly recommended. it's just good code hygiene
// mark methods const if they can be const
// mark methods noexcept if they are noexcept


int main(int argc, char **argv)
{
	try {
		runner::Application{}.Run();
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
   return 0;
}
