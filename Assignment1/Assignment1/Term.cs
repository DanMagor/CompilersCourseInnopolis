using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment1
{
    class Term : Expression
    {
        public enum Opcode
        {
           Plus,
           Minus,
           None
        }

        private Opcode _op;

        public Term(Opcode op, Expression left, Expression right)
        {
            _op = op;
            _left = left;
            _right = right;
        }

        public Opcode op
        {
            get { return _op; }
            set { _op = value; }
        }

        public override long Calculate()
        {
            var left = Left.Calculate();
            var right = Right.Calculate();
            switch (op)
            {
                case Opcode.Plus: return left + right;
                case Opcode.Minus: return left - right;
                default: throw new ArgumentException();
            }
        }
    }
}
