func countSpecialIntegers(nums []int) int {
    
	indicesMap := make(map[int][]int)

	for i, val := range nums {
		indicesMap[val] = append(indicesMap[val], i)
	}

	ans := 0

	for _, indices := range indicesMap {
		if len(indices) == 3 {
			if indices[1]-indices[0] == indices[2]-indices[1] {
				ans += 1
			}
		}
	}

	return ans

}