package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readLine(r *bufio.Reader) string {
	input, _ := r.ReadString('\n')
	return strings.TrimSpace(input)
}

func strToIntSlice(str string) []int {
	sSlice := strings.Split(str, " ")
	iSlice := make([]int, 0, len(sSlice))
	for _, str := range sSlice {
		n, _ := strconv.Atoi(str)
		iSlice = append(iSlice, n)
	}
	return iSlice
}

func min(nums ...int) int {
	if len(nums) == 1 {
		return nums[0]
	}

	minNum := nums[0]
	for _, n := range nums {
		if n < minNum {
			minNum = n
		}
	}

	return minNum
}

func main() {
	r := bufio.NewReader(os.Stdin)
	var H, W int
	fmt.Sscanf(readLine(r), "%d %d", &H, &W)

	img1 := make([][]int, H)
	for i := 0; i < H; i++ {
		img1[i] = strToIntSlice(readLine(r))
	}

	img2 := make([][]int, H)
	for i := 0; i < H; i++ {
		img2[i] = strToIntSlice(readLine(r))
	}

	imgDiff := make([][]int, H)
	for i := 0; i < H; i++ {
		imgDiff[i] = make([]int, W)
		for j := 0; j < W; j++ {
			diff := img1[i][j] - img2[i][j]
			diffSquare := diff * diff
			imgDiff[i][j] = diffSquare
		}
	}

	dp := make([]int, W)
	for i := 0; i < H; i++ {
		newDp := make([]int, W)
		for j := 0; j < W; j++ {
			if W == 1 {
				newDp[j] = dp[j] + imgDiff[i][j]
			} else if j == 0 {
				newDp[j] = min(dp[j], dp[j+1]) + imgDiff[i][j]
			} else if j == W-1 {
				newDp[j] = min(dp[j-1], dp[j]) + imgDiff[i][j]
			} else {
				newDp[j] = min(dp[j-1], dp[j], dp[j+1]) + imgDiff[i][j]
			}
		}
		dp = newDp
	}

	minDiffs := 987654321
	for _, diffs := range dp {
		if diffs < minDiffs {
			minDiffs = diffs
		}
	}

	fmt.Printf("%d\n", minDiffs)
}
