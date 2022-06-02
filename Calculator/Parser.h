#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stack>

class UnexpectedSymbolError
{
private:
	std::string message;
	int code;
public:
	UnexpectedSymbolError()
	{
		code = 1;
		message = "Error: unexpected symbol. Error code: " + std::to_string(code) + ".";
	}
	UnexpectedSymbolError(const int& index)
	{
		code = 1;
		message = "Error: unexpected symbol at index " + std::to_string(index) + ". Error code: " + std::to_string(code) + ".";
	}
	void print_error()
	{
		std::cout << message;
	}
};

#define PI 3.141593
#define ex exp(1)

typedef unsigned int uint;

enum LexemeType
{
	LeftBracket = 0, 
	RightBracket,
	Plus,
	Minus, UnaryMinus,
	Multiply,
	Division,
	Number,
	Sinus, 
	Cosin,
	Tang,
	Ctan,
	Sqrt,
	Power,
	Pi,
	Exp,
	Ln,
	Abs
};

class Lexeme
{
public:
	LexemeType type;
	std::string value;

	Lexeme(const LexemeType& type, const std::string& value)
	{
		this->type = type;
		this->value = value;
	}
	Lexeme(const LexemeType& type, const char& value)
	{
		this->type = type;
		this->value = std::to_string(value);
	}
};

std::vector<Lexeme> parse_to_lexems(const std::string& expression)
{
	std::vector<Lexeme> Lexemes;
	int i = 0;
	int BracketCount = 0;
	while (i < expression.size())
	{
		if (expression[i] == '(') { Lexemes.push_back(Lexeme(LeftBracket, "(")); ++i; ++BracketCount; }
		else if (expression[i] == ')') { Lexemes.push_back(Lexeme(RightBracket, ")")); ++i; --BracketCount; }
		else if (expression[i] == '+') { Lexemes.push_back(Lexeme(Plus, "+")); ++i; }
		else if (expression[i] == '-') { Lexemes.push_back(Lexeme(Minus, "-")); ++i; }
		else if (expression[i] == '/' || expression[i] == ':') { Lexemes.push_back(Lexeme(Division, "/")); ++i; }
		else if (expression[i] == '*') { Lexemes.push_back(Lexeme(Multiply, "*")); ++i; }
		else if (expression[i] == '^') { Lexemes.push_back(Lexeme(Power, "^")); ++i; }
		else if (expression[i] >= '0' && expression[i] <= '9')
		{
			std::string number = "";
			bool Continue = true;
			bool point = false;
			do
			{
				if (expression[i] == '.')
				{
					if (!point)
					{
						number += expression[i];
						point = true;
					}
					else throw UnexpectedSymbolError();
				}
				else number += expression[i];
				
				++i;
				Continue = i < expression.size();
				if (Continue) Continue = expression[i] >= '0' && expression[i] <= '9' || expression[i] == '.';
			} while (Continue);

			if (number[number.size() - 1] == '.') throw UnexpectedSymbolError();
			else if (number[0] == '0')
			{
				if (number.size() >= 2)
				{
					if (number[1] != '.') throw UnexpectedSymbolError();
					else Lexemes.push_back(Lexeme(Number, number));
				}
				else Lexemes.push_back(Lexeme(Number, number));
			}
			else Lexemes.push_back(Lexeme(Number, number));
		}

		else if (i + 3 < expression.size())
		{
			if (expression.substr(i, 4) == "sqrt") { Lexemes.push_back(Lexeme(Sqrt, "sqrt")); i += 4; }
			else if (expression.substr(i, 3) == "sin") { Lexemes.push_back(Lexeme(Sinus, "sin")); i += 3; }
			else if (expression.substr(i, 3) == "cos") { Lexemes.push_back(Lexeme(Cosin, "cos")); i += 3; }
			else if (expression.substr(i, 3) == "ctg") { Lexemes.push_back(Lexeme(Ctan, "ctg")); i += 3; }
			else if (expression.substr(i, 3) == "abs") { Lexemes.push_back(Lexeme(Abs, "abs")); i += 3; }
			else if (expression.substr(i, 2) == "tg") { Lexemes.push_back(Lexeme(Tang, "tg")); i += 2; }
			else if (expression.substr(i, 2) == "ln") { Lexemes.push_back(Lexeme(Ln, "ln")); i += 2; }
			else if (expression.substr(i, 2) == "pi") { Lexemes.push_back(Lexeme(Number, std::to_string(PI))); i += 2; }
			else if (expression[i] == 'e') { Lexemes.push_back(Lexeme(Number, std::to_string(ex))); ++i; }
			else if (expression[i] == ' ') ++i;
			else if (expression[i] == '.') throw UnexpectedSymbolError();
			else throw UnexpectedSymbolError();
		}

		else if (i + 2 < expression.size())
		{
			if (expression.substr(i, 3) == "sin") { Lexemes.push_back(Lexeme(Sinus, "sin")); i += 3;}
			else if (expression.substr(i, 3) == "cos") { Lexemes.push_back(Lexeme(Cosin, "cos")); i += 3; }
			else if (expression.substr(i, 3) == "ctg") { Lexemes.push_back(Lexeme(Ctan, "ctg")); i += 3; }
			else if (expression.substr(i, 3) == "abs") { Lexemes.push_back(Lexeme(Abs, "abs")); i += 3; }
			else if (expression.substr(i, 2) == "tg") { Lexemes.push_back(Lexeme(Tang, "tg")); i += 2; }
			else if (expression.substr(i, 2) == "ln") { Lexemes.push_back(Lexeme(Ln, "ln")); i += 2; }
			else if (expression.substr(i, 2) == "pi") { Lexemes.push_back(Lexeme(Number, std::to_string(PI))); i += 2; }
			else if (expression[i] == 'e') { Lexemes.push_back(Lexeme(Number, std::to_string(ex))); ++i; }
			else if (expression[i] == ' ') ++i;
			else if (expression[i] == '.') throw UnexpectedSymbolError();
			else throw UnexpectedSymbolError();
		}
	
		else if (i + 1 < expression.size())
		{
			if (expression.substr(i, 2) == "tg") { Lexemes.push_back(Lexeme(Tang, "tg")); i += 2; }
			else if (expression.substr(i, 2) == "ln") { Lexemes.push_back(Lexeme(Ln, "ln")); i += 2; }
			else if (expression.substr(i, 2) == "pi") { Lexemes.push_back(Lexeme(Number, std::to_string(PI))); i += 2; }
			else if (expression[i] == 'e') { Lexemes.push_back(Lexeme(Number, std::to_string(ex))); ++i; }
			else if (expression[i] == ' ') ++i;
			else if (expression[i] == '.') throw UnexpectedSymbolError();
			else throw UnexpectedSymbolError();
		}

		else if (expression[i] == 'e') { Lexemes.push_back(Lexeme(Number, std::to_string(ex))); ++i; }
		else if (expression[i] == ' ') ++i;
		else if (expression[i] == '.') throw UnexpectedSymbolError();
		else throw UnexpectedSymbolError();
	}

	if (BracketCount != 0) throw UnexpectedSymbolError();
	else
	{
		if (Lexemes.size() > 0)
		{
			if (Lexemes[0].type == Plus || Lexemes[0].type == Multiply || Lexemes[0].type == Division || Lexemes[0].type == RightBracket || Lexemes[Lexemes.size() - 1].type == Plus || Lexemes[Lexemes.size() - 1].type == Minus || Lexemes[Lexemes.size() - 1].type == Multiply || Lexemes[Lexemes.size() - 1].type == Division || Lexemes[Lexemes.size() - 1].type == Abs || Lexemes[Lexemes.size() - 1].type == Power || Lexemes[Lexemes.size() - 1].type == Sinus || Lexemes[Lexemes.size() - 1].type == Cosin || Lexemes[Lexemes.size() - 1].type == Tang || Lexemes[Lexemes.size() - 1].type == Ctan || Lexemes[Lexemes.size() - 1].type == Ln || Lexemes[Lexemes.size() - 1].type == LeftBracket)
				throw UnexpectedSymbolError();
			for (int i = 1; i < Lexemes.size(); i++)
			{
				switch (Lexemes[i].type)
				{
				case Plus:
				case Multiply:
				case Division:
				case Power:
				{
					if (Lexemes[i - 1].type == LeftBracket || Lexemes[i - 1].type == Plus || Lexemes[i - 1].type == Minus || Lexemes[i - 1].type == Multiply || Lexemes[i - 1].type == Division || Lexemes[i - 1].type == Power)
						throw UnexpectedSymbolError();
					break;
				}
				case Minus:
				{
					if (Lexemes[i - 1].type == Plus || Lexemes[i - 1].type == Minus || Lexemes[i - 1].type == Multiply || Lexemes[i - 1].type == Division || Lexemes[i - 1].type == Power)
						throw UnexpectedSymbolError();
					break;
				}
				case LeftBracket:
				{
					if (Lexemes[i - 1].type == Number || Lexemes[i - 1].type == RightBracket)
					{
						std::vector<Lexeme>::iterator it = Lexemes.begin() + i;
						Lexemes.insert(it, Lexeme(Multiply, "*"));
					}
					break;
				}
				case Number:
				{
					if (Lexemes[i].value == std::to_string(PI) || Lexemes[i].value == std::to_string(ex))
					{
						if (Lexemes[i - 1].type == Number)
						{
							std::vector<Lexeme>::iterator it = Lexemes.begin() + i;
							Lexemes.insert(it, Lexeme(Multiply, "*"));
						}
					}
					else if (Lexemes[i - 1].value == std::to_string(PI) || Lexemes[i - 1].value == std::to_string(ex) || Lexemes[i - 1].type == RightBracket)
						throw UnexpectedSymbolError();
					break;
				}
				case Abs:
				case Sinus:
				case Cosin:
				case Tang:
				case Ctan:
				case Sqrt:
				case Ln:
				{
					if (Lexemes[i - 1].type == Number || Lexemes[i - 1].type == RightBracket)
					{
						std::vector<Lexeme>::iterator it = Lexemes.begin() + i;
						Lexemes.insert(it, Lexeme(Multiply, "*"));
					}
					break;
				}
				case RightBracket:
				{
					if (Lexemes[i - 1].type == LeftBracket || Lexemes[i - 1].type == Plus || Lexemes[i - 1].type == Minus || Lexemes[i - 1].type == Multiply || Lexemes[i - 1].type == Division || Lexemes[i - 1].type == Power)
						throw UnexpectedSymbolError();
					break;
				}
				}
			}
		}
	}
	return Lexemes;
}

void absolute(std::stack<double>& numbers, std::stack<Lexeme>& operations)
{
	double operand = numbers.top();
	numbers.pop();
	numbers.push(abs(operand));
	operations.pop();
}

void nlog(std::stack<double>& numbers, std::stack<Lexeme>& operations)
{
	double operand = numbers.top();
	numbers.pop();
	if (operand <= 0) throw UnexpectedSymbolError();
	numbers.push(log(operand));
	operations.pop();
}

void square_root(std::stack<double>& numbers, std::stack<Lexeme>& operations)
{
	double operand = numbers.top();
	numbers.pop();
	numbers.push(sqrt(operand));
	operations.pop();
}

void sinus(std::stack<double>& numbers, std::stack<Lexeme>& operations)
{
	double operand = numbers.top();
	numbers.pop();
	if (round(operand / PI) == operand / PI)
		numbers.push(0);
	else
		numbers.push(sin(operand));
	operations.pop();
}

void cosinus(std::stack<double>& numbers, std::stack<Lexeme>& operations)
{
	double operand = numbers.top();
	numbers.pop();
	std::cout << round((operand - PI / 2) / PI) << "   " << (operand - PI / 2) / PI << std::endl;
	if (operand == 3 * PI / 2)//костыль
		numbers.push(0);
	else if (round((operand - PI / 2) / PI) == (operand - PI / 2) / PI)
		numbers.push(0);
	else
		numbers.push(cos(operand));
	operations.pop();
}

void tangens(std::stack<double>& numbers, std::stack<Lexeme>& operations)
{
	double operand = numbers.top();
	numbers.pop();
	if (operand == 3 * PI / 2)//костыль
		throw UnexpectedSymbolError();
	else if (round((operand - PI / 2) / PI) == (operand - PI / 2) / PI)
		throw UnexpectedSymbolError();
	else
		numbers.push(tan(operand));
	operations.pop();
}

void cotangens(std::stack<double>& numbers, std::stack<Lexeme>& operations)
{
	double operand = numbers.top();
	numbers.pop();
	if (round(operand / PI) == operand / PI)
		throw UnexpectedSymbolError();
	else
		numbers.push(cos(operand) / sin(operand));
	operations.pop();
}

void power(std::stack<double>& numbers, std::stack<Lexeme>& operations)
{
	double operandR = numbers.top();
	numbers.pop();
	double operandL = numbers.top();
	numbers.pop();
	numbers.push(pow(operandL, operandR));
	operations.pop();
}

void multiply(std::stack<double>& numbers, std::stack<Lexeme>& operations)
{
	double operandR = numbers.top();
	numbers.pop();
	double operandL = numbers.top();
	numbers.pop();
	numbers.push(operandL * operandR);
	operations.pop();
}

void division(std::stack<double>& numbers, std::stack<Lexeme>& operations)
{
	double operandR = numbers.top();
	numbers.pop();
	if (operandR == 0) throw UnexpectedSymbolError();
	double operandL = numbers.top();
	numbers.pop();
	numbers.push(operandL / operandR);
	operations.pop();
}

void pluss(std::stack<double>& numbers, std::stack<Lexeme>& operations)
{
	double operandR = numbers.top();
	numbers.pop();
	double operandL = numbers.top();
	numbers.pop();
	numbers.push(operandL + operandR);
	operations.pop();
}

void binary_minuss(std::stack<double>& numbers, std::stack<Lexeme>& operations)
{
	double operandR = numbers.top();
	numbers.pop();
	double operandL = numbers.top();
	numbers.pop();
	numbers.push(operandL - operandR);
	operations.pop();
}

void odinary_minuss(std::stack<double>& numbers, std::stack<Lexeme>& operations)
{
	double operand = numbers.top();
	numbers.pop();
	numbers.push(-operand);
	operations.pop();
}

/// <summary>
/// priorty:
/// sqrt, sin, cos, tg, ctg, ln, odinary -
/// power
/// *, /
/// +, -
/// </summary>
/// <param name="expression"></param>
/// <returns></returns>

double foo(const std::string& expression)
//алгоритм вычислений через два стека - с числами и операциями, 
//которые наполняются и обрабатывваются по мере чтения лексем(токенов)
{
	std::vector<Lexeme> token = parse_to_lexems(expression);
	std::stack<double> numbers;
	std::stack<Lexeme> operations;
	int i = 0;
	while (i < token.size())
	{
		if (token[i].type == Number)
		{
			numbers.push(std::stod(token[i].value));
			++i;
		}

		else if (token[i].type == LeftBracket)
		{
			operations.push(token[i]);
			++i;
		}

		else if (token[i].type == Plus || token[i].type == Minus)
		{
			if (operations.size() > 0)
			{
				if (token[i].type == Minus && (token[i - 1].type == LeftBracket || token[i - 1].type == Abs || token[i - 1].type == Ln || token[i - 1].type == Sinus || token[i - 1].type == Cosin || token[i - 1].type == Tang || token[i - 1].type == Ctan || token[i - 1].type == Sqrt || token[i - 1].type == Power))
				{
					token[i].type = UnaryMinus;
					operations.push(token[i]);
					++i;
				}
				else
				{
					switch (operations.top().type)
					{
					case UnaryMinus:
					{
						odinary_minuss(numbers, operations);
						break;
					}
					case Abs:
					{
						absolute(numbers, operations);
						break;
					}
					case Ln:
					{
						nlog(numbers, operations);
						break;
					}
					case Sqrt:
					{
						square_root(numbers, operations);
						break;
					}
					case Sinus:
					{
						sinus(numbers, operations);
						break;
					}
					case Cosin:
					{
						cosinus(numbers, operations);
						break;
					}
					case Tang:
					{
						tangens(numbers, operations);
						break;
					}
					case Ctan:
					{
						cotangens(numbers, operations);
						break;
					}
					case Power:
					{
						power(numbers, operations);
						break;
					}
					case Multiply:
					{
						multiply(numbers, operations);
						break;
					}
					case Division:
					{
						division(numbers, operations);
						break;
					}
					case Plus:
					{
						pluss(numbers, operations);
						break;
					}
					case Minus:
					{
						binary_minuss(numbers, operations);
						break;
					}
					case LeftBracket:
					{
						operations.push(token[i]);
						++i;
						break;
					}
					}
				}
			}
			else
			{
				if (token[i].type == Minus && numbers.size() == 0) token[i].type = UnaryMinus;
				operations.push(token[i]);
				++i;
			}
		}

		else if (token[i].type == Multiply || token[i].type == Division)
		{
			if (operations.size() > 0)
			{
				switch (operations.top().type)
				{
				case UnaryMinus:
				{
					odinary_minuss(numbers, operations);
					break;
				}
				case Abs:
				{
					absolute(numbers, operations);
					break;
				}
				case Ln:
				{
					nlog(numbers, operations);
					break;
				}
				case Sqrt:
				{
					square_root(numbers, operations);
					break;
				}
				case Sinus:
				{
					sinus(numbers, operations);
					break;
				}
				case Cosin:
				{
					cosinus(numbers, operations);
					break;
				}
				case Tang:
				{
					tangens(numbers, operations);
					break;
				}
				case Ctan:
				{
					cotangens(numbers, operations);
					break;
				}
				case Power:
				{
					power(numbers, operations);
					break;
				}
				case Multiply:
				{
					multiply(numbers, operations);
					break;
				}
				case Division:
				{
					division(numbers, operations);
					break;
				}
				case Plus:
				case Minus:
				case LeftBracket:
				{
					operations.push(token[i]);
					++i;
					break;
				}
				}
			}
			else
			{
				operations.push(token[i]);
				++i;
			}
		}

		else if (token[i].type == Power)
		{
			if (operations.size() > 0)
			{
				switch (operations.top().type)
				{
				case UnaryMinus:
				{
					odinary_minuss(numbers, operations);
					break;
				}
				case Abs:
				{
					absolute(numbers, operations);
					break;
				}
				case Ln:
				{
					nlog(numbers, operations);
					break;
				}
				case Sqrt:
				{
					square_root(numbers, operations);
					break;
				}
				case Sinus:
				{
					sinus(numbers, operations);
					break;
				}
				case Cosin:
				{
					cosinus(numbers, operations);
					break;
				}
				case Tang:
				{
					tangens(numbers, operations);
					break;
				}
				case Ctan:
				{
					cotangens(numbers, operations);
					break;
				}
				case Power:
				{
					power(numbers, operations);
					break;
				}
				case Multiply:
				case Division:
				case Plus:
				case Minus:
				case LeftBracket:
				{
					operations.push(token[i]);
					++i;
					break;
				}
				}
			}
			else
			{
				operations.push(token[i]);
				++i;
			}
		}

		else if (token[i].type == Sqrt || token[i].type == Sinus || token[i].type == Cosin || token[i].type == Tang || token[i].type == Ctan || token[i].type == Ln || token[i].type == Abs || token[i].type == UnaryMinus)
		{
			if (operations.size() > 0)
			{
				switch (operations.top().type)
				{
				case UnaryMinus:
				{
					odinary_minuss(numbers, operations);
					break;
				}
				case Abs:
				case Ln:
				case Sqrt:
				case Sinus:
				case Cosin:
				case Tang:
				case Ctan:
				case Power:
				case Multiply:
				case Division:
				case Plus:
				case Minus:
				case LeftBracket:
				{
					operations.push(token[i]);
					++i;
					break;
				}
				}
			}
			else
			{
				operations.push(token[i]);
				++i;
			}
		}

		else if (token[i].type == RightBracket)
		{
			while (operations.top().type != LeftBracket)
			{
				switch (operations.top().type)
				{
				case UnaryMinus:
				{
					odinary_minuss(numbers, operations);
					break;
				}
				case Abs:
				{
					absolute(numbers, operations);
					break;
				}
                case Ln:
				{
					nlog(numbers, operations);
					break;
				}
				case Sqrt:
				{
					square_root(numbers, operations);
					break;
				}
				case Sinus:
				{
					sinus(numbers, operations);
					break;
				}
				case Cosin:
				{
					cosinus(numbers, operations);
					break;
				}
				case Tang:
				{
					tangens(numbers, operations);
					break;
				}
				case Ctan:
				{
					cotangens(numbers, operations);
					break;
				}
				case Power:
				{
					power(numbers, operations);
					break;
				}
				case Multiply:
				{
					multiply(numbers, operations);
					break;
				}
				case Division:
				{
					division(numbers, operations);
					break;
				}
				case Plus:
				{
					pluss(numbers, operations);
					break;
				}
				case Minus:
				{
					binary_minuss(numbers, operations);
					break;
				}
				}
			}
			operations.pop();
			++i;
		}
	}

	while (operations.size() > 0)
	{
		switch (operations.top().type)
		{
		case UnaryMinus:
		{
			odinary_minuss(numbers, operations);
			break;
		}
		case Abs:
		{
			absolute(numbers, operations);
			break;
		}
		case Ln:
		{
			nlog(numbers, operations);
			break;
		}
		case Sqrt:
		{
			square_root(numbers, operations);
			break;
		}
		case Sinus:
		{
			sinus(numbers, operations);
			break;
		}
		case Cosin:
		{
			cosinus(numbers, operations);
			break;
		}
		case Tang:
		{
			tangens(numbers, operations);
			break;
		}
		case Ctan:
		{
			cotangens(numbers, operations);
			break;
		}
		case Power:
		{
			power(numbers, operations);
			break;
		}
		case Multiply:
		{
			multiply(numbers, operations);
			break;
		}
		case Division:
		{
			division(numbers, operations);
			break;
		}
		case Plus:
		{
			pluss(numbers, operations);
			break;
		}
		case Minus:
		{
			binary_minuss(numbers, operations);
			break;
		}
		}
	}

	if (numbers.size() > 0)
	{
		return numbers.top();
	}
	else throw UnexpectedSymbolError();
}