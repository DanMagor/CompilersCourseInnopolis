using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment1
{
    public class Parenthesized:Expression
    {
        private Expression _expression;

        public override long Calculate()
        {
            return _expression.Calculate();
        }

        public Parenthesized(Expression expression)
        {
            _expression = expression;
        }
    }
}
