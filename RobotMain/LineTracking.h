

#ifndef LINETRACKING_H
#define LINETRACKING_H

class LineTracking {
  private:
    int LT_R;
    int LT_M;
    int LT_L;
  public:
    LineTracking();
    void setup();
    void move();
    void forward();
    void back();
    void left();
    void right();
    void stop();
};

#endif
