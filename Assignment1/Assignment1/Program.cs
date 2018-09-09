using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment1
{
    class Program
    {
        public static void Main(string[] args)
        {
            //var input = System.IO.File.ReadAllText(@"input.txt");
            System.IO.StreamReader file = new System.IO.StreamReader(@"input.txt");
            string input;
            using (System.IO.StreamWriter output = new System.IO.StreamWriter(@"output.txt"))
            {
                while ((input = file.ReadLine()) != null)
                {
                    var parser = new Parser(input);
                    var expressionTree = parser.Parse();
                    var result = expressionTree.Calculate();
                    output.WriteLine(result);
                }
            }
        }
    }
}
