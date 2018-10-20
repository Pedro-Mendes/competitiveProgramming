/* https://leetcode.com/problems/compare-version-numbers
 git@Pedro-Mendes thanks to negc for posting this https://leetcode.com/problems/compare-version-numbers/discuss/180984/C%2B%2B-Short-and-simple-stringstream-solution-(0-ms)*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        stringstream s1(version1), s2(version2);
        
        int i1,i2;
        char delim;
        
        while(s1 || s2){
            
            if(!s1){ i1 = 0; }
            else{ s1>> i1; }
                
            if(!s2){ i2 = 0; }
            else{ s2>> i2; }
                
            if(i1 < i2){ return -1;}
            if(i1 > i2){ return 1;}
            
            s1 >> delim;
            s2 >> delim;
            
        }
        
        return 0;
    }
};