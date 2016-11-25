# ElapsedTimer
A simple class for an elapsed timer, primarily for use with Arduinos.

# Description
## ElapsedTimer(_dur_, _autoRestart_)
Creates a timer object (constructor). Creating a timer does NOT start it, you must call the _start_ method.
### Arguments
* unsigned long _dur_: duration in milliseconds. Default is 1000 milliseconds.
* bool _autoRestart_: if true, the timer will auto-restart when the method _timedOut_ is called and the result is true. Default is _false_.

## void start(_dur_)
Starts (activates) the timer with an optional duration.
### Arguments
* unsigned long _dur_: duration in milliseconds. If none is provided (e.g., duration = 0), the previous duration is used.

## void stop()
Stops (deactivates) the timer.

## bool isActive()
Returns the current state of the timer, true = active, false = inactive.

## bool timedOut()
Returns whether the timer has timed out (true) or not (false). When a timer times out, if the timer object was created with _autoRestart_ set to true, then the timer is automatically restarted, otherwise the timer is stopped (deactivated).

## unsigned long remainingMs()
Returns the number of milliseconds before the timer times out.
