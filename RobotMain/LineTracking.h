#ifndef LINETRACKING_H
#define LINETRACKING_H

class LineTracking {
  private:
    int LT_R; // Right line tracking sensor pin
    int LT_M; // Middle line tracking sensor pin
    int LT_L; // Left line tracking sensor pin
  public:
    LineTracking(); // Constructor for the LineTracking class
    void setup(); // Method to set up the line tracking system
    void move(); // Method to initiate line tracking movement
    void forward(); // Method to move forward
    void back(); // Method to move backward
    void left(); // Method to turn left
    void right(); // Method to turn right
    void stop(); // Method to stop movement
};

#endif
