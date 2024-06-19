
#ifndef MYMESH_H
#define MYMESH_H


#include<irrlicht.h>
#include<string>

class MyMesh
{
public:
    MyMesh(irr::scene::ISceneManager *manager, irr::io::path meshPath);//constructeur
    ~MyMesh();

    void setMesh(irr::scene::ISceneManager *manager, irr::io::path meshPath);
    void setNode(irr::scene::ISceneManager *manager);

    //les getteurs
    irr::scene::IAnimatedMesh *getMesh();
    irr::scene::IAnimatedMeshSceneNode *getNode();
    irr::f32 getWalkSpeed() const;

    //les animations d'actions
    void walk();
    void stealthWalk();
    void attack();
    void stand();

private:
    irr::scene::IAnimatedMesh *m_me;//la mesh de l'entité
    irr::scene::IAnimatedMeshSceneNode *m_myNode;//le noeud de scène de la mesh
    irr::f32 m_walkFrames[2];//l'intervalle de frame de l'animation marcher
    irr::f32 m_stealthWalkFrames[2];//celui de marche discret
    irr::f32 m_attackFrames[2];// celui de l'attaque de base
    irr::f32 m_standingFrames[2];//lorsu'il est juste debout
    irr::f32 m_walkSpeed;

};

#endif // MYMESH_H
