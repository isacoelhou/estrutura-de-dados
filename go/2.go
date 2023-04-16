package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {

	input, err := os.Open("lua.in")
	if err != nil {
		panic(err)
	}
	defer input.Close()

	output, err := os.Create("lua.out")
	if err != nil {
		panic(err)
	}
	defer output.Close()

	scanner := bufio.NewScanner(input)
	var n, m int
	teste := 0
	for {
		teste++
		if !scanner.Scan() {
			break
		}
		fmt.Sscanf(scanner.Text(), "%d %d", &n, &m)
		if n == 0 && m == 0 {
			break
		}
		temperaturas := make([]int, n)
		for i := 0; i < n; i++ {
			scanner.Scan()
			fmt.Sscan(scanner.Text(), &temperaturas[i])
		}
		menor, maior := calcularTemperaturaMedia(temperaturas, m)
		fmt.Fprintf(output, "Teste %d\n", teste)
		fmt.Fprintf(output, "%d %d\n\n", menor, maior)
	}
}

func calcularTemperaturaMedia(temperaturas []int, m int) (int, int) {
	menorMedia := 200 * m
	maiorMedia := -200 * m
	soma := 0
	for i := 0; i < m; i++ {
		soma += temperaturas[i]
	}
	for i := m; i <= len(temperaturas); i++ {
		media := soma / m
		if media < menorMedia {
			menorMedia = media
		}
		if media > maiorMedia {
			maiorMedia = media
		}
		if i < len(temperaturas) {
			soma += temperaturas[i] - temperaturas[i-m]
		}
	}
	return menorMedia, maiorMedia
}
