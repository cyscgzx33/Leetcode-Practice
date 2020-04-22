# Number Theory
## Background
---
* Very basic, challenging but fascinating algorithm type
* Usually correlated with theories such as **factor**, **prime numbers**, etc.
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
  * Here is an interesting property during the process of using **Newton's Method** to deal with square root finding:
  > Suppose our target is to calculate $\sqrt{\alpha}$, then one inequality (0) will always hold during the iteration *no matter how the initial value $x_0$ is chosen*, which is:
  >
  > $$x_{n+1}<\sqrt{\alpha}$$ (0) 
  * A simple proof of (0) can be achieved by proving by contradiction: 
  > Proof: Assume the condition doesn't always hold, say at step $k$ it violates condition (0), then we can claim (1):
  >
  > $$x_{k+1}^2<\alpha$$ (1)
  > consider the **Newton's Method** equation (2):
  >
  > $$x_{n+1} = x_{n} - \frac{f(x_{n})}{f^{\prime}({x_{n}})}$$(2)
  >
  > as we're trying to find square root, the target function $f(x)$ can be expressed as (3):
  >
  > $$f(x)=x^2-\alpha$$ (3)
  > Take derivative of (3), we can easily obtain $f^{\prime}(x)$ as (4):
  >
  > $$f^{\prime}(x)=2 x$$(4)
  > Now apply expressions (2) - (4) into (1) and organize the terms clearly, we can obtain (5):
  > 
  > $$(\frac{x_{n}}{2} + \frac{\alpha}{2 x_{n}})^2<\alpha$$ (5)
  > By further simplifying, we can obtain (6) as an equivalent expression as (5):
  > 
  > $$(\frac{x_{n}}{2} - \frac{\alpha}{2 x_{n}})^2<0$$ (6)
  > Clearly, (6) doesn't hold for $\frac{x_{n}}{2} - \frac{\alpha}{2 x_{n}} \in \mathbb{R}$, which is a contradiction. Therefore, inequality (0) has been proved.


## Basic Sub-topics
---
| # | Sub-topic | Classic Examples |
|---| --------- | ---------------- |
|1|[Newton's Method](newtons_method/) | [Three Distinct Factors](newtons_method/three_distinct_factors.cpp)|

## References
---
* [Newton's Method (general)](https://en.wikipedia.org/wiki/Newton%27s_method)
* [Newton's Method (specificlly for square root finding within integer)](https://en.wikipedia.org/wiki/Integer_square_root#Algorithm_using_Newton's_method)