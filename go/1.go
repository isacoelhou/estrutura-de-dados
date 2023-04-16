package main

import (
	"fmt"
	"os"
)

var (
	n, fst, teste, val int
	s rune
)

func main() {
	input, err := os.Open("calcula.in")
	if err != nil {
		panic(err)
	}

	defer input.Close()

	output, err := os.Create("calcula.out")
	if err != nil {
		panic(err)
	}

	defer output.Close()

	for {
		fmt.Fscanf(input, "%d\n", &n)
		if n == 0 {
			break
		}

		fmt.Fscanf(input, "%d%c", &fst, &s)
		for i := 1; i < n; i++ {
			aux := s
			fmt.Fscanf(input, "%d%c", &val, &s)
			switch aux {
			case '+':
				fst += val
			case '-':
				fst -= val
			case '\n':
				i = n
			}
		}
		teste++
		fmt.Fprintf(output, "Teste %d\n%d\n\n", teste, fst)
		
	}
}