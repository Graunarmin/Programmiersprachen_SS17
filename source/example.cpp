#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "rectangle.hpp"
#include "circle.hpp"
#include <vector> 



int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1{400 + 380 * std::sin(t)};
    float y1{400 + 380 * std::cos(t)};

    float x2{400 + 380 * std::sin(2.0f*t)};
    float y2{400 + 380 * std::cos(2.0f*t)};

    float x3{400 + 380 * std::sin(t-10.f)};
    float y3{400 + 380 * std::cos(t-10.f)};

    //Vektoren zum speichern initialisieren
    std::vector<Circle> vC;
    std::vector<Rectangle> vR;

    //erstellen der Objekte
    vR.push_back(Rectangle{Vec2{66.09f, 81.0f}, Vec2{273.0f, 302.0f}, Color{}});
    vR.push_back(Rectangle{Vec2{-10.0f, 45.50f}, Vec2{87.3f, 100.3}, Color{1.0f, 1.0f, 1.0f}});
    vR.push_back(Rectangle{Vec2{34.0f, 500.7f}, Vec2{98.0f, 720.f}, Color{}});

    vC.push_back(Circle{25.0f, Vec2{400.0f, 200.0f}, Color{}});
    vC.push_back(Circle{40.5f, Vec2{450.0f, 100.0f}, Color{}});
    vC.push_back(Circle{30.0f, Vec2{290.0f, 250.0f}, Color{}});
    
    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto m = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30, 30, // from
          m.first, m.second, // to
          1.0,0.0,0.0);
    }

    win.draw_line(0, m.second, 10, m.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, m.second, win.window_size().second, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0, m.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(m.first, win.window_size().second - 10, m.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string text = "mouse position: (" + std::to_string(m.first) + ", " + std::to_string(m.second) + ")";
    win.draw_text(10, 5, 35.0f, text);

    //Zeichnen
    vR[0].draw(win);
    vR[1].draw(win);
    vR[2].draw(win, Color{0.0f, 1.0f, 0.0f});

    //blau, wenn Zeiger drin
    for (int i = 0; i < vR.size(); ++i){
    	if (vR[i].is_inside(Vec2{(float)win.mouse_position().first, (float)win.mouse_position().second})){
    	vR[i].draw(win, Color{0.0f, 0.0f, 1.0f});
    	}
    }

    vC[0].draw(win);
    vC[1].draw(win, Color{0.0f, 1.0f, 1.0f});
    vC[2].draw(win);

    for (int i = 0; i < vC.size(); ++i){
    	if (vC[i].is_inside(Vec2{(float)win.mouse_position().first, (float)win.mouse_position().second})){
    	vC[i].draw(win, Color{0.0f, 0.0f, 1.0f});
    	}
    }
 

    win.update();
  }

  return 0;
}
