#ifndef GAME_MAPREAD_H
#define GAME_MAPREAD_H

#include "IReader.h"
#include <fstream>

class FileReader : public IReader {
private:
    std::ifstream stream;
public:
    explicit FileReader(const std::string &);

    bool has_next() override;

    int read() override;

    ~FileReader() override;
};

#endif //GAME_MAPREAD_H
