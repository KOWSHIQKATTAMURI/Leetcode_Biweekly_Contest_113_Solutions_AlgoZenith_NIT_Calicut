import java.util.*;

public class Solution {
    public int minimumRightShifts(int[] nums) {
        int n = nums.length;

        // to store the number of instances where the present element is greater than the next element as well as the index of that instance
        int number_of_break_points = 0, break_point_index = 0;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i + 1]){
                number_of_break_points++;
                break_point_index = i + 1;
            }
        }

        // if there are zero instances, then we need not sort the array as the array is already sorted
        // if the number of instances is greater than one, that means there are more than one point where the present element is greater than its next element. So right shifting it does not make it sorted.
        // also if the right most element is greater than the left most element (but number of break points is not equal to 0), that cannot be sorted. So in both the cases we return -1.
        if(number_of_break_points == 0){
            return 0;
        }else if((number_of_break_points > 1) || (nums[n - 1] > nums[0])){
            return -1;
        }
        return n - break_point_index;
    }
}
