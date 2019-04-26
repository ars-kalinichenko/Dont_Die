#include "ConfigReader.h"
#include <fstream>
#include <sstream>

using namespace std;


map<string, int> ConfigReader::read_config(const string &file_name) {
    ifstream infile(file_name);
    string key;
    int value;
    map<string, int> map_config;
    while (infile >> key >> value)
        map_config[key] = value;
    return map_config;
}
