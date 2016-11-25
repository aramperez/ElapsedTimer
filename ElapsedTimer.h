#ifndef ELAPSED_TIMER_H
#define ELAPSED_TIMER_H
/*
  A simple class for an elapsed timer, primarily for use with Arduinos.
  Written by Aram Perez, aramperez at mac dot com.

  The MIT License (MIT)
  Copyright © 2016 Aram Perez

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation   files (the “Software”), to
  deal in the Software without restriction, including without limitation the
  rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
  sell copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
  IN THE SOFTWARE.    
*/

class ElapsedTimer {
    unsigned long startTime;
    unsigned long duration;
    bool active;
    bool autoRestart;
    ElapsedTimer();

  public:
    ElapsedTimer(unsigned long dur = 1000, bool autoRes = false) :
      duration(dur), active(false), autoRestart(autoRes) {}
    virtual ~ElapsedTimer(){}
    void start(unsigned long dur = 0) {
      if ( dur != 0 ) {
        duration = dur;
      }
      active = true;
      startTime = millis();
    }
    inline void stop() {active = false;}
    inline bool isActive() {return active;}
    bool timedOut() {
      bool rv;
      if ( active ) {
        rv = ((millis() - startTime) > duration) ? true : false;
        if ( rv ) {
          if( autoRestart ){
            startTime = millis();
          }else{
            active = false;
          }
        }
      }else{
        rv = false;
      }
      return rv;
    }
    inline unsigned long remainingMs() {
      return startTime + duration - millis();
    }
};

#endif  //ELAPSED_TIMER_H
