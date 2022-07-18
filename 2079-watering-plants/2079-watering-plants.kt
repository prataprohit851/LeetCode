class Solution {
    fun wateringPlants(plants: IntArray, capacity: Int): Int {
        var bucket = capacity
        var steps = 0
        for (i in 0..plants.size-1) {
            if(bucket >= plants[i]){
                bucket -= plants[i]
                steps++
            }
            else{
                steps += (2*i) + 1
                bucket = capacity
                bucket -= plants[i]
            }
        }
        return steps
    }
}