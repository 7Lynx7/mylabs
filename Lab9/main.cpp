#include <iostream>
#include "lib.h"


int main()
{
        while (true) {
            int a;
            std::cin >> a;
            //std::cout << pow(2, a) << std::endl;
            if (a < 2147483647 && a > -2147483647) {
                setBinForm(a);
                showBin();
                std::cout << getDecForm() << std::endl;
                invert(4);
                showBin();
                std::cout << getDecForm() << std::endl;
            }
            else {
                a = 0;
                std::cout << " please, enter correctly number" << std::endl;
                break;
            }

        }
}



