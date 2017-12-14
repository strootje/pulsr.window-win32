#include <Pulsr.Drawing/WindowFactoryImpl.hpp>
#include <cstdlib>

int main( int argc, char* argv[] )
{
	Pulsr::Drawing::WindowFactoryImpl winFactory;
	auto win = winFactory.Create();
	win->Show();
	winFactory.Dispatch();

	return EXIT_SUCCESS;
}
