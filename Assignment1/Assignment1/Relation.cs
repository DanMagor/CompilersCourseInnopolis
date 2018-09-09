using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment1
{
    class Relation : Expression
    {
        public enum Opcode
        {
            Less,
            Greater,
            Equal,
            None
        }

        private Opcode _op;

        public Relation(Opcode op, Expression left, Expression right)
        {
            _op = op;
            _left = left;
            _right = right;
        }

        public Opcode op
        {
            get { return _op; }
            set { _op = value;  }
        }

        public override long Calculate()
        {
            var left = Left.Calculate();
            var right = Right.Calculate();
            switch (op)
            {
                case Opcode.Equal: return left == right?1:0;
                case Opcode.Less: return left < right ? 1 : 0;
                case Opcode.Greater: return left > right ? 1 : 0;
                default: throw new ArgumentException();
            }
        }
    }
}
