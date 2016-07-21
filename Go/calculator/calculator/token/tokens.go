package tokens

type Token interface {
    toString() string
}

type IntegerToken struct {
    num int
}

func (t IntegerToken) toString() string {
    return "INTEGER_TOKEN()"
}

const (
    ADDITION = iota
)

type OperatorToken struct {
    operator int
}

func (t OperatorToken) toString() string {
    return "ADDITION_TOKEN(+)"
}

func Tokenize(input string) []Token {
    token1 := IntegerToken{1}
    token2 := OperatorToken{ADDITION}
    token3 := IntegerToken{1}
    return []Token{token1, token2, token3}
}
