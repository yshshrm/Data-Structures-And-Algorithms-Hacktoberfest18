#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <chrono>
#include <ctime>
#include <cctype>

#include "../Logger/logger"

std::map<char, char> characterMap;

std::map<char, char> start();
std::map<char, char> create();
std::map<char, char> read();
bool exists(const std::string& filename);
std::string convert(std::string String);

int main() {
    characterMap = start();
    std::string inputString, encryptedString;

    std::getline(std::cin, inputString);
    encryptedString = convert(inputString);
    std::cout << encryptedString << std::endl;
}

std::map<char, char> start() {
    if (exists("CaesarTable.dat")) {
        return read();
    }

    else {
        log("File does not exist. Created file again");
        return create();
    }
}

bool exists(const std::string& filename) {
    std::ifstream file(filename.data());
    return file.good();
}

std::map<char, char> create() {
    std::fstream file;
    std::map<char, char> CaesarTable;
    int characterMap = 65;

    file.open("CaesarTable.dat", std::fstream::binary | std::fstream::trunc | std::fstream::out);
    for (int i = 0; i < 13; i++, characterMap++) {
        CaesarTable[char(characterMap)] = char(characterMap+13);
        CaesarTable[char(characterMap+32)] = char(characterMap+32+13);
    }

    for (int i = 0; i < 13; i++, characterMap++) {
        CaesarTable[char(characterMap)] = char(characterMap-13);
        CaesarTable[char(characterMap+32)] = char(characterMap+32-13);
    }

    auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    file.write((char*)&timenow, sizeof(timenow));
    for (std::pair<char, char> entry : CaesarTable) {
        file << entry.first;
        file << entry.second;
    }

    file.write((char*)&timenow, sizeof(timenow));
    file.close();
    return CaesarTable;
}

std::map<char, char> read() {
    std::fstream file;
    std::map<char, char> CaesarTable;
    char key, value;
    time_t timecheck, timecheck1;

    file.open("CaesarTable.dat", std::fstream::binary | std::fstream::in);
    file.read((char*)&timecheck, sizeof(timecheck));
    for (int i = 0; i < 52; i++) {
        file >> key;
        file >> value;
        CaesarTable[key] = value;
    }

    file.read((char*)&timecheck1, sizeof(timecheck1));
    file.close();

    if (timecheck == timecheck1) {
        return CaesarTable;
    }

    else {
        log("File Corrupted");
        return create();
        
    }
}

std::string convert(std::string String) {
    std::string rtrn = String;
    for (int i = 0; i < String.length(); i++) {
        if (isalpha(String[i])) 
            rtrn[i] = characterMap[String[i]];
        else
            rtrn[i] = String[i];
    }   

    return rtrn;
}