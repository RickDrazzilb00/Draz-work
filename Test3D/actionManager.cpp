#include "actionManager.h"

using namespace irr;

void setAction(MyInputReceiver &receiver, MyMesh *mesh, irr::f32 delta)
{
    core::vector3df nodePosition = mesh->getNode()->getPosition();
    if(receiver.IsKeyDown(KEY_KEY_Q) && receiver.IsKeyDown(KEY_KEY_Z))
    {
        mesh->getNode()->setRotation(core::vector3df(0.f, -45.f, 0.f));
        nodePosition.X-=mesh->getWalkSpeed()*delta;
        nodePosition.Z+=mesh->getWalkSpeed()*delta;
        mesh->walk();
    }
    else if(receiver.IsKeyDown(KEY_KEY_Z) && receiver.IsKeyDown(KEY_KEY_D))
    {
        mesh->getNode()->setRotation(core::vector3df(0.f, 45.f, 0.f));
        nodePosition.X+=mesh->getWalkSpeed()*delta;
        nodePosition.Z+=mesh->getWalkSpeed()*delta;
        mesh->walk();
    }
    else if(receiver.IsKeyDown(KEY_KEY_D) && receiver.IsKeyDown(KEY_KEY_S))
    {
        mesh->getNode()->setRotation(core::vector3df(0.f, 135.f, 0.f));
        nodePosition.X+=mesh->getWalkSpeed()*delta;
        nodePosition.Z-=mesh->getWalkSpeed()*delta;
        mesh->walk();
    }
    else if(receiver.IsKeyDown(KEY_KEY_S) && receiver.IsKeyDown(KEY_KEY_Q))
    {
        mesh->getNode()->setRotation(core::vector3df(0.f, -135.f, 0.f));
        nodePosition.X-=mesh->getWalkSpeed()*delta;
        nodePosition.Z-=mesh->getWalkSpeed()*delta;
        mesh->walk();
    }
    else if(receiver.IsKeyDown(KEY_KEY_Z))
    {
        mesh->getNode()->setRotation(core::vector3df(0.f, 0.f, 0.f));
        nodePosition.Z+=mesh->getWalkSpeed()*delta;
        mesh->walk();
    }
    else if(receiver.IsKeyDown(KEY_KEY_D))
    {
        mesh->getNode()->setRotation(core::vector3df(0.f, 90.f, 0.f));
        nodePosition.X+=mesh->getWalkSpeed()*delta;
        mesh->walk();
    }
    else if(receiver.IsKeyDown(KEY_KEY_S))
    {
        mesh->getNode()->setRotation(core::vector3df(0.f, 180.f, 0.f));
        nodePosition.Z-=mesh->getWalkSpeed()*delta;
        mesh->walk();
    }
    else if(receiver.IsKeyDown(KEY_KEY_Q))
    {
        mesh->getNode()->setRotation(core::vector3df(0.f, -90.f, 0.f));
        nodePosition.X-=mesh->getWalkSpeed()*delta;
        mesh->walk();
    }
    else
    {
        mesh->stand();
    }

    mesh->getNode()->setPosition(nodePosition);
}
