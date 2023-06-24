#include <iostream>
#include "Singleton.h"

int main() {
	MetricRegister::getInstance()->add_metr(0, 1000, 990);
	MetricRegister::getInstance()->show_metr();
	std::cout << MetricRegister::getInstance()->count_cometr(0) << std::endl;
	system("pause");
	return 0;
}