# Irrlicht-Game-Engine

This is a hobby project to make a scene editor similar to irredit, but open source.

for the base window display I used wxWidgets, same as irredit.

code snippets and scripts That I added from other people:

- wxirrlicht: originally by Yiannis Mandravellos, but updated by loptr. it makes it easier to render an irrlicht scene inside of wxwidgets

- CGridSceneNode: originally by Dark_Kilauea, but updated by CuteAlien. creates a dynamic grid that can be any size, spacing, color required.

- borrowed icons from copper-cube editor, its temporary for the moment, spent a whole day fiddling with different images that wxwidgets clamed where broken,
 but turns out the png handler hates its job, even if its an ico file and not its business.

the program is still in development and has no use  yet, but current features are:

- scene window with the horrible maya cam irrlicht comes with. will be switching to something different soon.
- instantiate basic shapes(cube, sphere, cylinder, plane), im using model files for this at the moment until i create a custom node to make all the basic shapes proceduraly.
- hierarchy window that displays the names of the objects in the scene.

the code is messy and there is a lot of dead code since i mashed the wxwidgets aui sample with the win32 example from irrlicht. will be removing soon.
