#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "circle.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include <vector> 


int main(int argc, char* argv[])
{
  Window win{std::make_pair(600,600)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    auto t = win.get_time();

    //Uhr zeichnen
    Circle clock{250.0f, Vec2{300.0f, 300.0f}, Color{}};
    clock.draw(win);

    //Zeit t in Bogenmaß umrechnen
    float sec = (t * 2 * M_PI)/60;
    float min = sec/60;
    float hou = min/60;

    /*Zeiger erstellen, die sich um 0|0 drehen aber auf 12 Uhr zeigen, 
    also |radius| über 0 (- radius.y)*/
    Vec2 sZ{0, -clock.getRadius()}; 
    Vec2 mZ{0, -clock.getRadius() * 0.9f}; //Zeiger kürzen
    Vec2 hZ{0, -clock.getRadius() * 0.8f};

    //Drehmatrizen für die Zeit im Bogenmaß erstellen
    Mat2 matSec = make_rotation_mat2(sec);
    Mat2 matMin = make_rotation_mat2(min);
    Mat2 matHou = make_rotation_mat2(hou);

    /*Vektoren, die aus den urpsr. Zeigern multipliziert mit der Drehmatrix entstehen,
    also immer um die Zeit gedreht werden, und ins Zentrum der Uhr verschoben sind */
    Vec2 secZeiger{(matSec * sZ) + clock.getCenter()}; //rot
    Vec2 minZeiger{(matMin * mZ) + clock.getCenter()}; //grün
    Vec2 houZeiger{(matHou * hZ) + clock.getCenter()}; //blau

    //Zeiger zeichnen
    win.draw_line(clock.getCenter().x_, clock.getCenter().y_, secZeiger.x_, secZeiger.y_, 1.0f, 0.0f, 0.0f);
    win.draw_line(clock.getCenter().x_, clock.getCenter().y_, minZeiger.x_, minZeiger.y_, 0.0f, 1.0f, 0.0f);
    win.draw_line(clock.getCenter().x_, clock.getCenter().y_, houZeiger.x_, houZeiger.y_, 0.0f, 0.0f, 1.0f);

    win.draw_point(clock.getCenter().x_, clock.getCenter().y_, 0.0f,0.0f,0.0f);

    win.update();
  }

  return 0;
}