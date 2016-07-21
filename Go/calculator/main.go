package main

import (
    "fmt"
    "os"
    "./calculator"
)

func main() {
    size := len(os.Args)
    if size <= 1 {
        fmt.Println("Please enter a quoted expression to calculate");
        os.Exit(1);
    } else {
        input := os.Args[1]
        result := calculator.Calculate(input)
        fmt.Println(result);
        os.Exit(0);
    }
}
