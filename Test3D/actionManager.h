
#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H

#include <irrlicht.h>
#include "mymesh.h"
#include "MyInputReceiver.h"

void setAction(MyInputReceiver &receiver, MyMesh *mesh, irr::f32 delta);

#endif // ACTIONMANAGER_H
