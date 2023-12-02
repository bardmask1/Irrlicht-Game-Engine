#pragma once
#include "MainFrame.h"
#include "CGridSceneNode.h"

#include <irrlicht.h>


class SceneDisplay
{
public:
	SceneDisplay(wxIrrlicht* irrlichtWindow);

	void CreateCube();
	void CreateSphere();
	void CreateCapsule();
	void CreateCylinder();
	void CreatePlane();
	void CreateGrid();

	wxIrrlicht* irrWind;
	IrrlichtDevice* device;
	ISceneManager* smgr;
	IVideoDriver* driver;
};

