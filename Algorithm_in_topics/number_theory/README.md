**Number Theory**
---
* Very basic, challenging but fascinating algorithm type
* Usually correlated with theories such as **factor**, **prime numbers***, etc.
* A very classic fixed point algoirthm, **Newton's Method**, refer to wikipedia pages for reference ([general method](https://en.wikipedia.org/wiki/Newton%27s_method), [specific method for square root integer finding](https://en.wikipedia.org/wiki/Integer_square_root#Algorithm_using_Newton's_method)). 
  * Here's a simple code snippet for square root finding within `double` type:
    ```C++
    double NewtonsMethodDouble(double num) // suppose the given num >= 0
    {
      double thres = 0.01;
      double x_curr = num, x_prev = num; 

      while (abs(curr - x_prev) > thres)
      {
        x_prev = x_curr;
        x_curr = 1/2 * (x_curr + num / x_curr);
      }

      return x_curr;
    }
    ```
  * Here's another simple code snippet for square root finding within `int` type:
    ```C++
    int NewtonsMethodInt(int num) // suppose the given num >= 0
    {
      int thres = 1; // according to the wikipedia, 1 is the largest possible threshold here
      int x_curr = num, x_prev = num; 

      while (abs(curr - x_prev) > thres)
      {
        x_prev = x_curr;
        x_curr = 1/2 * (x_curr + num / x_curr);
        if (x_prev == x_curr - 1) // important: according to the wiki, sqrt(n) is not a fixed point if n + 1 is a square number
                                  // now it triggers an additional termination criteria
        {
          x_curr = x_prev; // take the smaller one as root
          break;
        }
      }

      return x_curr;
    }
    ```

**Basic Sub-topics**
---
| # | Sub-topic | Classic Examples |
|---| --------- | ---------------- |
|1|[Newton's Method](newtons_method/) | [Three Distinct Factors](newtons_method/three_distinct_factors.cpp)|

**References**
---
* [Newton's Method (general)](https://en.wikipedia.org/wiki/Newton%27s_method)
* [Newton's Method (specificlly for square root finding within integer)](https://en.wikipedia.org/wiki/Integer_square_root#Algorithm_using_Newton's_method)