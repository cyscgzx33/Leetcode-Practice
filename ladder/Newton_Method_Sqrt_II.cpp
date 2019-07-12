class Solution {
public:
    /**
     * @param x: a double
     * @return: the square root of x
     */
    double sqrt(double x) {
        // write your code here
        
        // A Newton's method
        
        // Step 0: set the start point equal to the input
        double x_cur = x; // x0 = input
        double y_cur = x_cur * x_cur;
        
        while ( abs(y_cur - x) > pow(0.1, 12) ) { // not sure about the accuracy
            // Step 1: find a tangent line that goes through current point
            double derivative = 2 * x_cur; // f`(x) = 2x
            
            // Step 2: find the cross point of tangent line and the target line
            /* [detailed process] 
             * y = f'(x_cur) * (x - x_cur) + y_cur --> y = 2*x_cur*x - x_cur^2
             * Let y = target --> x0 = 2*x_cur*x - x_cur^2 --> x = (x0 + x_cur^2)/ (2*x_cur);
             */
            x_cur = (x + x_cur*x_cur) / (2*x_cur);
            y_cur = x_cur * x_cur;
        }
        
        return x_cur;
    }
};