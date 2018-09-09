using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Assignment1;
namespace ParserTest
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void OneNumber()
        {
            var inputString = "0";
            var expectedResult = 0;
            var parser = new Parser(inputString);
            var calculatedResult = parser.Parse().Calculate();
            Assert.AreEqual(expectedResult, calculatedResult, 0, "Test 1 failed. Expected: " + expectedResult + " Received: " + calculatedResult);
        }

        [TestMethod]
        public void Test2()
        {
            var inputString = "1+1";
            var expectedResult = 1+1;
            var parser = new Parser(inputString);
            var calculatedResult = parser.Parse().Calculate();
            Assert.AreEqual(expectedResult, calculatedResult, 0, "Test 1 failed. Expected: " + expectedResult + " Received: " + calculatedResult);
        }

        [TestMethod]
        public void Test3()
        {
            var inputString = "2+2*3";
            var expectedResult = 2+2*3;
            var parser = new Parser(inputString);
            var calculatedResult = parser.Parse().Calculate();
            Assert.AreEqual(expectedResult, calculatedResult, 0, "Test 1 failed. Expected: " + expectedResult + " Received: " + calculatedResult);
        }

        [TestMethod]
        public void Test4()
        {
            var inputString = "0<1";
            var expectedResult = 1;
            var parser = new Parser(inputString);
            var calculatedResult = parser.Parse().Calculate();
            Assert.AreEqual(expectedResult, calculatedResult, 0, "Test 1 failed. Expected: " + expectedResult + " Received: " + calculatedResult);
        }

        [TestMethod]
        public void Test5()
        {
            var inputString = "1>1";
            var expectedResult = 0;
            var parser = new Parser(inputString);
            var calculatedResult = parser.Parse().Calculate();
            Assert.AreEqual(expectedResult, calculatedResult, 0, "Test 1 failed. Expected: " + expectedResult + " Received: " + calculatedResult);
        }

        [TestMethod]
        public void Test6()
        {
            var inputString = "1=1";
            var expectedResult = 1;
            var parser = new Parser(inputString);
            var calculatedResult = parser.Parse().Calculate();
            Assert.AreEqual(expectedResult, calculatedResult, 0, "Test 1 failed. Expected: " + expectedResult + " Received: " + calculatedResult);
        }

        [TestMethod]
        public void Test7()
        {
            var inputString = "3>2";
            var expectedResult = 1;
            var parser = new Parser(inputString);
            var calculatedResult = parser.Parse().Calculate();
            Assert.AreEqual(expectedResult, calculatedResult, 0, "Test 1 failed. Expected: " + expectedResult + " Received: " + calculatedResult);
        }

        [TestMethod]
        public void Test8()
        {
            var inputString = "(0<1)>(2)";
            var expectedResult = 0;
            var parser = new Parser(inputString);
            var calculatedResult = parser.Parse().Calculate();
            Assert.AreEqual(expectedResult, calculatedResult, 0, "Test 1 failed. Expected: " + expectedResult + " Received: " + calculatedResult);
        }


        [TestMethod]
        public void Test9()
        {
            var inputString = "57+(23*23)-(1235)*32<23*(1>2)*5+32+31+556";
            var expectedResult = (57 + (23 * 23) - (1235) * 32) < (23 * (0) * 5 + 32 + 31 + 556)?1:0;
            var parser = new Parser(inputString);
            var calculatedResult = parser.Parse().Calculate();
            Assert.AreEqual(expectedResult, calculatedResult, 0, "Test 1 failed. Expected: " + expectedResult + " Received: " + calculatedResult);
        }

        [TestMethod]
        public void Test10()
        {
            var inputString = "57*123+123-45<23*((23)-45+(464*23)*465*0+23-89*23)";
            var expectedResult = (57 * 123 + 123 - 45) < (23 * ((23) - 45 + (464 * 23) * 465 * 0 + 23 - 89 * 23))?1:0;
            var parser = new Parser(inputString);
            var calculatedResult = parser.Parse().Calculate();
            Assert.AreEqual(expectedResult, calculatedResult, 0, "Test 1 failed. Expected: " + expectedResult + " Received: " + calculatedResult);
        }

        [TestMethod]
        public void Test11()
        {
            var inputString = "57*123+123-45*23*((23)-45+(464*23)*465*0+23-89*23)";
            var expectedResult = 57 * 123 + 123 - 45 * 23 * ((23) - 45 + (464 * 23) * 465 * 0 + 23 - 89 * 23);
            var parser = new Parser(inputString);
            var calculatedResult = parser.Parse().Calculate();
            Assert.AreEqual(expectedResult, calculatedResult, 0, "Test 1 failed. Expected: " + expectedResult + " Received: " + calculatedResult);
        }







    }
}
