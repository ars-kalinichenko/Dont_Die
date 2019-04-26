#ifndef GAME_ISCENE_H
#define GAME_ISCENE_H

class IScene {
public:
    virtual void start() = 0;

    virtual void stop() = 0;

    virtual ~IScene() = default;
};


#endif //GAME_ISCENE_H
