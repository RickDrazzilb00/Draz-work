
#ifndef MYINPUTRECEIVER_H
#define MYINPUTRECEIVER_H

#include<irrlicht.h>


class MyInputReceiver : public irr::IEventReceiver
{
public:
    virtual bool OnEvent(const irr::SEvent& event);

    virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;

    MyInputReceiver();

private:
    bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
};

#endif // MYINPUTRECEIVER_H
