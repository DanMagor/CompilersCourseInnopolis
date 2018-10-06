# HA-2.2: Testing Lexical analyzer
## Done by Anton Skudarnov and Damir Mubarakshin. BS3-SE.

### 1. Niyaz Ginatullin and Dilshat Salikhov. Scala Lexical Analyzer on Java.

#### Errors:   

1.   __Error:__ \` identificator\` in quotes detection. In scala, if you close some sequence of characters inside \` symbol 
it will be defined as identificator. As example \`if\`. This sequence will be defined 
not like keyword "if", but like identfiyer with this name.      
__Fix:__ _Change processStrangeIdentifyer_ method. Delete inside condition and paste *return new Token(currentTokenBuffer, Token.IDENTIFIER)*
2. __Error:__ Unsuspected behaviour on symbol $. Right after this symbol program just don't analyze next tokens.   
   __Fix:__ Change the function that will catch this type of tokens.   
3. __Error:__ No string detection in quotes like " " & ' '.       
__Fix:__ Add method that will catch this type of tokens.
4. __Error:__ Unsuspected behaviour on arithmetic operations with assign. As example: x = 1 + 2;     
5. __Error:__ No HEX numbers detections. Example: 0x0213f  
6. __Error:__  No float detection without digit before dot. As example .1  
7. __Error:__  No float detection with 'f' letter. Example: 0.1f 

#### Conclusion: 
In general analyzer parses tokens for simple code, but it fails on unsuspected cases. Also it skips all unsuspected patterns.
As example comments, $-symbol, identfiyers with \` \` brackets. Also float and HEX digits analyzer is not implemented fully.

### 2. Ilshat Gibadullin and Ildar Yalalov. Scala Lexical Analyzer on java.
#### Errors:
1.	__Error:__ Lexical analyzer does not recognize hexadecimal numbers. 
It splits, for example, ‘0xffff’ number into two tokens: T_literal_integer(0) and T_identifier(xffff). But it must recognize it like one numerical token.   
__Fix:__ Go into NumericLiteralToken class, look into Builder class and add there hexadecimal numbers handler.
2. __Error:__ Lexical analyzer does not recognize some float numbers like ‘3,14f’ (with ‘f’ in the end). It splits this numbers into two tokens, e.g.: T_literal_float(3,14) and T_identifier(f). It must recognize it like one numerical token.   
__Fix:__ Go into NumericLiteralToken class, look into Builder class and add there float numbers handler.

#### Conclusion:
In general analyzer was written well enough, but there is no detection for hex and float nubmer. It's easy to fix, and I think it's just small missing of implementation.



