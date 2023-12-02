#include "SceneDisplay.h"

using namespace irr;
using namespace core;
using namespace video;

SceneDisplay::SceneDisplay(wxIrrlicht* irrlichtWindow)
{
	
	//test scene
	irrWind = irrlichtWindow;
	device = irrWind->GetDevice();
	smgr = device->getSceneManager();
	driver = device->getVideoDriver();


	// add our media directory as "search path"
	device->getFileSystem()->addFileArchive("Assets/Editor/");

	scene::ICameraSceneNode* cam[2] = { 0, 0 };
	cam[0] = smgr->addCameraSceneNodeMaya(0, -200.0f, 200.0f, 200.0f, -1, 100.0f);
	cam[0]->setName("maya Cam");
	cam[0]->setFarValue(20000.f);
	cam[0]->setTarget(vector3df(0, 30, 0));
	irrWind->m_pCameraNode = cam[0];
	

	cam[1] = smgr->addCameraSceneNodeFPS();
	cam[1]->setName("fps Cam");
	cam[1]->setFarValue(20000.f);
	cam[1]->setPosition(vector3df(0, 0, -10));
	cam[1]->setTarget(vector3df(0, 5, 0));

	smgr->setActiveCamera(cam[0]);

	grid = new CGridSceneNode(smgr->getRootSceneNode(), smgr, -1, 1);
	grid->setGridsSize(irr::core::dimension2df(2500, 2500));
	grid->getGrid(0).setSpacing(10.f);
	grid->getGrid(0).setGridColor(irr::video::SColor(200, 255, 255, 255));
	grid->drop();  // added to scene already, that still has a reference
	grid->setIsDebugObject(true);


	CreateCube();
	
	smgr->addSkyBoxSceneNode(
		driver->getTexture("Editor/skyboxes/irrlicht2_up.jpg"),
		driver->getTexture("Editor/skyboxes/irrlicht2_dn.jpg"),
		driver->getTexture("Editor/skyboxes/irrlicht2_lf.jpg"),
		driver->getTexture("Editor/skyboxes/irrlicht2_rt.jpg"),
		driver->getTexture("Editor/skyboxes/irrlicht2_ft.jpg"),
		driver->getTexture("Editor/skyboxes/irrlicht2_bk.jpg"))->setName("SkyBox");

	core::dimension2du d = core::dimension2du(400, 300);
	driver->OnResize(d);
	// now irrlicht internally ajusted device's resolution, but active camera will not update its aspect ratio automatically (which is OK, because you may no need it), so if you want the camera to be OK after this resize, you need to write also something like:
	smgr->getActiveCamera()->setAspectRatio((float)d.Width / d.Height);

}

void SceneDisplay::CreateCube()
{
	ISceneNode* node = 0;
	scene::IAnimatedMesh* mesh = smgr->getMesh("Editor/meshes/cube.obj");

	node = smgr->addAnimatedMeshSceneNode(mesh);
	node->setName("cube");
	node->setScale(vector3df(10, 10, 10));
	node->setMaterialTexture(0, driver->getTexture("Editor/textures/grid_box.jpg"));
	node->setMaterialFlag(video::EMF_LIGHTING, false);
	node->setMaterialType(video::EMT_SOLID);
}

void SceneDisplay::CreateSphere()
{
	ISceneNode* node = 0;
	scene::IAnimatedMesh* mesh = smgr->getMesh("Editor/meshes/sphere.obj");
	
	node = smgr->addAnimatedMeshSceneNode(mesh);
	node->setName("sphere");
	node->setScale(vector3df(10, 10, 10));
	node->setMaterialTexture(0, driver->getTexture("Editor/textures/grid_box.jpg"));
	node->setMaterialFlag(video::EMF_LIGHTING, false);
	node->setMaterialType(video::EMT_SOLID);
}

void SceneDisplay::CreateCylinder()
{
	ISceneNode* node = 0;
	scene::IAnimatedMesh* mesh = smgr->getMesh("Editor/meshes/cylinder.obj");

	node = smgr->addAnimatedMeshSceneNode(mesh);
	node->setName("capsule");
	node->setScale(vector3df(10, 10, 10));
	node->setMaterialTexture(0, driver->getTexture("Editor/textures/grid_box.jpg"));
	node->setMaterialFlag(video::EMF_LIGHTING, false);
	node->setMaterialType(video::EMT_SOLID);
}

void SceneDisplay::CreateCapsule()
{
	ISceneNode* node = 0;
	scene::IAnimatedMesh* mesh = smgr->getMesh("Editor/meshes/capsule.obj");

	node = smgr->addAnimatedMeshSceneNode(mesh);
	node->setName("capsule");
	node->setScale(vector3df(10, 10, 10));
	node->setMaterialTexture(0, driver->getTexture("Editor/textures/grid_box.jpg"));
	node->setMaterialFlag(video::EMF_LIGHTING, false);
	node->setMaterialType(video::EMT_SOLID);
}

void SceneDisplay::CreatePlane()
{
	ISceneNode* node = 0;
	scene::IAnimatedMesh* mesh = smgr->getMesh("Editor/meshes/plane.obj");

	node = smgr->addAnimatedMeshSceneNode(mesh);
	node->setName("plane");
	node->setScale(vector3df(10, 10, 10));
	node->setMaterialTexture(0, driver->getTexture("Editor/textures/grid_box.jpg"));
	node->setMaterialFlag(video::EMF_LIGHTING, false);
	node->setMaterialType(video::EMT_SOLID);
}

void SceneDisplay::CreateGrid()
{
	ISceneNode* node = 0;
	scene::IAnimatedMesh* mesh = smgr->getMesh("Editor/meshes/plane.obj");

	node = smgr->addAnimatedMeshSceneNode(mesh);
	node->setName("grid");
	node->setScale(vector3df(500, 500, 500));
	node->setMaterialTexture(0, driver->getTexture("Editor/textures/grid-texture.png"));
	node->setMaterialFlag(video::EMF_LIGHTING, false);
	node->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL);
}
