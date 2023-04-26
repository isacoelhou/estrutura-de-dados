package main

import (
	"fmt"
	"os"
)

func main() {
	input, err := os.Open("tesouro.in")
	if err != nil {
		panic(err)
	}

	defer input.Close()

	output, err := os.Create("tesouro.out")
	if err != nil {
		panic(err)
	}

	defer output.Close()

	var (
		v1, v2, tot, sum int32
		aux                int32 = 1
	)

	for {
		fmt.Fscan(input, &v1, &v2, &tot)

		if v1 == 0 && v2 == 0 && tot == 0 {
			return
		}

		sum = v1 + v2
		tesouros := make([]int32, tot)

		for i := 0; int32(i) < tot; i++ {
			fmt.Fscan(input, &tesouros[i])
			sum += tesouros[i]
		}

		fmt.Fprintf(output, "Teste %d\n", aux)
		aux++

		if sum%2 != 0 {
			fmt.Fprintf(output, "N\n\n")
		} else {
			var div bool = false
			m := 1 << uint(tot)
			tes2 := make([][]int32, m)

			for i := range tes2 {
				tes2[i] = make([]int32, tot)
				for j := 0; int32(j) < tot; j++ {
					tes2[i][j] = int32((i >> uint(j)) & 1)
				}
			}

			var parcial int32 = v1
			var parcial2 int32 = v2

			for i := range tes2 {
				for j := 0; int32(j) < tot; j++ {
					if tes2[i][j] == 0 {
						parcial += tesouros[j]
					} else {
						parcial2 += tesouros[j]
					}
				}
				if parcial == parcial2 {
					div = true
				}
				parcial = v1
				parcial2 = v2
			}

			if div {
				fmt.Fprintf(output, "S\n\n")
			} else {
				fmt.Fprintf(output, "N\n\n")
			}
		}
	}
}
