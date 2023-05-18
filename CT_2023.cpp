// CT_2023.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string filename = "D:\\Проекты\\CT_2023\\DATA_Files\\Facility2Constellation\\Facility-Anadyr1.txt";
    ifstream input;

    input.open(filename);

    if (!input.is_open()) {
        return 1;
    }
    while (input) {
        string line;

        basic_istream::getline(input, line, "Anadyr1 - To - KinoSat_110101");
 
    }

    input.close();
    return 0;
}
