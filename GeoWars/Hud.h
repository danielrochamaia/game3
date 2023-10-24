#ifndef _HUD_H_
#define _HUD_H_

#include "Font.h"
#include "Object.h"
#include "Timer.h"
#include <sstream>

using std::stringstream;

class Hud : public Object
{
private:
    Font* fonte;
    Timer     timer;
    stringstream text;

    uint time;
    bool stopped;

public:
    Hud();
    ~Hud();

    void Update();
    void Draw();
    void Draw(float x, float y);

    void Stop() { stopped = true; };
    void ResetTime();
    uint Time();
};

#endif
