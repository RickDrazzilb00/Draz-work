#include <irrlicht.h>
#include "driverChoice.h"
#include "mymesh.h"
#include "MyInputReceiver.h"
#include "actionManager.h"

#ifdef _MSC_VER
// We'll also define this to stop MSVC complaining about sprintf().
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "Irrlicht.lib")
#endif

using namespace irr;

enum{
    ID_IsNotPickable = 0,
    IDFlag_IsPickable = 1 << 0,
    IDFlag_IsHighlightable = 1<<1
};

int main()
{
    video::E_DRIVER_TYPE driverType = driverChoiceConsole();
    if(driverType == video::EDT_COUNT)
    {
        return 1;
    }

    //MyReceiver receiver;
    MyInputReceiver receiver;

    IrrlichtDevice *device = createDevice(driverType, core::dimension2d<u32>(640,480),
                                          16, false, false, false, &receiver);

    if(!device) return 1;

    device->setWindowCaption(L"Irrlicht engine - RPG test");
    device->setResizable(true);

    video::IVideoDriver *driver = device->getVideoDriver();
    scene::ISceneManager *manager= device->getSceneManager();

    device->getFileSystem()->addFileArchive
        ("C:/Users/Ricardo/Documents/Projet/projetIrrLicht/irrlicht/media/map-20kdm2.pk3");
    scene::IAnimatedMesh* mesh = manager->getMesh("20kdm2.bsp");
    scene::IMeshSceneNode* node = 0;

    if(mesh)
    {
        node = manager->addOctreeSceneNode(mesh->getMesh(0), 0, IDFlag_IsPickable, 1024);
    }

    scene::ITriangleSelector *selector = 0;

    if (node)
    {
        node->setPosition(core::vector3df(-1300,-144,-1249));
        selector = manager->createOctreeTriangleSelector(node->getMesh(),node, 128);
        node->setTriangleSelector(selector);
    }

    MyMesh *ninja = new MyMesh(manager, "C:/Users/Ricardo/Documents/Projet/projetIrrLicht/irrlicht/media/ninja.b3d");
    if(!ninja->getMesh()){
        device->drop();
        return -1;
    }

    scene::ICameraSceneNode *camera = manager->addCameraSceneNodeFPS(0, 100.0f, 0.3f, ID_IsNotPickable, 0, 0, true, 3.f);
    camera->setPosition(core::vector3df(50,50,-60));
    camera->setTarget(core::vector3df(-70,30,-60));


    ninja->setNode(manager);
    scene::IAnimatedMeshSceneNode *node2 = ninja->getNode();
    if(ninja->getNode())
    {
        node2->setMaterialFlag(video::EMF_LIGHTING, false);
        node2->setPosition(core::vector3df(0,-60, 30));
        node2->setCurrentFrame(206);
        node2->setAnimationSpeed(12.f);
        node2->setScale(core::vector3df(12.f,12.f,12.f));
        node2->setMaterialTexture(0, driver->getTexture(
                                         "C:/Users/Ricardo/Documents/Projet/projetIrrLicht/irrlicht/media/nskinbl.jpg"));
    }

    if(selector)
    {
        scene::ISceneNodeAnimator *anime = manager->createCollisionResponseAnimator(
            selector, camera, core::vector3df(30, 50, 30), core::vector3df(0,-10, 0), core::vector3df(0,30,0));
        scene::ISceneNodeAnimator *anim = manager->createCollisionResponseAnimator(
            selector, node2, core::vector3df(6, 10, 6), core::vector3df(0,-10,0), core::vector3df(0, 0,0));
        selector->drop();
        node2->addAnimator(anim);
        camera->addAnimator(anime);
        anime->drop();
        anim->drop();
    }




    u32 then = device->getTimer()->getTime();

    while(device->run() && driver)
    {
        if(device->isWindowActive())
        {

            const u32 now = device->getTimer()->getTime();
            const f32 frameDeltaTime = (f32)(now - then)/1000.f;

            then = now;

            setAction(receiver, ninja, frameDeltaTime);

            driver->beginScene(true, true, video::SColor(0,200,200,200));
            manager->drawAll();

            driver->endScene();
        }
    }

    device->drop();
    return 0;
}
