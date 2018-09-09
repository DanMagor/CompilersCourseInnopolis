using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment1
{
    public abstract class Expression
    {
        protected Expression _left;
        protected Expression _right;

        

        public abstract long Calculate();

        public Expression Left => _left;

        public Expression Right => _right;
    }
}
