package main

import (
	"fmt"
	"math"
	"os"
)

func main() {
	input, err := os.Open("dobra.in")
	if err != nil {
		panic(err)
	}
	defer input.Close()

	output, err := os.Create("dobra.out")
	if err != nil {
		panic(err)
	}
	defer output.Close()

	var n int
	teste := 1

	for {
		fmt.Fscanf(input, "%d", &n)
		if n == -1 {
			break
		}

		pedacos := int(math.Pow(float64(math.Pow(2, float64(n))+1), 2))
		

		fmt.Fprintf(output, "Teste %d\n%d\n\n", teste, pedacos)
		teste++
	}
}
