package tokens

import (
    "testing"
    "../token"
)

func TestTokenize(t *testing.T) {
    tokens := tokens.Tokenize("1+2")
    if len(tokens) != 3 {
        t.Error("Incorrect number of tokens");
    }
}
