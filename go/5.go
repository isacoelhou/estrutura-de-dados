package main

import (
	"fmt"
	"os"
	"sort"
)

func main() {
	
	input, err := os.Open("aero.in")
	if err != nil {
		panic(err)
	}
	defer input.Close()

	output, err := os.Create("aero.out")
	if err != nil {
		panic(err)
	}
	defer output.Close()

	teste := 0

	for {
		var n1, n2 int

		fmt.Fscanf(input, "%d %d\n", &n1, &n2)

		if n1+n2 == 0 {
			return
		}

		voos := make([][2]int, n1)
		q := 1
		teste++
		k := 0

		for i := 0; i < n2*2; i++ {
			fmt.Fscan(input, &k)
			voos[k-1][0] += 1
		}

		for i := range voos {
			voos[i][1] = i + 1
		}

		sort.SliceStable(voos, func(i, j int) bool {
			return voos[j][0] > voos[i][0]
		})

		for i := n1-1; i > 0; i-- {
			if voos[i][0] == voos [i-1][0] {
				q++
			} else {
				break
			}}

		fmt.Fprintf(output, "Teste %d\n", teste)

		for i := n1-q; i < n1; i++ {
			fmt.Fprintf(output, "%d ", voos[i][1])
		}
		
		fmt.Fprintf(output, "\n\n")
		
	}
}