#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stack>

class UnexpectedSymbolError
{
private:
	std::string message;
	int index;
public:
	UnexpectedSymbolError(const std::string& message, const int& index = -1)
	{
		this->message = message;
		this->index = index;
		if (index != -1)
		{
			this->message += std::to_string(index);
		}
	}
	std::string get_message()
	{
		return message;
	}
	int get_index()
	{
		return index;
	}
};

#define PI 3.141593
#define ex exp(1)
int multiply_count = 0;

enum LexemeType
{
	LeftBracket = 0, 
	RightBracket,
	Plus,
	Minus, 
	UnaryMinus,
	Multiply,
	Division,
	Power,
	Sinus, 
	Cosin,
	Tang,
	Ctan,
	Sqrt,
	Ln,
	Abs,
	Number,
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

bool checkBinaryOperation(const std::vector<Lexeme>& Lexemes, const std::string expression, const int& index)
{
	if (expression[index] != '-')
	{
		if (Lexemes.size() == 0)
			throw UnexpectedSymbolError("Ожидалось выражение.\nОшибка перед словом № ", 1);
		else if (Lexemes.back().type != Number && Lexemes.back().type != RightBracket)
			throw UnexpectedSymbolError("Операция не ожидалась.\nОшибка в слове № ", Lexemes.size() - multiply_count + 1);
		return false;
	}
	else
	{
		if (Lexemes.size() == 0)
			return true;
		else
		{
			switch (Lexemes.back().type)
			{
			case Plus:
			case Minus:
			case UnaryMinus:
			case Multiply:
			case Division:
			case Power:
				throw UnexpectedSymbolError("Операция не ожидалась.\nОшибка в слове № ", Lexemes.size() - multiply_count + 1);
			case LeftBracket:
			case Sinus:
			case Cosin:
			case Tang:
			case Ctan:
			case Sqrt:
			case Ln:
			case Abs:
				return true;
			default:
				return false;
			}
		}
	}
}

void checkRightBracket(const std::vector<Lexeme>& Lexemes)
{
	if (Lexemes.size() == 0) throw UnexpectedSymbolError("Ожидалась открывающая скобка перед словом № ", 1);
	else if (Lexemes.back().type != Number && Lexemes.back().type != RightBracket)
	{
		throw UnexpectedSymbolError("Ожидалось выражение перед закрывающей скобкой. Слово № ", Lexemes.size() - multiply_count + 1);
	}
}

void checkLeftBracket(std::vector<Lexeme>& Lexemes, const std::string& expression, const int& index)
{
	if (Lexemes.size() > 0)
	{
		if (Lexemes.back().type == Number || Lexemes.back().type == RightBracket)
		{
			if (index - 1 >= 0)
			{
				if (expression[index - 1] == ' ')
					throw UnexpectedSymbolError("Ожидалась операция перед открывающей скобкой. Слово № ", Lexemes.size() - multiply_count + 1);
			}
			Lexemes.push_back(Lexeme(Multiply, ""));
			multiply_count++;
		}
	}
}

void check_UnaryOperation_Const(std::vector<Lexeme>& Lexemes, const std::string& expression, const int& index)
{
	if (Lexemes.size() > 0)
	{
		if (Lexemes.back().type == Number || Lexemes.back().type == RightBracket)
		{
			if (index - 1 >= 0)
			{
				if (expression[index - 1] == ' ')
					throw UnexpectedSymbolError("Ожидалась операция перед словом № ", Lexemes.size() - multiply_count + 1);
			}
			if (Lexemes.back().value == std::to_string(PI) || Lexemes.back().value == std::to_string(ex))
				throw UnexpectedSymbolError("Ожидалась операция после константы № ", Lexemes.size() - multiply_count);
			Lexemes.push_back(Lexeme(Multiply, ""));
			multiply_count++;
		}
	}
}

void checkNumber(const std::vector<Lexeme>& Lexemes)
{
	if (Lexemes.size() > 0)
	{
		if (Lexemes.back().type == Number)
			throw UnexpectedSymbolError("Между числами ожидалась операция. Перед словом № ", Lexemes.size() - multiply_count + 1);
		else if (Lexemes.back().type == RightBracket)
			throw UnexpectedSymbolError("Ожидалась операция перед словом № ", Lexemes.size() - multiply_count + 1);
	}
}

std::vector<Lexeme> parse_to_lexems(std::string& expression)
{
	std::vector<Lexeme> Lexemes;
	int i = 0;
	int BracketCount = 0;
	while (i < expression.size())
	{
		if (expression[i] == '(')
		{ 
			checkLeftBracket(Lexemes, expression, i);
			Lexemes.push_back(Lexeme(LeftBracket, "("));
			++i;
			++BracketCount;
		}
		else if (expression[i] == ')') 
		{
			checkRightBracket(Lexemes);
			Lexemes.push_back(Lexeme(RightBracket, ")")); 
			++i;
			--BracketCount;
			if (BracketCount < 0)
				throw UnexpectedSymbolError("Ожидалась открывающая скобка перед словом № ", Lexemes.size() - multiply_count + 1);
		}
		else if (expression[i] == '+') 
		{ 
			checkBinaryOperation(Lexemes, expression, i);
			Lexemes.push_back(Lexeme(Plus, "+"));
			++i;
		}
		else if (expression[i] == '-') 
		{ 
			if (checkBinaryOperation(Lexemes, expression, i))
			  Lexemes.push_back(Lexeme(UnaryMinus, "-")); 
			else
			  Lexemes.push_back(Lexeme(Minus, "-"));
			++i; 
		}
		else if (expression[i] == '/' || expression[i] == ':')
		{
			checkBinaryOperation(Lexemes, expression, i);
			Lexemes.push_back(Lexeme(Division, "/"));
			++i; 
		}
		else if (expression[i] == '*')
		{
			checkBinaryOperation(Lexemes, expression, i);
			Lexemes.push_back(Lexeme(Multiply, "*")); 
			++i;
		}
		else if (expression[i] == '^')
		{
			checkBinaryOperation(Lexemes, expression, i);
			Lexemes.push_back(Lexeme(Power, "^"));
			++i;
		}
		else if (expression[i] >= '0' && expression[i] <= '9' || expression[i] == '.')
		{
			std::string number = "";
			bool Continue = true;
			bool point = false;

			if (expression[i] == '.')
			{
				if (i + 1 < expression.size())
				{
					if (expression[i + 1] < '0' || expression[i + 1] > '9') throw UnexpectedSymbolError("Разделитель вне числа. Слово № ", Lexemes.size() - multiply_count + 1);
					else
					{
						number += "0.";
						expression.insert(i, "0");
						i += 2;
						point = true;
					}
				}
				else throw UnexpectedSymbolError("Разделитель вне числа. Слово № ", Lexemes.size() - multiply_count + 1);
			}

			do
			{
				if (expression[i] == '.')
				{
					if (!point)
					{
						number += expression[i];
						point = true;
					}
					else throw UnexpectedSymbolError("Более одного разделителя в числе. Слово № ", Lexemes.size() - multiply_count + 1);
				}
				else number += expression[i];
				
				++i;
				Continue = i < expression.size();
				if (Continue) Continue = expression[i] >= '0' && expression[i] <= '9' || expression[i] == '.';
			} while (Continue);

			if (number[number.size() - 1] == '.')
			{
				number += "0";
				expression.insert(i, "0");
				++i;
				checkNumber(Lexemes);
				Lexemes.push_back(Lexeme(Number, number));
			}
			else if (number[0] == '0')
			{
				if (number.size() >= 2)
				{
					if (number[1] != '.') throw UnexpectedSymbolError("Число не может начинаться с 0. Слово № ", Lexemes.size() - multiply_count + 1);
					else
					{
						checkNumber(Lexemes);
						Lexemes.push_back(Lexeme(Number, number));
					}
				}
				else
				{
					checkNumber(Lexemes);
					Lexemes.push_back(Lexeme(Number, number));
				}
			}
			else
			{
				checkNumber(Lexemes);
				Lexemes.push_back(Lexeme(Number, number));
			}
		}

		else if (i + 3 < expression.size())
		{
			if (expression.substr(i, 4) == "sqrt") 
			{
				check_UnaryOperation_Const(Lexemes, expression, i);
				Lexemes.push_back(Lexeme(Sqrt, "sqrt"));
				i += 4;
			}
			else if (expression.substr(i, 3) == "sin")
			{
				check_UnaryOperation_Const(Lexemes, expression, i);
				Lexemes.push_back(Lexeme(Sinus, "sin")); 
				i += 3;
			}
			else if (expression.substr(i, 3) == "cos")
			{
				check_UnaryOperation_Const(Lexemes, expression, i);
				Lexemes.push_back(Lexeme(Cosin, "cos"));
				i += 3;
			}
			else if (expression.substr(i, 3) == "ctg")
			{
				check_UnaryOperation_Const(Lexemes, expression, i);
				Lexemes.push_back(Lexeme(Ctan, "ctg")); 
				i += 3;
			}
			else if (expression.substr(i, 3) == "abs") 
			{
				check_UnaryOperation_Const(Lexemes, expression, i);
				Lexemes.push_back(Lexeme(Abs, "abs")); 
				i += 3;
			}
			else if (expression.substr(i, 2) == "tg") 
			{
				check_UnaryOperation_Const(Lexemes, expression, i);
				Lexemes.push_back(Lexeme(Tang, "tg"));
				i += 2; 
			}
			else if (expression.substr(i, 2) == "ln") 
			{
				check_UnaryOperation_Const(Lexemes, expression, i); 
				Lexemes.push_back(Lexeme(Ln, "ln"));
				i += 2;
			}
			else if (expression.substr(i, 2) == "pi")
			{
				check_UnaryOperation_Const(Lexemes, expression, i);
				Lexemes.push_back(Lexeme(Number, std::to_string(PI)));
				i += 2;
			}
			else if (expression[i] == 'e')
			{
				check_UnaryOperation_Const(Lexemes, expression, i);
				Lexemes.push_back(Lexeme(Number, std::to_string(ex)));
				++i;
			}
			else if (expression[i] == ' ') ++i;
			else throw UnexpectedSymbolError("Недопустимый символ. Слово № ", Lexemes.size() - multiply_count + 1);
		}

		else if (i + 2 < expression.size())
		{
			if (expression.substr(i, 3) == "sin")
			{
				check_UnaryOperation_Const(Lexemes, expression, i);
				Lexemes.push_back(Lexeme(Sinus, "sin")); 
				i += 3;
			}
			else if (expression.substr(i, 3) == "cos")
			{
				check_UnaryOperation_Const(Lexemes, expression, i);
				Lexemes.push_back(Lexeme(Cosin, "cos"));
				i += 3;
			}
			else if (expression.substr(i, 3) == "ctg")
			{
				check_UnaryOperation_Const(Lexemes, expression, i);
				Lexemes.push_back(Lexeme(Ctan, "ctg")); 
				i += 3;
			}
			else if (expression.substr(i, 3) == "abs") 
			{
				check_UnaryOperation_Const(Lexemes, expression, i);
				Lexemes.push_back(Lexeme(Abs, "abs")); 
				i += 3;
			}
			else if (expression.substr(i, 2) == "tg") 
			{
				check_UnaryOperation_Const(Lexemes, expression, i);
				Lexemes.push_back(Lexeme(Tang, "tg"));
				i += 2; 
			}
			else if (expression.substr(i, 2) == "ln") 
			{
				check_UnaryOperation_Const(Lexemes, expression, i); 
				Lexemes.push_back(Lexeme(Ln, "ln"));
				i += 2;
			}
			else if (expression.substr(i, 2) == "pi")
			{
				check_UnaryOperation_Const(Lexemes, expression, i);
				Lexemes.push_back(Lexeme(Number, std::to_string(PI)));
				i += 2;
			}
			else if (expression[i] == 'e')
			{
				check_UnaryOperation_Const(Lexemes, expression, i);
				Lexemes.push_back(Lexeme(Number, std::to_string(ex)));
				++i;
			}
			else if (expression[i] == ' ') ++i;
			else throw UnexpectedSymbolError("Недопустимый символ. Слово № ", Lexemes.size() - multiply_count + 1);
		}
	
		else if (i + 1 < expression.size())
		{
			if (expression.substr(i, 2) == "tg") 
			{
				check_UnaryOperation_Const(Lexemes, expression, i);
				Lexemes.push_back(Lexeme(Tang, "tg"));
				i += 2; 
			}
			else if (expression.substr(i, 2) == "ln") 
			{
				check_UnaryOperation_Const(Lexemes, expression, i); 
				Lexemes.push_back(Lexeme(Ln, "ln"));
				i += 2;
			}
			else if (expression.substr(i, 2) == "pi")
			{
				check_UnaryOperation_Const(Lexemes, expression, i);
				Lexemes.push_back(Lexeme(Number, std::to_string(PI)));
				i += 2;
			}
			else if (expression[i] == 'e')
			{
				check_UnaryOperation_Const(Lexemes, expression, i);
				Lexemes.push_back(Lexeme(Number, std::to_string(ex)));
				++i;
			}
			else if (expression[i] == ' ') ++i;
			else throw UnexpectedSymbolError("Недопустимый символ. Слово № ", Lexemes.size() - multiply_count + 1);
		}

		else if (expression[i] == 'e')
		{
			check_UnaryOperation_Const(Lexemes, expression, i);
			Lexemes.push_back(Lexeme(Number, std::to_string(ex)));
			++i;
		}
		else if (expression[i] == ' ') ++i;
		else throw UnexpectedSymbolError("Недопустимый символ. Слово № ", Lexemes.size() - multiply_count + 1);
	}

	if (Lexemes.size() > 0)
	{
		switch (Lexemes.back().type)
		{
		case Plus:
		case Minus:
		case UnaryMinus:
		case Multiply:
		case Division:
		case Power:
		case Sinus:
		case Cosin:
		case Tang:
		case Ctan:
		case Sqrt:
		case Ln:
		case Abs:
			throw UnexpectedSymbolError("Ожидался аргумент функции после слова № ", Lexemes.size() - multiply_count);
		case LeftBracket:
			throw UnexpectedSymbolError("Ожидалась закрывающая скобка после слова № ", Lexemes.size() - multiply_count);
		}
	}
	if (BracketCount < 0) throw UnexpectedSymbolError("Ожидалась открывающая скобка.");
	else if (BracketCount > 0) throw UnexpectedSymbolError("Ожидалась закрывающая скобка.");

	return Lexemes;
}

void absolute(std::stack<double>& numbers, std::stack<Lexeme>& operations)
{
	double operand = numbers.top();
	numbers.pop();
	numbers.push(abs(operand));
	operations.pop();
}

void nlog(std::stack<double>& numbers, std::stack<Lexeme>& operations, const int& index)
{
	double operand = numbers.top();
	numbers.pop();
	if (operand <= 0) throw UnexpectedSymbolError("Неположительное выражение под логарифмом. Слово № ", index + 1);
	numbers.push(log(operand));
	operations.pop();
}

void square_root(std::stack<double>& numbers, std::stack<Lexeme>& operations, const int& index)
{
	double operand = numbers.top();
	numbers.pop();
	if (operand < 0) throw UnexpectedSymbolError("Отрицательное значение под корнем. Слово № ", index + 1);
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
	if (operand == 3 * PI / 2)
		numbers.push(0);
	else if (round((operand - PI / 2) / PI) == (operand - PI / 2) / PI)
		numbers.push(0);
	else
		numbers.push(cos(operand));
	operations.pop();
}

void tangens(std::stack<double>& numbers, std::stack<Lexeme>& operations, const int& index)
{
	double operand = numbers.top();
	numbers.pop();
	if (operand == 3 * PI / 2)
		throw UnexpectedSymbolError("Тангенс не существует. Слово № ", index + 1);
	else if (round((operand - PI / 2) / PI) == (operand - PI / 2) / PI)
		throw UnexpectedSymbolError("Тангенс не существует. Слово № ", index + 1);
	else
		numbers.push(tan(operand));
	operations.pop();
}

void cotangens(std::stack<double>& numbers, std::stack<Lexeme>& operations, const int& index)
{
	double operand = numbers.top();
	numbers.pop();
	if (round(operand / PI) == operand / PI)
		throw UnexpectedSymbolError("Котангенс не существует. Слово № ", index + 1);
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

void division(std::stack<double>& numbers, std::stack<Lexeme>& operations, const int& index)
{
	double operandR = numbers.top();
	numbers.pop();
	if (operandR == 0) throw UnexpectedSymbolError("Невозможно поделить на 0. Слово № ", index + 1);
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

void unary_minuss(std::stack<double>& numbers, std::stack<Lexeme>& operations)
{
	double operand = numbers.top();
	numbers.pop();
	numbers.push(-operand);
	operations.pop();
}

/// <summary>
/// priorty:
/// sqrt, sin, cos, tg, ctg, ln, unary minus
/// power
/// *, /
/// +, -
/// </summary>
/// <param name="expression"></param>
/// <returns></returns>

double count(std::string& expression)
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
				switch (operations.top().type)
				{
				case UnaryMinus:
				{
					unary_minuss(numbers, operations);
					break;
				}
				case Abs:
				{
					absolute(numbers, operations);
					break;
				}
				case Ln:
				{
					nlog(numbers, operations, i);
					break;
				}
				case Sqrt:
				{
					square_root(numbers, operations, i);
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
					tangens(numbers, operations, i);
					break;
				}
				case Ctan:
				{
					cotangens(numbers, operations, i);
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
					division(numbers, operations, i);
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
			else
			{
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
					unary_minuss(numbers, operations);
					break;
				}
				case Abs:
				{
					if (token[i].value == "")
					{
						if (i + 1 < token.size())
						{
							if (token[i + 1].value == std::to_string(PI) || token[i + 1].value == std::to_string(ex))
							{
								operations.push(Lexeme(Multiply, ""));
								numbers.push(std::stod(token[i + 1].value));
								multiply(numbers, operations);
								i += 2;
							}
							else absolute(numbers, operations);
						}
						else absolute(numbers, operations);
					}
					else absolute(numbers, operations);
					
					break;
				}
				case Ln:
				{
					if (token[i].value == "")
					{
						if (i + 1 < token.size())
						{
							if (token[i + 1].value == std::to_string(PI) || token[i + 1].value == std::to_string(ex))
							{
								operations.push(Lexeme(Multiply, ""));
								numbers.push(std::stod(token[i + 1].value));
								multiply(numbers, operations);
								i += 2;
							}
							else nlog(numbers, operations, i);
						}
						else nlog(numbers, operations, i);
					}
					else nlog(numbers, operations, i);
					
					break;
				}
				case Sqrt:
				{
					if (token[i].value == "")
					{
						if (i + 1 < token.size())
						{
							if (token[i + 1].value == std::to_string(PI) || token[i + 1].value == std::to_string(ex))
							{
								operations.push(Lexeme(Multiply, ""));
								numbers.push(std::stod(token[i + 1].value));
								multiply(numbers, operations);
								i += 2;
							}
							else square_root(numbers, operations, i);
						}
						else square_root(numbers, operations, i);
					}
					else square_root(numbers, operations, i);
					
					break;
				}
				case Sinus:
				{
					if (token[i].value == "")
					{
						if (i + 1 < token.size())
						{
							if (token[i + 1].value == std::to_string(PI) || token[i + 1].value == std::to_string(ex))
							{
								operations.push(Lexeme(Multiply, ""));
								numbers.push(std::stod(token[i + 1].value));
								multiply(numbers, operations);
								i += 2;
							}
							else sinus(numbers, operations);
						}
						else sinus(numbers, operations);
					}
					else sinus(numbers, operations);
					
					break;
				}
				case Cosin:
				{
					if (token[i].value == "")
					{
						if (i + 1 < token.size())
						{
							if (token[i + 1].value == std::to_string(PI) || token[i + 1].value == std::to_string(ex))
							{
								operations.push(Lexeme(Multiply, ""));
								numbers.push(std::stod(token[i + 1].value));
								multiply(numbers, operations);
								i += 2;
							}
							else cosinus(numbers, operations);
						}
						else cosinus(numbers, operations);
					}
					else cosinus(numbers, operations);
					
					break;
				}
				case Tang:
				{
					if (token[i].value == "")
					{
						if (i + 1 < token.size())
						{
							if (token[i + 1].value == std::to_string(PI) || token[i + 1].value == std::to_string(ex))
							{
								operations.push(Lexeme(Multiply, ""));
								numbers.push(std::stod(token[i + 1].value));
								multiply(numbers, operations);
								i += 2;
							}
							else tangens(numbers, operations, i);
						}
						else tangens(numbers, operations, i);
					}
					else tangens(numbers, operations, i);
					
					break;
				}
				case Ctan:
				{
					if (token[i].value == "")
					{
						if (i + 1 < token.size())
						{
							if (token[i + 1].value == std::to_string(PI) || token[i + 1].value == std::to_string(ex))
							{
								operations.push(Lexeme(Multiply, ""));
								numbers.push(std::stod(token[i + 1].value));
								multiply(numbers, operations);
								i += 2;
							}
							else cotangens(numbers, operations, i);
						}
						else cotangens(numbers, operations, i);
					}
					else cotangens(numbers, operations, i);
					
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
					division(numbers, operations, i);
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
					unary_minuss(numbers, operations);
					break;
				}
				case Abs:
				{
					absolute(numbers, operations);
					break;
				}
				case Ln:
				{
					nlog(numbers, operations, i);
					break;
				}
				case Sqrt:
				{
					square_root(numbers, operations, i);
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
					tangens(numbers, operations, i);
					break;
				}
				case Ctan:
				{
					cotangens(numbers, operations, i);
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
					unary_minuss(numbers, operations);
					break;
				}
				case Abs:
				{
					absolute(numbers, operations);
					break;
				}
                case Ln:
				{
					nlog(numbers, operations, i);
					break;
				}
				case Sqrt:
				{
					square_root(numbers, operations, i);
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
					tangens(numbers, operations, i);
					break;
				}
				case Ctan:
				{
					cotangens(numbers, operations, i);
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
					division(numbers, operations, i);
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
			unary_minuss(numbers, operations);
			break;
		}
		case Abs:
		{
			absolute(numbers, operations);
			break;
		}
		case Ln:
		{
			nlog(numbers, operations, i);
			break;
		}
		case Sqrt:
		{
			square_root(numbers, operations, i);
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
			tangens(numbers, operations, i);
			break;
		}
		case Ctan:
		{
			cotangens(numbers, operations, i);
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
			division(numbers, operations, i);
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
	else throw UnexpectedSymbolError("Нет данных для обработки.");
}