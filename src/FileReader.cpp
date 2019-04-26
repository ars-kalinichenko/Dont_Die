#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <string>
#include <FileReader.h>

using namespace std;

FileReader::FileReader(const string &file_name) {
    stream.open(file_name);
}

bool FileReader::has_next() {
    return stream.is_open() && stream.peek() != -1;
}

int FileReader::read() {
    return stream.get();
}

FileReader::~FileReader() {
    stream.close();
}
