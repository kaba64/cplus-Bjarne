#include <FL/Fl.H> /*header includes the core FLTK library*/
#include <FL/Fl_Window.H> /*header includes the definition of the Fl_Window class, which represents a window in FLTK*/
#include <FL/fl_draw.H> /*header includes drawing functions and utilities for FLTK*/

/*This class represents a window that will display a triangle*/
class TriangleWindow : public Fl_Window {
public:
  TriangleWindow(int width, int height) : Fl_Window(width, height) {}
  
  void draw() override {
    /*This ensures that the window is properly drawn before drawing the triangle*/
    Fl_Window::draw(); // Call base class draw method
        
    fl_color(FL_RED); // Set color to red
    fl_begin_polygon();
    fl_vertex(100, 100); // Vertex 1
    fl_vertex(200, 300); // Vertex 2
    fl_vertex(300, 100); // Vertex 3
    fl_end_polygon();

  }
};

int main() {
  TriangleWindow window(400, 400);
  /*This displays the window on the screen*/
  window.show();
  /*This starts the FLTK event loop, which handles user input and window events. 
    The program will continue running until the user closes the window*/
  return Fl::run();
}
