
#include "mymesh.h"

using namespace irr;

enum{
    ID_IsNotPickable = 0,
    IDFlag_IsPickable = 1 << 0,
    IDFlag_IsHighlightable = 1<<1
};

MyMesh::MyMesh(scene::ISceneManager *manager, io::path meshPath)
{
    //les bornes des intervalles de frames
    f32 CURRENT_STANDING_FRAME_B = 206.0f;
    f32 CURRENT_STANDING_FRAME_E = 250.0f;

    f32 CURRENT_WALKING_FRAME_B = 1.0f;
    f32 CURRENT_WALKING_FRAME_E = 13.9f;

    f32 CURRENT_STEALTH_WALKING_FRAME_B = 15.0f;
    f32 CURRENT_STEALTH_WALKING_FRAME_E = 28.9f;

    f32 CURRENT_ATTACK_FRAME_B = 45.0f;
    f32 CURRENT_ATTACK_FRAME_E = 59.0f;

    //initialisation du reste des attributs

    m_me = manager->getMesh(meshPath);

    m_standingFrames[0] = CURRENT_STANDING_FRAME_B;
    m_standingFrames[1] = CURRENT_STANDING_FRAME_E;

    m_walkFrames[0] = CURRENT_WALKING_FRAME_B;
    m_walkFrames[1] = CURRENT_WALKING_FRAME_E;

    m_stealthWalkFrames[0] = CURRENT_STEALTH_WALKING_FRAME_B;
    m_stealthWalkFrames[1] = CURRENT_STEALTH_WALKING_FRAME_E;
    m_attackFrames[0] = CURRENT_ATTACK_FRAME_B;
    m_attackFrames[1] = CURRENT_ATTACK_FRAME_E;

    m_walkSpeed = 50.0f;
}

//les getters

scene::IAnimatedMesh *MyMesh::getMesh()
{
    return this->m_me;
}

scene::IAnimatedMeshSceneNode *MyMesh::getNode()
{
    return this->m_myNode;
}

f32 MyMesh::getWalkSpeed() const
{
    return this->m_walkSpeed;
}

void MyMesh::walk()
{
    if(m_myNode->getFrameNr()<m_walkFrames[0] || m_myNode->getFrameNr()>m_walkFrames[1])
    {
        m_myNode->setFrameLoop(m_walkFrames[0], m_walkFrames[1]);
    }
}

void MyMesh::stealthWalk(){
    if(m_myNode->getFrameNr()<m_stealthWalkFrames[0] || m_myNode->getFrameNr()>m_stealthWalkFrames[1])
    {
        m_myNode->setFrameLoop(m_stealthWalkFrames[0], m_stealthWalkFrames[1]);
    }
}

void MyMesh::attack(){
    if(m_myNode->getFrameNr()<m_attackFrames[0] || m_myNode->getFrameNr()>m_attackFrames[1])
    {
        m_myNode->setFrameLoop(m_attackFrames[0], m_attackFrames[1]);
    }
}

void MyMesh::stand(){
    if(m_myNode->getFrameNr()<m_standingFrames[0] || m_myNode->getFrameNr()>m_standingFrames[1])
    {
        m_myNode->setFrameLoop(m_standingFrames[0], m_standingFrames[1]);
    }
}

void MyMesh::setMesh(scene::ISceneManager *manager, io::path path)
{
    m_me = manager->getMesh(path);
}

void MyMesh::setNode(scene::ISceneManager *manager)
{
    m_myNode = manager->addAnimatedMeshSceneNode(m_me, 0, ID_IsNotPickable);
}

MyMesh::~MyMesh()
{
    this->m_me->drop();
    this->m_me = 0;


    this->m_myNode->drop();
    this->m_myNode = 0;
}
