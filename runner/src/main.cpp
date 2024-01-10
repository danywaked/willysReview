// main.cpp

#include "application.hpp"

//--TODO: delete everything that is unused 
//--Delete everything that is unecessary
//TODO: 2-step initialization needs to go. Use constructors. 
//TODO: this game does not need anything on the heap. gets rid of assetmanagement and all pointers.
// TODO: sf::sprite has position, so any thing that owns a sprite don't need a separate position// 
// TODO: use RAII. The sf::Texture object might already be one. 
//TODO: let objects own their own assets, let the ctor load and if it fails, throw
// TODO: naming. Why does Brick own a list of "brickparts"? 
// TODO: why does paralaxbackground own a list of "paralaxparts". They are stars. (and the stars are unecessary, you only need positions)
// TODO: the scrolling background draws stars. Stars don't need their own copy of color, sprite, texture etc. They are all identical, they just need a position. 
// TODO: consider which methods can be const, make them const. (render can always be const)
// TODO: consider which methods can be noexcept, make them noexcept. Anything that allocates can throw. And sf is a C++ lib, so it might throw. you'l have to check each fucntions' documentation.

int main(int argc, char **argv)
{
   runner::Application{}.run();
   return 0;
}
