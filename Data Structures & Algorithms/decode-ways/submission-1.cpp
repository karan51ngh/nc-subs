class Solution {
public:
    /*
        valid codes:
        - 1, 2, 3, 4, 5, 6 ..., 9,
        - 10, 11, 12, ..., 19,
        - 21, 22, ..., 26.

        rules
        - rules for both 1 step and 2 step invalids.

        while traversing:
        - each step -> 1 char or 2 char
        - check if valid (rules)
        
        - index: 0, 1, 2 ... i
        - no_decode_ways[ i ] = no_decode_ways[ i - 1 ] (if that +1 is valid)
            + no_decode_ways[ i - 2 ] (if that +2 is valid)

    */

    bool isValidUnit( string s ) {
        int sz = s.size();
        
        if (sz == 0 || sz > 2) return false;

        if (sz == 1) {
            if (s[0] == '0') return false;
        }
        
        if (sz == 2) {
            if (!(s[0] == '1' || s[0] == '2')) return false;

            if (s[0] == '2') {
                int num2 = (int)s[1] - (int)'0';

                if ( !(num2 >= 0 && num2 <= 6)) return false;
            }
        }
        return true;
    }


    int numDecodings(string s) {
        
        int sz = s.size();

        if (sz == 1) {
            return isValidUnit(s);
        }

        // if (sz == 2) {
        //     return isValidUnit(s);
        // }

        vector<int> now(sz);

        now[0] = isValidUnit(s.substr(0,1)) ? 1 : 0;

        now[1] = 
                (isValidUnit( s.substr( 1 , 1 ) ) ? now[ 0 ] : 0)
                +
                (isValidUnit( s.substr( 0 , 2 ) ) ?  1 : 0);

        for (int i = 2; i < sz; i++) {
            now[i] = 
                (isValidUnit( s.substr( i , 1 ) ) ? now[ i-1 ] : 0)
                +
                (isValidUnit( s.substr( i-1 , 2 ) ) ?  now[ i-2 ] : 0);
        }


        return now[ sz-1 ];
    }
};
