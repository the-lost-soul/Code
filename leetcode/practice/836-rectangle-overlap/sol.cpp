class Solution
{
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
    {
        // when input is straight line .
        if(rec1[0] == rec1[2] || rec1[1] == rec2[3] ||
                rec2[0] == rec2[2] || rec2[1] == rec2[3])
            return false ;

        return !(rec1[2] <= rec2[0] ||
                rec1[3] <= rec2[1] ||
                rec1[0] >= rec2[2] ||
                rec1[1] >= rec2[3]) ;


        
    }
};
