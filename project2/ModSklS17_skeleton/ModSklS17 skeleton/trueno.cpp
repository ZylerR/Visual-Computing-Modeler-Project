// The sample model.  You should build a file
// very similar to this for when you make your model.
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>

#include "modelerglobals.h"
double inc = 0;
double pop = 0;
double popTwo = 0;
double dec = 1;
// To make a SampleModel, we inherit off of ModelerView
class TruenoModel : public ModelerView 
{
public:
    TruenoModel(int x, int y, int w, int h, char *label) 
        : ModelerView(x,y,w,h,label) { }

    virtual void draw();
};

// We need to make a creator function, mostly because of
// nasty API stuff that we'd rather stay away from.
ModelerView* createTruenoModel(int x, int y, int w, int h, char *label)
{ 
    return new TruenoModel(x,y,w,h,label);
}

// We are going to override (is that the right word?) the draw()
// method of ModelerView to draw out SampleModel
void TruenoModel::draw()
{
    // This call takes care of a lot of the nasty projection 
    // matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
    ModelerView::draw();
	if (inc == 360)
	{
		inc = 0;
	}
	if (pop == 55)
	{
		dec = -1;
	}
	if (pop == 0)
	{
		dec = 1;
	}
	if (popTwo == 55)
	{
		dec = -1;
	}
	if (popTwo == 0)
	{
		dec = 1;
	}
	// draw the floor
	setAmbientColor(.1f,.1f,.1f);
	setDiffuseColor(COLOR_RED);
	glPushMatrix();
	glTranslated(-5,0,-5);
	drawBox(10,0.01f,10);
	glPopMatrix();

	// draw the sample model
	setAmbientColor(.1f,.1f,.1f);
	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glRotated(inc, 0.0, 1.0, 0.0);
	//inc = inc + 1; //Uncomment this for turntable animation :) 
	glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));

		glPushMatrix();
		//Base of car
		glTranslated(-1.5, 0.75, -2);
		glScaled(3, 0.5, 5);
		drawBox(1,1,1);

		glPopMatrix();

		setDiffuseColor(COLOR_BLACK);

		glPushMatrix();
		//Hood
		glTranslated(-1.49, 0.8, -2);
		glRotated(-10, 1.0, 0.0, 0.0);
		glScaled(3, 0.5, 1.5);
		drawBox(0.99, 0.99, 0.99);

		glPopMatrix();

		setDiffuseColor(COLOR_WHITE);
		//Windshield
		glPushMatrix();

		glTranslated(-1.49, 0.75, -0.5);
		glRotated(-45, 1.0, 0.0, 0.0);
		glScaled(3, 0.5, 1.5);
		drawBox(0.99, 0.99, .99);

		glPopMatrix();

		setDiffuseColor(COLOR_BLACK);

		glPushMatrix();
		//Underside of car
		glTranslated(-1.49, 0.5, -1.9);
		glScaled(3, 0.5, 4.8);
		drawBox(0.99, 0.99, 0.99);

		glPopMatrix();

		setDiffuseColor(COLOR_WHITE);

		glPushMatrix();
		//Rear windshield
		glTranslated(-1.49, 1.7, 1.25);
		glRotated(30, 1.0, 0.0, 0.0);
		glScaled(3, 0.5, 1.75);
		drawBox(0.99, 0.99, .99);

		glPopMatrix();

		setDiffuseColor(COLOR_BLACK);

		glPushMatrix();
		//Rear windshieldBlack
		glTranslated(-1.43, 1.35, 2.9);
		glRotated(-60, 1.0, 0.0, 0.0);
		glScaled(3, 0.5, 0.01);
		drawBox(0.95, 3, .99);

		glPopMatrix();

		glPushMatrix();
		//Front windshieldBlack
		glTranslated(-1.43, 1.51, -0.49);
		glRotated(45, 1.0, 0.0, 0.0);
		glScaled(3, 0.3, 0.01);
		drawBox(0.95, 3, .99);

		glPopMatrix();

		setDiffuseColor(COLOR_WHITE);

		glPushMatrix();
		//Roof
		glTranslated(-1.49, 1.7, 0.225);
		glScaled(3, 0.45, 1.30);
		drawBox(0.99, 0.99, .99);

		glPopMatrix();

		setDiffuseColor(COLOR_BLACK);

		glPushMatrix();
		//Front Left Tire
		glTranslated(-1.4, 0.5, -1.25);
		glTranslated(-VAL(AXELWIDTH), 0, 0);
		glRotated(VAL(TURN), 0.0, 1.0, 0.0);
		drawCylinder(0.5, 0.45, 0.45);

		glPopMatrix();

		glPushMatrix();
		//Front Right Tire
		glTranslated(0.9, 0.5, -1.25);
		glTranslated(VAL(AXELWIDTH), 0, 0);
		glRotated(VAL(TURN), 0.0, 1.0, 0.0);
		drawCylinder(0.5, 0.45, 0.45);

		glPopMatrix();

		glPushMatrix();
		//Front Axel #1
		glTranslated(-1, 0.5, -1.25);
		glRotated(90, 0.0, 1.0, 0.0);
		drawCylinder(VAL(AXELWIDTH) + 2.4, 0.1, 0.1);

		glPopMatrix();

		glPushMatrix();
		//Front Axel #2
		glTranslated(-1, 0.5, -1.25);
		glRotated(90, 0.0, 1.0, 0.0);
		glTranslated(0, 0, -1 * VAL(AXELWIDTH));
		drawCylinder(VAL(AXELWIDTH) + 2.4, 0.1, 0.1);

		glPopMatrix();

		glPushMatrix();
		//Back Axel #1
		glTranslated(-1, 0.5, 2.15);
		glRotated(90, 0.0, 1.0, 0.0);
		//glScaled(1, 1, );
		//glTranslated(0, 0, -1 * VAL(AXELWIDTH));
		drawCylinder(VAL(AXELWIDTH) + 2.4, 0.1, 0.1);

		glPopMatrix();

		glPushMatrix();
		//Back Axel #2
		glTranslated(-1, 0.5, 2.15);
		glRotated(90, 0.0, 1.0, 0.0);
		//glScaled(1, 1, );
		glTranslated(0, 0, -1 * VAL(AXELWIDTH));
		drawCylinder(VAL(AXELWIDTH) + 2.4, 0.1, 0.1);

		glPopMatrix();

		glPushMatrix();
		//Back Right Tire
		glTranslated(0.9, 0.5, 2.15);
		glTranslated(VAL(AXELWIDTH), 0, 0);
		glRotated(90, 0.0, 1.0, 0.0);
		drawCylinder(0.5, 0.45, 0.45);

		glPopMatrix();

		glPushMatrix();
		//Back Left Tire
		glTranslated(-1.4, 0.5, 2.15);
		glTranslated(-VAL(AXELWIDTH), 0, 0);
		glRotated(90, 0.0, 1.0, 0.0);
		drawCylinder(0.5, 0.45, 0.45);

		glPopMatrix();

		glPushMatrix();
		//Front Left Headlight
		glTranslated(-1.4, 1.4, -1.55);//-1.4, 1.4, -1.55
		glRotated(VAL(POPLIGHTS) + pop, 1.0, 0.0, 0.0);//-190 is headlights closed -135 open
		//pop = pop + dec; //uncomment for poplight anims :) (not compatible with the poplight slider)
		glScaled(1, 0.45, 1);
		drawBox(0.5, 0.45, 0.45);

		//glPopMatrix();

		setDiffuseColor(COLOR_YELLOW);

		glPushMatrix();
		//Front Left Headlight Light
		glTranslated(0, 1, 0.15);//-1.4, 1.25, -2
		glRotated(70, 1.0, 0.0, 0.0);//-190 is headlights closed -135 open
		glScaled(1, 0.2, 1);
		drawBox(0.5, 0.45, 0.6);

		setDiffuseColor(COLOR_ORANGE);

		glPushMatrix();
		//Front Left Headlight Orange Part of Light
		glTranslated(0.005, 0.25, 0);//-1.4, 1.25, -2
		glRotated(10, 1.0, 0.0, 0.0);//-190 is headlights closed -135 open
		drawBox(0.29, 0.25, 0.3);//49 45 5

		setDiffuseColor(COLOR_WHITE);

		glPushMatrix();
		//Front Left Headlight White Part of Light
		glTranslated(0.005, 0.45, 0);//-1.4, 1.25, -2
		glScaled(1, 0.2, 1);
		drawBox(0.09, 0.05, 0.1);//29 25 3

		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();

		setDiffuseColor(COLOR_BLACK);

		glPushMatrix();
		//Front Right Headlight
		glTranslated(0.9, 1.4, -1.55);//-1.4, 1.4, -1.55
		glRotated(VAL(POPLIGHTS) + popTwo, 1.0, 0.0, 0.0);//-190 is headlights closed -135 open
		//popTwo = popTwo + dec; //uncomment for poplight anims :) (not compatible with the poplight slider)
		glScaled(1, 0.45, 1);
		drawBox(0.5, 0.45, 0.45);

		setDiffuseColor(COLOR_YELLOW);

		glPushMatrix();
		//Front Right Headlight Light
		glTranslated(0, 1, 0.15);//-1.4, 1.25, -2
		glRotated(70, 1.0, 0.0, 0.0);//-190 is headlights closed -135 open
		glScaled(1, 0.2, 1);
		drawBox(0.5, 0.45, 0.6);

		setDiffuseColor(COLOR_ORANGE);

		glPushMatrix();
		//Front Right Headlight Orange Part of Light
		glTranslated(0.005, 0.25, 0);//-1.4, 1.25, -2
		glRotated(10, 1.0, 0.0, 0.0);//-190 is headlights closed -135 open
		drawBox(0.29, 0.25, 0.3);//49 45 5

		setDiffuseColor(COLOR_WHITE);

		glPushMatrix();
		//Front Right Headlight White Part of Light
		glTranslated(0.005, 0.45, 0);//-1.4, 1.25, -2
		glScaled(1, 0.2, 1);
		drawBox(0.09, 0.05, 0.1);//29 25 3

		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();

		setDiffuseColor(COLOR_ORANGE);

		glPushMatrix();
		//Front Right Blinker
		glTranslated(0.9, 1.05, -2.05);//-1.4, 1.4, -1.55
		glRotated(80, 1.0, 0.0, 0.0);//-190 is headlights closed -135 open
		glScaled(1, 0.2, 1);
		drawBox(0.5, 0.05, 0.1);//29 25 3

		glPopMatrix();

		glPushMatrix();
		//Front Left Blinker
		glTranslated(-1.4, 1.05, -2.05);//-1.4, 1.4, -1.55
		glRotated(80, 1.0, 0.0, 0.0);//-190 is headlights closed -135 open
		glScaled(1, 0.2, 1);
		drawBox(0.5, 0.05, 0.1);//29 25 3

		glPopMatrix();

		setDiffuseColor(COLOR_YELLOW);

		glPushMatrix();
		//Front Left Fog Light
		glTranslated(-1.15, 0.7, -1.95);//-1.4, 1.4, -1.55
		glRotated(80, 1.0, 0.0, 0.0);//-190 is headlights closed -135 open
		glScaled(0.5, 0.2, 1);
		drawBox(0.5, 0.05, 0.1);//29 25 3

		glPopMatrix();

		glPushMatrix();
		//Front Right Fog Light
		glTranslated(0.9, 0.7, -1.95);//-1.4, 1.4, -1.55
		glRotated(80, 1.0, 0.0, 0.0);//-190 is headlights closed -135 open
		glScaled(0.5, 0.2, 1);
		drawBox(0.5, 0.05, 0.1);//29 25 3

		glPopMatrix();
		 //Add axel binded to wheel functionality. Also wheel turns maybe? 
		/*
		// draw cannon
		glPushMatrix();
		glRotated(VAL(ROTATE), 0.0, 1.0, 0.0);
		glRotated(-90, 1.0, 0.0, 0.0);
		drawCylinder(VAL(HEIGHT), 0.1, 0.1);

		glTranslated(0.0, 0.0, VAL(HEIGHT));
		drawCylinder(1, 1.0, 0.9);

		glTranslated(0.0, 0.0, 0.5);
		glRotated(90, 1.0, 0.0, 0.0);
		drawCylinder(4, 0.1, 0.2);
		glPopMatrix();*/


	glPopMatrix();
}

int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
    ModelerControl controls[NUMCONTROLS];
    controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
    controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
    controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);
    controls[HEIGHT] = ModelerControl("Height", 1, 2.5, 0.1f, 1);
	controls[POPLIGHTS] = ModelerControl("Pop Lights", -190, -135, 1, -190);
	controls[AXELWIDTH] = ModelerControl("Axel Width", 0, 1, 0.1f, 0.12);
	controls[TURN] = ModelerControl("Turn Tires", 75, 105, 1, 90);

    ModelerApplication::Instance()->Init(&createTruenoModel, controls, NUMCONTROLS);
    return ModelerApplication::Instance()->Run();
}
