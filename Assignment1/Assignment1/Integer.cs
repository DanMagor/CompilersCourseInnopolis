using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment1
{
    public class Integer : Expression
    {
        private long _value;

        public Integer(long value)
        {
            _value = value;
        }

        public long Value => _value;
        public override long Calculate()
        {
            return _value;
        }

       
    }
}
