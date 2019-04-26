#ifndef GAME_CONFIGREADER_H
#define GAME_CONFIGREADER_H

#include <string>
#include <fstream>
#include <IReader.h>
#include <map>


class ConfigReader {
public:
    explicit ConfigReader() = default;

    static std::map<std::string, int> read_config(const std::string &);

};

#endif //GAME_CONFIGREADER_H
