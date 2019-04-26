#ifndef GAME_IREADER_H
#define GAME_IREADER_H

class IReader {
public:
    virtual bool has_next() = 0;

    virtual int read() = 0;

    virtual ~IReader() = default;
};

#endif //GAME_IREADER_H
