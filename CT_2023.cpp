#include <iostream>
#include <fstream>

using namespace std;

//addr: maxodrom.ru (31.31.196.25)
//base: u0632405_CT_2023
//user: u0632405_max
//Pass: jL2wJ8wE4syH7gM1


int main()
{
    string filename = "DATA_Files\\Facility2Constellation\\Facility-Anadyr1.txt";
    ifstream f;

    f.open(filename);

    if (!f.is_open()) {
        return 1;
    }
    while (f) {
        string line;
        
        f >> line;
        const char* c = line.c_str();
        printf(c);
 
    }

    f.close();
    return 0;
}
