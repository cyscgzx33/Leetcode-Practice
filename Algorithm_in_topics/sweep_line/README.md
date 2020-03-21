**Sweep Line**
---
* Easy to understand: imaging an imaginary vertical line that sweeps along with **time intervals**
* As a template, one can usually define an `Event` class for convenience of the sweep line
    ```c++
    class Event
    {
      public:
        int time;
        int flag; // 1: start, -1:end

        Event(int t, int f) : time(t), flag(f) {}
    };
    ```
* Sort the `vector` (or other containers) of the `Event` class objects if necessary

**Basic Sub-topics**
---
| # | Sub-topic | Classic Examples |
|---| --------- | ---------------- |
|1|Simple Sweep Line| [Airplane in the sky](airplane_in_the_sky.cpp), [Meeting rooms II](meeting_rooms_II.cpp), [Merge intervals](merge_intervals.cpp)
|2|Multiple Sweep Line| [Skyline problem](skyline_problem.cpp)