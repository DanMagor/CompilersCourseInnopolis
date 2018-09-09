using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment1
{
    class Factor : Expression
    {

        public enum Opcode
        {
            Multiply,
            None
        }

        private Opcode _op;

        public Factor(Opcode op, Expression left, Expression right)
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
                case Opcode.Multiply: return left * right;
                default: throw new ArgumentException();
            }
        }
    }
}
