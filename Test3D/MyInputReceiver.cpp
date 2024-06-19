
#include "MyInputReceiver.h"

using namespace irr;

MyInputReceiver::MyInputReceiver()
{
    for(u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
        {
            KeyIsDown[i] = false;
        }

}

bool MyInputReceiver::OnEvent(const SEvent& event)
{
    if(event.EventType == EET_KEY_INPUT_EVENT)
    {
            KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    }

    return false;
}

bool MyInputReceiver::IsKeyDown(irr::EKEY_CODE keyCode) const
{
    return KeyIsDown[keyCode];
}

