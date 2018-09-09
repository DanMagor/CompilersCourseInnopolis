using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment1
{
    public class Parser
    {
        private string _input;
        private int _currentChar;

        public Parser(string s)
        {
            s = s.Replace(" ", string.Empty);
            _input = s;
            _currentChar = 0;
        }
        
        public Expression Parse()
        {
            return ParseRelation();
        } 

        private Expression ParseRelation()
        {
            var result = ParseTerm();
            var op = ParseRelationOperator();
            while (op != Relation.Opcode.None)
            {
                var right = ParseTerm();
                result = new Relation(op, result, right);
                op = ParseRelationOperator();
            }

            return result;
        }

        private Relation.Opcode ParseRelationOperator()
        {
            if (_currentChar >= _input.Length) return Relation.Opcode.None;
            switch (_input[_currentChar])
            {
                case '<':
                    _currentChar++;
                    return Relation.Opcode.Less;
                case '>':
                    _currentChar++;
                    return Relation.Opcode.Greater;
                case '=':
                    _currentChar++;
                    return Relation.Opcode.Equal;
                default: return Relation.Opcode.None;
            }
        }

        private Expression ParseTerm()
        {
            var result = ParseFactor();
            var op = ParseTermOperator();
            while (op!= Term.Opcode.None)
            {
                var right = ParseFactor();
                result = new Term(op, result, right);
                op = ParseTermOperator();
            }
            return result;
        }

        private Term.Opcode ParseTermOperator()
        {
            if (_currentChar >= _input.Length) return Term.Opcode.None;
            switch (_input[_currentChar])
            {
                case '+':
                    _currentChar++;
                    return Term.Opcode.Plus;
                case '-':
                    _currentChar++;
                    return Term.Opcode.Minus;
                default: return Term.Opcode.None;
            }
        }

        private Expression ParseFactor()
        {
            var result = ParsePrimary();

            var op = ParseFactorOperator();
            while (op != Factor.Opcode.None)
            {
                var right = ParsePrimary();
                result = new Factor(op, result, right);
                op = ParseFactorOperator();
            }
            return result;
        }

        private Factor.Opcode ParseFactorOperator()
        {
            if (_currentChar >= _input.Length) return Factor.Opcode.None;
            switch (_input[_currentChar])
            {
                case '*':
                    _currentChar++;
                    return Factor.Opcode.Multiply;
                
                default:
                    return Factor.Opcode.None;
            }
        }

        private Expression ParsePrimary()
        {
            Expression result = null;
            if (_currentChar < _input.Length && char.IsDigit(_input[_currentChar]))
            {
                result = ParseInteger();
            }
            else if (_input[_currentChar] == '(')
            {
                _currentChar++;
                result = new Parenthesized(Parse());
                _currentChar++; //skip )
            }
            else
            {
                throw new Exception("invalid input");
            }

            return result;
        }

        private Integer ParseInteger()
        {
            var temp = "";

            temp += _input[_currentChar];
            _currentChar++;
            while(_currentChar < _input.Length && char.IsDigit(_input[_currentChar]))
            {
                temp += _input[_currentChar];
                _currentChar++;
            }
            try
            {
                return new Integer(Convert.ToInt64(temp));
            }
            catch (Exception)
            {
                Console.WriteLine("Convertation Exception!");
                throw;
            }
        }
    }
}
