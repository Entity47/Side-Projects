package calculator

import (
    "testing"
    "../calculator"
)

func TestBasicAddition(t *testing.T) {
    result := calculator.Calculate("1+2")
    if result != "3" {
        t.Error("Expected 3, got ", result)
    }
}
