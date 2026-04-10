class Solution {
public:
    char nextDir(char dir,int action){
        if(dir=='n'){
            if(action==-1){
               dir='e'; 
            }
            else if(action==-2){
                dir='w';
            }
        }
        else if(dir=='s'){
            if(action==-1){
                dir='w';
            }
            else if(action==-2){
                dir='e';
            }
        }
        else if(dir=='e'){
            if(action==-1){
                dir='s';
            }
            else if(action==-2){
                dir='n';
            }
        }
        else if(dir=='w'){
            if(action==-1){
                dir='n';
            }
            else if(action==-2){
                dir='s';
            }
        }
        return dir;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0;
        int y=0;
        char cd='n';
        int maxi=0;
        set<vector<int>> s(obstacles.begin(),obstacles.end());
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1){
                cd=nextDir(cd,-1);
            }
            else if(commands[i]==-2){
                cd=nextDir(cd,-2);
            }
            else{
                for(int k=0;k<commands[i];k++){
                    int nx=x;
                    int ny=y;

                    if(cd=='n') ny++;
                    else if(cd=='s') ny--; 
                    else if (cd=='e') nx++;
                    else if (cd=='w') nx--;

                    if(s.contains({nx,ny})){
                        break;
                    }
                    x=nx;
                    y=ny;
                }
            }
            maxi=max(maxi,x*x+y*y);
        }
        return maxi;
    }
};