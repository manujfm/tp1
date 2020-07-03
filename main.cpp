#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;
const int MAX_COUNTRY = 20;


struct country {
    string countryName;
    string continent;
    int people;
    void print() const {
        cout << " Pais: " << countryName << " - ";
        cout << " Continente: "<< continent << " - ";
        cout << " Personas: "<< people << endl;
    }
};


void splitLineOfCountry(string const line, string countryArray []){
    string newLine;
    int len, space;
    space  = line.find(" ");
    len  = line.length();
    countryArray[0] = line.substr(0, space);
    space = line.find(" ");
    newLine = line.substr(space + 1, len+1);
    countryArray[1] = newLine.substr(0 ,newLine.find(" "));
    space = newLine.find(" ");
    len = newLine.length();
    countryArray[2] = newLine.substr(space,len);
};

void readCountryFile(ifstream &file, struct country countries[]){
    string countryArray[3];
    string line;
    int i;
    for (i = 0; i < MAX_COUNTRY; i++) {
        getline(file, line);
        splitLineOfCountry(line, countryArray);
        countries[i].countryName = countryArray[0];
        countries[i].continent = countryArray[1];
        countries[i].people = atoi(countryArray[2].c_str());
        countries[i].print();
    };
}


int main() {
    ifstream MyReadFile("/home/manu/UTN/TP1New/Paises.txt");
    country countries[MAX_COUNTRY];
    cout << "Generando Archivos..." << endl;
    if (MyReadFile.is_open()) {
        readCountryFile(MyReadFile, countries);
    } else {
        cout << "No se pudo abrir el archivo";
    }
    MyReadFile.close();
    return 0;
}
