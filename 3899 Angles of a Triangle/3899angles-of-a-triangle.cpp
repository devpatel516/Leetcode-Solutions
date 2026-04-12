class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double a=sides[0];
        double b=sides[1];
        double c=sides[2];
        double pi=M_PI;
        double theta1,theta2,theta3;
        if(a+b>c && b+c>a && c+a>b){
            theta1=acos((b*b+c*c-a*a)/(2*b*c))*180.0/pi;
            theta2=acos((a*a+b*b-c*c)/(2*a*b))*180.0/pi;
            theta3=acos((a*a+c*c-b*b)/(2*a*c))*180.0/pi;
        }
        else{
            return {};
        }
            vector<double> ans(3);
            ans[0]=theta1;
            ans[1]=theta2;
            ans[2]=theta3;
            sort(ans.begin(),ans.end());
        return ans;
    }
};