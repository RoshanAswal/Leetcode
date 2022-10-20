class Solution {
public:
    string intToRoman(int num) {
        string table[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                           {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                           {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                           {"", "M", "MM", "MMM"}
                          };
        string roman;
        int c=0;
        while(num!=0){
            int temp=num%10;
            roman=table[c][temp]+roman;
            num/=10;
            c++;
        }
        return roman;
    }
};