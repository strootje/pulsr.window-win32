#include <Pulsr.Window/Manager.hpp>

int main(int argc, char* argv[])
{
	Pulsr::Window::ManagerImpl windowManager;
	windowManager.Create("test window");
	return 0;
}
