func productExceptSelf(nums []int) []int {
    prod := 1
    zeroCount := 0

    for _, num := range nums {
        if num != 0 {
            prod *= num
        } else {
            zeroCount++
        }
    }

    res := make([]int, len(nums))
    if zeroCount > 1 {
        return res
    }

    for i, num := range nums {
        if zeroCount > 0 {
            if num == 0 {
                res[i] = prod
            } else {
                res[i] = 0
            }
        } else {
            res[i] = prod / num
        }
    }
    return res
}