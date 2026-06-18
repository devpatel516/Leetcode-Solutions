class Solution {
public:
    double angleClock(int hour, int minutes) {
      hour%=12;
      double a=30*hour;
      double b=double(11/2.0)*minutes;
      return min(abs(a-b),360-abs(a-b));  
    }
};