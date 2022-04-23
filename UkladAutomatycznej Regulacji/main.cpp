#include "Symulation.hpp"
#include <memory>

int main() {
	Symulation symulation;
	int choose = 0;
	//while (1) {
	//regulator memory problem
		do {
			while (1) {
				system("cls");
				std::cout << "Automatic Regulation System" << std::endl;
				std::cout << "1-New symulation\n2-Exit\n" << std::endl;
				std::cin >> choose;
				if (std::cin.fail() == true) {
					std::cin.clear();
					std::cin.ignore(256, '\n');
				}
				else break;
			}
		} while (choose != 1 && choose != 2);

		switch (choose) {
		case 1:
			system("cls");
			std::cout << "Choose regulator type:" << std::endl;
			symulation.run();
			break;
		case 2:
			system("cls");
			std::cout << "Successful exit" << std::endl;
			return 0;
		}
	//}

}